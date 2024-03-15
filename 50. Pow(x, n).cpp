class Solution {
public:
    /*
    Time: (log(n))
    Space: log(n) (recursive stack)
    
    Use bigmod approach of dividing the exponent in half in every recursive call
    since, a^k = a^(k/2) * a^(k/2) 
    As there's overlapping subproblem, store the intermediate result in a dp table
    */

    unordered_map<long long,double> dp; 

    double bigPow(double x, long long n){
        if(n==1)  return x;
        if(dp.count(n))  return dp[n];
        
        double rem = (n%2==0) ? 1.0 : x; //x^5 = x^2 * x^2 * x
        return dp[n] = bigPow(x, n/2) * bigPow(x, n/2) * rem;
    }

    double myPowIterative(double x, long long n){
        //edge case
        if(n==0)  return 1;

        if(n<0)  x = 1/x;
        n = abs(n);

        double res = 1;
        double exp = x;

        while(n>1){
            if(n%2 == 1)  res *= exp; //do on paper - when exp^5 = exp^2 * exp^2 * exp (that's why for every odd, we multiply the current exp to res)
            exp = exp*exp;

            n /= 2;
        }

        return res * exp;
    }

    double myPow(double x, long long n) {
        return myPowIterative(x, n);

        /*
        //edge case
        if(n==0)  return 1;

        if(n<0)  x = 1/x;
        n = abs(n);

        return bigPow(x,n);
        */
        
    }
};
