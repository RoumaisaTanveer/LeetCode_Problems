 #include <bits/stdc++.h>
using namespace std;
vector<int> findSubstring(string s, vector<string>& words) {

      vector<int> result;
      if(words.empty()|| s.empty())
          return result;
      int wordLen = words[0].size(); //all have same length
      int stringCount = words.size(); //number of strings in words vector
      int totalLen = wordLen * stringCount; //conactAllstrings of size wordLen
      int sLen = s.size();  //input string

      unordered_map<string, int> wordMap;
      for(const string &word:words){
          wordMap[word]++; //increase frequency of that word

      }
      for (int i = 0; i <= sLen - totalLen;i++){
          unordered_map<string, int> seen;
          int j = 0;
          while(j<stringCount){
              string word = s.substr(i + j * wordLen, wordLen); // the next word start wordLen charcters after the first so mulitply by j

              if(wordMap.find(word)==wordMap.end())
                  break;
              seen[word]++;
              if(seen[word]>wordMap[word])
                  break;
              j++;

          }
          if(j == stringCount){
              result.push_back(i);
          }
      }
      return result;
  }
int main() {
    return 0;
}