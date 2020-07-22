/*
** EPITECH PROJECT, 2020
** CPE_dante_2019
** File description:
** main
*/

#include "../include/dante.h"
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

map *algo(map *maps, int x, int y)
{
    if (maps->map[maps->line-1][maps->col-1] != '*') exit (84);
    int li = maps->line - 1, c = maps->col - 1, i = 0;
    maps->map[y][x] = 'o';
    if (x == c && y == li) {
        for (i = 0; maps->map[i+1] != NULL; i++)
            printf("%s\n", maps->map[i]);
        printf("%s", maps->map[i]);
        exit (0);
    }
    if (y != li && maps->map[y+1][x] == '*')
        algo(maps, x, (y+1));
    if (x != c && maps->map[y][x+1] == '*')
        algo(maps, (x+1), y);
    if (y != 0 && maps->map[y-1][x] == '*')
        algo(maps, x, (y-1));
    if (x != 0 && maps->map[y][x-1] == '*')
        algo(maps, (x-1), y);
    maps->map[y][x] = '*';
    return (0);
}

int gest_error(int ac, char **av, char *filepath)
{
    int col = 0, tmp = 0;
    struct stat size;
    char *buffer;
    int fd = open(filepath, O_RDONLY);
    stat(filepath, &size);
    buffer = malloc(sizeof(char) * (size.st_size + 1));
    read(fd, buffer, size.st_size);
    buffer[size.st_size] = '\0';
    for (int j = 0; buffer[j] != '\n'; j++)
        col++;
    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == '\n') {
            if (tmp != col) return (84);
            tmp = 0;
        } else
            tmp++;
    }
    free(buffer);
    close(fd);
    return (0);
}

map *malloc_map(int nbl, int nbc, char *filepath)
{
    char tmp = 0;
    int fd = open(filepath, O_RDONLY);
    char **tab = malloc(sizeof(char *) * (nbl + 1));
    for (int i = 0; i <= nbl; i++) {
        tab[i] = malloc(sizeof(char) * (nbc + 1));
        for (int o = 0; o < nbc; o++)
            read(fd, &tab[i][o], 1);
        read(fd, &tmp, 1);
        tab[i][nbc] = '\0';
    }
    tab[nbl] = NULL;
    map *maps = malloc(sizeof(map));
    maps->map = tab;
    maps->col = nbc;
    maps->line = nbl;
    return (maps);
}

map *get_map(char *filepath)
{
    int lg = 1, col = 0;
    struct stat size;
    char *buffer;
    int fd = open(filepath, O_RDONLY);
    if (fd == -1) {
        printf("Can't open file\n");
        exit (84);
    }
    if (stat(filepath, &size) == -1) exit (84);
    buffer = malloc(sizeof(char) * (size.st_size + 1));
    read(fd, buffer, size.st_size);
    buffer[size.st_size] = '\0';
    for (int j = 0; buffer[j] != '\n'; j++)
        col++;
    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == '\n')
            lg++;
    }
    close(fd);
    free(buffer);
    return (malloc_map(lg, col, filepath));
}

int main(int ac, char **av)
{
    if (ac != 2)
        return (84);
    if (gest_error(ac, av, av[1]) != 0)
        return (gest_error(ac, av, av[1]));
    map *maps = get_map(av[1]);
    algo(maps, 0, 0);
    for (int i = 0; i <= maps->line; i++)
        free(maps->map[i]);
    free(maps->map);
    free(maps);
    return (0);
}