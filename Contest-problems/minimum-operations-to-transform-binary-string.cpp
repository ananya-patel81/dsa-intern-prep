class Solution {
public:
        int minOperations(string s1, string s2) {
        if (s1 == "1" && s2 == "0") {
            return -1;
        }
        int res = 0, n = s1.length();
        for (int i = 0; i < n; i++) {
            if (s1[i] == s2[i]) continue;
            res++; //agar s1[i] 0 hota toh bhi usko 1 hone mein ek aur step lagta, aur agar s1[i]=1 hai, toh usko zero hone ke liye
          //ek step toh lagega hi, aur ek aur chahiye ke nahi woh aage dikhega, agar uske baad kuch nahi hai, matlab this is something
          //like 11->10 (since isse pehle ka change nahi karna and current(in this case the second one) 1 ko 0 karna hai
          //karne ke liye 2 steps total, ya phir 01->00 ke liye bhi 2 steps total lagte toh uss hisaab se. And agar yeh last index nahi hai and
          //we can check the next index, then toh phir agar next index 1 bhi hai toh yeh bas ek hi step, jo hum gin chuke hai, usme 0 mein
          //ho jaayega convert, warna agle 0 ko 1 karke dono ko 11 se 00 karne ke liye ek aur step so total 2 steps, and we add the next step 
          // through res += s1[i + 1] == '0';, and since dono case mein s1[i+1] =0 hi hota hai at the end, hence the s1[i+1]=0;
          
            if (s1[i] == '1') {
                if (i == n - 1) { // it's like 11 se 10 jaane mein 2 steps lagte hai in total 
                    res++;
                } else { // 
                    res += s1[i + 1] == '0';
                    s1[i + 1] = '0';
                }
            }
        }
        return res;
    
    }
};
