/* find square root */

int sqrt_root(int number)
{
    int temp;
    int x;
    if (number < 0)
        number = -number;
    while ()
    for (temp = 0, x = 1u << (sizeof(unsigned int) * 4 - 1); x; x >>= 1) {
        if ((temp | x) * (temp | x) <= number)
            temp |= x;
    }
    return temp;
}

/*find size of field */

int find_field_size(int tetro_num)
{
    int     size;

    size = sqrt_root(num * 4);
    return size;
}