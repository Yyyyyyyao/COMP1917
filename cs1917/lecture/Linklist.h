typedef struct _node * Node;
typedef struct _list * List;

Node createnode(int item);
List creatlist();
void Appendlist(List list, Node node);
void Printlist(List list);
void freenode(Node node);
void freelist(List list);
void Deletenode(List list, int item);
void printsize(List list);
List reverselist(List list);
