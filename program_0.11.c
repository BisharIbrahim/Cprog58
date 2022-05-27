/******************************************************************************
 * Header Files
******************************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "crypt.h"
/*#include "depression.h"*/

/******************************************************************************
 * Prototype Function
******************************************************************************/
void printMenu();
void adminMenu();
void adminOptions();
void encryptFile();
void decryptFile();
void compressFile();
void printList();
/**const char* encryptPassword(char pw[]);**/

/*global variables initialized*/
int fileCounter = 0;

/******************************************************************************
 * Create Linked List
*****************************************************************************/

struct fileList{
    int fileID;
    char fileName[100];
    char filePassword[100];
    struct fileList *next;
};

struct fileList *head = NULL;
struct fileList *current = NULL;

/******************************************************************************
 * This is the program start - John
*****************************************************************************/
int main(){

    int selection;
    
    /*char encrypted_pass[];*/

        do{
            printMenu();
            scanf("%d", &selection);
            switch(selection){
				/*Case 1 should encrypt and compress a file*/
                case 1: encryptFile();
                    break;

				/*Case 2 should decrypt and decompres a file*/
                case 2: decryptFile();
                    break;

                case 3: compressFile();
                    break;

                case 4: printf("decompressFile();");
                    break;

                case 5: adminOptions();
                    break;

                case 6:
                    exit(0);
                    break;

                default: printf("Invalid choice.");
                    while(getchar() != '\n'); /* clears previous input allowing 
                                                 for fresh user input         */

            } 
        } while (selection != 6);
    return (0);
}

/******************************************************************************
 * Prints Menu - Bishar
******************************************************************************/
void printMenu(){
    printf("\n\n"
    "************************************************************************\n"
    "                              Main Menu\n"
    "************************************************************************\n"
    "1. Encrypt a File\n"
    "2. Decrypt a File\n"
    "3. Compress a File\n"
    "4. Decompress a File\n"
    "5. Admin\n"
    "6. Exit\n"
    "\n"
    "Enter your choice> \n");
    
}
/******************************************************************************
 * Admin Menu - Bishar
******************************************************************************/
void adminMenu(){
    printf("\n\n"
    "************************************************************************\n"
    "                              Admin Menu\n"
    "************************************************************************\n"
    "1. Access file list\n"
    "2. Get master key\n"
    "3. Return\n"
    "\n"
    "Enter your choice> \n");
}

/******************************************************************************
 * Admin Options - Bishar
******************************************************************************/
void adminOptions(){
    
	int selection;
    
    do{
		adminMenu();
		scanf("%d", &selection);
        switch(selection){
            case 1: 
                printList();
				break;

            case 2: printf("get master key");
                break;

            case 3:
                break;

            default:
                printf("Please input a valid option");
                while(getchar() != '\n'); /* clears previous input allowing 
                                            for fresh user input         */
        }
    }while(selection!= 3);
}

void printList() {
   struct fileList *ptr = head;
   printf("\n[ ");
	
   while(ptr != NULL) {
      printf("(%d,%s,%s) ",ptr->fileID,ptr->fileName, ptr->filePassword);
      ptr = ptr->next;
   }
	
   printf(" ]");
}


/******************************************************************************
 * Perfroms file encryption - Bishar
******************************************************************************/
void encryptFile(){
	char fname[100];
	char inputPassword[100];
	
	printf("\n\n"
    "************************************************************************\n"
    "                     Encrpyt a Text File\n"
    "************************************************************************\n"); 	

	printf(" Input the name of file to encrypt: ");
	scanf("%s",fname);	
    printf("Enter a new password for file: ");
    scanf("%s",inputPassword);

    if((encrypt(fname))==1){

        struct fileList *link = (struct fileList*) malloc(sizeof(struct fileList));
            
        link->fileID = fileCounter;

        strcpy(link->fileName, fname);
        strcpy(link->filePassword, inputPassword);

        /*fname = link->fileName;
        inputPassword = link->filePassword;*/
            
        link->next = head;
            
        head = link;
        fileCounter++;
    }
    
    
}

/******************************************************************************
 * Perfroms file decryption - Bishar
******************************************************************************/
void decryptFile(){

	char fname[20];
	char inputPassword[100];
	
	printf("\n\n"
    "************************************************************************\n"
    "                         Decrypt a Text File\n"
    "************************************************************************\n"); 		
	
	printf(" Input the name of file to decrypt : ");
	scanf("%s",fname);	
	printf("Input password for file: ");
    scanf("%s",inputPassword);

    if(/*password is correct*/){
        decrypt(fname);
    }else{
        printf("Password is incorrect...");
    }
	

}

void compressFile(){
     
    char fname[100];

    printf("\n\n"
    "************************************************************************\n"
    "                         Compress a Text File\n"
    "************************************************************************\n");     

    printf(" Input the name of file to compress : ");
    scanf("%s",fname);

    /*compress(fname);*/

}
