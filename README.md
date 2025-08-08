# CAMP - Clean Array (i)MPlementation

> [!WARNING]
> Work in progress!

# Info
This is a small library for handleing common data structures in C.
These currently include:
 - CampArray - dynamic array that supports any type of data
 - CampLL - linked list

# Usage

## CampArray

To use the CampArray first initialize it with
```c
    CampArray* my_arr = camp_array_new(sizeof(YOURTYPE));
```

> CampArrays can work with any data type as long as it can be measured by the sizeof() function

> [!CAUTION]
> At the end of your program/scope in which this array should live call `camp_array_destroy(my_arr)` because it is heap allocated

### Possible functions
These are mostly self explanatory:

```c
// dump the array with possible print options defined in config.h
void camp_array_dump(CampArray* array);

// append something
void camp_array_append(CampArray* array, void* item);

// insert something
void camp_array_insert(CampArray* array, size_t index, void* item);

// get something
void* camp_array_get(CampArray* array, size_t index);

// set something (you get the idea)
void camp_array_set(CampArray* array, size_t index, void* item);

// remove an element and push every element past that "one space left"
void camp_array_remove(CampArray* array, size_t index);

// returns the size
size_t camp_array_get_size(CampArray* array);

// true if size == 0
bool camp_array_is_empty(CampArray* array);

// memsets every element to 0
void camp_array_clear(CampArray* array);

// equivalent of calling camp_array_new but only malloc'ing the data not the whole struct
void camp_array_reset(CampArray* array);
```

## CampLL
> Quick side note:
>   LL stands for Linked-List because i am too lazy to type that all out

just like camp_array you init it with:
```c
    CampLL* list = camp_ll_new(sizeof(YOURTYPE));
```

> It also supports any type you trow at it

### Possible Functions
> [!WARNING]
> still incomplete

``` c
// returns a ptr to the new linked list
CampLL* camp_ll_new(size_t data_size);

// inserts as the first element, O(1)
void camp_ll_insert_at_head(CampLL* list, void* data);

// inserts as the last element, O(1)
void camp_ll_insert_at_tail(CampLL* list, void* data);

// removes at a specific index O(N)
void camp_ll_remove_at_index(CampLL* list, size_t index);

// removes the head O(1)
void camp_ll_remove_head(CampLL* list);

// removes the tail O(n) because there is no prev ptr ):
void camp_ll_remove_tail(CampLL* list);

// dumps the linked list
void camp_ll_dump(CampLL* list);

// returns the data from the node at the given index, O(n)
void* camp_ll_get_at_index(CampLL* list, size_t index);

// returns the ptr to the entire node
CampLLNode* camp_ll_get_node_at_index(CampLL* list, size_t index);

// returns the list size
size_t camp_ll_get_list_size(CampLL* list);

// free the list and all the nodes
void camp_ll_destroy(CampLL* list);
```

# Inspriation
needed a dynamic array

idk why i did a linked list tbh


