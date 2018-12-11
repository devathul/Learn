// C++ template version of binary search ,Not complete
#include <stdio.h>
#include <iostream>
#include <stdio.h>
#include <algorithm>    // std::fill
#include <string>
#include <iterator>
#include <array>
#include <cassert>

using namespace std;

template <typename T>
int int_ascending_order (const T& c1, const T& c2){
	if (c1 == c2 ) return 0;
	if (c1 < c2 ) return 1;
	return -1;
}

template <typename T>
class binarysearch {
public:
	binarysearch(vector<T>& d,int s,int(*cf) (const T& c1, const T& c2),bool dis ): _darray(d){
		//_darray =d;
		_size =s;
		_cf  = cf;
		_display = dis;
		
	}
	~binarysearch(){}
	void 	_assertSorted();
	bool binary_search(const T& tofind, int& pos, int& num_compare); //Called from main !
private:
	/* private data */
	vector<T>& _darray;
	int _size;
	int(*_cf) (const T& c1, const T& c2);
	bool _display;
	bool _binary_search(const T& tofind, int s, int e, int& pos, int& num_compare);
	void _assertSorted(int s, int e);
	bool _bs();
	
};
template <typename T>
bool binarysearch<T>::_binary_search(
	const T& tofind,
	int first,
	int last,
	int& pos,
	int& num_compare) 
	{
		//cout <<"first " << first  << " last " << last << endl;
		cout << "tofind: " << tofind  << " "<<endl;
		_assertSorted(first, last); //Array must be in ascending or descending order
		//WRITE YOUR CODE To DO BINARY SEARCH HERE>>
		//return (_bs())
		pos = -1;
		while(first <= last){
			int mid = first + (last-first)/2;
		//	cout <<"mid " << mid << endl;

			if (_darray[mid] == tofind){
				num_compare++;
				pos = mid;
			//	cout << "Found : " << tofind << endl;
				return true;
			}
			if (_darray[mid] < tofind ){
				num_compare++;
				first  = mid+1;
			}
			else{
				last = mid-1;	
			}
			
		}
		return false;
	}
	
	
template <typename T>
void binarysearch<T>::_assertSorted(int s, int e){
	int p = 0;
	for (int i = s; i <= e; ++i) {
		//cout << _darray[p]  << " " << _darray[i] ;

		int r = _cf(_darray[p], _darray[i]);
		//cout << " " << r <<endl;
		assert(r >= 0);
		p = i;
	}
}	
template <typename T>
void binarysearch<T>::_assertSorted(){

	int s = _size;
	_assertSorted(0, s - 1);
}

template <typename T>
bool binarysearch<T>::binary_search(const T& tofind, int& pos, int& num_compare){
	int n = _size;
	bool found =  _binary_search(tofind, 0, n-1, pos, num_compare);
	cout <<"Number of comparisons "<< num_compare <<endl;
	if (found ){
		cout << "Number "<< tofind << "found " <<endl;
	}
	else
		cout << "Number "<< tofind << " Not found " <<endl;
	return found;
}

static void int_test()
{
	bool verbose = false;
	
	int a[] = { -5, -3, -1, 0, 1, 4, 7, 7, 9, 10, 21, 45 };
	int sz = sizeof(a) / sizeof(int);
	vector<int> b ;
	b.assign(a,a+sz);
	cout << "size " << sz <<endl;

	int n = b.size(); 
    cout << "vector size " << n <<endl;
    cout << "The last element is: " << b[n - 1]<<endl; 

	// ={ -5, -3, -1, 0, 1, 4, 7, 7, 9, 10, 21, 45 };
	//binarysearch<int>::fill(b, a, sz);
	binarysearch<int> bb(b, sz, int_ascending_order, verbose);
	int pos = -1;
	int nc = 0;
	bb.binary_search(45, pos, nc);
	assert(pos == 11);
	
	bb.binary_search(4, pos, nc);
	assert(pos == 5);
	bb.binary_search(-5, pos, nc);
	assert(pos == 0);
	
	
	bb.binary_search(-4, pos, nc);
	assert(pos == -1);
	bb.binary_search(46, pos, nc);
	assert(pos == -1);
	bb.binary_search(-6, pos, nc);
	assert(pos == -1);
	bb.binary_search(44, pos, nc);
	assert(pos == -1);
}

int main (){
	
	int_test();
	    cout << "All test PASSED !!!" <<endl;

}
