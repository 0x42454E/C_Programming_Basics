/* Ben
reviewed by Or 30.09*/
int StrLen(char* str)
{
	if (0 == *str)
	{
		return 0;
	}
	
	return StrLen(++str) + 1;
}
