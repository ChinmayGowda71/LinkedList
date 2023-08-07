#ifndef __LINKEDLIST_H
#define __LINKEDLIST_H


typedef struct cll_node_s {
    int is_head;
    int value;
    struct cll_node_s *prev;
    struct cll_node_s *next;
} cll_node;



cll_node *cll_head(cll_node *list);


cll_node *cll_tail(cll_node *list);


unsigned long cll_length(cll_node *list);


cll_node *cll_find(cll_node *list, int value);



cll_node *cll_remove(cll_node *list);


cll_node *cll_insert(int value, cll_node *list, int before);

void cll_show(cll_node *list);


#endif /* ifdef __LINKEDLIST_H */
