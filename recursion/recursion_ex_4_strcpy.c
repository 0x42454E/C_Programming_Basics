/* Ben
reviewed by Or 30.09*/
char* StrCpy(char *dest, const char *src)
{
	if ('\0' == *src)
	{
		*dest = '\0';
		return dest;
	}

	*dest = *src++;
	
	 StrCpy(++dest, src);
	 
	 return dest;
}
