/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 09:52:30 by alucas-           #+#    #+#             */
/*   Updated: 2017/12/13 08:28:05 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shvm/op.h"

extern t_op		*shvm_oppush(uint16_t *it);
extern t_op		*shvm_opat(uint16_t it);
extern t_op		*shvm_opjump(uint16_t it, uint16_t jump);
extern t_op		*shvm_opor(uint16_t it, uint16_t flag);
