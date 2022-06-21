class Solution {
public:
    string decodeString(string s) {
        if(s.size()<=3) return s;
    int i=0,ld=0,rd=0,lb,rb;
    while(i<s.size()){
        if (isalpha(s[i])) i++;
        else {
            ld=i;
            while(s[i]!='[') i++;
            string pre = s.substr(0,ld);
            int k = stoi(s.substr(ld,i-ld));
            i++;
            lb = i;
            int cnt=1;
            while(cnt!=0){
                if (s[i]=='[') cnt++;
                else if (s[i]==']') cnt--;
                i++;
            }
            rb=i-2;
            string curDuplicate = decodeString(s.substr(lb,rb-lb+1));
            while(k>0){
                pre+=curDuplicate;
                k--;
            }
            pre+=decodeString(s.substr(i));
            return pre;
        }
    }
    return s;
        
    }
};