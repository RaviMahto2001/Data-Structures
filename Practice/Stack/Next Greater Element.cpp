// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        
        vector<long long> ans(n);
        
        ans[n-1] = -1;
        
        int maxi=n-1;
        int j;
        
        for(int i=n-2; i>=0;i--)
        {
            j=i+1;
            while(j<maxi && arr[i]>=arr[j])
                j++; 
            if(j==maxi)
            {
                if(arr[i]<arr[maxi])
                {
                    ans[i]=arr[maxi];
                }
                else
                {
                    ans[i]=-1;
                    maxi=i;
                }
            }
            else
            {
                ans[i]=arr[j];
            }
        }
        
    return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        
        int n;
        cin>>n;
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        Solution obj;
        vector <long long> res = obj.nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
}  // } Driver Code Ends