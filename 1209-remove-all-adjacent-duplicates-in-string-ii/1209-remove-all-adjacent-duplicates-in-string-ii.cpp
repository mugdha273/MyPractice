class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<int,int>> st;
        int i=0;
        int n=s.size();
        while(i<n)
        {
            if((!st.empty())) 
            {
                if(s[st.top().first]==s[i])  
                {
                    if(st.top().second+1==k)  
                    {
                        int temp=k-1;
                        while(temp--)
                        {
                            st.pop();
                        }
                    }
                    else   
                    {
                        st.push({i,st.top().second+1});
                    }
                }
                else  
                {
                    st.push({i,1});
                }
            }
            else
            {
                st.push({i,1});
            }
            i++;
        }
  
        string str="";
        while(!st.empty())
        {
            str+=s[st.top().first];
            st.pop();
        }
        reverse(str.begin(),str.end());
        return str;
        
    }
};