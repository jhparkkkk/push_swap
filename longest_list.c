#include "libft.h"
#include "push_swap.h"


int *find_lis_len(t_toolbox *box)
{
	int *len;
	int *map;
    int i;
    int j;
    i = 0;
    j = 0;
    len = ft_calloc(box->count, sizeof(int));
	map = ft_calloc(box->count, sizeof(int));
	i = 0;
    while(i < box->count)                                                       // J'initialise mon tableau LEN rempli de 1 
    {   
        len[i] = 1;
        i++;
    }
    i = 1;
    while(i < box->count)                                                       // Je check la liste la plus longue 
    {
        j = 0;
        while(j < i)
        {
            if (box->index[j] < box->index[i] && len[i] <= len[j] + 1)
            { 
                len[i] = len[j] + 1;
				map[i] = j;
                if (box->max < len[i])
                {
                    box->max = len[i];
					box->max_pos = i;
            	}
        	}
			j++;
		}
        i++;
    }
	return(map);
}

int	*ft_find_lis_pos(t_toolbox *box)
{
	int *map;
	int *pos;
	int i;
	int j;
	int k;
	
	k = 1;
	map = find_lis_len(box);
	pos = ft_calloc(box->max, sizeof(int));
	i = box->max_pos;
	j = box->max_pos;
	pos[0] = i;
	while(i >= 0)
	{
		
		while(j >= 0)
		{
			if (map[i] == j)
			{
				i = j;
				pos[k++] = j;
			}
			j--;
		}
		i--;
	}
	return(pos);
}

int *ft_lis_keeper(t_toolbox *box)
{
	int *pos;
	int i;
	int j;
	int k;
	pos = ft_find_lis_pos(box);
	box->lis = ft_calloc(box->max, sizeof(int));
	i = 0;
	k = 0;
	j = box->max_pos;
	while(i < box->max)
	{
		j = box->max_pos;	
		while(j >= 0)
		{
			if (pos[i] == j)
			{
				box->lis[k++] = box->index[j];
			}
			j--;
		}
		i++;
	}
	return(&(*box->lis));
}