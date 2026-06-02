class Solution {
  private:
    vector<int> toposort(int V, vector<vector<int>>& adj){
        vector<int> indegree(V, 0);
        for(int i=0;i<V;i++){
            for(auto node : adj[i]){
                indegree[node]++;
            }
        }
        queue<int> q;
        
        for(int i=0;i<V;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        
        vector<int> topo;
        
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            topo.push_back(curr);
            for(auto node : adj[curr]){
                indegree[node]--;
                if(indegree[node]==0){
                    q.push(node);
                }
            }
        }
        
        return topo;
    }
  public:
    string findOrder(vector<string> &words) {
        // code here
        unordered_set<char> uniqueChar;
        for(const string& word : words){
            for(char ch : word){
                uniqueChar.insert(ch);
            }
        }
        int V=26;
        vector<vector<int>> adj(V);
        int n=words.size();
        for(int i=0;i<n-1;i++){
            string s1=words[i];
            string s2=words[i+1];
            if(s1.size()>s2.size() && s1.substr(0,s2.size())==s2){
                return "";
            }
            int len=min(s1.size(),s2.size());
            for(int j=0;j<len;j++){
                if(s1[j]!=s2[j]){
                    adj[s1[j]-'a'].push_back(s2[j]-'a');
                    break; // as we found one edge from here; 
                }
            }
        }
        
        vector<int> mytopo=toposort(V,adj);
        string res="";
        for(int i : mytopo){
            char ch=char(i+'a');
            if(uniqueChar.count(ch)){
                res=res + char(i+'a');
            }
        }
        if(res.size()==uniqueChar.size()) return res;
        return "";
        
    }
};
