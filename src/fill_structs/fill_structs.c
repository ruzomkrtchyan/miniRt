#include "minirt.h"

t_amb	*lstadd(char **line)
{
	t_amb	*tmp;
	char	**colors;
	char	*ration;

	tmp = (t_amb *)malloc(sizeof(t_amb));
	if (!tmp)
		return (NULL);
	ration = ft_strdup(line[1]);
	colors = ft_split(line[2], ',');
	tmp->color->r = ft_atoi(colors[0]);
	tmp->color->g = ft_atoi(colors[1]);
	tmp->color->b = ft_atoi(colors[2]);
	tmp->ratio = ft_atof(ration);
	return (tmp);
}

void	lstback(t_amb **pars, t_amb *new)
{
	t_amb	*tmp;

	tmp = lstlast(*pars);
	if (!tmp)
		*pars = new;
	else
	{
		tmp->next = new;
		new->prev = tmp;
	}
}

void	lstclear(t_amb **lst)
{
	t_amb	*ptr;

	ptr = NULL;
	if (!lst || !*lst)
		return ;
	while ((*lst))
	{
		ptr = (*lst)->next;
		free ((*lst)->cmd);
		free (*lst);
		(*lst) = ptr;
	}
	ptr = NULL;
}

t_amb	*lstlast(t_amb *lst)
{
	t_amb	*tmp;

	tmp = lst;
	if (!tmp)
		return (NULL);
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp);
}

int	lstsize(t_amb *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		i++;
		(lst) = (lst)->next;
	}
	return (i);
}