class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {
       if(arr.size()==1)
       return arr[0];
        for(int i = 0; i<arr.size(); i = i+2)
        {
        if(arr[i]!=arr[i+1])
          return arr[i];
        }

        return {};
        
    }
};