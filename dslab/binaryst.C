#include <stdio.h>
#include <stdlib.h>

struct node
{
	struct node *left;
	struct node *right;
	int data;
};


struct node *root;


struct node *newnode(int value)
{
	struct node *newnode = (struct node*)malloc(sizeof(struct node));
	newnode->data = value;
	newnode->left = NULL;
	newnode->right = NULL;
	return newnode;
}


struct node *insert(struct node *root, int value)
{
	if (root == NULL)
	{
		return newnode(value);
    	}
	else if (value == root->data)
	{
        	printf("Same data can't be stored!\n");
        	return root;
	}
	else if (value > root->data)
	{
        	root->right = insert(root->right, value);
    	}
	else
	{
        	root->left = insert(root->left, value);
    	}
    	return root;
}


void inorderTraversal(struct node *root)
{
	if (root == NULL)
	{
		return;
    	}
    	inorderTraversal(root->left);
    	printf("%d ", root->data);
    	inorderTraversal(root->right);
}


void preorderTraversal(struct node *root)
{
	if (root == NULL)
	{
        	return;
    	}
    	printf("%d ", root->data);
    	preorderTraversal(root->left);
    	preorderTraversal(root->right);
}


void postorderTraversal(struct node *root)
{
	if (root == NULL)
	{
        	return;
	}
    	postorderTraversal(root->left);
    	postorderTraversal(root->right);
    	printf("%d ", root->data);
}


struct node *searchNode(struct node *root, int key)
{
	if (root == NULL)
	{
        	printf("Item does not Found!\n");
        	return NULL;
    	}
	else if (root->data == key)
	{
        	printf("Item Found in Tree!\n");
        	return root;
    	}
	else if (root->data < key)
	{
        	return searchNode(root->right, key);
    	}
	else
	{
        	return searchNode(root->left, key);
    	}
}


struct node *minValueNode(struct node *root)
{
	struct node *current = root;
    	while (current && current->left != NULL)
	{
        	current = current->left;
    	}
    	return current;
}


struct node *deleteNode(struct node *root, int key)
{
	if (root == NULL)
	{
        	return root;
    	}
    	if (key < root->data)
	{
        	root->left = deleteNode(root->left, key);
    	}
	else if (key > root->data)
	{
        	root->right = deleteNode(root->right, key);
    	}
	else
	{
        	if (root->left == NULL)
		{
            		struct node *temp = root->right;
            		free(root);
            		return temp;
        	}
		else if (root->right == NULL)
		{
            		struct node *temp = root->left;
            		free(root);
            		return temp;
        	}
        	struct node *temp = minValueNode(root->right);
        	root->data = temp->data;
        	root->right = deleteNode(root->right, temp->data);
    	}
    	return root;
}


int main()
{
	int choice;
    	int value, search, key;
    	do {
        	printf("\n1.Create root Node\n2.Insert Node\n3.Search Node\n4.Inorder Traversal\n5.preorder Traversal");
		printf("\n6.Postorder Traversal\n7.Delete Node\n8.Exit\n");
        	printf("Select an Option : ");
        	scanf("%d", &choice);
        	switch (choice)
		{
            		case 1:
                		printf("Enter a Number :");
                		scanf("%d", &value);
                		root = newnode(value);
				printf("Root node created!\n");
                		break;
            		case 2:
                		printf("Enter a Number :");
                		scanf("%d", &value);
                		root = insert(root, value);
				printf("Value Inserted!\n");
                		break;
            		case 3:
                		printf("Enter the Value :");
                		scanf("%d", &search);
                		searchNode(root, search);
                		break;
            		case 4:
                		inorderTraversal(root);
				printf("\n");
                		break;
            		case 5:
                		preorderTraversal(root);
				printf("\n");
                		break;
            		case 6:
                		postorderTraversal(root);
				printf("\n");
                		break;
            		case 7:
                		printf("Enter Value to be Deleted :");
                		scanf("%d", &key);
                		deleteNode(root, key);
				printf("Item deleted!\n");
				break;
			case 8:
				printf("Exiting...\n");
				break;
            		default:
                		printf("Invalid Option!,Try Again!\n");
        	}
    	} while (choice != 8);
	return 0;
}
