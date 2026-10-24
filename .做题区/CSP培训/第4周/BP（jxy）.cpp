#include<iostream>
#include<map>
#include<cmath>
using namespace std;

const int R = 50;
const int C = 50;

struct fund
{
	char t;
	int num = -1;
};
int main()
{
	fund p[R][C];
	int r, c, sy, sx, gy, gx;
	cin >> r >> c >> sy >> sx >> gy >> gx;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> p[i][j].t;
		}
	}
	int num = 0;
	p[sy - 1][sx - 1].num = 0; 
	int y = sy - 1;
	int x = sx - 1;
	int k = 0;
	while (true)
	{
		num++;
		//起点p[sy-1][sx-1].t,终点p[gy-1][gx-1].tqq
		for(int y=0;y<r;y++)
			for (int x = 0; x < c; x++)
			{
				if (p[y][x].num == k)
				{
					if (p[y + 1][x].t == '.')
					{
						if (p[y + 1][x].num == -1)
						{
							p[y +1][x ].num = num;
						}
					}
					if (p[y - 1][x ].t == '.')
					{
						if (p[y - 1][x].num == -1)
							p[y - 1][x].num = num;

					}
					if (p[y][x - 1].t == '.' )
					{
						if (p[y][x - 1].num == -1)
							p[y][x - 1].num = num;

					}
					if (p[y][x +1].t == '.' )
					{
						if (p[y][x + 1].num == -1)
							p[y][x + 1].num = num;
					}
				}
			}
		if (p[gy - 1][gx - 1].num != -1)
			break;
		k++;
	}
	cout << p[gy - 1][gx - 1].num << endl;
	system("pause");
   return 0;
}