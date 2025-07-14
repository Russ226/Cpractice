#include <stdio.h>
#include <stdlib.h>
#include "basicLinkList/basicLinkList.h"

int main() {
    struct LinkList *list = create_Link_List(5);
    insert_into_link_list(list, 8);
    insert_into_link_list(list, 12);
    insert_into_link_list(list, 575);

    
    print_link_list(list);

    delete_link_list(&list);

    printf("testing assert arr == null: %d\n\n",  list == NULL);

    struct LinkList *delete_list_ex = create_Link_List(7);
    insert_into_link_list(delete_list_ex, 8);
    insert_into_link_list(delete_list_ex, 33);
    insert_into_link_list(delete_list_ex, 22);

    delete_node_by_val(&delete_list_ex, 33);

    print_link_list(delete_list_ex);

    return 0;
}