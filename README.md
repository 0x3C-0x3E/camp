# CAMP - Clean Array (i)MPlementation

> [!WARNING]
> Work in progress!

# Usage

## CampArray

To use the CampArray first initialize it with
```c
    CampArray* my_arr = camp_array_new(sizeof(YOURTYPE));
```

> CampArrays can work with any data type as long as it can be measured by the sizeof() function

> [!CAUTION]
> At the end of your program/scope in which this array should live call `camp_array_destroy(my_arr)` because it is heap allocated
