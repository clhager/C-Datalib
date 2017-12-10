# Linked List

&nbsp;

Versatile data structure for a list of items. Note: out of range indexing will throw an error.

&nbsp;

## Constructor / Destructor

&nbsp;

#### `new_LinkedList()`

Creates a new empty Linked List object.

Parameter |  Type  | Description
--------- | ---- | -----------
*None*    | *None* | *None*

**Returns:** `linkedlist_t*` pointer to a new Linked List of size 0

&nbsp;

#### `destroy_LinkedList(linkedlist_t* list)`

Frees the memory associated to a Linked List object.

Parameter |  Type  | Description
--------- | ---- | -----------
list    | `linkedlist_t` | Linked List to be freed

**Returns:** *None*

&nbsp;

## Functions

&nbsp;

#### `LL_append(linkedlist_t* list, int item)`

Appends the specified item to the end of the Linked List

Parameter |  Type  | Description
--------- | ---- | -----------
list    | `linkedlist_t` | Linked List to append to
item    | `int` | Item to append

**Returns:** *None*

&nbsp;

#### `LL_clear(linkedlist_t* list)`

Clears the list of all its items and frees the associated memory

Parameter |  Type  | Description
--------- | ---- | -----------
list    | `linkedlist_t` | Linked List to clear

**Returns:** *None*

&nbsp;

#### `LL_count(linkedlist_t* list, int item)`

Counts the number of appearances of a specified item in the list

Parameter |  Type  | Description
--------- | ---- | -----------
list    | `linkedlist_t` | Linked List to inspect
item | `int` | Item to count

**Returns:** `int` number of appearances of the item in the list

&nbsp;

#### `LL_find(linkedlist_t* list, int item)`

Finds the index of the first occurence of a specified item in the list

Parameter |  Type  | Description
--------- | ---- | -----------
list    | `linkedlist_t` | Linked List to inspect
item | `int` | Item to find

**Returns:** `int` index of the first occurence of the item in the list, -1 if it does not appear in the list

&nbsp;

#### `LL_get(linkedlist_t* list, int index)`

Gets the item at the specified index in the list

Parameter |  Type  | Description
--------- | ---- | -----------
list    | `linkedlist_t` | Linked List to get from
index | `int` | Index of the item to return

**Returns:** `int` item at the specified index

&nbsp;

#### `LL_insert(linkedlist_t* list, int index, int item)`

Inserts an item at the specified index, displacing the items after the specified index (non-destructive)

Parameter |  Type  | Description
--------- | ---- | -----------
list    | `linkedlist_t` | Linked List to insert to
index | `int` | Index to place item
item | `int` | Item to insert

**Returns:** *None*

&nbsp;

#### `LL_pop(linkedlist_t* list, int index)`

Returns the item at the specified index and removed it from the list

Parameter |  Type  | Description
--------- | ---- | -----------
list    | `linkedlist_t` | Linked List to pop from
index | `int` | Index to pop item from

**Returns:** `int` item from the specified index

&nbsp;

#### `LL_print(linkedlist_t* list)`

Prints out the list to the command line

Parameter |  Type  | Description
--------- | ---- | -----------
list    | `linkedlist_t` | Linked List to print

**Returns:** *None*

&nbsp;

#### `LL_printrange(linkedlist_t* list, int start, int end)`

Prints out the list from index start to index end

Parameter |  Type  | Description
--------- | ---- | -----------
list    | `linkedlist_t` | Linked List to print
start | `int` | index to start printing from
end | `int` | index to end printing at (exclusive)

**Returns:** *None*

&nbsp;

#### `LL_put(linkedlist_t* list, int index, int item)`

Puts the specified item into the list at the specified index

Parameter |  Type  | Description
--------- | ---- | -----------
list    | `linkedlist_t` | Linked List to put into
index | `int` | Index to replace item
item | `int` | Item to place into list

**Returns:** *None*

&nbsp;

#### `LL_remove(linkedlist_t* list, int index)`

Removes the node at the specified index and frees associated memory

Parameter |  Type  | Description
--------- | ---- | -----------
list    | `linkedlist_t` | Linked List to modify
index | `int` | Index of node to remove

**Returns:** *None*

&nbsp;

#### `LL_removeAll(linkedlist_t* list, int item)`

Removes all instances of a particular item from the list

Parameter |  Type  | Description
--------- | ---- | -----------
list    | `linkedlist_t` | Linked List to modify
item | `int` | Item to remove from the list

**Returns:** `int` number of removals done

&nbsp;

#### `LL_size(linkedlist_t* list)`

Returns the number of items currently in the list

Parameter |  Type  | Description
--------- | ---- | -----------
list    | `linkedlist_t` | Linked List to inspect

**Returns:** `int` size of list

&nbsp;

## Test Suite

#### `test_linkedlist()`

Runs the tests for the Linked List data structure.
