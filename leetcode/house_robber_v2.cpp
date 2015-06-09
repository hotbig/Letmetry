#include<iostream>
#include<cstring>
#include<cstdlib>
#include<set>
#include<string>
#include<vector>

using namespace std;

int  g_cur_max[1000];
int* g_start=NULL;

int rob(int* nums, int size)
{
    if(g_start == NULL)
    {
        g_start = nums;
        memset(g_cur_max, -1, sizeof(g_cur_max));
    }
            
    if(size == 0)
        return 0;
    else if(size == 1)
    {
        g_cur_max[(nums-g_start)] = nums[0];
        return nums[0];
    }
    else if(size == 2)
    {
        int max = nums[0]>nums[1] ? nums[0]:nums[1];       
        g_cur_max[(nums-g_start)] = max;
        return max;
    }
    else if(size == 3)
    {
        int a = nums[0]+nums[2];
        int b = nums[1];
        int max = a>b?a:b;
        g_cur_max[(nums-g_start)] = max;
             
        return max;
    }
    else
    {
        int a = 0;
        int b = 0;
        if(g_cur_max[(nums-g_start)+2] != -1)
        {
            a = nums[0] + g_cur_max[(nums-g_start)+2];
        }
        else
        {
            int cur_max = rob(nums+2, size-2);
            a = nums[0] + cur_max;
            g_cur_max[(nums-g_start)+2] = cur_max;
        }

        if(g_cur_max[(nums-g_start)+3] != -1)
        {
            b = nums[1] + g_cur_max[(nums-g_start)+3];
        }
        else
        {
            int cur_max = rob(nums+3, size-3);
            b = nums[1] + cur_max;
            g_cur_max[(nums-g_start)+3] = cur_max;
        }
                
        if(nums == g_start)
            g_start = NULL;
        return a>b?a:b;
    }        
}



int main()
{
    
#if 1
    int arr1[] = {226,174,214,16,218,48,153,131,128,17,157,142,88,
        43,37,157,43,221,191,68,206,23,225,82,54,118,111,46,80,49,
        245,63,25,194,72,80,143,55,209,18,55,122,65,66,177,101,63,
        201,172,130,103,225,142,46,86,185,62,138,212,192,125,77,
        223,188,99,228,90,25,193,211,84,239,119,234,85,83,123,120,
        131,203,219,10,82,35,120,180,249,106,37,169,225,54,103,55,
        166,124};

    //cout << rob(arr1, sizeof(arr1)/sizeof(int)) << endl;
    cout << rob(arr1, sizeof(arr1)/sizeof(int)) << endl;
    int arr3[]={1,3,1,3,100};
    cout << rob(arr3, 5) << endl;
    

#endif    
    return 0;
}
