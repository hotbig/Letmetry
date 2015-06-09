#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int rob1(int* nums, int numsSize)
{
    int preNoRob = 0;
    int preYesRob = 0;

    for(int i = 1; i <= numsSize; i++)
    {
        int temp = preNoRob;
        preNoRob = preYesRob>preNoRob?preYesRob:preNoRob;
        preYesRob = nums[i-1] + temp;
    }

    return preNoRob>preYesRob?preNoRob:preYesRob;
}

int main()
{
    int arr[]={1,1,1,1};
    printf("%d\n", rob(arr, 4));
    printf("%d\n", rob1(arr, 4));

    int arr5[]={183,219,57,193,94,233,202,154,65,240,97,234,100,249,186,66,90,238,168,128,177,235,50,81,185,165,217,207,88,80,112,78,135,62,228,247,211};

    printf("%d\n", rob(arr5, sizeof(arr5)/sizeof(int)));
    printf("%d\n", rob1(arr5, sizeof(arr5)/sizeof(int)));
    return 0;
}

