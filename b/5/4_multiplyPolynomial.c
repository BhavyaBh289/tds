 
#include <stdio.h>
#include <malloc.h>
 struct node
{
    int coeff;
    int power;
    struct node * next;

};
struct sll{
    struct node * head;
    struct node * last;
};
struct sll create(struct sll a, int n,int m){
    a.head = (struct node *) malloc(sizeof(struct node));
    a.head->coeff = n;
    a.head->power = m;
    a.head->next = NULL;
    a.last = a.head;
    return a;
}
struct sll insert_last(struct sll a,int n,int m){
    struct node * next = (struct node *) malloc(sizeof(struct node));
    next->coeff = n;
    next->power = m;
    a.last->next = next;
    a.last = next;
    return a;
}
void display(struct sll a){
    struct node *temp;
    temp = a.head;
    if (temp != NULL){
        printf("%d*x^%d ",temp->coeff,temp->power);
        temp = temp->next;
        while(temp->next != NULL){
            printf("+ %d*x^%d ",temp->coeff,temp->power);
            temp = temp->next;
        }
        printf("+ %d \n",temp->coeff,temp->power);
    }
}
struct sll addd(struct sll a,struct sll b){
    struct node *temp,*temp1;
    struct sll c;
    char s;
    temp = a.head;
    temp1 = b.head;
    if (temp != NULL){
        c = create(c,temp->coeff+temp1->coeff,temp->power);
        temp = temp->next;
        temp1 = temp1->next;
        while(temp != NULL){
            c = insert_last(c,temp->coeff+temp1->coeff,temp->power);
            temp = temp->next;
            temp1 = temp1->next;
        }
    }
    return c;
}
Node* multiply(Node* poly1, Node* poly2,Node* poly3){

    // Create two pointer and store the
    // address of 1st and 2nd polynomials
    Node *ptr1, *ptr2;
    ptr1 = poly1;
    ptr2 = poly2;
    while (ptr1 != NULL) {
        while (ptr2 != NULL) {
            int coeff, power;

            // Multiply the coefficient of both
            // polynomials and store it in coeff
            coeff = ptr1->coeff * ptr2->coeff;

            // Add the powerer of both polynomials
            // and store it in power
            power = ptr1->power + ptr2->power;

            // Invoke addnode function to create
            // a newnode by passing three parameters
            poly3 = addnode(poly3, coeff, power);

            // move the pointer of 2nd polynomial
            // two get its next term
            ptr2 = ptr2->next;
        }

        // Move the 2nd pointer to the
        // starting point of 2nd polynomial
        ptr2 = poly2;

        // move the pointer of 1st polynomial
        ptr1 = ptr1->next;
    }

    // this function will be invoke to add
    // the coefficient of the elements
    // having same powerer from the resultant linked list
    removeDuplicates(poly3);
    return poly3;
}
int main() {
    struct sll a,b,c;
    int x,y,i;
    printf("enter the highest power of x ");
    scanf("%d",&y);
    printf("enter polynomial a\n");
    i = y;
    printf("enter coeffecient of x ^ %d ",i);
    scanf("%d",&x);
    a=create(a,x,i);
    i--;
    while (i >= 0){
        printf("x ^ %d ",i);
        scanf("%d",&x);
        a = insert_last(a,x,i);
        i--;
    }
    display(a);
    printf("enter polynomial b\n");
    i = y;
    printf("enter coeffecient of x ^ %d ",i);
    scanf("%d",&x);
    b = create(b,x,i);
    i--;
    while (i >= 0){
        printf("x ^ %d ",i);
        scanf("%d",&x);
        b = insert_last(b,x,i);
        i--;
    }

    c = addd(a,b);
    printf("sum of \n");
    display(a);
    printf("and ");
    display(b);
    printf("is\n");

    display(c);
    return 0 ;
}
