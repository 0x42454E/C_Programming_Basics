/*  API for linux Authenticator	*/
/*  Group: ILRD CR8 			*/
/*  Created:  30.10.24			*/
/*  Modified: 			*/
/*  Version:  0.0.1				*/

#ifndef __Authentication_H__
#define __Authentication_H__

typedef struct authorization_s AU_t;


/******************************************************************************
 * Create a credentials data base archive dummy.
 * Return pointer to data center, null on failure.
 * Time Complexity: O(1)
 */
AU_t* AuInit(void);


/******************************************************************************
 * Function recieves data_center struct and credentials for storage.
 * Create a new user and archive its credentials.
 * Return pointer to data center, null on failure.
 * Time Complexity: O(1)
 */
AU_t* AuAddUser(AU_t* data_center, char* nickname, char* password);


/******************************************************************************
 * Find and Delete user from data base.
 * *data_center: pointer to the manager and credentials for the user to delete.
 * Return success or failure, true or false.
 * Time Complexity: O(n)
 */
int AuDeleteUser(AU_t* data_center, char* nickname, char* password);


/******************************************************************************
 * Authentication function. 
 * *data_center: pointer to the data_center.
 * Return success or failure, true or false.
 * Time Complexity: O(n); while n is the data base size.
 */
int Authenticate(AU_t* data_center, char* nickname, char* password);


/******************************************************************************
 * Authentication data center destroy function. 
 * *data_center: pointer to the data_center.
 * Return success or failure, true or false.
 * Time Complexity: O(n); while n is the data base size.
 */
void AuDestroy(AU_t* data_center);




#endif          /*  __Authentication_H__ */






