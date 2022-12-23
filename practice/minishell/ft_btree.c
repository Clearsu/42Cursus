/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 14:10:35 by jincpark          #+#    #+#             */
/*   Updated: 2022/12/23 14:19:24 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_btree.h"

t_btree	*ft_btreenew(void *content)
{
	t_btree	*btree;

	btree = (t_btree *)malloc(sizeof(t_btree));
	if (!btree)
		return (NULL);
	btree->parent = NULL;
	btree->child_left = NULL;
	btree->child_right = NULL;
	btree->content = content;
	return (btree);
}

void	ft_btree_add_child_left(t_btree **btree, t_btree *child)
{
	if (!btree || !child || !*btree)
		return ;
	*btree->child_left = child;
	if (!child->parent)
		child->parent = *btree;
}

void	ft_btree_add_child_right(t_btree **btree, t_btree *child)
{
	if (!btree || !child || !*btree)
		return ;
	*btree->child_right = child;
	if (!child->parent)
		child->parent = *btree;
}
