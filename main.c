#include <stdio.h>
#include <stdlib.h>
#include"doublelinklist.h"
int main(int argc, const char* argv[])
{
    int i;
    double_list_t p = createEmptyDoubleLinkList();
    for (i = 0; i < 5; i++)
        insertIntoDoubleLinkList(p, i, i);
    showDoubleLinkList(p);//0 1 2 3 4
    deletePostDoubleLinkList(p, 2);
    showDoubleLinkList(p);//0 1 3 4
    deleteDataDoubleLinkList(p, 3);
    showDoubleLinkList(p);//0 1 4
    printf("%d\n", searchPostDoubleLinkList(p, 1));
    for (i = 0; i < p->len; i++)
        deletePostDoubleLinkList(p, i);
    free(p->head);
    p->head = NULL;
    free(p);
    p = NULL;
    return 0;
}
