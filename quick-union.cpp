 
 
 
 
 
 /*
 
 https://people.eecs.berkeley.edu/~jrs/61b/lec/33
 
 
 Implementing Quick-Union with an Array
--------------------------------------
Suppose the items are non-negative integers, numbered from zero.  We'll use an
array to record the parent of each item.  If an item has no parent, we'll
record the size of its tree.  To distinguish it from a parent reference, we'll
record the size s as the negative number -s.  Initially, every item is the root
of its own tree, so we set every array element to -1.

                        -------------------------------
                        |-1|-1|-1|-1|-1|-1|-1|-1|-1|-1|
                        -------------------------------
                          0  1  2  3  4  5  6  7  8  9

 The forest illustrated at left below is represented by the array at right.

          8        1        2                  -------------------------------
         / \      /|\                          | 1|-4|-1| 8| 5| 8| 1| 3|-5| 1|
        5   3    9 0 6                         -------------------------------
        |   |                                    0  1  2  3  4  5  6  7  8  9 
        4   7

 
 
 */
 #include <stdio.h>
int array[] = {1,-4,-1,8,5,8,1,3,-5,1};

//Complexity =  inverse Ackermann function (w/ path compression)                
//log(log(log(log(log(n)))))Will never go bigger than 5.
//Extremely slowly-growing function

int SmartFind(int x) {
    if (array[x] < 0) {
      return x;  // x is the root of the tree; return it
    } 
    else {
      // Find out who the root is; compress path by making the root x's parent
      array[x] = SmartFind(array[x]);// -> patch compression achieved here
      printf("root of %d is %d\n",x,array[x]);
      return array[x];  // Return the root
    }
}


 //Check if a and b has same root
bool is_connected(int a ,int b){
    int x = SmartFind(a) ;  
          printf("root of a %d is %d\n\n",a,x);
 
    int y = SmartFind(b) ;  
          printf("root of b %d is %d\n\n",b,y);
 
    return (x == y) ? true : false ;
}

 
 
bool union_by_size(int root1, int root2) {
	
	bool x = is_connected(root1,root2);
	bool y = is_connected(root2,root1);
	if (x == false){ // This means root1 and root2 are not same, we can go ahead and union them 
	    if (array[root2] < array[root1]) {     // root2 has larger tree
	      array[root2] += array[root1];        // update # of items in root2's tree
	      array[root1] = root2;                // make root2 parent of root1
	    }
	    else {                                  // root1 has equal or larger tree
	      array[root1] += array[root2];        // update # of items in root1's tree
	      array[root2] = root1;                       // make root1 parent of root2
	    }
	    return true;
	}
	return false;
}


int main (){
	bool complete = false;
	int x = 7;
	int y = 9;
	bool has_same_root = Connected(x,y);
	printf ("x and y Connected? %d\n",has_same_root);
	if(!has_same_root){
		complete = union_by_size( x,  y);
	}
	printf ("x and y are unified !!! -> %d\n",complete);
	
}
