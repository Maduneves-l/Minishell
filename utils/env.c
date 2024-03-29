/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoao-me <cjoao-me@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 13:55:55 by mneves-l          #+#    #+#             */
/*   Updated: 2024/01/12 13:08:18 by cjoao-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	get_env(char **env, t_env **ev)
{
	int		l;
	int		size;
	int		len;

	l = 0;
	size = 0;
	while (env[l] != (void *)0)
	{
		size = g_size(env[l], '=');
		len = ft_strlen(env[l]);
		ev_lstadd_back(ev, ev_lstnew(ft_substr(env[l], 0, size), \
			ft_substr(env[l], size + 1, len - size)));
		l++;
	}
}

int	g_size(char *s, int a)
{
	size_t	i;

	i = 0;
	while (*s)
	{
		if (s[i] == a)
			return (i);
		i++;
	}
	return (0);
}

t_env	*ev_lstnew(char *name, char *content)
{
	t_env	*node;

	node = (t_env *)malloc(sizeof(t_env));
	if (!node)
		return (NULL);
	node->name = name;
	node->content = content;
	node->next = NULL;
	return (node);
}

void	ev_lstadd_back(t_env **lst, t_env *new)
{
	t_env	*current;

	current = *lst;
	if (*lst == NULL)
		*lst = new;
	else
	{
		while (current->next != NULL)
			current = current->next;
		current->next = new;
	}
}

int	ev_lstsize(t_env *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}
