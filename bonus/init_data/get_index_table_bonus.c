/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_index_table_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:37:37 by bena              #+#    #+#             */
/*   Updated: 2023/03/31 05:58:52 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "s_array_bonus.h"

void	sort_array(t_array *array);

void	get_index_table(t_array *index_table, t_array *array)
{
	int	size;

	size = array->number_of_parameters;
	index_table->array = (int *)malloc(sizeof(int) * size);
	if (index_table->array == NULL)
		return ;
	index_table->number_of_parameters = size;
	while (size-- > 0)
		index_table->array[size] = array->array[size];
	sort_array(index_table);
}
