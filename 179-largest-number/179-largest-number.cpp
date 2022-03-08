bool cmp(string a,string b){
    // cout<<a<<" and "<<b<<endl;
    return a+b > b+a;
}

class Solution {
    
public:
    
    string largestNumber(vector<int>& nums) {
        
        vector<string> vec;
		
        for(int i : nums)  vec.push_back(to_string(i));
        
        sort(vec.begin(), vec.end(), cmp);
        
        
        string s="";
        for(auto x: vec) s+=x;
        
        return s[0]=='0'? "0" : s;
        
    }
};