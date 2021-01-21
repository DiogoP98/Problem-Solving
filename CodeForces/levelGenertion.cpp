/*
    Ajudas: https://codeforces.com/blog/entry/52991

    Complexidade: O(logn)

    TODO
*/

#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
    int q;
    scanf("%d", &q);

    for(int i = 0; i < q; i++) {
        long long n;
        scanf("%lld", &n);

        if (n == 1) 
            printf("0\n");

        else {
        	int l = 0, h = n;
        	while (h - l > 1) {
            	long long m = l + (h - l)/2;

            	long long value = (n-m) * (n - m - 1) /2;

            	if (m >=value) 
            		h = m;
            	else 
            		l = m;
        	}
        	
        	long long ans = max((long long)2 * (h - 1), h + (n - h) * (n - h - 1) / 2);
        	printf("%lld\n", ans);
        }
    }

    return 0;
}