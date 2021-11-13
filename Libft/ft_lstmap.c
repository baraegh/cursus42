/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 16:04:44 by eel-ghan          #+#    #+#             */
/*   Updated: 2021/11/13 22:55:16 by eel-ghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list *ft_lstmap(t_list *lst, void *(*f)(void *),void (*del)(void *))
{
    t_list      *newlst;
    t_list      *tmp;

    if (!lst || !f)
        return (0);
    newlst = NULL;
    while (lst)
    {
        if (f(lst->content))
        {   
            tmp = ft_lstnew(f(lst->content)); 
            if (!tmp)
            {
                ft_lstclear(&newlst, del);
                return (0);
            }
            ft_lstadd_back(&newlst, tmp);
        }
        lst = lst->next;
    }
    return (newlst);
}