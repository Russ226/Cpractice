#ifndef BASICLINKLIST_H
#define BASICLINKLIST_H

struct LinkListNode;
struct LinkList;

struct LinkListNode* create_Linked_list_node(int v, struct LinkListNode *n);
struct LinkList* create_Link_List(int v);
void insert_into_link_list(struct LinkList *list, int v);
void delete_node_by_val(struct LinkList **list, int v);
void delete_link_list(struct LinkList **list);
void print_link_list(struct LinkList *list);

#endif
