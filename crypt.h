#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


void encrypt(char *name){
    FILE *fpts, *fptt;
    char ch;

    fpts=fopen(name, "r");
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
    fpts=fopen(name, "w");
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
    printf(" File %s successfully encrypted ..!!\n\n", name);
    fclose(fpts);
    fclose(fptt);
    
}

void decrypt(char *name){
    
    FILE *fpts, *fptt;
    char ch;

	fpts=fopen(name, "w");
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
	printf(" The file %s decrypted successfully..!!\n\n",name);
	fclose(fpts);
	fclose(fptt);
}
