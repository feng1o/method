
void MiniSpanTree_prim(Mgraph G){
	int min, i, j, k;
	int adjvex[MAXVEX];  //相关顶点下标【1,0,1,0，0】表示0和1，，2和1有关系
	int lowcost[MAXVEX];  //最小代价数组

	lowcost[0] = 0;  //
	adjvex[0] = 0;

	for (int i = 0; i < G.numVertex; ++i)
	{
		lowcost[i] = G.arc[0][i];  //从0点开始...
		adjvex[i] = 0;    //都默认与0点有关初始化，，，，
	}

	for (int i = 0; i < G.numVertex; ++i)
	{
		min = INFINITY;
		j = 1;
		k = 0;
		while (j < G.numVertex){  //找出所有与这个顶点i距离最近的那个dian,存在k里面
			if (lowcost[j] != 0 && lowcost[j] < min){  //==0是自己和自己
				min = lowcost[j];
				k = j;
			}
			++j;
		}

		cout << adjvex[k] << k << endl;
		lowcost[k] = 0;   //表示这个点后面不用再找了，，，

		for (int j = 0; j < G.numVertex; ++j)  //更新以k为起点的所有与k相邻的点的代价，，lowcost是没一个k就变一次
		{
			if (lowcost[j] != 0 && G.arc[k][j] < lowcost[j])
			{
				lowcost[j] = g.arc[k][j];
				adjvex[j] = k;
			}
		}
	}
}