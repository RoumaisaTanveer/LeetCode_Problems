#include <iostream>
#include <vector>

using namespace std;

vector<int> reverseArray(vector<int> a) {
    int left = 0, right = a.size() - 1;
    while (left < right) {
        swap(a[left], a[right]);
        left++;
        right--;
    }
    return a;
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
 vector<int>reversedArray= reverseArray(array);
 cout << "Reversed array: ";
    for(int i = 0; i < reversedArray.size(); i++) {
        cout << reversedArray[i] << " ";
    }
    cout << endl;

    return 0;
}
