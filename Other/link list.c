/*link list*/

//Header file for create node structure.
typedef struct node         //將struc node定義為一種新的形態
{
    void *dataPtr;          //宣告一會指向data的指標
    struct node *link;      //宣告一為struct node為型態的指標變數
}NODE;                      //將此型態命名為NODE


//Create Node
NODE *createNode(void *itemPtr)  //宣告一型態為NODE(struct node)的指標函式
{
    NODE *nodePtr;                             //宣告型態為NODE的指標變數
    nodePtr = (NODE*)malloc(sizeof(NODE));     //動態配置記憶體給nodePtr指標變數
    nodePtr->dataPtr = itemPtr;                //nodePtr會指向dataPtr，itemPtr給值到dataPtr
    nodePtr->link = NULL;                      //nodePtr指向link(link會指向空NULL)
    return nodePtr;
}
