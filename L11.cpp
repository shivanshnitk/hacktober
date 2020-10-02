#include<stdio.h>
#include<stdlib.h>

struct node
{
             int coeff;
             int expon;
             struct node *link;
};
typedef struct node *NODE;

NODE getnode()
{
            NODE x;
            x =(NODE) malloc(sizeof(struct node));
            return x;
}
void display(NODE head);

NODE attach(int coeff, int expon, NODE head)
{
            NODE temp, cur;
            temp = getnode();
            temp->coeff = coeff;
            temp->expon = expon;
            cur = head->link;
            while(cur->link != head)
            {
                        cur = cur->link;
            }
            cur->link = temp;
            temp->link = head;
            return head;
}

NODE read_poly(NODE head)
{
            int i = 1, coeff, expon;
            printf("\nEnter the coefficient as -999 to end the polynomial ");
            while(1)
            {
                        printf("\nEnter the %d term:\n",i++);
                        printf("\n\tCoeff = ");
                        scanf("%d", &coeff);
                        if(coeff == -999)
                                    break;
                        printf("\tPow x = ");
                        scanf("%d", &expon);
                        head = attach(coeff, expon, head);
            }
              return head;
}
void removeDuplicates(NODE head) 
{ 
    NODE ptr1, ptr2, dup; 
    ptr1 = head; 
  
    do { 
        	ptr2 = ptr1; 
  			while (ptr2->link != head) { 
            if (ptr1->expon == ptr2->link->expon) {
                ptr1->coeff = ptr1->coeff + ptr2->link->coeff; 
                dup = ptr2->link; 
                ptr2->link = ptr2->link->link; 
                delete (dup); 
            } 
            else
                ptr2 = ptr2->link; 
        } 
        ptr1 = ptr1->link; 
    }while (ptr1->link !=head);
}

NODE poly_mult(NODE head1, NODE head2, NODE head3)
{
            NODE cur1, cur2;
            if(head1->link == head1 || head2->link == head2)
            {
                        printf("\nMultiplied polynomial is zero polynomial");
                        return NULL;
            }
            cur1 = head1->link;
            while(cur1 != head1)
            {
                        cur2 = head2->link;
                        while(cur2!=head2)
                        {
                                    head3 =attach(cur1->coeff*cur2->coeff, cur1->expon+cur2->expon, head3);
                                   cur2=cur2->link;
                        }
                        cur1=cur1->link;
            }
            removeDuplicates(head3);
            return head3;
} 

void display(NODE head)
{
            NODE temp;
            if(head->link == head)
            {
                         printf("\nPolynomial does not exist");
                         return;
            }
            temp = head->link;
            while(temp != head)
            {
                         printf("%dx^%d", temp->coeff, temp->expon);
                         temp = temp->link;
                         if(temp != head)
                                    printf(" + ");
            }
}

int main()
{
             NODE head1, head2, head3;
            head1 = getnode();
            head2 = getnode();
            head3 = getnode();

            head1->link=head1;
            head2->link=head2;
            head3->link=head3;

              printf("\nEnter the first polynomial \n");
              head1=read_poly(head1);
              printf("\nEnter the second polynomial \n");
              head2=read_poly(head2);
            head3=poly_mult(head1, head2, head3);
                       
              printf("\nPolynomial 1:\t");
              display(head1);
              printf("\nPolynomial 2:\t");
              display(head2);
              printf("\nPolynomial Result:\t");
              display(head3);
              
              return 0;
}
