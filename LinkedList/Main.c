#include <stdio.h>
#include <stdlib.h>

struct LinkListNode{
    int val;
    struct LinkListNode *next; 
};

struct LinkList{
    size_t length;
    struct LinkListNode *head; 
};

struct LinkListNode* create_Linked_list_node(int v, struct LinkListNode *n){
    struct LinkListNode* ret_item = malloc(sizeof(struct LinkListNode));
    ret_item->val = v;
    ret_item->next = n;
    return ret_item;
}

struct LinkList* create_Link_List(int v){
    struct LinkListNode *head = create_Linked_list_node(v, NULL);
    struct LinkList *ret_item = malloc(sizeof(struct LinkList));

    ret_item->length = 1;
    ret_item->head = head;

    return ret_item;
}

void insert_into_link_list(struct LinkList *list, int v){
    struct LinkListNode *cur = list->head;

    if(cur == NULL){
        list->head = create_Linked_list_node(v, NULL);
    }

    while(cur != NULL){
        if(cur->next == NULL){
            break;
        }

        cur = cur->next;
    }

    cur->next = create_Linked_list_node(v, NULL);
}

int main() {
    struct LinkList *list = create_Link_List(5);
    insert_into_link_list(list, 8);

    
    printf("element number one: %d\n", list->head->val);
    printf("element number two: %d\n", list->head->next->val);


    return 0;
}