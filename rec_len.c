/*----------------------------------------------------------------
Copyright (c) 2018 Author: Jagadeesh Vasudevamurthy
file: length.cpp
The array of size N will have numbers from (0 to N-1)ONLY
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
all includes here
-----------------------------------------------------------------*/
#include "../util/util.h"
#include "length.h"

/*----------------------------------------------------------------
Time complexity O(n)
Space Complexity O(1)
CANNOT CHANGE BELOW
-----------------------------------------------------------------*/
int length::length_easy(int x) {
  int l = 0;
  int gx = x;
  while (true) {
    if (_a[x] == gx) {
      return l;
    }
    x = _a[x];
    ++l;
  }
  return l;
}

/*----------------------------------------------------------------
Time complexity:
Space Complexity:O(1)

YOU CANNOT USE ANY static variable in this function
YOU can use as many local variables inside the function
Cannot use any loop statements like  for, while, do, while, go to
Can use if. 
ONLY AFTER THE execution of this routine array s MUST have the same contents as you got it.
YOU cannot call any subroutine inside this function except length_tough itself (NOT length_easy)
-----------------------------------------------------------------*/
int length::length_tough(int x) {

    //WRITE CODE HERE
	
	//This program is cool  !!

	int tmp = 0,tmp_ret=0;
	int ret = 0;
	//Base case
	if (x ==  _a[x]) {
	  return 0;
	}
	//Swap the elements at positions _a[x] and x 
	tmp     = _a[x];
	_a[x]   = _a[tmp];
	_a[tmp] = tmp;

	ret = (1 + length_tough(x));
	//use stack to unswap the array elements ..
	//Swap the elements at positions x and _a[x] 

	tmp_ret = _a[tmp];
	_a[tmp] = _a[x];
	_a[x] = tmp_ret;
	// ret will have the correct value after stack is completly popped .
	return ret;

}

//EOF

