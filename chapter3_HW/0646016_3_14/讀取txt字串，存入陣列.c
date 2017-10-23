/*Åª¨útxt¦r¦ê¡A¦s¤J°}¦C*/
#include <stdio.h>
#define maxSize 500

int main()
{
   FILE *fp;
   //int maxSize;

   //maxSize = (int*) malloc(sizeof(int));
   int i=0;
   char temp[maxSize];
   char *dataPtr;
   dataPtr = (char*) malloc(sizeof(char)*maxSize);

   /* opening file for reading */
   fp = fopen("test.txt" , "r");
   if( fgets (temp, maxSize, fp)!=NULL ) {
      /* writing content to stdout */
      puts(temp);
   }
   for(i=0;i<maxSize;i++){
        dataPtr = &temp[i];
        printf("%s\n",dataPtr);
   }

   fclose(fp);

   return(0);
}
