#include "libft.h"
#include <fcntl.h>

int			main(int ac, char **av)
{
	char	**arr;
	char	*str;
	int		fd;

	fd = 0;
	str = NULL;
	arr = ft_split(" hello    les   5  gens ", " 5");
	for(int i = 0; arr && arr[i]; i++)
		ft_putendl(arr[i]);
	free(str);
	(void)ac;
	(void)av;
	(void)arr;
/*	if (ac > 1)
	{
		fd = open(av[1], O_RDONLY);
		while (ft_gnl(fd, &str) > 0)
		{
			ft_putendl(str);
			free(str);
		}
		close(fd);
		fd = open(av[2], O_RDONLY);
		while (ft_gnl(fd, &str) > 0)
		{
			ft_putendl(str);
			free(str);
		}
		close(fd);

	}
*/	
	return (1);
}
