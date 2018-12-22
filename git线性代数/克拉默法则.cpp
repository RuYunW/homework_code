#include<stdio.h>

int main()
{
	//获取阶数
	int n;
	printf("该程序用来计算二元或三元一次方程式\n");
	printf("请输入方程式变量个数（2或3）：\n");
	scanf_s("%d", &n);

	
	//二阶行列式
	if (n == 2)
	{
		//获取行列式
		int a[2][2];
		int b[2];
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				printf("请输入a%d%d:\n", i + 1, j + 1);
				scanf_s("%d", &a[i][j]);
				if (j == 1)
				{
					printf("请输入b%d\n",i+1);
					scanf_s("%d", &b[i]);
				}
				
			}
		}
		//克拉默法则
		float d, d1, d2;
		d = a[0][0] * a[1][1] - a[0][1] * a[1][0];
		if (d == 0)
		{
			printf("方程没有唯一解\n");
		}
		else
		{
			d1 = b[0] * a[2][2] - b[1] * a[0][1];
			d2 = a[0][0] * b[1] - b[0] * a[1][0];

			float x1, x2;
			x1 = d1 / d;
			x2 = d2 / d;

			printf("x1 = %f.2, x2 = %f.2\n", x1, x2);
		}
			
	}

	//三阶行列式
	if (n == 3)
	{
		//获取三阶行列式
		int a[3][3];
		int b[3];
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				printf("请输入a%d%d:\n", i + 1, j + 1);
				scanf_s("%d", &a[i][j]);
				if (j == 1)
				{
					printf("请输入b%d\n", i + 1);
					scanf_s("%d", &b[i]);
				}
			}
		}
		
		float d,d1,d2,d3;
		d = a[0][0]*a[1][1]*a[2][2] + a[0][1]*a[1][2]*a[2][0] + a[0][2]*a[1][0]*a[2][1] - a[0][2]*a[1][1]*a[2][0] - a[0][0]*a[1][2]*a[2][1] - a[0][1]*a[1][0]*a[2][2];
		if (d == 0)
		{
			printf("方程没有唯一解\n");
		}
		else
		{
			d1 = b[0] * a[1][1] * a[2][2] + a[0][1] * a[1][2] * b[2] + a[0][2] * b[1] * a[2][1] - a[0][2] * a[1][1] * b[2] - b[0] * a[1][2] * a[2][1] - a[0][1] * b[1] * a[2][2];
			d2 = a[0][0] * b[1] * a[2][2] + b[0] * a[1][2] * a[2][0] + a[0][2] * a[1][0] * b[2] - a[0][2] * b[1] * a[2][0] - a[0][0] * a[1][2] * b[2] - b[0] * a[1][0] * a[2][2];
			d3 = a[0][0] * a[1][1] * b[2] + a[0][1] * b[1] * a[2][0] + b[0] * a[1][0] * a[2][1] - b[0] * a[1][1] * a[2][0] - a[0][0] * b[1] * a[2][1] - a[0][1] * a[1][0] * b[2];

			float x1, x2, x3;
			x1 = d1 / d;
			x2 = d2 / d;
			x3 = d3 / d;
			printf("x1 = %d, x2 = %d, x3 = %d\n", x1,x2,x3);

		}

		
	}
	return 0;
}