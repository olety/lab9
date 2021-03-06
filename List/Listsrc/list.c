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
    fprintf(stdout,"appending %d\n",val);
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
    fprintf(stdout,"inserting %d in %dth place\n",val,where);
    if ( where < 0 )
        return 0;

    List *elem=calloc(sizeof(List),1);
    if ( elem == 0 )
        return(0);

    elem->val = val;

    if ( where == 0 )
    {
      /*  if (appendToList(head,val) == 0)
            return 0;
        return 1;*/
        elem->next = *head;
        *head = elem;
        return (1);
    }
    else
    {
        List *temp; //left and right may be not allocated because they'll point to existing list chains
        int i = 0;
        temp = *head;

        while(i!= where-1)
        {
            i++;
            temp = temp->next;
        }
        if ( temp == 0 )
            return 0;
        elem->next = temp->next;
        temp->next = elem;
    }
    return (1);
}

int deleteFromList(List **head, int where)
{
    fprintf(stdout,"deleting from %dth place\n",where);
    if ( where < 0)
        return 0;
    List *temp;
    temp = *head;

    if( where == 0)
    {
        *head = (*(head))->next;
        free(temp);
        return (1);
    }
    else
    {
    List *prev;
    int i = 0;
    while ( i!= where && temp )
    {
        i++;
        prev = temp;
        temp = temp->next;
    }
    if (temp == 0)
        return (0);

    prev->next = temp->next;
    free(temp);
    return (1);
    }
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
    printList(head,15);
    //appending
    appendToList(&head, 5);
    printList(head,15);
    appendToList(&head, 4);
    printList(head,15);
    appendToList(&head, 7);
    printList(head,15);
    appendToList(&head, 17);
    printList(head,15);
    //get elems
    p=getElement(head,0);
    p=getElement(head,-1);
    p=getElement(head,2);
    p=getElement(head,10);
    //inserting
    insertIntoList(&head, 1, 1);
    printList(head,15);
    insertIntoList(&head, 2, 2);
    printList(head,15);
    insertIntoList(&head, 0, 0);
    printList(head,15);
    //deleting
    deleteFromList(&head, 0);
    printList(head,15);
    deleteFromList(&head, 2);
    printList(head,15);
    deleteFromList(&head, 1);
    printList(head,15);
    deleteFromList(&head, 115);
    printList(head,15);
    p=getElement(head,0);
    printf("%d\n", p->val);
}
