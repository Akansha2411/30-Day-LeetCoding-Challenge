/*
Given two strings S and T, return if they are equal when both are typed into empty text editors. # means a backspace character.

Example 1:
Input: S = "ab#c", T = "ad#c"
Output: true
Explanation: Both S and T become "ac".

Example 2:
Input: S = "ab##", T = "c#d#"
Output: true
Explanation: Both S and T become "".

Example 3:
Input: S = "a##c", T = "#a#c"
Output: true
Explanation: Both S and T become "c".

Example 4:
Input: S = "a#c", T = "b"
Output: false
Explanation: S becomes "c" while T becomes "b".

Note:
1 <= S.length <= 200
1 <= T.length <= 200
S and T only contain lowercase letters and '#' characters.

*/

/*

Approach:
1. Loop string S in reverse. Maintain a variable 'skip' to count the number of chacters that need to be skipped. Maintain a vector for the final string.
2. For every '#' that is observed, increase the skip variable. For every alphanumeric character that is observed, check if skip > 0. If yes, skip that character and decrement skip, else add it to the final vector.
3. Loop strin T in reverse, follow step 2 but for every character that doesn't get skipped, instead of pushing it into a vector, simply compare it to its corresponding character in the final vector for String S. If the condition satisfies, continue else, return false
4. Return true at the end if all the comparison in step 3 pass 


*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool backspaceCompare(string S, string T) {
        vector<char> res;
        int skip = 0;
        int resSize = 0;
        int k = 0;
        for(int i=S.size()-1;i>-1;i--){
            if(S[i]=='#')
                skip++;
            else if(skip>0)
                skip--;
            else{
                resSize++;
                res.push_back(S[i]);
            }            
        }
        
        skip = 0;
        for(int i=T.size()-1;i>-1;i--){
            if(T[i]=='#')
                skip++;
            else if(skip>0)
                skip--;
            else{
                if(k<resSize && res[k]==T[i])
                    k++;
                else
                    return false;
            }
        }
        
        if(k!=resSize)
            return false;
        return true;
    }
};

int main()
{
    Solution obj;
    cout<<obj.backspaceCompare("ab#c#","ad#c");
    return 0;
}


/* class Solution {
public:
    bool backspaceCompare(string S, string T) 
    {
        stack<char>Ss;
        stack<char>St;
        //if(Ss.empty() && S[0]!='#')Ss.push(S[0]);
        for(int i=1;i<S.size();i++)
        {
            if(S[i] != '#')Ss.push(S[i]);
            else if(!Ss.empty() && S[i] == '#')Ss.pop();
            //else if(Ss.empty() && S[i]!='#')Ss.push(S[i]);
            
        }
        //if(St.empty() && T[0]!='#')St.push(T[0]);
        for(int i=1;i<T.size();i++)
        {
            if(T[i] != '#')St.push(T[i]);
            else if(!St.empty() && T[i] == '#')St.pop();
            //else if(St.empty() && T[i]!='#')St.push(T[i]);
            
        }
        bool flag = true; 
  
    // Check if size of both stacks are same 
        if (St.size() != Ss.size()) 
        { 
            flag = false; 
            return flag; 
        } 

        // Until the stacks are not empty 
        // compare top of both stacks 
        while (Ss.empty() == false) 
        { 
            // If the top elements of both stacks 
            // are same 
            if (St.top() == Ss.top()) 
            { 
                // Pop top of both stacks 
                //cout<<Ss.top()<<" "<<St.top();
                Ss.pop(); 
                St.pop(); 
            } 
            else 
            { 
                // Otherwise, set flag to false 
                flag = false; 
                break; 
            } 
        } 
        return flag;
        
    }
};
