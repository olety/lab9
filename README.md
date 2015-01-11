A list is a dynamic data structure that starts with a list head and consists of any number of
ments. The head points to the first element and each element point to its successor.

#The module has the following header file:
```c
#ifndef INTLIST_H
#define INTLIST_H
typedef struct IntList {
 int val;
 struct IntList * next;
} IntList;
IntList * iniList();
//creates a list head, exits on failure
int appendToList(IntList **head, int val);
//appends an element with the value val at the start of the list; returns 0 if it is not possible and
1 otherwise
int insertIntoList(IntList **head, int val, int where);
//inserts an element with the value val before the element on the position where; returns 0 if it
is not possible and 1 otherwise.
// The first element has the position of 0.
int deleteFromList(IntList **head, int where);
// deletes an element on the position where; returns 0 if it is not possible and 1 otherwise.
// The first element has the position of 0.
IntList * getElement(IntList *head, int pos);
// returns the pointer to an element on the position pos, returns 0 if such an element does ton
exist.
int CountListElements(IntList *head);
// counts the number of elements with the value equal to val
void printList(IntList * head, int elemPerLine);
// prints on standard output all list elements separated by a tabulation and semicolon ("\t"),
// each line should contain at most elemPerLine elements
void testList();
// testing the functions
#endif
```
#Supplement the missing functions in the implementation file:
```c
#include <stdio.h>
#include <stdlib.h>
#include "IntList.h"
IntList * iniList()
{
 return(0);
}
int appendToList(IntList **head, int val)
{
 IntList *elem=calloc(sizeof(IntList),1);
 if (elem==0)
 return(0);
 elem->next=*head;
 elem->val=val;
 *head=elem;
 return (1);
}
int insertIntoList(IntList **head, int val, int where)
{ 
 ???
}
int deleteFromList(IntList **head, int where)
{
 ???
}
IntList * getElement(IntList *head, int pos)
{
 int cp=-1;
 pos--;
 while (pos!=cp && head->next!=0)
 {
 cp++;
 head=head->next;
 }
 if (pos==cp)
 return(head);
 return(0);
}
int CountListElements(IntList *head)
{
 int cnt=0;
 while (head->next!=0)
 {
 cnt++;
 head=head->next;
 }
 return(cnt);
}
void printList(IntList * head, int elemPerLine)
{
 int cnt=0;
 while (head!=0)
 {
 cnt++;
 printf("%d%s", head->val, (cnt%elemPerLine==0)? "\n":";\t");
 head=head->next;
 }
 puts("\tend of data");
}
void testList()
{
 IntList *head, *p;
 head= iniList();
 printList(head,5);
 appendToList(&head, 5);
 printList(head,5);
 appendToList(&head, 4);
 printList(head,5);
 appendToList(&head, 7);
 printList(head,5);
 appendToList(&head, 17);
 printList(head,5);
 p=getElement(head,0);
 p=getElement(head,-1);
 p=getElement(head,2);
 p=getElement(head,10);
 deleteFromList(&head, 0);
 printList(head,5);
 deleteFromList(&head, 2);
 printList(head,5);
 deleteFromList(&head, 1);
 printList(head,5);
 deleteFromList(&head, 10);
 printList(head,5);
 p=getElement(head,0);
 printf("%d\n", p->val);
}
```
Assigment written by Andrej Sieminski
