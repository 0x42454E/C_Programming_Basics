/**
 * PAM-like Authentication API implementation.
 * 
 * Author: Ben
 * Date: 2024-10
 */

#include <stdio.h>   /* perror */
#include <string.h>  /* strcmp */
#include "PAM_API.h"



struct pam_handle
{
	int   status;
	char* nickname;
	char* password;
	AU_t* next;
	AU_t* head;
};

int pam_open_session(pam_handle_t *pamh, int flags)
{
	return (manager->status) ? 1 : 0;
}


int pam_close_session(pam_handle_t *pamh, int flags)
{
	if (manager->status)
	manager->status = 0;
	
	return manager->status;
}	  


int pam_authenticate(pam_handle_t *pamh, int flags)
{
	if (!data_center || !data_center->status)
	{
		perror("Invalid Parameters\n");
		return 0;
	}
	
	data_center = data_center->head;
	
	while (data_center->next && (strcmp(data_center->nickname, nickname) && strcmp(data_center->password, password)))
	{
		data_center = data_center->next;
	}
	
	if (!data_center->next)
	{
		perror("Authentication failed, No Stored User\n");
		return 0;
	}
	
	if (!data_center->status)
	{
		perror("Authentication Failed, Authorization Revoked\n");
		return 0;
	}
	
	return 1;
}

