#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct tree {
	int info;
	struct tree *left;
	struct tree *right;
};
struct tree *insert(struct tree *,int);
void inorder(struct tree *);
int main(void) {
	struct tree *root;
	int choice, item,item_no;
	root = NULL;

	do {
		do {
			printf("\n \t 1. Insert in Binary Tree  ");
			printf("\n\t 2. Inorder traversal of Binary tree");
			printf("\n\t 3. Exit ");
			printf("\n\t Enter choice : ");
			scanf(" %d",&choice);
			if(choice<1 || choice>4)
			      printf("\n Invalid choice - try again");
		}
		while (choice<1 || choice>7);
		switch(choice) {
			case 1:
				   printf("\n Enter new element: ");
			scanf("%d", &item);
			root= insert(root,item);
			printf("\n root is %d",root->info);
//			printf("\n Inorder traversal of binary tree is : ");
//			inorder(root);
			break;
		
			case 2:
				  printf("\n Inorder traversal of binary tree is : ");
			inorder(root);
			break;
			default:
				   printf("\n End of program ");
		}
		/* end of switch */
	}
	while(choice !=4);
	return(0);
}
struct tree *insert(struct tree *root, int x) {
	if(!root) {
		root=(struct tree*)malloc(sizeof(struct tree));
		root->info = x;
		root->left = NULL;
		root->right = NULL;
		return(root);
	}
	if(root->info > x)
	     root->left = insert(root->left,x); else {
		if(root->info < x)
			root->right = insert(root->right,x);
	}
	return(root);
}
void inorder(struct tree *root) {
	if(root != NULL) {
		inorder(root->left);
		printf(" %d",root->info);
		inorder(root->right);
	}
	return;
}
