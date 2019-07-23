#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<queue>

using namespace std;

int buildtime[1005];
int buildcnt_pre[1005];
int maxtime[1005];
vector<int> prebuild[1005];

int main() {
	
	int T, N,K;
	int pre, nexte, target;
	scanf("%d", &T);
	for (int t = 0; t < T; t++) {
		scanf("%d %d", &N,&K);

		for (int n = 1; n <= N; n++) {
			scanf("%d", &buildtime[n]);
			buildcnt_pre[n] = 0;
			maxtime[n] = 0;
			prebuild[n].clear();
		}
		for (int k = 0; k <K; k++) {
			scanf("%d %d", &pre,&nexte);
			prebuild[pre].push_back(nexte);
			buildcnt_pre[nexte]++;
		}

		scanf("%d", &target);
		pair<int, int> now, next;

		queue<pair<int, int>> que;

		//선행 노드가 없는 노드
		for (int n = 1; n <= N; n++) {
			if (buildcnt_pre[n] == 0) {
				now.first = n; now.second = 0;
				que.push(now);
			}
		}

		while (!que.empty()) {
			now = que.front();
			que.pop();

			if (now.first == target) {//목표 도달
				printf("%d\n",now.second + buildtime[target]);
				break;
			}

			for (int i = 0; i < prebuild[now.first].size(); i++) {//다음 노드
				next.first = prebuild[now.first][i];
				next.second = now.second + buildtime[now.first];

				buildcnt_pre[next.first]--; // 선행 노드 하나 완료

				maxtime[next.first] = max(maxtime[next.first], next.second);//다음 노드의 최대 건설 시간
				next.second = maxtime[next.first];

				if (buildcnt_pre[next.first] == 0) {//다음 노드의 선행이 더 이상 없음
					que.push(next);
				}
			}

		}
		
	}


	return 0;
}