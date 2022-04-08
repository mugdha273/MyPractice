class Solution {
public:
    
    void mergeSort(vector<int>& nums, int l, int r)
    {
        if(l<r)
        {
            int mid = l + (r-l)/2;
            mergeSort(nums, l, mid);
            mergeSort(nums,mid+1, r);
            
            merge(nums, l, mid, r);
        }
    }
    
    void merge(vector<int>&nums, int l, int mid, int r)
    {
        int n1 = mid-l+1;
        int n2= r - mid;
        
        vector<int>v1(n1);
        vector<int>v2(n2);
        
        for(int i=0; i<n1; i++)
        {
            v1[i]= nums[l+i];
        }
        
        for(int i=0; i<n2; i++)
        {
            v2[i] = nums[mid+1+i];
        }
        
        int i=0, j=0, k=l;
        
        while(i<n1 && j<n2)
        {
            if(v1[i]<= v2[j])
            {
                nums[k++]= v1[i++];
            }
            else
            {
                nums[k++] = v2[j++];
            }
        }
        
        while(i<n1)
        {
            nums[k++]= v1[i++];
        }
        while(j<n2)
        {
            nums[k++]= v2[j++];
        }
        
    }
    
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size()-1);
        return nums;
    }
};