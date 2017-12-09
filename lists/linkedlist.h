#ifndef LINKEDLIST
#define LINKEDLIST

/*--- Structs ---*/

/* One node from a Linked List */
typedef struct _node{
  int item;
  struct _node* next;
} node_t;

/* Linked List with size and a pointer to the first node */
typedef struct {
  int size;
  node_t* list;
} linkedlist_t;

/*--- Constructors ---*/

/* Allocates space and returns a pointer to a new linked list */
linkedlist_t* new_linkedlist();

/* Frees a linked list */
void LL_destroy(linkedlist_t* list);

/*--- Functions ---*/

/* Append a new item to the end of the list. */
void LL_append(linkedlist_t* list, int item);

/* Clears all of the items in the list. */
void LL_clear(linkedlist_t* list);

/* Return the amount of occurrences of an item in the list. */
int LL_count(linkedlist_t* list, int item);

/* Return the first index at which the item is found. */
int LL_find(linkedlist_t* list, int item);

/* Returns a pointer to the item at the specified index */
int LL_get(linkedlist_t* list, int index);

/* Replaces the item at the specified index in this list 
 * with the specified item. */
int LL_insert(linkedlist_t* list, int index, int item);

/* Pops the item at a specified index */
int LL_pop(linkedlist_t* list, int index);

/* Prints out the list. */
void LL_print(linkedlist_t* list);

/* Puts the item at the index, overriding the previous item. */
int LL_put(linkedlist_t* list, int index, int item);

/* Remove the node at the specified index. */
int LL_remove(linkedlist_t* list, int index);

/* Remove every instance of a specified item from the list. */
int LL_removeAll(linkedlist_t* list, int item);

/* Returns the number of items currently in the list. */
int LL_size(linkedlist_t* list);

/*--- Tests ---*/

/* Runs tests */
void test_linkedlist();

#endif
