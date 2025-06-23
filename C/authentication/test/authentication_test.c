#include <stdio.h>
#include "authentication.h"

int main()
{
	int   result = 0;
	AU_t* manager = AuInit();
	pam_handle_t *pam = manager;
	if (!manager)
	{
		perror("manager malloc Failed\n");
		return 0;
	}
	
	if (AuAddUser(manager, "momy", "dummy") != manager)
	{
		perror("AuAddUser test Failed\n");
		return 0;
	}
	
	if (AuAddUser(manager, "dumdum", "bumbum") != manager)
	{
		perror("AuAddUser test Failed\n");
		return 0;
	}
	
	if (AuAddUser(manager, "uri", "uri") != manager)
	{
		perror("AuAddUser test Failed\n");
		return 0;
	}
	
	
	/* PAM *****************************************
	 */
	

	result = pam_authenticate(pam_handle_t *pamh, int flags);
	printf("pam_authenticate result\n", result);
	
	AuDestroy(manager);
	
	return 0;
}

