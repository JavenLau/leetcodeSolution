


//new/delete动态开辟一维数组
void DynamicCreate1Array()
{
	int *p = new int[len];	
	delete[] p;
}

//new/delete动态开辟二维数组
void DynamicCreate2Array()
{
	//动态开辟空间
    int **p = new int*[m]; //开辟行
	for(int i = 0; i < m; i++)
		p[i] = new int[n]; //开辟列

	//释放开辟的资源
    for(i = 0; i < m; i++)
		delete[] p[i];
	delete[] p;

}

//STL中的vector动态开辟二维数组
void VectorCreate()
{	
	//注意下面这一行：vector <int后两个 "> "之间要有空格！否则会被认为是重载 "> > "。 
    vector<vector<int> > p(m,vector<int>(n));	
}