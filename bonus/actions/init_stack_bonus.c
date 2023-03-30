/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 00:29:35 by bena              #+#    #+#             */
/*   Updated: 2023/03/31 06:49:42 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "s_array_bonus.h"
#include "s_stack_bonus.h"

t_stack			*release_stack(t_stack *stack);
static void		write_stack_from_array(t_stack *stack, t_array *array);
static void		remove_all_elems(t_elem **gate);
static t_elem	*add_a_new_elem_to_the_last(t_elem *last, t_elem *new);

t_stack	*init_stack(t_array *array)
{
	t_stack	*output;

	output = (t_stack *)malloc(sizeof(t_stack));
	if (output == NULL)
		return (NULL);
	if (array == NULL || array->number_of_parameters == 0)
	{
		output->size = 0;
		output->gate = NULL;
		return (output);
	}
	write_stack_from_array(output, array);
	if (output->gate == NULL)
		return (release_stack(output));
	return (output);
}

t_stack	*release_stack(t_stack *stack)
{
	if (stack->gate == NULL)
	{
		free(stack);
		return (NULL);
	}
	remove_all_elems(&(stack->gate));
	free(stack);
	return (NULL);
}

static void	write_stack_from_array(t_stack *stack, t_array *array)
{
	int		index;
	t_elem	*the_last_elem;
	t_elem	*temp_elem;

	stack->size = array->number_of_parameters;
	stack->gate = (t_elem *)malloc(sizeof(t_elem));
	if (stack->gate == NULL)
		return ;
	stack->gate->before = stack->gate;
	stack->gate->next = stack->gate;
	stack->gate->value = array->array[0];
	the_last_elem = stack->gate;
	index = 0;
	while (++index < array->number_of_parameters)
	{
		temp_elem = (t_elem *)malloc(sizeof(t_elem));
		if (temp_elem == NULL)
			return (remove_all_elems(&(stack->gate)));
		temp_elem->value = array->array[index];
		the_last_elem = add_a_new_elem_to_the_last(the_last_elem, temp_elem);
	}
	stack->gate->before = the_last_elem;
}

static void	remove_all_elems(t_elem **gate)
{
	t_elem	*target;
	t_elem	*next;

	target = *gate;
	next = target->next;
	while (next != NULL && next != *gate)
	{
		target = next;
		next = target->next;
		free(target);
	}
	free(*gate);
	*gate = NULL;
}

static t_elem	*add_a_new_elem_to_the_last(t_elem *last, t_elem *new)
{
	new->before = last;
	new->next = last->next;
	last->next = new;
	return (new);
}
