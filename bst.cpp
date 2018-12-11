
#include <iostream>
#include <stdio.h>

using namespace std;

struct BSTNode
{
	int data ;
	BSTNode * left;
	BSTNode * right;
};


// A utility function to do inorder traversal of BST 
void inorder(BSTNode* root) 
{ 
    if (root != NULL) { 
        inorder(root->left); 
        printf("%d ", root->data); 
        inorder(root->right); 
    } 
    
} 
 
BSTNode* getNewNode(int data) {

    BSTNode* temp = new BSTNode; 
    temp->data = data; 
    temp->left = temp->right = NULL; 
    return temp; 
}

BSTNode* insert (BSTNode *node ,int data){
	
	if (node == NULL){
		return getNewNode (data);
	}
	if( data < node->data ){
		node ->left = insert (node->left ,data );
	}
	else{
		node->right =insert (node->right ,data );
	}
	return node;
}
/* Given a binary search tree and a data, this function deletes the data 
   and returns the new root */
   
BSTNode* deleteNode(BSTNode* root, int k) 
{ 
    // Base case 
    if (root == NULL) 
        return root; 
  
    // Recursive calls for ancestors of node to be deleted 
    if (root->data > k) { 
        root->left = deleteNode(root->left, k); 
        return root; 
    } 
    else if (root->data < k) { 
        root->right = deleteNode(root->right, k); 
        return root; 
    } 
  
    // We reach here when root is the node 
    // to be deleted. 
  
    // If one of the children is empty 
    if (root->left == NULL) { 
        BSTNode* temp = root->right; 
        delete root; 
        return temp; //new root 
    } 
    else if (root->right == NULL) { 
        BSTNode* temp = root->left; 
        delete root; 
        return temp; 
    } 
  
    // If both children are not NULL
    else {
	    BSTNode *succParent  = root->right; 
	    BSTNode *succ        = root->right;  
	    while (succ->left != NULL){
		    succParent = succ;
		    succ = succ->left;
	    }
		delete succ;
  		return root ;
	}
	
}
bool isBST_r(BSTNode *root ,BSTNode* &prev) {
	// traverse the tree in inorder fashion and  keep track of prev node 
	
	//base case
    if (root == NULL)
    	return true;
    	
    // L V R - inorder traversal	
    if (!isBST_r(root->left, prev)) 
    	return false; 
   
    // Allows only distinct valued nodes  
    if (prev != NULL )cout << "root->data = "<< root->data << " prev->data = " << prev->data << endl ;
    
    if (prev != NULL && root->data < prev->data)
    	return false; 
   
   	prev = root; 
   	return isBST_r(root->right, prev); 
      
}

bool isBST(BSTNode *root ) {
	BSTNode *prev = NULL ;
	return isBST_r(root , prev);


}

int main ()
{
	BSTNode *root = NULL ;

	//for (int i =0 ;i <1000 ;
	root = insert(root,15);
	root = insert(root,10);
	root = insert(root,20);
	root = insert(root,40);
	root = insert(root,30);
	root = insert(root,60);
	root = insert(root,35);
	root = insert(root,15);
	root = insert(root,90);
	
	printf("Inorder traversal of the given tree \n"); 
    
	inorder(root); 
    cout <<endl;
    
    root = deleteNode(root,10);
    cout << "inorder traversal " <<endl;

    inorder(root); 
    cout <<endl;
  //  root = deleteNode(root,60);

     if ( isBST(root ) )
	     cout << "Tree is BST "<<endl;
     else
	     cout << "Tree is Not BST "<<endl;

    cout <<endl;
    return 0;

}

