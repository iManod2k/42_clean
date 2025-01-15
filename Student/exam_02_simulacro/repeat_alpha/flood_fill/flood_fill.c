#include "flood_fill.h"

void    flood(char **tab, t_point size, t_point begin, char c)
{
    if (begin.x >= size.x || begin.x < 0)
        return ;
    if (begin.y >= size.y || begin.y < 0)
        return ;
    if (c != tab[begin.y][begin.x])
        return ;
    tab[begin.y][begin.x] = 'F';
    flood(tab, size, (t_point) {begin.x+1, begin.y}, c);
    flood(tab, size, (t_point) {begin.x-1, begin.y}, c);
    flood(tab, size, (t_point) {begin.x, begin.y+1}, c);
    flood(tab, size, (t_point) {begin.x, begin.y-1}, c);
}

void    flood_fill(char **tab, t_point size, t_point begin)
{
    flood(tab, size, begin, tab[begin.y][begin.x]);
}