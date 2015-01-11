//Supplement the missing functions in the implementation file:
#include <stdio.h>
#include <stdlib.h>
#include "List.h"

List * iniList()
{
    return(0);
}

int appendToList(List **head, int val)
{
    List *elem=calloc(sizeof(List),1);
    if (elem==0)
        return(0);
    elem->next=*head;
    elem->val=val;
    *head=elem;
    return (1);
}
int insertIntoList(List **head, int val, int where)
{
    if ( CountListElements(*head) < where )
        return 0;
    List *elem=calloc(sizeof(List),1),*left,*right; //left and right can be not alloced because they'll point to existing list chains
    if ( elem == 0 )
        return(0);
    elem->val = val;
    int i = 0;
    right = *head;

    if ( where == 0)
    {
        if (appendToList(head,val) == 0)
            return 0;
        return 1;
    }

    for (i; i < where; i++)
    {
        left = right;
        right = right->next;
    }

    left->next = elem;
    elem->next = right;
    return (1);
}

int deleteFromList(List **head, int where)
{
    List *temp,*prev;
    temp = *head;
    int cnt = 0;
    while (where!=cnt && temp->next!=0)
    {
        cnt++;
        prev = temp;
        temp = temp->next;
    }
    prev->next = temp->next;
    free(temp);
    return (1);
}

List * getElement(List *head, int pos)
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

int CountListElements(List *head)
{
    int cnt=0;
    while (head->next!=0)
    {
        cnt++;
        head=head->next;
    }
    return(cnt);
}

void printList(List * head, int elemPerLine)
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
    List *head, *p;
    head = iniList();
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
