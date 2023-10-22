class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
         vector<pair<int,int>> ans;
       
       for(int i=0;i<n;i++)
           ans.push_back({wt[i],val[i]});
           
        sort(ans.begin(),ans.end());
        
        vector<vector<int>> dp(n+1,vector<int>(W+1,0));
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=W;j++)
            {
                if(ans[i-1].first > j)
                dp[i][j]=dp[i-1][j];
                else
                dp[i][j]=max(dp[i-1][j],ans[i-1].second+dp[i-1][j-ans[i-1].first]);
            }
        }
        
        return dp[n][W];
    }
};
