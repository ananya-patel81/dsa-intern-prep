#include <vector>
#include <queue> // 1. Don't forget this!

using namespace std; // Allows you to omit 'std::'


long long int minimumCostToConnectSticks(vector<int> &arr) {
     // Write your Code here.
     priority_queue<int,vector<int>,greater<int>> pq;
     for(int num : arr){
          pq.push(num);
     }
     long long int cost=0;

     while(!pq.empty()){
          int stick1=pq.top();
          pq.pop();
          if(!pq.empty()){
               int stick2=pq.top();
               pq.pop();
               int newStick=stick1+stick2;
               cost+=newStick;
               pq.push(newStick);

          }
          else{
               return cost;
          }
          
     }

     return cost;
}
