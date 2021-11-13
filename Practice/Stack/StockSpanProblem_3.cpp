// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends



class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int price[], int n)
    {
        vector<int> S;
        
        S.push_back(1);
        
        int max_i=0;
        
        for(int i=1; i<n; i++)
        {
            int j=i-1;
            while((j>=0) && (price[j]<=price[i]) && (j>max_i))
            {
                
                j--;
            }
            if(j==-1)
            {
                S.push_back(i+1);
                max_i = i;
            }
            else if (j==max_i)
            {
                if(price[j]<=price[i])
                {
                    S.push_back(i+1);
                    max_i = i;
                }
                else 
                    S.push_back(i-j);
                    
            }
            else
            {
                S.push_back(i-j);
            }
        }
        
        return S;
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
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution obj;
		vector <int> s = obj.calculateSpan(a, n);
		
		for(i=0;i<n;i++)
		{
			cout<<s[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
  // } Driver Code Ends