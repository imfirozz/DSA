class Solution {
public:
    bool checkDivisibility(int n) {
      vector<int>ans;
      int N = n;
        while(n)
        {
            ans.push_back(n%10);
            n/=10;

        }
       long long sum = 0, product = 1;

       for(int i = 0; i<ans.size(); i++)
       {
        sum+=ans[i];
        product*=ans[i];
       }
      long long totalSum = sum+product;
      int div = n%totalSum;
    //   cout<<totalSum<<endl;
    //   cout<<div;
    if (N%totalSum)
    return 0;
    return 1;
    }
};