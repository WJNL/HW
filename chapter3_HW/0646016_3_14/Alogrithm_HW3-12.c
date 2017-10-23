/*�굲�@�~_HW3-12
  �m�W�G�i���p
  �Ǹ��G0646016
*/

/*�D�ءG
  Write a program to implement Algorithm 3-9, "Parse Parentheses," matching braces
  rather than parentheses. In your implementation, push the line number into the
  stack rather than the opening brace. When an error occurs, print the line number
  for the unmatched opening brace or through itself (there should be no errors) and
  then test it with the following small program.

  //�ϥ�Algorithm 3-9
*/

/*Algorithm(3-9) parseParens
  //this algorithm reads a source program and parses it to make sure all opening-
  closing parse{theses are paired.�T�{Ū�����{�����A�Ҧ����A�����O�t���٪�

  loop (more data)
  1   read (character)
  2   if (opening parenthesis)
          pushStack (stack, character)
  3   else
          if (closing parenthesis){
             if (emptyStack (stack))
                  print (Error: Closing parenthesis not matched)
             else
                  popStack(stack)
             //end if
          //end if
  4   end if
  //end loop

  if (not emptyStack (stack))
      print (Error: Opening parenthesis not matched)
end parseParens
*/
/*Test_brace_errors
  }  line 2 closing brace is not paired          //��2�������j�A��"}"���t��
  No braces.                                     //�S���j�A��
      {opening brace is paired on same line}     //�}�Ҥj�A��"{"�t��b�P�@��"}"
  No braces.                                     //�S���j�A��
      {opening brace paired later                //�}�Ҥj�A��"{"�t��
      No braces.                                 //�S���j�A��
      } Closing brace paired two lines up.       //�����A��"}"�t���e���
  {{{ Line 9. Three braces--only two paired.     //��9��T�Ӥj�A��"{{{" - �u����Ӱt��
    } First closing brace                        //�Ĥ@�������j�A��"}"
   } Second closing brace.                       //�ĤG�������j�A��"}"
  End of program. One opening brace left.        //Program���� �d�U�@�Ӷ}�f�j�A��(��9�檺���Q�t�諸"{")
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    //read file
    FILE *filePtr;
    filePtr = fopen("Test_brace_errors.txt","r")

    //�i��parenthesis(�A��)�P�_
    if (opening parethensis){
        pushStack(stack, character);
    }
    else{
        if (closing parenthesis){
            if (emptyStack(stack)){
                printf("Error�GClosing parenthesis not matched");
            }
            else{
                popStack(stack);
            }
        }
    }

    if (not emptyStack(stack))
        printf("Error�GOpening parenthesis not matched")

}
