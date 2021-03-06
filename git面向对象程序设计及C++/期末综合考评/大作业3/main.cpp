#include <iostream>
using namespace  std;
//------------------【child类】-----------------------------------
class Child             //1.定义小朋友节点类
{
public:
	int childNo;         //当前小孩的编号
	Child* leftchild;    //记录小孩对象的左邻居
	Child* rightchild;   //记录小孩对象的右邻居
public:
	Child(int id = 0) 	  //构造函数
	{
		childNo = id;
		leftchild = NULL;
		rightchild = NULL;
	}
};
//-------------------【Circle类】----------------------------------
class Circle               // 定义圆圈游戏类
{
public:
	int scale;             //当前-正在参与游戏的人数
	Child children[1000];  //最初-参与游戏的小孩对象
public:
	Circle(int num = 1000) // 带默认值构造函数：初始化小孩节点
	{
		scale = num;
		for (int i = 0; i < num; i++)
			children[i] = Child(i);//No赋值
	};
	//构建节点的循环链表函数：确立每个小孩的左右邻居
	void Build()
	{
		for (int i = 0; i < scale; i++)//108
		{
			if (i == 0)
				children[i].leftchild = &children[scale];
			else
				children[i].leftchild = &children[i - 1];
			children[i].rightchild = &children[(i + 1)%scale];
		}
	}
	//游戏运行函数：从当前节点顺时针循环开始数num个数
	void Run(int T)// T==8
	{
		int k;
		cout << "从第几个小孩开始游戏，请输入编号(k<109)：" << endl;
		cin >> k;
		int count = 0;
		Child* current = &children[k];
		Child* p;//工作指针
		while (scale > 1)
		{
			count += 1;
			if (count == T)//T==8   小孩退出当前圆圈
			{
				scale = scale - 1;
				p = current->rightchild;
				current->leftchild->rightchild = current->rightchild;
				current->rightchild->leftchild = current->leftchild;
				current = p;
				count = 0;
			}
			else  //Count the next：继续数数游戏	            		
			{
				current = current->rightchild;
			}
		}
		cout << "The last child id is " << current->childNo << endl;
	}
};
//----------------------------主函数----------------------------------
int main()
{
	Circle nodes(108); // 圆圈类内有108个节点对象（小孩）
	nodes.Build();
	nodes.Run(8);      // 开始循环运行数“8”的游戏，输出最后的获胜者
	return 0;
}