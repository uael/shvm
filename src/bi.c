/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 09:52:30 by alucas-           #+#    #+#             */
/*   Updated: 2017/12/13 08:28:05 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shvm/bi.h"
#include "shvm/vm.h"

inline void		shvm_biregister(char const *name, t_bi *bi)
{
	uint32_t	it;
	char		*var;

	if (ft_mapput(&g_shvm->builtins, var = ft_strdup(name), &it))
		((t_bi **)g_shvm->builtins.vals)[it] = bi;
	else
		free(var);
}
