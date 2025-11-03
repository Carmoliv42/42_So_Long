#include "so_long.h"

static void trim_line(char *line)
{
    int len;

    len = so_strlen(line);
    while (len > 0 && (line[len - 1] == '\n' || line[len - 1] == '\r'))
    {
        line[len - 1] = '\0';
        len--;
    }
}

static int  get_map_height(const char *file)
{
    int fd;
    int height;
    char *line;

    fd = open(file, O_RDONLY);
    if (fd < 0)
        return (-1);
    height = 0;
    while ((line = get_next_line(fd)))
    {
        free(line);
        height++;
    }
    close(fd);
    return (height);
}

static char **fill_map(const char *file, int height)
{
    int fd;
    int i;
    char *line;
    char **map;

    fd = open(file, O_RDONLY);
    if(fd < 0)
        return (NULL);
    map = malloc(sizeof(char *) * (height + 1));
    if(!map)
        return (NULL);
    i = 0;
    while((line = get_next_line(fd)))
    {
        trim_line(line);
        map[i++] = line;
    }
    map[i] = NULL;
    close(fd);
    return(map);
}

char **read_map(const char *file, t_game *game)
{
    char **map;

    game->height = get_map_height(file);
    if (game->height <= 0)
        return (NULL);
    map = fill_map(file, game->height);
    if (!map)
        return (NULL);
    if (map[0])
        game->width = so_strlen(map[0]);
    else
        game->width = 0;
    return (map);
}
