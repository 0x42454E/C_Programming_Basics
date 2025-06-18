/**
 * Simple linked list based authentication system implementation.
 * 
 * Author: Ben
 * Date: 2024-10
 */


#include <stdio.h>    /* perror */
#include <stdlib.h>   /* malloc, free */
#include <string.h>   /* strcmp */

#include "authentication.h"


struct authorization_s
{
	int   status;
	char* nickname;
	char* password;
	AU_t* next;
	AU_t* head;
};

/******************************************************************************
 * Create a credentials data base archive dummy.
 * Return pointer to data center, null on failure.
 * Time Complexity: O(1)
 */
AU_t* AuInit(void)
{
	AU_t* data_center = malloc(sizeof(AU_t));
	if (!data_center)
	{
		perror("Init Malloc Failed\n");
		return NULL;
	}
	
	
	data_center->status = 1;
	data_center->next = NULL;
	data_center->head = data_center;
	
	return data_center;
}

/******************************************************************************
 * Function recieves data_center struct and credentials for storage.
 * Create a new user and archive its credentials.
 * Return pointer to data center, null on failure.
 * Time Complexity: O(1)
 */
AU_t* AuAddUser(AU_t* data_center, char* nickname, char* password)
{
	AU_t* user = malloc(sizeof(AU_t));
	if (!user)
	{
		perror("User Malloc Failed\n");
		return NULL;
	}
	
	user->nickname = nickname;
	user->password = password;
	user->status = 1;
	user->next = data_center->head;
	data_center->head = user;
		
	return data_center;
}

/******************************************************************************
 * Find and Delete user from data base.
 * *data_center: pointer to the manager and credentials for the user to delete.
 * Return success or failure, true or false.
 * Time Complexity: O(n)
 */
int AuDeleteUser(AU_t* data_center, char* nickname, char* password)
{
	if (!data_center)
	{
		perror("Invalid User\n");
		return 0;
	}
	
	if (!data_center->status)
	{
		perror("Invalid Request, Send To AuDestroy()\n");
		return 0;
	}
	
	data_center = data_center->head;
	
	while (data_center->next && (strcmp(data_center->nickname, nickname) && strcmp(data_center->password, password)))
	{
		data_center = data_center->next;
	}
	
	if (!data_center->next)
	{
		perror("User Is Not Stored\n");
		return 0;
	}
	
	if (!data_center->status)
	{
		perror("User Has Already Been Deleted\n");
		return 0;
	}
	
	data_center->status = 0;
	
	return 1;
}

/******************************************************************************
 * Authentication function. 
 * *data_center: pointer to the data_center.
 * Return success or failure, true or false.
 * Time Complexity: O(n); while n is the data base size.
 */
int Authenticate(AU_t* data_center, char* nickname, char* password)
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


/******************************************************************************
 * Authentication data center destroy function. 
 * *data_center: pointer to the data_center.
 * Return success or failure, true or false.
 * Time Complexity: O(n); while n is the data base size.
 */
void AuDestroy(AU_t* data_center)
{
	AU_t*  runner = data_center->head;
	
	data_center = data_center->head;
	
	while (runner)
	{
		data_center = data_center->next;
		free(runner);
		runner = data_center;
	}
}




