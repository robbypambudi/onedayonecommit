/**
 * @file LDCSUMAB.cpp
 * @brief
 * @version 0.1
 * @date 2023-02-26
 * @link https://www.spoj.com/problems/LDCSUMAB/
 *
 */

#include <iostream>
using namespace std;

#define fast_cin()                  \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL);                    \
  cout.tie(NULL)
#define forn(e) for (int i = 0; i < e; i++)

void solve()
{
  int t, k;
  scanf("%d", &t);
  while (t--)
  {
    scanf("%d", &k);
    int temp = 0, a, b;
    while (k > 0)
    {
      temp += 1;
      a = temp;
      k = k - temp;
    }
    printf("Nilai keluar loop %d %d\n", k, temp);

    if (k == 0)
    {
      b = temp - 1;
    }
    else
    {
      b = (k + temp) - 1;
    }
    printf("%d %d\n", b, a);
  }
}
int main()
{
  fast_cin();
  solve();
  return 0;
}

/*
Explanation:
In the first input of the first series of 3, 5, 6, 9, 10.
The need to find the number 3, 6, 10 :

3 = 2 ^ 0 + 2 ^ 1;
6 = 2 ^ 1 + 2 ^ 2;
10 = 2 ^ 1 + 2 ^ 3.

Agar lebih muda dipahami maka arti dari 3, 5, 6, 9, 10 adalah
3 = 2 ^ 0 + 2 ^ 1; -> Ke 1
5 = 2 ^ 0 + 2 ^ 2; -> Ke 2
6 = 2 ^ 1 + 2 ^ 2; -> Ke 3
9 = 2 ^ 0 + 2 ^ 3; -> Ke 4
10 = 2 ^ 1 + 2 ^ 3; -> Ke 5
12 = 2 ^ 2 + 2 ^ 3; -> Ke 6

Dari diatas dapat disimpulkan bahwa banyak perulangan akan mengikuti nilai terbesar dari n
n = 5 -> perulangan 5
n = 10 -> perulangan 10

maka untuk mencari nilai yang dicari,
kita bisa menentukan dengan melihat nilai k setelah keluar dari loop
Jika K = 0 maka
  nilai m adalah n -1;

Selain itu maka :
  nilai k dikembalikan lagi 1 iterasi sebelum keluar
  dan nilai m adalah k - 1


Contoh Mencari nilai ke 2 :
5 = 2 ^ 0 + 2 ^ 2; -> Ke 2

Nilai keluar dari loop adalah -1, 2
maka nilai k adalah dikemablikan lagi menjadi 1
dan nilai m adalah k -1 maka 1 - 1
jawaban adalah (0, 2);

Kompleksitas waktu adalah
- O(n)
*/