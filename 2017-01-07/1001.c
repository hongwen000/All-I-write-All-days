main(n)
{
    float b;
    for (;n = scanf("%f", &b), b; printf("%d card(s)\n", n - 1))
        for (; b > 0;) b -= 1. / ++n;
}
