// User function Template for C++

class Solution {
  public:
    vector<vector<string>> findSequences(string beginWord, string endWord,
                                         vector<string>& wordList) {
        // code here
        unordered_set<string>st(wordList.begin(),wordList.end());
        queue<vector<string>> q;
        q.push({beginWord});
        vector<string> usedOnLevel;
        usedOnLevel.push_back(beginWord);
        vector<vector<string>> ans;
        int level=0;
        while(!q.empty()){
            vector<string> curr=q.front();
            
            if(curr.size()>level){ //erasing the words used so far from the 
            //previous levels.
                level++;
                for(auto s : usedOnLevel){
                    st.erase(s);
                }
                usedOnLevel.clear();
            }
            string word=curr.back();
            if(word==endWord){
                if(ans.size()==0){ // first found solution;
                    ans.push_back(curr);
                }
                else if(ans[0].size()==curr.size()){
                    ans.push_back(curr);
                }
            }
            for(int i=0;i<word.size();i++){
                char og=word[i];
                for(char ch='a';ch<='z';ch++){
                    word[i]=ch;
                    if(st.count(word)>0){
                        curr.push_back(word);
                        q.push(curr);
                        usedOnLevel.push_back(word);
                        curr.pop_back();
                    }
                }
                word[i]=og; //so we can move on to the next index, 
                //preserving the previous ones searched.
            }
        }
        
        return ans;
    }
};
