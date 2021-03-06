#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <set>
#include <map>
#include <algorithm>
#include <iterator>
#include <numeric>

using namespace std;

template<typename arrayType,int size>
class genericArray {
private:
	arrayType m_array[size];
public:
	arrayType& operator[] (const int index) { //Writing lhs
		if (index > size) {
			cout << "Index out of bounds" << endl;
			// return last element.
			return m_array[size-1];
		}
		return m_array[index];
	}

	arrayType operator[] (int index) const { //Reading rhs
		if (index > size) {
			cout << "Index out of bounds" << endl;
			// return last element.
			return m_array[size-1];
		}
		return m_array[index];
	}

};



int main(int argc, char* argv[]) {

	genericArray<int, 5> myIntArray;
	genericArray<double, 5> myDoubleArray;
	genericArray<float, 5> myFloatArray;
	for (int i = 0; i < 5; i++) {
		myIntArray[i] = i*2;
		myDoubleArray[i] = (double)(i * 2.0);
		myFloatArray[i] = (float)(i * 2.0);
	}

	for (int i = 0; i < 5; i++) {
		cout << "myIntArray[" << i << "] is " << myIntArray[i] << "\n";
	}

	cout << "\n\n";

	for (int i = 0; i < 5; i++) {
		//cout << "myFloatArray[%d] is %lf \n"<< i<< myFloatArray[i]<< "\n";
				cout << "myFloatArray[" << i << "] is " <<(float)myFloatArray[i] << "\n";

	}

	cout << "\n\n";

	for (int i = 0; i < 5; i++) {
		//cout << "myFloatArray[%i] is %f \n"<< i<< myFloatArray[i]<< "\n";
			cout << "myFloatArray[" << i << "] is " << myFloatArray[i] << "\n";

	}

	cout << "\n\n";

	cout << myIntArray[99] << "\n\n";

	return 0;
}
