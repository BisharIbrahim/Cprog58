/******************************************************************************
 * Header Files
******************************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
/*#include <PlaceHolder.h>*/

/******************************************************************************
 * Prototype Function
******************************************************************************/
void printMenu();
void listFiles();
void encrypt(char pass[]);
void decrypt(char pass[]);
void compress();
const char* encryptPassword(char pw[]);

/******************************************************************************
 * This is the program start - John
*****************************************************************************/
int main(){

    int selection;
    char encrypted_pass[];

        do{
            printMenu();
            scanf("%d", &selection);
            switch(selection){
                case 1: encrypt(encrypted_pass);
                    break;

                case 2: decrypt();
                    break;

                case 3: listFiles();
                    break;

                case 4: compress();
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
    printf("Menu text");

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
void encrypt(char pass[]){
/*This opens the file*/


   FILE *fp;
    int i = 0;
    fp = fopen(file, "r");

    if (fp == NULL){
        printf("File not found");
    }

    encryptFile();
    printf("Enter Password: ");
    scanf("%s", password);
    strcpy(pass, encryptPassword(password));
    fclose(fp);
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

    int flag = 0;

    while(flag != 1){
    
        char input[10];

        printf("Enter password: ");
        scanf("%s", input);

        if(strcmp(input, ascii_decrypt(encrypt_pass)) == 0){
            printf("password correct\n");
            flag = 1;
            break;
        }
        else{
            printf("password incorrect, try again\n");
            continue;
        }

    }

    if(flag == 1){
        decompressFile();        
        decryptFile();
        printf("File is decrypted");
        fclose(file);
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
    char password = "Password123";
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
const char* encryptPassword(char pw[]){
    int key = 3;
    int i = 0;
    static char encPass[10];

    while(i < 10 && pw[i] != strlen(pw)){
        encPass[i] = pw[i] + key;
        i++;
    }

    return encPass;
}
/******************************************************************************
 * Perfroms file encryption - Bishar
******************************************************************************/
void encryptFile(){
	char fname[20], ch;
	FILE *fpts, *fptt;
	
	printf("\n\n Encrypt a text file :\n");
	printf("--------------------------\n"); 	
	
	printf(" Input the name of file to encrypt : ");
	scanf("%s",fname);	

	fpts=fopen(fname, "r");
	if(fpts==NULL)
	{
		printf(" File does not exists or error in opening..!!");
		exit(1);
	}
	fptt=fopen("temp.txt", "w");
	if(fptt==NULL)
	{
		printf(" Error in creation of file temp.txt ..!!");
		fclose(fpts);
		exit(2);
	}
	while(1)
	{
		ch=fgetc(fpts);
		if(ch==EOF)
		{
			break;
		}
		else
		{
			ch=ch+100;
			fputc(ch, fptt);
		}
	}
	fclose(fpts);
	fclose(fptt);
	fpts=fopen(fname, "w");
	if(fpts==NULL)
	{
		printf(" File does not exists or error in opening..!!");
		exit(3);
	}
	fptt=fopen("temp.txt", "r");
	if(fptt==NULL)
	{
		printf(" File does not exists or error in opening..!!");
		fclose(fpts);
		exit(4);
	}
	while(1)
	{
		ch=fgetc(fptt);
		if(ch==EOF)
		{
			break;
		}
		else
		{
			fputc(ch, fpts);
		}
	}
	printf(" File %s successfully encrypted ..!!\n\n", fname);
	fclose(fpts);
	fclose(fptt);
    
}
/******************************************************************************
 * Perfroms file decryption - Bishar
******************************************************************************/
void decryptFile(){

	char ch, fname[20];
	FILE *fpts, *fptt;
	
	printf("\n\n Decrypt a text file :\n");
	printf("--------------------------\n"); 	
	
	printf(" Input the name of file to decrypt : ");
	scanf("%s",fname);	
	
	fpts=fopen(fname, "w");
	if(fpts==NULL)
	{
		printf(" File does not exists or error in opening..!!");
		exit(7);
	}
	fptt=fopen("temp.txt", "r");
	if(fptt==NULL)
	{
		printf(" File does not exists or error in opening..!!");
		fclose(fpts);
		exit(9);
	}
	while(1)
	{
		ch=fgetc(fptt);
		if(ch==EOF)
		{
			break;
		}
		else
		{
			ch=ch-100;
			fputc(ch, fpts);
		}
	}
	printf(" The file %s decrypted successfully..!!\n\n",fname);
	fclose(fpts);
	fclose(fptt);

}
/******************************************************************************
 * 
******************************************************************************/

const char* decryptPassword(char pw[]){
    int key = 3;
    static char decPass[10];
    int i = 0;

    while(i < 10 && pw[i] != strlen(pw)){
        decPass[i] = pw[i] - key;
        i++;
    }

    return decPass[]
}
