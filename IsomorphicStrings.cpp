//Problem
/*
    Given two strings s and t, determine if they are isomorphic.
    Two strings s and t are isomorphic if the characters in s can be replaced to get t.
    All occurrences of a character must be replaced with another character while preserving the order of characters. 
    No two characters may map to the same character, but a character may map to itself.    
*/

//Tools
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>

//Solution
// O(N) Time, O(N) Space.
class Solution {
public:
    bool isIsomorphic(std::string s, std::string t) {
        //Edge Case
        if(s.size() != t.size()){
            return false;
        }

        std::unordered_map<char, char> charMap;
        std::unordered_set<char> charSet;
        for(int i = 0; i < s.size(); i++){
            if(charMap.count(s[i])){
                if(charMap[s[i]] != t[i]){
                    return false;
                }
            } else if(charSet.count(t[i])){
                return false;
            } else {
                charSet.insert(t[i]);
                charMap.insert(std::pair<char, char>(s[i], t[i]));
            }
        }
        
        return true;
    }
};