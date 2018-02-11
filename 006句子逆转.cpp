//题目：逆转一个句子，但是不逆转里面的单词，比如为 i love you，逆转为 you love i
//
//思路：先逆转整个句子为 uoy evol i； 之后逐个逆转单词
//
//

char *reverseSentence(char *str)
{
	if(str == NULL)
		return str;
	
	reverse(str, strlen(str));//逆转整个句子
	
	char *pBegin = str;
	char *pEnd = str;
	while(*pEnd != '\0')
	{
		while(*pEnd != '\0' && *pEnd != ' ')
			++pEnd;
		
		reverse(pBegin, pEnd - pBegin);//逆转每个单词
		
		if(*pEnd == '\0')
			break;
		
		++pEnd;
		pBegin = pEnd;		
	}
	return str;
}