/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 03:52:49 by bena              #+#    #+#             */
/*   Updated: 2023/03/29 04:50:48 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_stack.h"

void	swap(t_stack *stack)
{
	int	temp;

	if (stack->size < 2)
		return ;
	temp = stack->gate->value;
	stack->gate->value = stack->gate->next->value;
	stack->gate->next->value = temp;
}
