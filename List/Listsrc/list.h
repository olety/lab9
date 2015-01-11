#ifndef LIST_H
#define LIST_H
typedef struct List
{
    int val;
    struct List * next;
} List;
List *iniList();
//creates a list head, exits on failure
int appendToList(List **head, int val);
//appends an element with the value val at the start of the list; returns 0 if it is not possible and
//1 otherwise
int insertIntoList(List **head, int val, int where);
//inserts an element with the value val before the element on the position where; returns 0 if it
//is not possible and 1 otherwise.
// The first element has the position of 0.
int deleteFromList(List **head, int where);
// deletes an element on the position where; returns 0 if it is not possible and 1 otherwise.
// The first element has the position of 0.
List * getElement(List *head, int pos);
// returns the pointer to an element on the position pos, returns 0 if such an element does ton
//exist.
int CountListElements(List *head);
// counts the number of elements
void printList(List * head, int elemPerLine);
// prints on standard output all list elements separated by a tabulation and semicolon ("\t"),
// each line should contain at most elemPerLine elements
void testList();
// testing the functions
#endif
