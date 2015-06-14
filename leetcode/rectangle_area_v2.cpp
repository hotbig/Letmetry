#include<iostream>
#include<string>

using namespace std;

class Solution{
    public:
        int computeArea(int A, int B, int C, int D, int E, int F, int G, int H){
            int x=0;
            int y=0;

            if(E>=A && E<C)
            {
                x = (C>G)?(G-E):(C-E);
            }
            else if(A>=E && A<G)
            {
                x = (C>G)?(G-A):(C-A);
            }

            if(B>=F && B<H)
            {
                y = (D>H)?(H-B):(D-B);
            }
            else if(F>=B && F<D)
            {
                y = (H>D)?(D-F):(H-F);
            }
            return (x*y);
        }
};


int main()
{
    Solution s;

    cout << s.computeArea(-3, 0, 3, 4, 0, -1, 9, 2) << endl;
    cout << s.computeArea(-3, 0, 3, 4, 0, -1, 9, 4) << endl;
    cout << s.computeArea(-3, 0, 0, 4, 0, -1, 9, 4) << endl;
    cout << s.computeArea(-3, 0, -1, 4, 0, -1, 9, 4) << endl;
    cout << s.computeArea(-2, -2, 2, 2, -2, -2, 2, 1) << endl;
    return 0;
}
