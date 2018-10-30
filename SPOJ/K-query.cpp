/**

	Explicação: Colocamos as queries e as inserções num vector, sendo o conteúdo
	desse vetor uma estrtura que contém invervalos[i,j] para as range queries
	o valor index para inserções e para saber qual o número da query, um avlor k, 
	que é o valor que queremos inserir no caso das inserções, ou o valor
	sobre o qual queremos saber quantos número são maiores que ele no caso das queries.
	Ordenamos este vetor, e depois vamos percorre-lo. Se a ação for uma inserção
*/


#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

#define MAX 250000


struct order {
	int i;
	int j;
	int index;
	int k;
	char type;
};

vector<int> bt(MAX,0);
vector<order> ac(MAX);


bool operator<(order o1, order o2) {
	if(o1.k == o2.k) {
		if(o1.type == 'q') return true;
		else return false;
	}

	return o1.k > o2.k;
}

int query(int index){
    int sum = 0;
    while(index > 0){
        sum += bt[index];
        index -= (index & -index);
    }
    return sum;
}
 
void update(int index, int n){
    while(index <= n){
    	//printf ("index: %d\n", index);
        bt[index] += 1;
        index += (index & -index);
    }
}

int main() {
	int n, q;
	scanf("%d", &n);
	int j = 0;
	for(int  i = 0; i < n; i++){
		scanf("%d", &ac[j].k);
		ac[j].index = i+1;
		ac[j].type='i'; 
		j++;
	}

	scanf("%d", &q);
	vector<int> ans(q);

	for(int i = 0; i < q; i++) {
		scanf("%d %d %d", &ac[j].i, &ac[j].j, &ac[j].k);
		ac[j].index = i;
		ac[j].type = 'q';
		j++;
	}

	sort(ac.begin(), ac.end());
	for(int i = 0; i < j; i++) {
		if(ac[i].type == 'q') {
			int k = query(ac[i].j)- query(ac[i].i-1);
			//printf ("k= %d\n", k);
			ans[ac[i].index] = k;
		}
		else update(ac[i].index, n);
	}

	for(int i = 0; i < q; i++) {
		printf("%d\n", ans[i]);
	}

	return 0;
}