/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gettimeofday.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 23:03:28 by jincpark          #+#    #+#             */
/*   Updated: 2022/11/16 23:13:35 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <stdio.h>

int main()
{
	struct timeval tp;
	
	gettimeofday(&tp, NULL);
	printf("tv_sec : %ld\ntv_usec : %d\n", tp.tv_sec, tp.tv_usec);
	return (0);
}
