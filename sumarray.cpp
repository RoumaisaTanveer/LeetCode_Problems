#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int simpleArraySum(vector<int> ar) {

    int sum ;
    for(int i=0;i<ar.size();i++){
       sum +=ar[i];
    }
    return sum;
}
int main() {
    int n;
    cout<<"Enter number of elements:  "<<flush;
    cin>>n;
    cout<<"Enter "<<n<<" elements: "<<endl;
    vector<int> array(n);
    for(int i=0;i<n;i++){
    cin>>array[i];
    }
   
    int sum = simpleArraySum(array);
    cout<<sum;
   
    
    cout<<endl;
    return 0;
}