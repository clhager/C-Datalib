#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include "../utils/utils.h"
#include "linkedlist.h"

/* Colors */
#define RED  "\x1B[31m"
#define GRN  "\x1B[32m"
#define RESET "\x1B[0m"

/* Allocates space and returns a pointer to a new linked list */
linkedlist_t* new_linkedlist() {
  
    linkedlist_t* new_list = (linkedlist_t*) malloc(sizeof(linkedlist_t));
    if (!new_list) {
        allocation_failed();
    }
    new_list->size = 0;
    new_list->list = NULL;
    return new_list;
    
}

/* Frees a linked list */
void LL_destroy(linkedlist_t* list) {
  
    LL_clear(list);
    free(list);
    
}

//

/* Append a new item to the end of the list. */
void LL_append(linkedlist_t* list, int item) {
  
    node_t* new_node = (node_t*) malloc(sizeof(node_t));
    if (!new_node) {
        allocation_failed();
    }
    new_node->item = item;
    new_node->next = NULL;
    
    if (list->list) {
        node_t* node = list->list;
        while (node->next) {
            node = node->next;
        }
        node->next = new_node;
    } else {
        list->list = new_node;
    }
    list->size++;
    
}

/* Clears all of the items in the list. */
void LL_clear(linkedlist_t* list) {
    
    node_t *prev, *curr;
    prev = curr = list->list;
    while (curr) {
        prev = curr;
        curr = curr->next;
        free(prev);
    }
    list->size = 0;
    list->list = NULL;
    
}

/* Return the amount of occurrences of an item in the list. */
int LL_count(linkedlist_t* list, int item) {
      
    node_t* node = list->list;
    int count = 0;
    while (node) {
        if (node->item == item) {
            count++;
        }
        node = node->next;
    }
    return count;
    
}

/* Return the first index at which the item is found. */
int LL_find(linkedlist_t* list, int item) {
    
    node_t* node = list->list;
    int count = 0;
    while (node) {
        if (node->item == item) {
            return count;
        }
        node = node->next;
        count++;
    }
    return -1;
    
}

/* Returns the item at the specified index */
int LL_get(linkedlist_t* list, int index) {
    
    if (index >= list->size) {
        printf(RED "Error: List length exceeded." RESET);
        exit(0);
    }
    node_t* node = list->list;
    while (index) {
        node = node->next;
        index--;
    }
    return node->item;
    
}

/* Replaces the item at the specified index in this list 
 * with the specified item. */
int LL_insert(linkedlist_t* list, int index, int item) {
  
    if (index >= list->size) {
        return -1;
    }
    
    node_t* node = list->list;
    while (index) {
        node = node->next;
        index--;
    }
    node_t* new_node = (node_t*) malloc(sizeof(node_t));
    if (!new_node) {
        allocation_failed();
    }
    new_node->item = item;
    new_node->next = node->next;
    node->next = new_node;
    return 0;
  
}

/* Pops the item at a specified index */
int LL_pop(linkedlist_t* list, int index) {
  
    if (index >= list->size) {
        printf(RED "Error: List length exceeded." RESET);
        exit(0);
    }
    node_t* node = list->list;
    node_t* pop;
    while (index > 1) {
        node = node->next;
        index--;
    }
    pop = node->next;
    node->next = pop->next;
    int ret = pop->item;
    free(pop);
    return ret;
    
}

/* Prints out the list. */
void LL_print(linkedlist_t* list) {
  
    if (!list->list) {
        printf("[ ]\n");
        return;
    }
  
    node_t* node = list->list;
    while (node->next) {
        printf("[ %d ]->", node->item);
        node = node->next;
    }
    printf("[ %d ]\n", node->item);
    
}

/* Puts the item at the index, overriding the previous item. */
int LL_put(linkedlist_t* list, int index, int item) {
  
    if (index >= list->size) {
        return -1;
    }
    node_t* node = list->list;
    while (index) {
        node = node->next;
        index--;
    }
    node->item = item;
    return 0;
    
}

/* Remove the node at the specified index. */
int LL_remove(linkedlist_t* list, int index);

/* Remove every instance of a specified item from the list. */
int LL_removeAll(linkedlist_t* list, int item);

/* Returns the number of items currently in the list. */
int LL_size(linkedlist_t* list);

//

void test_linkedlist() {
  
    printf(GRN "Testing...\n" RESET);
    clock_t start, end; 
    double cpu_time_used;
    bool test;
    start = clock();
    printf("Test new_linkedlist()...");
    linkedlist_t* list = new_linkedlist();
    if (!list || list->size != 0 || list->list != NULL) {
        printf(RED "failed.\n Fatal Error: Could not run the rest of the tests." RESET);
        exit(0);
    } else {
        printf(GRN "passed!\n" RESET);
    }
    printf("Test LL_append()...");
    test = true;
    for (int i = 0; i < 10; i++) {
        LL_append(list, i);
    }
    for (int i = 0; i < 10; i++) {
        test = test && LL_get(list, i) == i;
    }
    if (test && list->size == 10) {
        printf(GRN "passed!\n" RESET);
    } else {
        printf(RED "failed.\n" RESET);
    }
    printf("Test LL_get()...");
    if (test) {
        printf(GRN "passed!\n" RESET);
    } else {
        printf(RED "failed.\n" RESET);
    }
    printf("Test LL_put()...");
    test = true;
    LL_put(list, 1, 5);
    LL_put(list, 3, 9);
    test = test && LL_get(list, 1) == 5;
    test = test && LL_get(list, 3) == 9;
    if (test && list->size == 10) {
        printf(GRN "passed!\n" RESET);
    } else {
        printf(RED "failed.\n" RESET);
    }
    printf("Test LL_count()...");
    LL_put(list, 4, 2);
    LL_put(list, 5, 2);
    if (LL_count(list, 2) == 3) {
        printf(GRN "passed!\n" RESET);
    } else {
        printf(RED "failed.\n" RESET);
    }
    printf("Test LL_clear()...");
    LL_clear(list);
    LL_clear(list);
    LL_clear(list);
    if (!list || list->size != 0 || list->list != NULL) {
        printf(RED "failed.\n" RESET);
    } else {
        printf(GRN "passed!\n" RESET);
    }
    LL_destroy(list);
    
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf(YEL "Time for 10 appends: %f\n" RESET, cpu_time_used);
    printf(YEL "Time per append: %f\n" RESET, cpu_time_used / 10);
    
}

int main() {  
    test_linkedlist();

    return 0;
}
