#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"
#define fast ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;

//1920 수찾기
int part(vector<long long> &N2, int left, int right) {
	int pivot = N2[left];
	int low = left + 1;
	int high = right;

	while (low <= high) {
		//포인터가 엇갈리기전까지 반복
		while (low <= right && pivot >= N2[low]) {
			low++;
		}
		while (high >= (left+1) && pivot <= N2[high]) {
			high--;
		}
		if (low <= high) {
			//엇갈렸을 때
			int temp = N2[low];
			N2[low] = N2[high];
			N2[high] = temp;
		}
	}
	int temp = N2[left];
	N2[left] = N2[high];
	N2[high] = temp;

	return high;
}
void quick(vector<long long>& N2, int left, int right) {
	if (left < right) {
		int q = part(N2, left, right);
		quick(N2, left, q - 1);
		quick(N2, q + 1, right);
	}
}
int main() {
	fast;
	long long N;
	long long M;
	cin >> N;
	vector<long long> N2;
	long long a = 0;
	for (int i = 0; i < N; i++) {
		cin >> a;
		N2.push_back(a);
	}
	//quick(N2,0, N2.size()-1);
	sort(N2.begin(), N2.end(), less<long long>());
	cin >> M;
	long long b;
	for (int i = 0; i < M; i++) {
		cin >> b;
		bool flag = 0;
		long long min = 0;
		long long max = N2.size()-1;
		while (min <= max) {
			int mid = (min + max) / 2;
			if (N2[mid] == b) {
				cout << 1 << endl;
				flag = 1;
				break;
			}
			else if (N2[mid]>b) {
				max = mid-1;
			}
			else min = mid+1;
		}
		if (flag != 1) cout << 0 << endl;
	}
}