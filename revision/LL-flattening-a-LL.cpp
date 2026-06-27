using t= tuple<double,int,int>;
class Solution {
    struct compare{
        bool operator()(auto a, auto b){
            auto [e1,p1,u1]= a;
            auto [e2,p2,u2]= b;
            if(abs(e1-e2)<1e-9){
                return p1>p2 ;
            }
            return e1<e2;
        }
    };
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n=items.size();
        vector<int> freq(n+1,0);
        vector<int> freebies(n+1,0);
        int minPrice=INT_MAX;
        priority_queue<t,vector<t>,compare> pq; 
        for(int i=0;i<n;i++){
            freq[items[i][0]]++;
            minPrice = min(minPrice, items[i][1]);
        }
        for(int f=1;f<=n;f++){
            if(freq[f]>0){
                for(int m=f;m<=n;m=m+f){
                    freebies[f]+=freq[m]; //like harr factor ke liye uske compatible kitne hai.
                }
            }
        }

        for(int i=0;i<n;i++){
            int units=freebies[items[i][0]]-1;
            if(units>0){
                double perunit = 2.0/items[i][1] ; 
                pq.push({perunit,items[i][1],units});
            }
        }

        int cnt=0;
        while(!pq.empty() && budget>0){
            auto [u,p,c]= pq.top();
            pq.pop();
            if(u< 1.0/minPrice) break;
            int afford= budget/p ; 
            int buy = min(afford, c);
            if(buy>0){
                cnt+= buy*2;
                budget = budget - buy*p ;
            }
        }

        cnt+= budget/minPrice ;

        return cnt;
        
    }
};
