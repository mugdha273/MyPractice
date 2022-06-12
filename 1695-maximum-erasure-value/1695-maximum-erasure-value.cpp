class Solution {
public:
    int maximumUniqueSubarray(vector<int>& v) {
        int l=0, r=0, sum=0, maxSum = INT_MIN;
		unordered_map<int, int> m;

		while(r< v.size())
		{
			sum += v[r];
			m[v[r]]++;

			while (m[v[r]] > 1)
			{
				sum -= v[l];
				m[v[l]]--;
				l++;
			}


			maxSum = max(maxSum, sum);
            r++;
		}

		return maxSum;
    }
};