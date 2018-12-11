#include <stdio.h>

int _a[] = {2,0,1,3}; // Orig array

static int val=2;
int length_tough(int x );

 
int length_tough(int x ) {
  static int j = 0;
  int temp = 0 ;
  printf("calling length_tough x = %d  a[x]= %d\n",x,_a[x]);
  if ((_a[x] - val ) == 0) {
 	return 0;
  }
  else{
	//  temp      = _a[x];
	// _a[x]     = _a[_a[x]];
	// _a[_a[x]] = temp;
 	return (1+length_tough(_a[x]));
  }

}

int main(){
    int len=0;
    len = length_tough(2);
     printf ("Length = %d \n",len);
}
