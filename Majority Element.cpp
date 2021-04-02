//Problem =========================
/*
    The majority element is the element that appears more than ⌊n / 2⌋ times. 
    You may assume that the majority element always exists in the array.
*/

//Tools
#include <vector>
#include <unordered_map>
#include <utility>

//Naive Solution:
// O(N) Time, O(N / Unique Items) Space
// Keeps count of every unique item in list.
class SolutionNaive {
public:
    int majorityElementNaive(std::vector<int>& nums) {
        //Edge
        if(nums.size() == 1){
            return nums[0];
        }
        std::unordered_map<int, int> count;
        for(int num : nums){
            if(count.count(num)){
                count[num]++;
                if(count[num] > nums.size()/2){
                    return num;
                }
            } else {
                count.insert(std::pair<int, int>(num, 1));
            }
        }
        return 0;
    }
};

//Best Solution:
// O(N) Time, O(1) Space
// Majority will always have a count >= 1.
class Solution {
public:
    int majorityElement(std::vector<int>& nums) {
        //Edge
        if(nums.size() == 1){
            return nums[0];
        }
        int majority = 0;
        int count = 1;
        for(int i = 0; i < nums.size(); i++){
            if(nums[majority] == nums[i]){
                count++;
            } else {
                count--;
                if(!count){
                    majority = i;
                    count = 1;
                }
            }
        }
        return nums[majority];
    }
};