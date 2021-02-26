#include "lab05.h"


void prepare(OneWayList *arg)
{
  if(arg == 0) return;

  arg -> head = (struct node *) malloc(sizeof (struct node));
  if(arg -> head == 0)
  {
    std::cout << "blad alokacji pamieci" << std::endl;
    return;
  }
}


void add(OneWayList *arg, std::string text)
{
  if(arg == 0) return;

  struct node *temp = arg -> head;

  //przewin na ostatni element
  while(temp -> next != 0)
  {
    temp = temp -> next;
  }

  temp -> next = (struct node *) malloc (sizeof (struct node));
  temp -> data = text;
}

void dump(const OneWayList *arg)
{
  if(arg == 0 || arg -> head == 0) return;
  struct node *temp = arg -> head;

  std::cout << temp -> data << " ";
  while(temp -> next != 0)
  {
    temp = temp -> next;
    std::cout << temp -> data << " ";
  }
}

int empty(const OneWayList *arg){
  return 0;
}

void clear(OneWayList *arg)
{
  struct node *temp = arg -> head;
  struct node *temp2;// = temp;
  while (temp -> next !=0)
  {
    temp2 = temp;
    temp = temp -> next;
    free((void *)temp2);
    temp2 = 0;
  }
  free((void *)temp );
  temp  = 0;

  free((void *)arg);
  arg = 0;
}