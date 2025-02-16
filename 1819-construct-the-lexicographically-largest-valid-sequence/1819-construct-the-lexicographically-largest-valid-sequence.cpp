class Solution {
private:
    bool check(vector<int> &seq,vector<bool> &vis,int ind,int n)
    {
        if(ind==seq.size())   return true;
        if(seq[ind]!=0) return check(seq,vis,ind+1,n);
        for(int i=n;i>=1;i--)
        {
            int nextnum=(i==1)?ind:ind+i;
            if(vis[i]||(i>1&&(nextnum>=seq.size()||seq[nextnum]!=0)))
                continue;
            seq[ind]=seq[nextnum]=i;
            vis[i]=true;
            if(check(seq,vis,ind+1,n))  return true;
            seq[ind]=seq[nextnum]=0;
            vis[i]=false;
        }
        return false;
    }
public:
    vector<int> constructDistancedSequence(int n) {
        vector<int> seq(2*n-1,0);
        vector<bool> vis(n+1,false);
        check(seq,vis,0,n);
        return seq;
    }
};