/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 04:55:06 by bena              #+#    #+#             */
/*   Updated: 2023/03/29 07:30:14 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_stack.h"
#define NULL 0

static void	delete_the_gate_elem(t_stack *stack);
static void	add_the_elem_into_the_gate(t_elem *target, t_stack *stack);

void	push(t_stack *from, t_stack *to)
{
	t_elem	*target;

	if (from->size == 0)
		return ;
	from->size--;
	target = from->gate;
	if (from->size > 0)
		delete_the_gate_elem(from);
	else
		from->gate = NULL;
	if (to->size > 0)
		add_the_elem_into_the_gate(target, to);
	else
	{
		to->gate = target;
		target->before = target;
		target->next = target;
	}
	to->size++;
}

static void	delete_the_gate_elem(t_stack *stack)
{
	t_elem	*target;

	target = stack->gate;
	target->before->next = target->next;
	target->next->before = target->before;
	stack->gate = target->next;
}

static void	add_the_elem_into_the_gate(t_elem *target, t_stack *stack)
{
	t_elem	*new_before;
	t_elem	*new_next;

	new_before = stack->gate->before;
	new_next = stack->gate;
	new_before->next = target;
	new_next->before = target;
	target->before = new_before;
	target->next = new_next;
	stack->gate = target;
}
