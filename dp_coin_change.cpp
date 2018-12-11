#include <iostream>
#include <climits>
using namespace std;

// Function to find the minimum number of coins required
// to get total of N from set S
int findMinCoins(int coins[], int n, int N)
{
    // T[i] stores minimum number of coins needed to get total of i
    int T[N + 1];
    T[0] = 0;    // 0 coins are needed to get total of 0
	T[1] = 1 ;   // 1 coin  needed to get total of 1
    for (int i = 2; i <= N; i++)
    {
	    //cout << "N = "<< N <<endl;

        // initialize minimum number of coins needed to infinity
        T[i] = INT_MAX;
        int sub_res = INT_MAX;
		//cout << "T[i] = "<< T[i] <<endl;
		
        // do for each coin
		cout << "i = "<< i<<endl;
		
        for (int c = 0; c < n; c++) {
            // check if index doesn't become negative by including
            // current coin c
			cout << "c = "<< c<<" coins[c] = " <<coins[c]<<endl;

            if (coins[c] <= i){                
                sub_res = T[i - coins[c]];
				cout << " sub_res = " <<sub_res<<endl;
			}
            // if total can be reached by including current coin c,
            // update minimum number of coins needed T[i]
            if (sub_res != INT_MAX){
                T[i] = min(T[i], sub_res + 1);
            }
	        cout << " T[i] = " <<T[i]<<endl;
        }
        cout << " <<<<<<<<<<<Ans for i = "<< i<<" T[i] = " <<T[i]<<endl;
	    cout <<endl;
    }

    // T[N] stores the minimum number of coins needed to get total of N
    return T[N];
}

// main function
int main()
{
    // n coins of given denominations
    int S[] = { 1,  3, 4};
    int n = sizeof(S) / sizeof(S[0]);

    // Total Change required
    int N = 6;

    cout << "Minimum number of coins required to get desired change is "
            << findMinCoins(S, n, N)<<endl;

    return 0;
}