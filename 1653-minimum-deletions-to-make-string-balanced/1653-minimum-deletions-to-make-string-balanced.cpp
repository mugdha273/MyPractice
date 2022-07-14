class Solution {
public:
    //recursive solution
//     int helper(int i, int j, vector<int>&a, vector<int>&b)
//     {
//         if(i<0||j>=b.size()||a[i]<b[j]) return 0;
//         int t1= helper(i-1,j,a,b)+1;
//         int t2= helper(i,j+1,a,b)+1;
//         int t3= helper(i-1,j+1,a,b)+2;
//         return min({t1,t2,t3});
//     }
    
//     int minimumDeletions(string s) {
//         vector<int>a;
//         vector<int>b;
//         for(int i=0; i<s.size(); i++)
//         {
//             if(s[i]=='b') b.push_back(i);
//             if(s[i]=='a') a.push_back(i);
//         }
//         for(auto x:a) cout<<x<<" ";
//         cout<<endl;
//         for(auto x:b) cout<<x<<" ";
//         cout<<endl;
//         return helper(a.size()-1, 0,a,b);
//     }
    
    //optimized solution
     int minimumDeletions(string s) {
        vector<int>pref , suff ;
        int a = 0 ;
        for(int i = 0 ; i < s.size() ; ++i ){
            a += s[i] == 'a' ;
            pref.push_back(a) ;
        }
        int b = 0 ;
        for(int i = s.size() - 1 ; i >= 0 ; --i ){
            b += s[i] == 'b' ;
            suff.push_back(b) ;
        }
        reverse(begin(suff),end(suff)) ; 
        
        int dels = s.size() ;
        for(int i = 0 ; i < s.size() ; ++i ) dels = min(dels,(int)s.size() - pref[i] - suff[i]) ;
        return dels ;
    }
};