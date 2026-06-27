class Solution {
  private:
    struct data{
        int start;
        int end;
        int ind;
    };
    
    struct compare{
        bool operator()(const data &a, const data &b )const{
            if(a.end==b.end){
                return a.start<b.start;
            }
            return a.end<b.end;
        }
    };
  public:
    int activitySelection(vector<int> &start, vector<int> &finish) {
        int n=start.size();
        vector<data> act(n);
        for(int i=0;i<n;i++){
            act[i].start=start[i];
            act[i].end=finish[i];
            act[i].ind=i;
        }
        
        sort(act.begin(),act.end(),compare());
        
        int lastend=act[0].end;
        int k=1;
        for(int i=1;i<n;i++){
            if(act[i].start>lastend){
                k++;
                lastend=act[i].end;
            }
        }
        return k;
    }
};
