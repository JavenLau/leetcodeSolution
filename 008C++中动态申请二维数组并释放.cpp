


//new/delete��̬����һά����
void DynamicCreate1Array()
{
	int *p = new int[len];	
	delete[] p;
}

//new/delete��̬���ٶ�ά����
void DynamicCreate2Array()
{
	//��̬���ٿռ�
    int **p = new int*[m]; //������
	for(int i = 0; i < m; i++)
		p[i] = new int[n]; //������

	//�ͷſ��ٵ���Դ
    for(i = 0; i < m; i++)
		delete[] p[i];
	delete[] p;

}

//STL�е�vector��̬���ٶ�ά����
void VectorCreate()
{	
	//ע��������һ�У�vector <int������ "> "֮��Ҫ�пո񣡷���ᱻ��Ϊ������ "> > "�� 
    vector<vector<int> > p(m,vector<int>(n));	
}