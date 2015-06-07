#include<iostream>
#include<string>
#include<cmath>

using namespace std;

class Solution{
    public:
        bool isPrime(int n){
            if((n % 2)  == 0)
                return false;

            int sqrt_of_n = sqrt(double(n));
            for(int i = 3; i <= sqrt_of_n; i=i+2)
                if(n % i == 0)
                    return false;

            return true;
        }

        int countPrimes(int n){
            int count = 1;
            if(n <= 1)
                count = 0;

            for(int i = 3; i < n; i=i+2)
            {
                if(isPrime(i)) 
                {
                    count++;
                }
            }

            return count;
        }
};


int main()
{
    Solution s;
    cout << s.countPrimes(2) << endl;

    return 0;
}
