/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_debug_stack.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 12:53:17 by bena              #+#    #+#             */
/*   Updated: 2023/04/07 12:53:38 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

static void	print_debug_stack(t_status *stat)
{
	t_elem	*a;
	t_elem	*b;

	a = stat->a->gate;
	b = stat->b->gate;
	printf("Stack A Stack B\n");
	if (a != NULL && b == NULL)
	{
		printf("%d\n", a->value);
		while (a->next != stat->a->gate)
		{
			a = a->next;
			printf("%d\n", a->value);
		}
		return ;
	}
	if (a == NULL && b != NULL)
	{
		printf("        %d\n", b->value);
		while (b->next != stat->b->gate)
		{
			b = b->next;
			printf("        %d\n", b->value);
		}
		return ;
	}
	printf("%-7d %-7d\n",a->value, b->value);
	while (a->next != stat->a->gate || b->next != stat->b->gate)
	{
		if (a->next != stat->a->gate && b->next == stat->b->gate)
		{
			a = a->next;
			printf("%d\n", a->value);
			continue ;
		}
		if (a->next == stat->a->gate && b->next != stat->b->gate)
		{
			b = b->next;
			printf("        %d\n", b->value);
			continue ;
		}
		a = a->next;
		b = b->next;
		printf("%-7d %-7d\n",a->value, b->value);
	}
	return ;
}
