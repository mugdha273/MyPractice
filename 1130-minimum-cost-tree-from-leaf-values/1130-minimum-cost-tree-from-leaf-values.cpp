class Solution {
public:
    int mctFromLeafValues(vector<int>& a) {
        
        int sum=0;
        // int n = a.size();
        
        while(a.size()>1)
        {
            int idx = min_element(a.begin(), a.end()) -a.begin();

            if(idx>0 && idx<a.size()-1){
                sum+=(min(a[idx]*a[idx-1],a[idx]*a[idx+1]));
            } 
            else if(idx==0){

                sum+= a[idx]*a[idx+1];
            } 
            else if(idx==a.size()-1){
                sum+= a[idx]*a[idx-1];
  
            } 

            vector<int>::iterator it;                         
            it = a.begin()+idx;
            a.erase(it);

        }
        
        return sum;
    }
};