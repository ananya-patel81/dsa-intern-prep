class Solution {
    bool is_prime(int num){
        // vector<int> factors;
        // factors.push_back(1);
        // int n = num;
        // int i = 2;
        // while(n>1 && i<=num){
        //     if(n%i == 0){
        //         n= n/i;
        //         factors.push_back(i);
        //     }
        //     else i++;
        // }
    
        // return (factors.size()==2);
        if(num==1) return false;
        if(num<=3) return true;
        if(num%2==0 || num%3==0) return false;
        for(int i=5;i*i<=num;i+=6){
            if((num%i)==0 || (num%(i+2))==0) return false;
        }
        return true;
        
        
    }
    int make_prime(int num){
        if(num==1) return 1;
        if(num%2==0 && is_prime(num+1)) return 1;
        int ops=(num%2==0) ? 1 : 0;
        if(num%2==0) num=num+1;
        while(!is_prime(num)){
            num+=2;
            ops+=2;
        }
        return ops;
    }

    int make_not_prime(int num){ //O(1)
        if(num==2) return 2;
        if(num!=2) return 1;
        return 0;
        
    }
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int tot_ops=0;
        for(int i=0;i<n;i++){
            if(i%2==0){
                if(is_prime(nums[i])) continue;
                else tot_ops+=make_prime(nums[i]);
            }
            else{
                if(!is_prime(nums[i])) continue;
                else tot_ops+=make_not_prime(nums[i]);
            }
        }
        return tot_ops;
        // cout<<make_prime(1)<<endl;
        // cout<<make_not_prime(2)<<endl;
        // if(is_prime(4)){
        //     cout<<"true";
        // }
        // else cout<<"false";
        
        // return 0;
        
    }
};
