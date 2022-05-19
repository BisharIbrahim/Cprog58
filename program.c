/******************************************************************************
 * Header Files
******************************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <PlaceHolder.h>

/******************************************************************************
 * Prototype Function
******************************************************************************/
void printMenu();
void listFiles();
void encrypt();
void decrypt();
void compress();

/******************************************************************************
 * This is the program start - John
*****************************************************************************/
int main(){

    int selection;

        do{
            printMenu();
            scanf("%d", &selection);
            switch(selection){
                case 1: Compress();
                    break;

                case 2: Decompress();
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
 * Admib Menu - Bishar
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
    adminMenu();
    scanf("%d", selection);
    do{
        switch(selection){
            case 1: 
                printf("%s", masterkey);

            case 2: listfiles();
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
 * Prints linked list that contains all file names
 * of files that were compressed and/or encrypted by this program. - Bishar
*****************************************************************************/
void listFiles(){


}
/******************************************************************************
 * Performs File (and adds password if needed) Encryption. - John
******************************************************************************/
void encrypt(){
/*This opens the file*/


   FILE *fp;
    int i = 0;
    fp = fopen(file, "r");

    if (fp == NULL){
        printf("File not found");
    }

    encryptFile();
    printf("Enter Password");
    scanf(password);
    encryptPassword();
  

}

/******************************************************************************
 * Performs data decryption - John
******************************************************************************/
void decrypt(){
/*This opens the file*/
    printf("ask for file name");
    scanf(file name);
    
    FILE *fp;
    int i = 0;
    fp = fopen(file, "r");

    if (fp == NULL){
        printf("File not found");
    }


    if(there is a password){
        prompt user for password;


        while(true){
            check if password is true;
            if password is correct{
                decompressFile();        
                decryptFile();
                printf("File is decrypted");
                fclose(file);
                break;
            }

            else{
                printf password incorrect;
            }
                
        }


    }

}
/******************************************************************************
 * Performs File compression - John
******************************************************************************/
void compress(){
    /*This opens the file*/
    printf("ask for file name");
    scanf(file);
    
    FILE *fp;
    int i = 0;
    fp = fopen(file, "r");

    if (fp == NULL){
        printf("File not found");
    }
    compressFile();
}

/******************************************************************************
 * Header File
******************************************************************************/
/******************************************************************************
 * Get the master key. - Bishar
******************************************************************************/

char getMaster(){
    char password = "Password1234!";
    return password;
}

/******************************************************************************
 * Performs the file compression - Alex
******************************************************************************/
void compressFile(){

}
/******************************************************************************
 * Performs file decompression - Alex
******************************************************************************/
void decompressFile(){

}
/******************************************************************************
 * Performs the password encryption - John
******************************************************************************/
void encryptPassword(){

}
/******************************************************************************
 * Performs the password decryption - John
******************************************************************************/
void decryptPassword(){

}
/******************************************************************************
 * Perfroms file encryption - Bishar
******************************************************************************/
void encryptFile(){

    
}
/******************************************************************************
 * Perfroms file decryption - Bishar
******************************************************************************/
void decryptFile(){
    
}
/******************************************************************************
 * 
******************************************************************************/