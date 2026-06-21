class Solution {
private:
    int max4(int a,int b,int c,int d){
        int maxi=a;
        if(b>maxi) maxi=b;
        if(c>maxi) maxi=c;
        if(d>maxi) maxi=d;
        return maxi;

    }
    int calc(int s1, int s2, string& moves){
        int sum=0;
        for(int i=0;i<moves.size();i++){
            if(moves[i]=='U'){
                if(s2>0) sum+=1;
                else sum-=1;
            }
            else if(moves[i]=='D'){
                if(s2>0) sum-=1;
                else sum+=1;
            }
            else if(moves[i]=='L'){
                if(s1>0) sum-=1;
                else sum+=1;
            }
            else if(moves[i]=='R'){
                if(s1>0) sum+=1;
                else sum-=1;
            }
            else{
                sum+=1;
            }
        }

        return sum;
    }
public:
    int maxDistance(string moves) {
        int max_dist=0;
        int xy1=calc(1,1,moves); //x+y
        int xy2=calc(-1,-1,moves); //-x-y
        int xy3=calc(1,-1,moves); //x-y
        int xy4=calc(-1,1,moves); //-x+y
        return max4(xy1,xy2,xy3,xy4);
        
    }
};
