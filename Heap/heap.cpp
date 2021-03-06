/*
Author : sk92907
github:https://github.com/notreallystatic
linkedin : https://www.linkedin.com/in/notreallystatic/
*/

#include <iostream>
#include <stdlib.h>
#include <numeric>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <set>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <list>
#include <functional>
#include <cctype>
#include <sstream>
#include <cmath>
#include <limits.h>
#include <bitset>
#include <random>

using namespace std;

#define int int
#define pb push_back
#define all(v) v.begin(), v.end()
#define deb(x) cout << #x << " " << x << endl;
#define debxy(x, y) cout << #x << " " << x << "\t" << #y << " " << y << endl;
#define forall(i, a, b) for (int i = a; i < b; ++i)
#define forit(it, a) for (decltype(a.begin()) it = a.begin(); it != a.end(); it++)
#define endl "\n"

typedef long long ll;
typedef unsigned int ui;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef set<int> si;
typedef vector<pii> vpii;
typedef map<int, int> mii;

bool isUpper(char c) { return c >= 'A' && c <= 'Z'; }
bool isLower(char c) { return c >= 'a' && c <= 'z'; }
bool isLetter(char c) { return c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z'; }
bool isDigit(char c) { return c >= '0' && c <= '9'; }
char toLower(char c) { return (isUpper(c)) ? (c + 32) : c; }
char toUpper(char c) { return (isLower(c)) ? (c - 32) : c; }
int str2int(string s)
{
  int r = 0;
  istringstream sin(s);
  sin >> r;
  return r;
}
int char2int(char c) { return (int)c; }
bool isPowerOfTwo(const int &x) { return !(x & (x - 1)); }
bool isPerfectSquare(const int &x) { return floor(sqrt(x)) == ceil(sqrt(x)); }
int pow2(const int &x) { return (1LL << x); }
int min(const int &a, const int &b, const int &c) { return min(a, min(b, c)); }

const int mod = 1000000007;

template <typename... T>
void read(T &... args)
{
  ((cin >> args), ...);
}

template <typename... T>
void write(T &&... args)
{
  ((cout << args << " "), ...);
}

template <class T>
void display(const vector<T> &v)
{
  for_each(all(v), [](auto x) {
    cout << x << " ";
  });
  cout << endl;
}

class Heap
{
private:
  vector<int> heap;
  int size;
  int capacity;

  int parent(const int &i)
  {
    return (i - 1) / 2;
  }

  int left(const int &i)
  {
    return 2 * i + 1;
  }

  int right(const int &i)
  {
    return 2 * i + 2;
  }

  void heapify(int i)
  {
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < size && heap[l] < heap[smallest])
      smallest = l;
    if (r < size && heap[r] < heap[smallest])
      smallest = r;
    if (smallest != i)
    {
      swap(heap[i], heap[smallest]);
      heapify(smallest);
    }
  }

public:
  Heap()
  {
    capacity = 100;
    size = 0;
    heap.resize(capacity);
  }

  void push(int value)
  {
    if (size == capacity)
    {
      capacity = capacity * 2;
      size = size * 2;
    }
    heap[size] = value;
    ++size;
    int i = size - 1;
    while (heap[i] < heap[parent(i)])
    {
      swap(heap[i], heap[parent(i)]);
      i = parent(i);
    }
  }

  int top()
  {
    return heap[0];
  }

  int pop()
  {
    int value = heap[0];
    heap[0] = heap[size - 1];
    --size;
    heapify(0);
    return value;
  }

  void display()
  {
    for (int i = 0; i < size; ++i)
    {
      cout << heap[i] << " ";
    }
    cout << endl;
  }
};

int32_t main()
{

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  Heap h;
  h.push(3);
  h.display();
  h.push(2);
  h.display();
  h.push(1);
  h.display();
  h.push(10);
  h.push(20);
  h.push(19);
  h.push(-2);
  h.display();
  h.push(0);
  h.display();
  h.pop();
  h.display();
  return 0;
}
