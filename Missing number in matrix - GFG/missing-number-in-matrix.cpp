//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    long long int MissingNo(vector<vector<int> >& mat)
    {
        int n = mat.size();
        vector<vector<long long int> > matrix(n,vector<long long int>(n));
        
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<n;j++)
            {
                matrix[i][j] = mat[i][j];
            }
        }
        
        long long int zeros = 0;
        long long int nZeros = 0;
        int x = -1;
        int y = -1;
        
        for(int i = 0;i<n;i++)
        {
            long long int temp = 0;
            int flag = 0;
            
            for(int j = 0;j<n;j++)
            {
                temp = temp + matrix[i][j];
                
                if(matrix[i][j]==0)
                {
                    flag = 1;
                    x = i;
                    y = j;
                }
            }
            
            if(flag == 1)
            {
                zeros = temp;
            }
            else
            {
                nZeros = temp;
            }
            if(zeros>0 and nZeros>0)
            {
                break;
            }
        }
       
        long long int update = nZeros - zeros;
        if(update<=0)
            return -1;
        matrix[x][y] = update;
         //cout<<update<<endl;
        for(int i = 0;i<n;i++)
        {
             long long int sum = 0;
            
            for(int j = 0;j<n;j++)
            {
                sum  = sum + (long long int)matrix[i][j];
            }
            //cout<<sum<<" "<<nZeros<<endl;
            if(sum!=nZeros)
            {
               // cout<<"1"<<endl;
                return -1;
                
            }
        }
        
        for(int i = 0;i<n;i++)
        {
             long long int sum = 0;
            
            for(int j = 0;j<n;j++)
            {
                sum +=matrix[j][i];
            }
            
            if(sum!=nZeros)
            {
                // cout<<"2"<<endl;
                return -1;
            }
        }
         long long int sum = 0;
        
        for(int i = 0;i<n;i++)
        {
            sum +=matrix[i][i];
        }
        if(sum!=nZeros)
        {
           // cout<<"3"<<endl;
            return -1;
        }
        
        sum = 0;
        
        for(int i = 0;i<n;i++)
        {
            sum +=matrix[i][n-i-1];
        }
        if(sum!=nZeros)
        {
            // cout<<"4"<<endl;
            return -1;
        }
        return update;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>> matrix(n, vector<int>(n,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		long long int ans = ob.MissingNo(matrix);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends