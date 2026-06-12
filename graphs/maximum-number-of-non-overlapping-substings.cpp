class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n=s.size();
        vector<int> first(26,n);
        vector<int> last(26,-1);
        for(int i=0;i<n;i++){
            char ch=s[i];
            first[ch-'a']=min(first[ch-'a'],i);
            last[ch-'a']=i;
        }

        vector<pair<int,int>> intervals;
        
        for(int i=0;i<26;i++){
            if(last[i]==-1) continue;
            int start=first[i];
            int end=last[i];
            bool valid=true;

            for(int j=start;j<=end;j++){
                int ch=s[j]-'a';
                if(first[ch]<start){
                    valid=false;
                    break;
                }

                end = max(end, last[ch]);
            }

            if(valid) intervals.push_back({start,end});

        }

        sort(intervals.begin(),intervals.end(),[](const auto& a,const auto& b){
            return a.second<b.second;
        });

        vector<string> ans;
        int prevInd=-1;
        for(auto& interval : intervals){
            int l=interval.first;
            int r=interval.second;
            if(l>prevInd){
                ans.push_back(s.substr(l,r-l+1));

            }
            prevInd=r;
        
        }

        return ans;
        
    }
};
