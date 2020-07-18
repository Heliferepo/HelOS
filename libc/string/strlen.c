size_t strlen(const char *str)
{
    size_t len = 0;
    if(!str)
        return (len);
    while (str[len])
        len++;
    return (len);
}
