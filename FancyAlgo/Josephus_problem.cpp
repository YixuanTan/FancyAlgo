# include <iostream>
/*
http://www.geeksforgeeks.org/josephus-problem-set-1-a-on-solution/

There are n people standing in a circle waiting to be executed. The counting out begins at some point in the circle and proceeds around the circle in a fixed direction. In each step, a certain number of people are skipped and the next person is executed. The elimination proceeds around the circle (which is becoming smaller and smaller as the executed people are removed), until only the last person remains, who is given freedom. Given the total number of persons n and a number k which indicates that k-1 persons are skipped and kth person is killed in circle. The task is to choose the place in the initial circle so that you are the last one remaining and so survive.
*/

/* recurrence 
opt(n, k) = (opt(n - 1, k) + k - 1) % n + 1
k - 1 is the # person before the guy just killed.
% n means they are in a circle
 
opt(i, k) = (opt(i - 1, k) + k - 1) % i + 1
i is the # of persons left.
opt(i - 1, k) is subprob
为什么右边需要+1， 举个例子
e.x. if k == 1, then opt(i, 1) = opt(i-1, 1) % i + 1 

递归方程很tricky
*/
using namespace std;
int dp(int n, int k) {
  if(n == 1) {
    return 1;
  }else {
    return (k - 1 + dp(n - 1, k)) % n + 1;
  }
}
int main() {
  cout << dp(41, 3) << endl;
  return 0;
}