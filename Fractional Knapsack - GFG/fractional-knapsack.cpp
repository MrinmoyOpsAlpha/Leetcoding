//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    static bool comparison(Item a,Item b){
        double r1 = (double) a.value/(double) a.weight;
        double r2 = (double) b.value/(double) b.weight;
        return r1>r2;
    }
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        sort(arr,arr+n,comparison);
        
        int currWeight = 0;
        double finalValue =0.0;
        
        for(int i=0;i<n;i++){
            if(currWeight + arr[i].weight <= W){
                currWeight += arr[i].weight;
                finalValue += arr[i].value;
            }
            else{
                int remaining = W - currWeight;
                finalValue = finalValue + ((double) arr[i].value/(double) arr[i].weight) * (double) remaining;
                break;
            }
        }
        return finalValue;
    }
        
};


//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends