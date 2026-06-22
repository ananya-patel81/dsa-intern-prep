class Solution {
private:
    vector<int> calcRange(int ind, int v,int n){
        int mini=max(0,ind-v);
        int maxi=min(n-1,ind+v);
        return {mini,maxi};
    }

    vector<int> calcRange2(int ind, int n){
        int mini=max(0,ind-1);
        int maxi=min(n-1,ind+1);
        return {mini,maxi};
    }
public:
    int minLights(vector<int>& lights) {
        //hash map of index to range of illumination
        // visited array to see what all is illuminated, if all covered through range then good
        int n=lights.size();
        
        vector<int> vis(n,0);
        vector<int> diff(n,0);
        for(int i=0;i<n;i++){
            if(lights[i]==0) continue;
            else{
                vector<int> newR=calcRange(i,lights[i],n);
                diff[newR[0]]++;
                if(newR[1]+1<n) diff[newR[1]+1]--;
            }
        }
        int active=0;
        for(int i=0;i<n;i++){
            active+=diff[i];
            vis[i]=active;
        }
        int addbulb=0;
        // for(int i=0;i<n;i++){
        //     if(vis[i]==0){
        //         addbulb++;
        //         vector<int> newR=calcRange2(i,n);
        //         for(int k=newR[0];k<=newR[1];k++){
        //             vis[k]++;
        //         }
                
        //     }
        // }
        for(int i=0;i<n;i++){
            if(vis[i]>0){
                
                continue;
            }
            int len=0;
            while(i<n && vis[i]==0){
                len++;
                i++;
            }
            addbulb+=(len+2)/3;
        }
        return addbulb;
        
    }
};
