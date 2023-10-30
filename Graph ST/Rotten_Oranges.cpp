// https://practice.geeksforgeeks.org/problems/rotten-oranges2536/1

/*
 int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<pair<int,int>,int>>q;                // we will store the coordinates{i,j} and the timer int the q
        int vis[n][m];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)                     // agar vo 2 hai i.e. ki agar vo rotten orange hai to uske coordinates ko queue me push kardenge aur timer 0 bhi push kar denge aur visited matrix me bhi 2 mark kar denge
                {
                    q.push({{i,j},0});
                    vis[i][j]=2;
                }
                else{                                   // agar vo rotten nahi hai to 0 mark kar denge visited matrix me
                    vis[i][j]=0;
                }
            }
        }
        int tm=0;
        int drow[]={-1,0,1,0};                          // drow aur dcol up down right left move karne ke lie hai
        int dcol[]={0,1,0,-1};  
        while(!q.empty())                   
        {   
            int r=q.front().first.first;                // row number nikal lia
            int c=q.front().first.second;               // col number nikal lia
            int t=q.front().second;                     // time nikal dia
            tm=max(tm,t);                               // max time nikalne ke lie
            q.pop();
            for(int i=0;i<4;i++)                        // up down right left move kar rahe hai
            {
                int nrow=r+drow[i];
                int ncol=c+dcol[i];
                if(nrow>=0  &&  nrow<n  &&  ncol>=0 &&  ncol<m  &&  vis[nrow][ncol]!=2  &&  grid[nrow][ncol]==1)        // agar row aur col dono matrix ki boundries ke andar hai aur vo abhi tak visited nahi hai aur vo ek fresh orange hai
                {
                    q.push({{nrow,ncol},t+1});              // to hum use q me push kar denge time increase karke
                    vis[nrow][ncol]=2;                      // uska visited matrix me bhi 2 mark kar denge
                }
            }
        }
        for(int i=0;i<n;i++)                            // yeh check karne ke lie hai ki saare fresh orange rotten ho gae ki nahi kyoki agar koi fresh orange chaaro taraf se 0 se ghira ho i.e. empty cell to vo kabhi rotten nahi ho sakta islie hum answer -1 return kar denge
        {
            for(int j=0;j<m;j++)
            {
                if(vis[i][j]!=2  &&  grid[i][j]==1)     // agar vo orange ka visited 2 na ho aur vo still fresh ho i.e. ki vo empty cell se ghira hai
                {
                    return -1;
                }
            }
        }
        return tm;                              // else hum max time return kar denge
    }
*/