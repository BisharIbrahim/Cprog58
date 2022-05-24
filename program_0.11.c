/******************************************************************************
 * Header Files
******************************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "crypt.h"

/******************************************************************************
 * Prototype Function
******************************************************************************/
void printMenu();
void adminMenu();
void adminOptions();
void encryptFile();
void decryptFile();
void compressFile();
/**
void listFiles();
void encrypt(char pass[]);
void decrypt(char pass[]);
void compress();
const char* encryptPassword(char pw[]);**/

/******************************************************************************
 * Creating structures
******************************************************************************

typedef struct file{
    int fileID;
    char fileName;
    struct node * next;
}node;

******************************************************************************
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

                case 3: adminOptions();
                    break;

                case 4:
                    exit(0);
                    break;

                default: printf("Invalid choice.");
                    while(getchar() != '\n'); /* clears previous input allowing 
                                                 for fresh user input         */

            } 
        } while (selection != 4);
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
    "1. Compress and Encrypt a File\n"
    "2. Decompress and Decrypt a File\n"
    "3. Admin\n"
    "4. Exit\n"
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
                printf("List files");
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

/******************************************************************************
 * Perfroms file encryption - Bishar
******************************************************************************/
void encryptFile(){
	char fname[100];
	
	
	printf("\n\n"
    "************************************************************************\n"
    "                        Encrpyt and Compress a Text File\n"
    "************************************************************************\n"); 	

	printf(" Input the name of file to encrypt and compress: ");
	scanf("%s",fname);	
    
    encrypt(fname);
}

/******************************************************************************
 * Perfroms file decryption - Bishar
******************************************************************************/
void decryptFile(){

	char fname[20];
	
	printf("\n\n"
    "************************************************************************\n"
    "                         Decrypt a Text File\n"
    "************************************************************************\n"); 		

	printf(" Input the name of file to decrypt : ");
	scanf("%s",fname);	
	
	decrypt(fname);

}

/*void compressFile(){
     
    FILE f,g;

    unsigned int n, freqs[NUM_CHARS];
    char codes[NUM_CHARS], code[NUM_CHARS], fname[100], output[100];


    struct _treenoder = malloc(sizeof(r));

    printf("\n\n"
    "************************************************************************\n"
    "                         Compress a Text File\n"
    "************************************************************************\n");     

    printf(" Input the name of file to compress : ");
    scanf("%s",fname);


    memset(freqs, 0, sizeof(freqs));

    f= fopen (fname, "r");
    if (!f){
        perror(fname);
        exit(1);
    }

    n = get_frequencies (f, freqs);
    fclose(f);

    traverse (r, 0, code, codes);

    sprintf(output, "%s", fname);
    g = fopen(output, "w");
    if (!g){
        perror(output);
        exit(1);
    }

    fwrite(freqs, NUM_CHARS, sizeof(int), g);

    fwrite(&n, 1, sizeof (int), g);

    f = fopen(fname, "r");
    if (!f){
        perror(fname);
        exit(1);
    }

    encode_file(f, g, codes);
    fclose (f);
    fclose (g);

    printf("%s has been compressed\n", fname);
    exit(0);
}
*/
