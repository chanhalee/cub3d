#include "./header/cub3d.h"

void	ft_strfill(char *buf, int start, int end, char c)
{
	int	i;

	i = start;
	while (i < end)
	{
		buf[i] = c;
		i++;
	}
	buf[i] = '\0';
	return ;
}

void	ft_strcpy(char *dest, char *src)
{
	int	i;
	int	len;

	len = ft_strlen(src);
	i = 0;
	while (i < len)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return ;
}
