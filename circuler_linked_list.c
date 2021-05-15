#include <stdio.h>
#include<stdlib.h>
struct node
{
 int data;
 int *next;
}*head=NULL;
void add_at_begin()
{
 int num1;
 struct node *temp,*temp1;
 temp=(struct node*)malloc(sizeof(struct node));
 printf("enter the data:");
 scanf("%d",&num1);
 temp->data=num1;
 if(head==NULL)
   {
     head=temp;
     temp->next=head;
   }
else
   {
     temp1 = head;
     while(temp1->next!= head)
        {
          temp1 = temp1->next;
        }
     temp->next = head;
     temp1 -> next = temp;
     head = temp;
   }
}
void display()
{
struct node *temp=head;
   if(head==NULL)
     {
        printf("given nodes are empty\n");
     }
   else
     {
        while(temp->next!=head)
          {
             printf("%d ",temp->data);
             temp=temp->next;
          }
     }

     printf("%d \n",temp->data);
}
void add_at_end()
{
int num1;
struct node *temp,*temp1;
temp1=(struct node*)malloc(sizeof(struct node));
printf("enter the data:");
scanf("%d",&num1);
temp1->data=num1;
    if(head==NULL)
      {
        head=temp1;
        temp1->next=head;
      }
    else
      {
        temp=head;
        while(temp->next!=head)
          {
             temp=temp->next;
          }
        temp->next=temp1;
        temp1->next=head;
      }
}
void delete_at_begin()
{
    struct node *temp;
    if(head==NULL)
    {
        printf("given node is empty\n");
    }
    else
    {
        temp=head;
        while(temp->next!=head)
        {
            temp=temp->next;
        }
        temp->next=head->next;
        head=NULL;
        free(head);
        head=temp->next;
    }
}
void delete_at_end()
{
    struct node *temp,*temp1;
    if(head==NULL)
    {
        printf("given node is empty\n");
    }
    else if(head->next!=head)
    {
        temp=head;
        while(temp->next!=head)
        {
            temp1=temp;
            temp=temp->next;
        }
        temp1->next=temp->next;
        free(temp);
    }
    else
    {
        head=NULL;
        free(head);
    }
}
void delete_at_any()
{
    struct node *temp,*temp1;
    int location,i=1,len;
    len=length();
    if(head==NULL)
    {
        printf("given list is empty\n");
    }
    else if(location<len)
    {
        printf("enter the location:");
        scanf("%d",&location);
        temp=head;
        while(i<location)
        {
            temp1=temp;
            temp=temp->next;
            i++;
        }
        temp1->next=temp->next;
        free(temp);
    }
    else
    {
        printf("given location is invalid\n");
    }
}
int length()
{
struct node *temp=head;
int count;
   if(head==NULL)
     {
        printf("given nodes are empty\n");
     }
   else
     {
        while(temp->next!=head)
          {
             temp=temp->next;
             count++;
          }
     }
     return count;
}
void main()
{
    int num1,num2;
    while(1)
    {
        printf("1:add_at_begin:\n2:add_at_end:\n3:display:\n4:delete_at_begin:\n5:delete_at_end:\n6:delete_at_any:\n7:length:\n");
        printf("enter the choice:");
        scanf("%d",&num1);
        switch(num1)
        {
            case 1:
                  add_at_begin();
                  break;
            case 2:
                  add_at_end();
                  break;
            case 3:
                  display();
                  break;
            case 4:
                  delete_at_begin();
                  break;
            case 5:
                  delete_at_end();
                  break;
            case 6:
                   delete_at_any();
                   break;
            case 7:
                    num2=length();
                    printf("\nlength is:%d:",num2);
                   break;
            default:
                   printf("entered choice is invalid please enter the valid choice");
    }
}
}
