/*資結作業_HW3-12
  姓名：張完如
  學號：0646016
*/

/*題目：
  Write a program to implement Algorithm 3-9, "Parse Parentheses," matching braces
  rather than parentheses. In your implementation, push the line number into the
  stack rather than the opening brace. When an error occurs, print the line number
  for the unmatched opening brace or through itself (there should be no errors) and
  then test it with the following small program.

  //使用Algorithm 3-9
*/

/*Algorithm(3-9) parseParens
  //this algorithm reads a source program and parses it to make sure all opening-
  closing parse{theses are paired.確認讀取的程式內，所有的括號都是配對對稱的

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
  }  line 2 closing brace is not paired          //第2行關閉大括號"}"未配對
  No braces.                                     //沒有大括號
      {opening brace is paired on same line}     //開啟大括號"{"配對在同一行"}"
  No braces.                                     //沒有大括號
      {opening brace paired later                //開啟大括號"{"配對
      No braces.                                 //沒有大括號
      } Closing brace paired two lines up.       //關閉括號"}"配對到前兩行
  {{{ Line 9. Three braces--only two paired.     //第9行三個大括號"{{{" - 只有兩個配對
    } First closing brace                        //第一個關閉大括號"}"
   } Second closing brace.                       //第二個關閉大括號"}"
  End of program. One opening brace left.        //Program結束 留下一個開口大括號(第9行的未被配對的"{")
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    //read file
    FILE *filePtr;
    filePtr = fopen("Test_brace_errors.txt","r")

    //進行parenthesis(括號)判斷
    if (opening parethensis){
        pushStack(stack, character);
    }
    else{
        if (closing parenthesis){
            if (emptyStack(stack)){
                printf("Error：Closing parenthesis not matched");
            }
            else{
                popStack(stack);
            }
        }
    }

    if (not emptyStack(stack))
        printf("Error：Opening parenthesis not matched")

}
