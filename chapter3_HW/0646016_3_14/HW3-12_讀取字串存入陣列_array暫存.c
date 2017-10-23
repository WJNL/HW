/*Åª¨útxt¦r¦ê¡A¦s¤J°}¦C*/
#include <stdio.h>
#define maxSize 500

int main()
{
   FILE *filePtr;
   //int maxSize;
   //maxSize = (int*) malloc(sizeof(int));
   char temp[maxSize];
   int i=0;

   /* opening file for reading */
   filePtr = fopen("test.txt" , "r");
   if(filePtr == NULL) {
      perror("Error opening file");
      return(-1);
   }
   while((temp[i] = fgetc(filePtr))!=EOF ) {
      /* writing content to stdout */

      i++;
   }
   puts(temp);
   fclose(filePtr);

   return(0);
}
