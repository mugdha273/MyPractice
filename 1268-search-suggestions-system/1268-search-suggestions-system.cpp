class Solution {
public:
    
//     static bool my_compare(string a, string b)
// {
//     // Check if a string is present as
//     // prefix in another string, then
//     // compare the size of the string
//     // and return the larger size
//     if (a.compare(0, b.size(), b) == 0
//         || b.compare(0, a.size(), a) == 0)
 
//         return a.size() > b.size();
 
//     // Else return lexicographically
//     // smallest string
//     else
//         return a < b;
// }
    vector<string>helper(string s, vector<string>&pro)
    {
        vector<string>vec;
        int i= s.length();
        
        for(auto x:pro)
        {
            if(x.length()>=s.length())
            {
                string k= x.substr(0,i);
                if(k==s) vec.push_back(x);
            }
            if(vec.size()==3) return vec;
            
        }
        
        return vec;
        
    }
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        vector<string>pre;
        vector<vector<string>>ans;
        
        for(int i=1; i<=searchWord.length(); i++)
        {
            pre.push_back(searchWord.substr(0,i));
        }
        for(int i=0; i<pre.size(); i++)
        {
            vector<string>v1= helper(pre[i], products);
            // sort(v1.begin(), v1.end(), my_compare);
            ans.push_back(v1);
        }
        // for(auto x:products) cout<<x<<endl;
        
        return ans;
    }
};