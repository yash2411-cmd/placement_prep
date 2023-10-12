// leetcode hard- daily challenge
#include<bits/stdc++.h>
using namespace std;

/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        
        int left = 1;
        int right = n-2;
        while(left != right){
            int mid = (left + right)/2;
            if(mountainArr.get(mid) < mountainArr.get(mid+ 1)){
                left = mid +1;
            }
            else{
                right = mid;
            }
        }
        int peak = left;

        left = 0;
        right = peak;
        while(left != right){
            int mid = (left + right)/2;
            if(mountainArr.get(mid) < target){
                left = mid +1;
            }
            else{
                right = mid;
            }
        }

        if(mountainArr.get(left) == target){
            return left;
        }
        left = peak + 1;
        right = n-1;
        while(left != right){
            int mid = (left + right)/2;
            if(mountainArr.get(mid) > target){
                left = mid +1;
            }
            else{
                right = mid;
            }
        }
        if(mountainArr.get(left) == target){
            return left;
        }
        return -1;




    }
};


int main()
{
 return 0;
}