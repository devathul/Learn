#include <stdio.h>
using namespace std; 

int _a[] = { 2,0,1,3}; //Orig array


int main(){
    int len=0;
    len = length_tough(2);
     printf ("Length = %d \n",len);
}

 
int length_tough(int x ) {
  static int j = 0;
  //int len =0 ;
  //WRITE CODE HERE a(arr,3)
  // 1 2 0
  // 0 1 2 
 int temp = 0 ;
  int val = x;
  printf("calling length_tough x = %d  a[x]= %d\n",x,_a[x]);
  j++ ; if (j>10 ) return 0;
  if ((_a[val] - val ) == 0) {
 	return 0;
  }
  else{
	  temp      = _a[x];
	  _a[x]     = _a[_a[x]];
	  _a[_a[x]] = temp;
 	return (1+length_tough(x));
  }

}