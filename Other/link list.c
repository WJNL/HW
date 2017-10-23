/*link list*/

//Header file for create node structure.
typedef struct node         //�Nstruc node�w�q���@�طs���κA
{
    void *dataPtr;          //�ŧi�@�|���Vdata������
    struct node *link;      //�ŧi�@��struct node�����A�������ܼ�
}NODE;                      //�N�����A�R�W��NODE


//Create Node
NODE *createNode(void *itemPtr)  //�ŧi�@���A��NODE(struct node)�����Ш禡
{
    NODE *nodePtr;                             //�ŧi���A��NODE�������ܼ�
    nodePtr = (NODE*)malloc(sizeof(NODE));     //�ʺA�t�m�O���鵹nodePtr�����ܼ�
    nodePtr->dataPtr = itemPtr;                //nodePtr�|���VdataPtr�AitemPtr���Ȩ�dataPtr
    nodePtr->link = NULL;                      //nodePtr���Vlink(link�|���V��NULL)
    return nodePtr;
}
