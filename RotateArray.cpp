// Problem
/*
    Given an array, rotate the array to the right by k steps, where k is non-negative.
*/

//Tools
#include <bits/stdc++.h>
#include <iostream>

// Naive Solution 
// O(N) Time, O(1) Space
// Incrementally Swapping
class SolutionNaive {
public:
    static void printArray(std::vector<int> nums){
        std::cout << "[";
        for(int i = 0; i < nums.size(); i++){
            if(i != nums.size()-1){
                std::cout << nums[i] << ", ";
            } else {
                std::cout << nums[i];
            }
            
        }
        std::cout << "]" << std::endl;
    }
    static void rotateNaive(std::vector<int>& nums, int k) {
        //Edge Case
        if(nums.size() > 1 && k > 0){
            if(nums.size() > k*2){
                //Rotate
                int lastIndex = nums.size()-1;
                int i = k-1;
                int j = lastIndex;
                std::cout << "Rotating ====================" << std::endl;
                while(j > lastIndex-k){
                    std::swap(nums[i], nums[j]);
                    i--;
                    j--;
                    printArray(nums);
                }
                //Organize
                i = k;
                j = nums.size()-k;
                std::cout << "Organize ====================" << std::endl;
                while(i < lastIndex){
                    if(j >= nums.size()){
                        if(lastIndex - i < k && nums.size()%k != 0){
                            k = k - ((lastIndex - i) + 1);
                        } else if (lastIndex - i < k && nums.size()%k == 0) {
                            break;
                        }
                        j = nums.size()-k;
                    }
                    std::swap(nums[i], nums[j]);
                    printArray(nums);
                    i++;
                    j++;
                }
            } else {
                //Rotate
                for(int i = 0; i < k; i++){
                    nums.emplace(nums.begin(), nums[nums.size()-1]);
                    nums.pop_back();
                }
            }
            
        }
    }
};

//Best Solution
//O(N) Time, O(1) Space
//Reversing Subarrays

class Solution {
public:
    static void reverse(std::vector<int>& nums, int start, int end){
        while(end > start){
            std::swap(nums[start], nums[end]);
            start++;
            end--;
        }
    }
    static void rotate(std::vector<int>& nums, int k) {
        if(nums.size() > 1 && k > 0){
            if(nums.size() > k){
                reverse(nums, 0, nums.size()-1);
                reverse(nums, 0, k-1);
                reverse(nums, k, nums.size()-1);
            } else {
                for(int i = 0; i < k; i++){
                    nums.emplace(nums.begin(), nums[nums.size()-1]);
                    nums.pop_back();
                }
            }
        }
        
    }
};

int main(){
    std::vector<int> data1 = {1,2,3,4,5,6};
    std::vector<int> data2 = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49};
    int k1 = 2;
    int k2 = 10;
    Solution::rotate(data2, k2);
    // std::cout << data2.size() << std::endl;
    // std::cout << data1.size() << std::endl;
    return 0;
}
