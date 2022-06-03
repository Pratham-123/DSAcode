Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

Example 1:

Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
Example 2:

Input: digits = ""
Output: []
Example 3:

Input: digits = "2"
Output: ["a","b","c"]
 

Constraints:

0 <= digits.length <= 4
digits[i] is a digit in the range ['2', '9'].
  
  *****************************SOLUTION************************
  
  class Solution {
public:
    void solve(string digit,string output, int index, vector<string>&ans, string mapping[]){
        //if we have reached to the last rec call, we will push the output
        //in the final ans vector and return
        if(index>=digit.length()){
            ans.push_back(output);
            return;
        }
        
        int number = digit[index] - '0';
        //saving the string present on that corresponding integer value
        string value = mapping[number];
        
        //pushing one by one in the output array and making the next rec call
        for(int i=0;i<value.length();i++){
            output.push_back(value[i]);
            solve(digit, output, index+1, ans, mapping);
            //when we will return from the rec call, we will remove the previously added
            // character
            output.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.length()==0){
            return ans;
        }
        int index = 0;
        string output;
        string mapping[10] = {"", "", "abc", "def", "ghi","jkl","mno","pqrs","tuv","wxyz"};
        solve(digits, output, index, ans, mapping);
        return ans;
        
    }
};
