/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoyette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 14:29:09 by jgoyette          #+#    #+#             */
/*   Updated: 2018/12/11 14:29:45 by jgoyette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_del(void *content, size_t content_size)
{
	(void)content_size;
	ft_memdel(content);
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*alst;
	t_list	*tmp;

	alst = NULL;
	while (lst && f)
	{
		tmp = (*f)(lst);
		if (tmp)
			ft_lstaddend(&alst, tmp);
		else
		{
			ft_lstdel(&alst, &ft_del);
			return (NULL);
		}
		lst = lst->next;
	}
	return (alst);
}
