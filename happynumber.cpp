 #include <bits/stdc++.h>
using namespace std;

 bool isHappy(int n) {
     unordered_set<int> seen;
     if(n!=1 && seen.find(n)==seen.end()){
         seen.insert(n);
         int sum = 0;
         while(n>0){
             int digit = n % 10;
             sum += digit + digit;
             n /= 10;
         }
         n = sum;
     }
     return n == 1;
    }
int main() {
    return 0;
}