# include <iostream>
# include <limits.h>
using namespace std;

/*
http://stackoverflow.com/questions/9007993/algorithm-to-find-high-low-numbers-with-at-most-1-5n-comparisons

high/low numbers with at most 1.5n comparisons

intuitive solution requries O(2n) comparisons. 1.5n solution need O(n) extra space
*/
pair<int, int> go(int A[], int n){ // A is pass as an pointer, you can not use sizeof(A)/sizeof(A[0]) to get size of A
  int max_every_two[n/2], min_every_two[n/2];

  // O(n/2) comparison
  for(int i = 0; i < n/2; i++) {
    if(A[i] > A[n-1-i]) {
      max_every_two[i] = A[i];
      min_every_two[i] = A[n-1-i];
    }else {
      max_every_two[i] = A[n-1-i];
      min_every_two[i] = A[i];
    }
  }

  // O(n/2)
  int g_max = INT_MIN;
  int g_min = INT_MAX;
  for(int i = 0; i < n/2; i++) {
    g_max = max(g_max, max_every_two[i]); // O(n/2)
    g_min = min(g_min, min_every_two[i]); // O(n/2)
  }
  return {g_min, g_max};
  //totally O(n/2) + O(n/2) + O(n/2) = O(1.5n)
}

int main(){
  int A[10] = {4,3,9,2,7,1,6,5,8,0};
    int n = sizeof(A)/sizeof(A[0]);

  auto ans = go(A, n);
  cout << "min: " << ans.first << "  max: " << ans.second << endl;
  return 0;
}