
#include <vector>

#include <iostream>
#include <algorithm>
#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <set>
#include <map>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <iomanip>
#include <string>

using namespace std;


	const int w[] = { 3,2,1 };
    const int v[] = { 5,3,4 };
    
void print_items(vector< vector<bool> >&K,  int &ans,int bagsize, int numitem ) ;
void knapsack(const char* t, int bagsize, int numitem, const int* w, const int* v, int& ans) {

	/*create 2d vector “T[row = numitem][column = bagsize]” and initializes all elements to 0)*/
	vector< vector<int>  > T(numitem+1, vector<int>(bagsize+1, 0));
	vector< vector<bool> > K(numitem+1, vector<bool>(bagsize+1, 0));

	for (int curr_item = 0; curr_item <= numitem; curr_item++ ) {

		for (int size = 0; size <= bagsize; size++) {
			
			if (curr_item == 0 || size == 0) {
				T[curr_item][size] = 0;
			}
			else if ( w[curr_item-1] <= size ){
				//sample curr_item = 2,size =3  :: Max(3,Sum(4,v[2-2]) = 4    
				T[curr_item ][size] = max(T[curr_item - 1][size],  T[curr_item-1][size - w[curr_item-1]]+ v[curr_item - 1]);
				if (T[curr_item ][size]!= T[curr_item - 1][size])
					K[curr_item][size] = true;

			}
			else {
				
				T[curr_item ][size] = T[curr_item-1][size];
			}

		}
	}

	//ans = 9;
	cout <<"------------ V matrix ----------------"<<endl ;

	ans = T[numitem][bagsize];
	cout << "knapsack = "<< ans << endl; 
	print_items(K,ans,bagsize,numitem );
	
				cout <<endl;


}
print_matrix(bool type)
{
	if (
	cout <<"------------ K matrix ----------------"<<endl ;

		for ( i = 0; i <= numitem; i++ ) {

			for ( s = 0; s <= bagsize; s++) {
				cout <<setw(5)<< K[i][s] <<"" ;	
			}
			cout <<endl;
		}
	
}

void print_items(vector< vector<bool> > &K,  int &ans,int bagsize, int numitem ) {
		vector <int> result ;
		int i = 0 ,s =0,j=0;
		string outstr ;
		cout <<"------------ K matrix ----------------"<<endl ;

		for ( i = 0; i <= numitem; i++ ) {

			for ( s = 0; s <= bagsize; s++) {
				cout <<setw(5)<< K[i][s] <<"" ;	
			}
			cout <<endl;
		}
		int p = ans;
		i = numitem;
		s = bagsize;
		while (p){
			if (K[i][s]){
				cout << "pushing " << i<<endl;
				result.push_back(i);
				p-=v[i-1];
				i-- ; s--;
			}
			else{				
				i--;
			}
		}		
		j= 0;
		cout <<"Max Value of "<< ans >>"can be obtained from items {" ;
		
		cout<<outstr <<endl;
		for (int j :result ) {
			cout<<result[j]<<",";
		}
		cout<<"} ";
		j=0;
		cout <<"that has values {" ;//{4+5=9};
		for (int j :result ) {
			cout<<v[j-1]<<"+";
		}
		cout<<"} ";
		cout <<endl;
		//		 {3,1} that has values {4+5=9}
//Max Value of 9 can obtained from items {3,1} that has values {4+5=9}


	
		
		
/*	   
------------ k matrix ----------------
   0   0   0   0   0   0
   0   0   0   1   1   1
   0   0   1   0   0   1
   0   1   1   1   1   1

   
  */ 
}
//EOF

int main(){
		
	int numitem = sizeof(w) / sizeof(int);
    int bagsize = 5;
    int ans = 0;
    knapsack("knapsack2(k2)", bagsize, numitem, w, v, ans);
}