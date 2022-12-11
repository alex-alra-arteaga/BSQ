/*
** EPITECH PROJECT, 2022
** my_getnbr
** File description:
** library
*/
int my_strlen(char const *str);

int change_sign(int sign, int number)
{
    if (sign == -1)
        number = number * sign;
}

int get_sign_before_int(int i, char const *str, int sign)
{
    while (str[i] == '-' || str[i] == '+') {
        if (str[i] == '-') {
            sign = sign * -1;
        }
        i++;
    }
    return (sign);
}

int prevent_under_overflow(char *aux, int i, int number, int number1)
{
    i = 0;
    while (aux[i] != '\0') {
        if (number < number1) {
            return (0);
        } else {
            number1 = number;
            number = number * 10 + aux[i] - '0';
            i++;
        }
    }
    return (number);
}

int my_getnbr(char const *str)
{
    int i = 0;
    int number = 0;
    int count = 0;
    int sign = 1;
    int number1 = 0;
    char aux[my_strlen(str)-1];
    sign = get_sign_before_int(i, str, sign);
    while (str[i]) {
        if (str[i] <= '9' && str[i] >= '0')
            aux[count++] = str[i];
        if ((str[i] <= '9' && str[i] >= '0')
            && (str[i + 1] > '9' || str[i + 1] < '0')) {
            aux[count] = '\0';
            number = prevent_under_overflow(aux, i, number, number1);
            change_sign(sign, number);
            return (number);
        }
        i++;
    }
    return (0);
}
/*
int main(void)
{
    my_getnbr("return-432dsa+1");
    this won't work, a change in sign accountability is needed
    return (0);
}
*/
