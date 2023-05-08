#include<bits/stdc++.h>
using namespace std;

bool issafe(vector<vector<int>>m,int n,vector<vector<int>> visited, int x,int y){
            
            if((x>=0 && x<n) && (y>=0 && y<n) && m[x][y]==1 && visited[x][y]==0){
                return true;
            }
            else{
                return false;
            }
        
    }
    void solve(vector<vector<int>> &m, int n,vector<vector<int>> visited,int x,int y, vector<string>& ans,string path ){
        // base case 
        if(x== n-1 && y== n-1){
            ans.push_back(path);
            return;
        }
        
        // marking first cell visited cox we are in the maze
        visited[x][y]=1;
        
        // down
        int newx= x+1;
        int newy= y;
        if(issafe(m,n,visited,newx,newy)){
            path.push_back('D');
            solve(m,n,visited,newx,newy,ans,path);
            path.pop_back();
        }
        
        // left
        newx= x;
        newy= y-1;
        if(issafe(m,n,visited,newx,newy)){
            path.push_back('L');
            solve(m,n,visited,newx,newy,ans,path);
            path.pop_back();
        }
        
        // right
        newx= x;
        newy= y+1;
        if(issafe(m,n,visited,newx,newy)){
            path.push_back('R');
            solve(m,n,visited,newx,newy,ans,path);
            path.pop_back();
        }
        // up
        newx= x-1;
        newy= y;
        if(issafe(m,n,visited,newx,newy)){
            path.push_back('U');
            solve(m,n,visited,newx,newy,ans,path);
            path.pop_back();
        }
        
        visited[x][y]=0;
    }

    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string>ans;
        if(m[0][0]==0){
            return ans;
        }
        vector<vector<int>> visited=m;
        string path= "";
        // initiazied visited with zeros
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                visited[i][j]=0;
            }
        }
        int x=0;
        int y=0;
        
        solve(m,n,visited,x,y,ans,path);
        sort(ans.begin(),ans.end());
        
        return ans;
        
    }


int main()
{
 return 0;
}