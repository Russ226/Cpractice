#include <stdio.h>
#include <stdlib.h>
#include "basicLinkList.h"

struct LinkListNode{
    int val;
    struct LinkListNode *next; 
};
//can store dupilicate int vals
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
    list->length++;
}
//deletes all occurance of v
void delete_node_by_val(struct LinkList **list, int v){
    if((*list)->head->val == v){
        struct LinkListNode *new_head = (*list)->head->next;
        free((*list)->head); 
        (*list)->head= new_head;  
    }else{
        struct LinkListNode *cur = (*list)->head->next;
        struct LinkListNode *prev = (*list)->head;

        while(cur != NULL){
            if(cur->val == v){
                struct LinkListNode *new_next = cur->next;
                free(cur);
                cur = NULL; 
                prev->next = new_next;
            }

            if(cur == NULL){
                cur = prev->next;
            }else{
                prev = cur;
                cur = cur->next;
            }
        }
    }
}

void delete_link_list(struct LinkList **list){
    struct LinkListNode *cur = (*list)->head;

    while(cur->next != NULL){
        struct LinkListNode *prev = cur;
        cur = prev->next;
        free(prev);
    }

    free(*list);
    *list = NULL;
}

void print_link_list(struct LinkList *list){
    struct LinkListNode *cur = list->head;

    while(cur != NULL){
        printf("Print cur elements of link list : %d\n", cur->val);
        cur = cur->next;
    }

    printf("Finished printing all elements of link list\n\n");
}