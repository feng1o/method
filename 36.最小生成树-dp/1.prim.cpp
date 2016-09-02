
void MiniSpanTree_prim(Mgraph G){
	int min, i, j, k;
	int adjvex[MAXVEX];  //��ض����±꡾1,0,1,0��0����ʾ0��1����2��1�й�ϵ
	int lowcost[MAXVEX];  //��С��������

	lowcost[0] = 0;  //
	adjvex[0] = 0;

	for (int i = 0; i < G.numVertex; ++i)
	{
		lowcost[i] = G.arc[0][i];  //��0�㿪ʼ...
		adjvex[i] = 0;    //��Ĭ����0���йس�ʼ����������
	}

	for (int i = 0; i < G.numVertex; ++i)
	{
		min = INFINITY;
		j = 1;
		k = 0;
		while (j < G.numVertex){  //�ҳ��������������i����������Ǹ�dian,����k����
			if (lowcost[j] != 0 && lowcost[j] < min){  //==0���Լ����Լ�
				min = lowcost[j];
				k = j;
			}
			++j;
		}

		cout << adjvex[k] << k << endl;
		lowcost[k] = 0;   //��ʾ�������治�������ˣ�����

		for (int j = 0; j < G.numVertex; ++j)  //������kΪ����������k���ڵĵ�Ĵ��ۣ���lowcost��ûһ��k�ͱ�һ��
		{
			if (lowcost[j] != 0 && G.arc[k][j] < lowcost[j])
			{
				lowcost[j] = g.arc[k][j];
				adjvex[j] = k;
			}
		}
	}
}