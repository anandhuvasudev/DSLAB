#include<stdio.h>
#include<stdlib.h>
struct node{
	struct node *right;
	struct node *left;
	int data;
};
struct node* tree=NULL;
void const(int data){
	struct node *node,*parent;
	struct node*node*ptr=(struct node)malloc(size of (struct node));
	ptr->data=data;
	ptr->left=NULL;
	ptr->right=NULL;

	if(tree==NULL){
	tree=ptr;
	ptr->left=NULL;
	ptr->right=NULL;
	}
	else{
	parent=NULL;
	node=tree;
	while(node!=NULL){
	}
	}
}
void main(){
	int value,ch;
	do{
	printf("\n 1.Insert\n 2.Deletion\n 3.search\n 4.traversal \n.5 Exit");
	printf("Enter your choice");
	scanf("%d",&ch);
	switch(ch){
	case 1:
	printf("Enter a value");
	scanf("%d",&value);
	insertion();
	break;
	case 2:
	del();

	}
	}

	}
