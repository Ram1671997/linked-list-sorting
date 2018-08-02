/* this program will sort a linked list using selection sory */
#include <stdio.h>
#include <stdlib.h>
struct node
{
int val;
struct node *next;
};
void sorting(struct node ** root); //function prototype
// one argument call by reference using pointer to pointer
void printing(struct node * root);

int main()
{
  // here i implement my linked list
   struct node * element_1 = (struct node *)malloc(sizeof(struct node ));
   struct node * element_2 = (struct node *)malloc(sizeof(struct node ));
   struct node * element_3= (struct node *)malloc(sizeof(struct node ));
   struct node * root = element_1;
   element_1 -> val = 7;
   element_1 -> next = element_2;
   element_2 -> val = 11;
   element_2 -> next = element_3;
   element_3 -> val = 5;
   element_3 -> next = NULL;
   // here i test the function on the created linked list
   sorting(&root);
   printing(root);// passing the root

}
void sorting(struct node ** root)
{
    struct node * temp =*root;
    if(temp == NULL || temp ->next ==NULL)
        printf("list can not be sorted  ");// it is empty or  has one element
    else{
      while(temp != NULL){
        struct node * temp_iterator = temp-> next;
        struct node * temp_swapped = temp;
        while(temp_iterator != NULL)
        {
            if(temp_iterator ->val < temp_swapped ->val){
               temp_swapped =temp_iterator;
            }
            temp_iterator =temp_iterator->next;
        }
        int hold = temp -> val;
        temp -> val= temp_swapped -> val;
        temp_swapped -> val =hold;
        temp =temp->next;

      }
    }
}
void printing(struct node * root)
{
    struct node * temp =root;
    while(temp != NULL)
    {
        printf("%d\t",temp->val);
        temp =temp ->next;

    }
}
