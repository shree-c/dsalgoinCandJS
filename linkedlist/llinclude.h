typedef struct llnode {
    int data;
    struct llnode *next;
} llnode;

llnode *newNode(int data, llnode *next);
void printLlist(llnode *start);