/* Ben
reviewed by Or 30.09*/
int StrCmp(char* str, char* str2)
{
	if (!*str || !*str2 || *str != *str2)
	{
		return *str - *str2;
	}
	
	return StrCmp(++str, ++str2);
}
