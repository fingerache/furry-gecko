
#include <iostream>
#include <string>
#include <map>
#include <vector>

// date: 30-Oct-2022
// https://leetcode.com/problems/longest-common-prefix/

using namespace std;

string longestCommonPrefix(vector<string>& strs){
        if(strs.size() == 1){
            return strs[0];
        }
       
        int pos = -1;
        bool flag = true;

        if(strs[0].length() == 0 || strs[1].length() == 0)
            return "";
        
        pos = strs[0].length() > strs[1].length() ? strs[1].length(): strs[0].length();
        pos = pos - 1;
        int k=1;
        for (; k<strs.size(); k++){
            int npos = -1;
            int x = strs[k].length() > strs[k-1].length() ? strs[k-1].length(): strs[k].length();
            pos = x-1 < pos ? x-1: pos;
            flag = true;
            for (int i = 0; (i<=pos)&&flag ; i++){
                flag = strs[k][i] == strs[k-1][i];
                npos = flag ? i: npos;
            }
            if(npos == -1){
                return "";
            }
            pos = npos;
        }
        
        string ret_val = "";
        for (int i=0; i<=pos; i++)
            ret_val+= strs[k-1][i];
        
            return ret_val;
}


int main(){
    // start: code-init 
    vector<string> strs;

    strs.push_back("abca");
    strs.push_back("aba");
    strs.push_back("aaab");
    // end: code-init 

    // code from here:
    string s = longestCommonPrefix(strs);
    cout<<"\n output is:"<<s<<endl;

}