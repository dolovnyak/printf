char    *re_strsub(char *s, int start, int len)
{
	char    *a;
	int     i;

	i = 0;
	if (!s)
		return (0);
	if ((a = (char*)ft_memalloc(len + 1)))
	{
		while (i < len)
		{
			a[i] = s[start];
			start++;
			i++;
		}
		a[i] = '\0';
	}
	free(s);
	return (a);
}
