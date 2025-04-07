/*
*******************************************************************************************************
                                        Task_2_description
*******************************************************************************************************
The main() function of the following C program initially constructs a binary search tree with each node 
of type struct node. Each node in the tree consists of a data member that is a positive integer greater 
than zero. After the tree is constructed, the main() function calls a user-defined function 
delete_tree() that takes a pointer to the rootnode of the tree as input argument and deletes all the 
nodes in the right subtree of the rootnode.

For instance, if data was inserted into this binary search tree in the following order: 
7 4 6 3 5 2 8 1 9

inOrder traversal of the tree after construction and upon executing the delete_tree() function would 
print the following output within the main() function:

After construction of tree: 1 2 3 4 5 6 7 8 9
Upon exiting delete_tree() function: 1 2 3 4 5 6 7

1. The definition of the delete_tree() function contains errors. You must correct these 
errors and verify that the function provides the correct output.

2. Prepare the C file Task_2.c for system testing by allowing it to receive the numbers to be inserted
into the tree as a command line argument utilizing the commma character as delimiter. Once the 
generated executable is called with the required command line argument, the printed output should be 
the result of inOrder traversal of the tree after deletion of the right subtree of the rootnode of the 
tree, where the data in the printed output is delimited using one whitespace character.
*******************************************************************************************************
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct node
{
	struct node* leftPtr;
	int data;
	struct node* rightPtr;
};

void insert_node(struct node** treePtr, int data);
void inOrder(struct node* treePtr);
void delete_tree(struct node** treePtr);

int main(int argc, char* argv[]) {
	int temp = 0;
	struct node* treePtr = NULL;
    char *tokenPtr = NULL;
    tokenPtr = strtok(argv[1], ",");

    //printf("Enter the value of the new data member: ");
	//scanf("%d", &temp);
    while (tokenPtr != NULL)
    {
        insert_node(&treePtr, atoi(tokenPtr));
        tokenPtr = strtok(NULL, ",");          
    }
    printf("Initial version of binary tree:\n");
    inOrder(treePtr);
    printf("\n");
    delete_tree(&(treePtr->rightPtr)); //DELETE ENTIRE RIGHT OR LEFT BRANCH
    printf("Modified version of binary tree:\n");
    inOrder(treePtr);
    printf("\n");
}


void insert_node(struct node** treePtr, int data)
{
	if (*treePtr == NULL)
	{
		(*treePtr) = (struct node*)malloc(sizeof(struct node));
		(*treePtr)->data = data;
		(*treePtr)->leftPtr = NULL;
		(*treePtr)->rightPtr = NULL;
	}
	else
	{
		if (data < (*treePtr)->data)
		{
			insert_node(&((*treePtr)->leftPtr), data);
		}
		else if (data > (*treePtr)->data)
		{
			insert_node(&((*treePtr)->rightPtr), data);
		}
	}
}

void inOrder(struct node* treePtr)
{
	if (treePtr != NULL)
	{
		inOrder(treePtr->leftPtr);
		printf("%d ", treePtr->data);
		inOrder(treePtr->rightPtr);
	}
}

void delete_tree(struct node** treePtr)
{

	if ((*treePtr) != NULL)
	{
		delete_tree(&((*treePtr)->leftPtr)); //look left
		delete_tree(&((*treePtr)->rightPtr)); //look right
		free(*treePtr); //visit & delete
		(*treePtr) = NULL;
	}
}