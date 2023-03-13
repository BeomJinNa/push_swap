/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_array_from_input.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 09:41:31 by bena              #+#    #+#             */
/*   Updated: 2023/03/13 10:01:30 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 
#include "s_input.h"
#include "s_array.h"

static void	extract_array_from_string(t_array *array, t_input *input);

void	get_array_from_input(t_array *array, t_input *input)
{
	if (input->input == NULL)
	{
		array->array = NULL;
		return ;
	}
	array->number_of_parameters = input->number_of_parameters;
	array->array = (int *)malloc(sizeof(int) * array->number_of_parameters);
	if (array->array == NULL)
		return ;
	extract_array_from_string(array, input);
}

static void	extract_array_from_string(t_array *array, t_input *input)
{
	int		i;
	char	*ptr;

	ptr = input->input;
	i = -1;
	while (++i < array->number_of_parameters)
	{
		while (*ptr == ' ')
			ptr++;
		array->array[i] = ft_atoi(ptr);
	}
}
