#include "libft.h"

int			main(void)
{
	char	**arr;
	char	*str;

	str = NULL;
	arr = ft_split("Hello Ziyi", " ");
	for(int i = 0; arr && arr[i]; i++)
		ft_putendl(arr[i]);
	while (ft_gnl(0, &str))
	{
		ft_putendl(str);
	}
	return (1);
}
