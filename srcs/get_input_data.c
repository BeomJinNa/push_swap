/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 12:43:45 by bena              #+#    #+#             */
/*   Updated: 2023/02/28 17:51:18 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "s_input.h"

int			does_input_error_exist_ps(t_input *memory);
int			is_this_space_ps(int c);
static char	*get_linked_input_string(int ac, char **av);
static int	get_number_of_parameters(const char *str);

void	get_input_data_ps(t_input *memory, int ac, char **av)
{
	memory->input = get_linked_input_string(ac, av);
	if (memory->input == NULL)
		return ;
	memory->number_of_parameters = get_number_of_parameters(memory->input);
	if (does_input_error_exist_ps(memory))
	{
		free(memory->input);
		memory->input = NULL;
	}
}

static char	*get_linked_input_string(int ac, char **av)
{
	char	*linked_string;
	int		counter;
	size_t	length;
	char	*ptr_to;
	char	*ptr_from;

	length = 0;
	counter = ac;
	while (--counter > 0)
		length += ft_strlen(av[counter]) + 1;
	linked_string = (char *)malloc(sizeof(char) * length);
	if (linked_string == NULL)
		return (NULL);
	ptr_to = linked_string;
	while (++counter < ac)
	{
		ptr_from = av[counter];
		while (*ptr_from)
			*ptr_to++ = *ptr_from++;
		*ptr_to++ = ' ';
	}
	*--ptr_to = '\0';
	return (linked_string);
}

static int	get_number_of_parameters(const char *str)
{
	int			number_of_parameters;
	const char	*ptr;

	number_of_parameters = 0;
	ptr = str;
	while (is_this_space_ps(*ptr))
		ptr++;
	while (*ptr)
	{
		number_of_parameters++;
		while (*ptr && is_this_space_ps(*ptr) == 0)
			ptr++;
		while (is_this_space_ps(*ptr))
			ptr++;
	}
	return (number_of_parameters);
}
