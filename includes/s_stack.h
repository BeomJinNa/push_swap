/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_stack.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 03:42:52 by bena              #+#    #+#             */
/*   Updated: 2023/03/24 04:30:05 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_STACK_H
# define S_STACK_H

typedef s_elem
{
	int		value;
	t_elem	*before;
	t_elem	*next;
}			t_elem;

typedef struct s_stack
{
	int		size;
	t_elem	*gate;
}			t_stack;

typedef struct s_status
{
	int		number_of_elems;
	char	*answer_sheet;
	char	*ptr;
	t_elem	*A;
	t_elem	*B;
}			t_status;
#endif
