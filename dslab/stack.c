#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
	struct node*top=NULL;
void push()
	{
		int  value;
		struct node*newNode=(struct node*)malloc(sizeof( struct node));
if (!newNode){
	printf("Stack Overflow!!\n");
	return;
}
else
{
	printf("Enter a Element to Push : ");
	scanf("%d",&value);
	if(top==NULL){
		newNode->data = value;
		newNode->next = NULL;
		top=newNode;
	}
	else{
		newNode->data = value;
		newNode->next = top;
		top =newNode;
		}
	printf("%d Pushed into the stack",value);
	}
	}
void pop ()
	{
  	struct node*temp =top;
	if (top== NULL){
		printf("Stack Underflow !!");
		return;
	}
	top = (top) -> next;
	printf("%d Popped from the stack\n",temp->data);
	free(temp);

}
void display()
	{
	struct node*temp= top;
	if(top == NULL){
	printf("Stack is empty\n");
	}
	else
	{
	printf("Stack elements : \n");
	while(temp!=NULL)
	{
	printf("%d -> ",temp->data);
	temp = temp->next; 
	}
    }
}
void search()
		{
	struct node*temp=top;
	int position= 1,found= 0,el;
		if (top == NULL){
		printf("stack is empty\n");
	}
		else
	{
	printf("Enter value to search");
	scanf("%d",&el);
		while(temp!=NULL){
	if (temp -> data ==el)
	{
	printf("%d found at position %d\n",el,position);
	found=1;
	break;
	}
	temp= temp -> next;
	position++;
	}
	if (found == 0)
	{
	printf("%d notfound in the stack\n",el);
	}
	}
	}
int main(){
	int choice,value;
	do{
		printf("\n Choose an operation : \n 1.Push\n 2.Pop \n 3.dispaly\n 4.search\n");
		scanf("%d",&choice);
	switch(choice)
	{
	case 1:
		push();
		break;
	case 2:
		pop();
		break;
	case 3: 
		display();
		break;
	case 4:
		search();
		break;
	default :
		printf("invalid choice");
	}
}
while(choice!=5);
return 0;
}
