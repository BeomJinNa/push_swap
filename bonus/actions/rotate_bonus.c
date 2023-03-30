/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 04:51:01 by bena              #+#    #+#             */
/*   Updated: 2023/03/31 06:49:49 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_stack_bonus.h"

void	rotate(t_stack *stack)
{
	if (stack->size < 2)
		return ;
	stack->gate = stack->gate->next;
}

void	r_rotate(t_stack *stack)
{
	if (stack->size < 2)
		return ;
	stack->gate = stack->gate->before;
}
