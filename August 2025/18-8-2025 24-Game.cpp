class Solution {
    //TC:O(N*N!)
    //SC:O(1)
public:
    const double EPS = 1e-6;
    bool judgePoint24(vector<int>& cards) {
        //cards can also be used in any order
        //we can put (4,1), (4,8), (4,7)
        //at every stage we can just put into existing bracket or just create new bracket -- can fix this problem using postfix expression
        vector<double> dc;
        for (int c: cards){
            dc.push_back((double)c);
        }
        return dfs(dc);
    }
private:
    vector<double> cal(double x, double y){
        vector<double> ans;
        ans.push_back(x+y);
        ans.push_back(x-y);
        //this is redundant, as we are trying out all combinations
        ans.push_back(y-x);
        ans.push_back(x*y);
        if (fabs(x)>EPS)ans.push_back(y/x);
        if (fabs(y)>EPS)ans.push_back(x/y);
        return ans;
    }
    bool dfs(vector<double>&dc){
        if (dc.size()==1){
            return fabs(dc[0]-24)<EPS;
        }

        //loop through all permutations
        int n = dc.size();
        for (int i=0; i<n; i++){
            for (int j=i+1; j<n; j++){
                vector<double> next;
                for (int k=0; k<n; k++){
                    //will have same number so just compare index
                    if (k!=i && k!=j) next.push_back(dc[k]);
                }

                //do operations on both value 
                for (double val: cal(dc[i], dc[j])){
                    next.push_back(val);
                    if (dfs(next)) return true;
                    next.pop_back();
                }
            }
        }
        return false;
    }
};