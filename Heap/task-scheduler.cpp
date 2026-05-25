class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int nums=tasks.size();
        unordered_map<char,int> mpp;
        for(int i=0;i<nums;i++){
            mpp[tasks[i]]++;
        }
        priority_queue<int> maxH;
        for(auto& entry : mpp){
            maxH.push(entry.second);
        }
        int time=0;

        while(!maxH.empty()){
            vector<int> temp;
            int cycle=n+1;
            int i=0;
            while(i<cycle && !maxH.empty()){
                int cnt = maxH.top();
                maxH.pop();

                cnt--;

                if(cnt>0){
                    temp.push_back(cnt);
                }

                time++;

                i++;

            }

            for(int el : temp){
                maxH.push(el);
            }

            if(maxH.empty()){
                break;
            }

            time+= (cycle-i);
        }

        return time;
    }
};
