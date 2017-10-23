/*資結作業_HW3-12
  Function：開啟檔案，並讀取字串存入陣列
  姓名：張完如
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
