#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void previous_permutation(vector<int> &nums) {
  int n = nums.size();
  if (n == 0) return;
  int i = n - 2;
  while (nums[i] <= nums[i + 1]) {
    --i;
  }
  if (i < 0) {
    reverse(nums.begin(), nums.end());
    return;
  }
  int j = n - 1;
  while (nums[i] <= nums[j]) {
    j--;
  }
  swap(nums[i], nums[j]);
  int k = i + 1;
  j = n - 1;
  while (k < j) {
    swap(nums[k], nums[j]);
    ++k;
    --j;
  }
}

int main() {
  vector<int> a;
  a.push_back(1);
  a.push_back(2);
  a.push_back(3);
  previous_permutation(a);
  for (int i = 0; i < a.size(); i++) {
      cout<<a[i];
  }
  cout<<endl;
  a.clear();
  a.push_back(2);
  a.push_back(1);
  a.push_back(3);
  previous_permutation(a);
  for(int i = 0; i < a.size(); i++) {
      cout<<a[i];
  }
  cout<<endl;
  return 0;
}
