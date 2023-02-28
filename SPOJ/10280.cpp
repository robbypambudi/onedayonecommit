#include <iostream>
using namespace std;

#define fast_cin()                  \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL);                    \
  cout.tie(NULL)

void solve()
{
  int min = 1005;
  int max = 0;
  int N;
  scanf("%d", &N);
  while (N--)
  {
    int x;
    scanf("%d", &x);

    min = x < min ? x : min;
    max = x > max ? x : max;
  }
  printf("%d", 2 * (max - min));
}
int main()
{
  fast_cin();
  solve();
  return 0;
}