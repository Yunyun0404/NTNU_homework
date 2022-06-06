// #define DEBUG
#include "myvector.h"
#include <unistd.h>
#include <stdio.h>
#include <math.h>

int main()
{
    int stdout_bk = dup(fileno(stdout));
    int score = 0;
    int choice;
    scanf("%d", &choice);

    if (choice == 6)
    {
        if (myvector_set(NULL, 1, 3, 4) == -1)
            score += 1;
        printf("%d", score);
        return 0;
    }

    sVector *cartesian_a = myvector_init();
    myvector_set(cartesian_a, 1, 3, 4);

    sVector *cartesian_b = myvector_init();
    myvector_set(cartesian_b, 1, -2, -1);

    sVector *polar_a = myvector_init();
    myvector_set(polar_a, 2, 3, M_PI / 2);

    sVector *polar_b = myvector_init();
    myvector_set(polar_b, 2, 7, M_PI * 7 / 4);

    if (choice == 1 || choice == 2)
    {
        int pipefd[2];
        pipe(pipefd);

        // What used to be stdout will now go to the pipe.
        dup2(pipefd[1], fileno(stdout));

        if (choice == 1)
        {
            myvector_print(cartesian_a, 1);
            myvector_print(cartesian_a, 2);

            myvector_print(polar_a, 1);
            myvector_print(polar_a, 2);
        }

        if (choice == 2)
        {
            sVector *test = myvector_init();
            myvector_add(test, cartesian_a, cartesian_b);
            myvector_print(test, 1);

            myvector_add(test, cartesian_a, polar_a);
            myvector_print(test, 1);

            myvector_add(test, polar_a, cartesian_a);
            myvector_print(test, 1);

            myvector_add(test, polar_a, polar_b);
            myvector_print(test, 1);
        }

        fflush(stdout);
        close(pipefd[1]);
        dup2(stdout_bk, fileno(stdout)); // restore
        char buf[1001];
        read(pipefd[0], buf, 1000);

        double n[8];
        if (choice == 1)
        {
            double answers[8] = {3, 4, 5, 0.3, 0, 3, 3, 0.5};
            fprintf(stderr, "%s", buf);
            sscanf(buf, "(%lf, %lf) (%lf, %lf-pi) (%lf, %lf) (%lf, %lf-pi)", n, n + 1, n + 2, n + 3, n + 4, n + 5, n + 6, n + 7);

            for (int i = 0; i < 8; i += 2)
            {
                if (fabs(n[i] - answers[i]) < 0.1 && fabs(n[i + 1] - answers[i + 1]) < 0.1)
                    score += 1;
            }
        }

        if (choice == 2)
        {
            double answers2[8] = {1, 3, 3, 7, 3, 7, 4.95, -1.95};
            fprintf(stderr, "%s", buf);
            sscanf(buf, "(%lf, %lf) (%lf, %lf) (%lf, %lf) (%lf, %lf)", n, n + 1, n + 2, n + 3, n + 4, n + 5, n + 6, n + 7);

            for (int i = 0; i < 8; i += 2)
            {
                if (fabs(n[i] - answers2[i]) < 0.1 && fabs(n[i + 1] - answers2[i + 1]) < 0.1)
                    score += 1;
            }
        }
    }

    if (choice == 3)
    {
        double inner = 0;

        myvector_inner_product(&inner, cartesian_a, cartesian_b);
        if (fabs(inner - (-10)) < 0.1)
            score += 1;

        myvector_inner_product(&inner, cartesian_a, polar_a);
        if (fabs(inner - 12) < 0.1)
            score += 1;

        myvector_inner_product(&inner, polar_a, cartesian_a);
        if (fabs(inner - 12) < 0.1)
            score += 1;

        myvector_inner_product(&inner, polar_a, polar_b);
        if (fabs(inner - (-14.85)) < 0.1)
            score += 1;
    }

    if (choice == 4)
    {
        double area = 0;

        myvector_area(&area, cartesian_a, cartesian_b);
        if (fabs(area - 5) < 0.1)
            score += 1;

        myvector_area(&area, cartesian_a, polar_a);
        if (fabs(area - 9) < 0.1)
            score += 1;

        myvector_area(&area, polar_a, cartesian_a);
        if (fabs(area - 9) < 0.1)
            score += 1;

        myvector_area(&area, polar_a, polar_b);
        if (fabs(area - 14.8) < 0.1)
            score += 1;

        sVector *parallel_a = myvector_init();
        myvector_set(parallel_a, 1, 0, -200);

        sVector *parallel_b = myvector_init();
        myvector_set(parallel_b, 2, 300, M_PI * 1 / 2);

        myvector_area(&area, parallel_a, parallel_b);
        if (fabs(area - 0) < 0.1)
            score += 1;
    }
    if (choice == 5)
    {

        double X, Y, Tx = 100000, Ty = -100000;
        myvector_cvp(&X, &Y, &Tx, &Ty, cartesian_a, polar_a);
        if (fabs(X - 99996) < 0.1 && fabs(Y - (-100000)) < 0.1)
            score += 1;

        Tx = 50000;
        Ty = -50000;
        myvector_cvp(&X, &Y, &Tx, &Ty, polar_b, cartesian_b);
        if (fabs(X - 50002.35) < 0.1 && fabs(Y - (-50002.35)) < 0.1)
            score += 1;
    }

    printf("分%d", score);
}
