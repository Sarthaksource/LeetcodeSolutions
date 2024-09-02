class Solution {
private:
    vector<int> parent;
    vector<int> size;
    
    int find(int i)
    {
        if(parent[i]==i)
        {
            return i;
        }
        else
        {
            return parent[i] = find(parent[i]);
        }
    }
    
    void unionByRank(int i, int j)
    {
        int irep = find(i);
        int jrep = find(j);
        
        if(irep==jrep)
        {
            return;
        }
        
        int irank = size[irep];
        int jrank = size[jrep];
        
        if(irank>jrank)
        {
            parent[jrep] = irep;
            size[irep] += size[jrep];
        }
        else
        {
            parent[irep] = jrep;
            size[jrep] += size[irep];
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        parent.resize(m*n + 1);
        size.resize(m*n + 1, 1);

        for(int i=0; i<m*n; i++)
        {
            parent[i] = i;
        }

        int edgeParent = m*n;

        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(board[i][j]=='X')
                {
                    continue;
                }
                if(i==0 || i==m-1 || j==0 || j==n-1)
                {
                    unionByRank(i*n+j, edgeParent);
                }
                if(i+1<m && board[i+1][j]=='O')
                {
                    unionByRank(i*n+j, (i+1)*n + j);
                }
                if(j+1<n && board[i][j+1]=='O')
                {
                    unionByRank(i*n+j, i*n + (j+1));
                }
            }
        }

        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(board[i][j]=='O' && find(i*n+j) != find(edgeParent))
                {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
