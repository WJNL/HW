/*�굲�@�~_HW3-12
  Function�G�}���ɮסA��Ū���r��s�J�}�C
  �m�W�G�i���p
*/

#include <stdio.h>
#include <stdlib.h>


int main()
{
    FILE *filePtr;
    char *fileWord;
    char word;

    fileWord = (char*) malloc(sizeof(char));

    filePtr = fopen("simple_Test.txt","r");

    while((fileWord=getc(filePtr)) != NULL){
        printf("%s", *fileWord);
    }


    return 0;
}
