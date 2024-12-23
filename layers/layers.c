#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h> 
#include <stdlib.h>

int x, y, z, x1, y1, z1, x2, y2, z2, dist[21][36][31], c = INT_MAX;

void get_distance(int xx, int yy, int zz, int d) {
	if (xx < 1 || xx > x || yy < 1 || yy > y || zz < 1 || zz > z) return;

	if (dist[xx][yy][zz] < d) return;
	if (c < d) return; 

	dist[xx][yy][zz] = d;

	if (xx == x1 && yy == y1 && zz == z1) {
		c = min(c, d);
		return;
	}

	if (xx == x2 && yy == y2 && zz == z2) {
		c = min(c, d);
		return;
	}

	get_distance(xx - 1, yy, zz, d + 1);
	get_distance(xx, yy - 1, zz, d + 1);
	get_distance(xx, yy, zz - 1, d + 1);
	get_distance(xx, yy, zz + 1, d + 1);
	get_distance(xx, yy + 1, zz, d + 1);
	get_distance(xx + 1, yy, zz, d + 1);
}

int main() {
	scanf("%d %d %d %d %d %d %d %d %d", &x, &y, &z, &x1, &y1, &z1, &x2, &y2, &z2);
	
	for (int k = 1; k <= z; ++k) {
		printf("layer %d:\n", k);
		for (int i = 1; i <= x; ++i) {
			for (int j = 1; j <= y; ++j) {
				for (int i = 1; i <= x; ++i) for (int j = 1; j <= y; ++j) for (int k = 1; k <= z; ++k) dist[i][j][k] = INT_MAX;
				c = INT_MAX;
				get_distance(i, j, k, 0);
				printf("%d ", c);
			}
			printf("\n");
		}
	}

	return 0;
}
