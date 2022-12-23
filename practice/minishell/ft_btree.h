/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 12:57:38 by jincpark          #+#    #+#             */
/*   Updated: 2022/12/23 14:13:29 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BINARY_TREE_H
# define BINARY_TREE_H

typedef struct s_btree
{
	t_btree *parent;
	t_btree	*child_left;
	t_btree	*child_right;
	void	*content;
}	t_btree;

t_btree	*ft_btreenew(void *content);
void	ft_btree_add_child_left(t_btree **btree, t_btree *child);
void	ft_btree_add_child_right(t_btree **btree, t_btree *child);

#endif
