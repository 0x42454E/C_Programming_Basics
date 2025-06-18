#include <stdlib.h>
#include <stddef.h>
#include <security/pam_appl.h>

#include <errno.h>
#include <stdio.h>


int pam_tty_conv(int num_msg, const struct pam_message **mess, struct pam_response **resp, void *my_data)
{
    struct pam_message *m = (void*)*mess;
    struct pam_response *r;
    int i;
    
    if (my_data)
    {
    	printf("%p\n", my_data);
    }
    
    if (num_msg <= 0 || num_msg >= PAM_MAX_NUM_MSG) 
    {
        (void) fprintf(stderr, "bad number of messages %d " "<= 0 || >= %d\n", num_msg, PAM_MAX_NUM_MSG);
        *resp = NULL;
        return (PAM_CONV_ERR);
    }
    
    if ((*resp = r = calloc(num_msg, sizeof (struct pam_response))) == NULL)
        return (PAM_BUF_ERR);

errno = 0; /* don't propogate possible EINTR */

    /* Loop through messages */
    for (i = 0; i < num_msg; i++) 
    {

        /* bad message from service module */
        if (m->msg == NULL) 
        {
            (void) fprintf(stderr, "message[%d]: %d/NULL\n", i, m->msg_style);
            goto err;
        }

        /*
         * fix up final newline:
         *     removed for prompts
         *     added back for messages
         */

        r->resp = NULL;
        r->resp_retcode = 0;

        switch (m->msg_style) 
        {

        case PAM_PROMPT_ECHO_OFF:
            /*FALLTHROUGH*/

        case PAM_PROMPT_ECHO_ON:
            (void) fputs(m->msg, stdout);

            break;

        case PAM_ERROR_MSG:
            (void) fputs(m->msg, stderr);
            (void) fputc('\n', stderr);
            break;

        case PAM_TEXT_INFO:
            (void) fputs(m->msg, stdout);
            (void) fputc('\n', stdout);
            break;

        default:
            (void) fprintf(stderr, "message[%d]: unknown type "
                "%d/val=\"%s\"\n",
                i, m->msg_style, m->msg);
            /* error, service module won't clean up */
            goto err;
        }
        if (errno == EINTR)
            goto err;

        /* next message/response */
        m++;
        r++;
    }
    return (PAM_SUCCESS);

err:
    *resp = NULL;
    return (PAM_CONV_ERR);
}
         
         
int main()
{
	int err;
	pam_handle_t *pamh;
	struct pam_conv convi;
	convi.conv = pam_tty_conv;
	convi.appdata_ptr = NULL; 
	  
	err = pam_start("chpasswd", "ben", &convi,  &pamh);
	if (err != PAM_SUCCESS) 
	{
		(void) fprintf(stderr, "plock: pam_start failed: %s\n",  pam_strerror(pamh, err));
        	return 0;
	}
	
	err = pam_authenticate(pamh, 0);
	if (err != PAM_SUCCESS) 
        {
            	(void) fprintf(stderr, "Invalid password.\n");
        }
        
        
	return 0;
}

