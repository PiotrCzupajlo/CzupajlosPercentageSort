﻿// Author: Piotr Czupajlo
// CzupajlosPercentageSort

#include <iostream>
constexpr size_t n = 1000;
using namespace std;
double* CzupajlosPercentageSort(int ints[]) {
    double max = ints[0];
    double min = 0;


    for (int i = 0; i < n; i++)
    {
        if (max < ints[i])
            max = ints[i];
        else if (min > ints[i])
        {
            min = ints[i];
        }


    }

    double section = max;
    if (min < 0)
    {
        section = max - min;
    }

    double doublemin = min;
    double results[n][2];
    for (int i = 0; i < n; i++)
    {
        results[i][0] = max + 1;
        results[i][1] = 0;
    }

    int counterdown = n / 2;
    int counterup = n - counterdown;

    for (int i = 0; i < n; i++)
    {
        double percentage = ((ints[i] - min) / section);
        int position = (percentage * (n - 1));
        if (results[position][0] == max + 1)
        {
            results[position][0] = ints[i];
            results[position][1] = 1;
            if (position > n / 2)
                counterup--;
            else counterdown--;


        }
        else {

            bool isempty = false;
            int emptyposition = 0;
            bool correct = false;
            int j = 0;
            int x = 0;
            int x2 = 0;
            double temp;
            double temp2;
            double temp3;
            if (results[position][0] == ints[i])
            {
                results[position][1]++;
            }
            else
            {

                bool doineed = true;
                if (results[position][0] > ints[i])
                {

                    for (int s = position; s >= 0; s--)
                    {
                        if (ints[i] == results[s][0])
                        {
                            results[s][1]++;
                            doineed = false;
                            s = -1;
                        }
                        else if (ints[i] > results[s][0] || s == 0 || results[s][0] == max + 1)
                        {
                            x = s;
                            s = -1;

                        }

                    }
                }

                else
                {

                    for (int s = position; s < n; s++)
                    {
                        if (ints[i] == results[s][0])
                        {
                            results[s][1]++;
                            doineed = false;
                            s = n + 1;
                        }
                        else if (ints[i] < results[s][0] || s == n - 1)
                        {
                            x = s;
                            s = n + 1;
                        }
                    }
                }
                if (doineed == true)
                {
                    x2 = x;
                    temp = ints[i];
                    temp3 = 1;
                    emptyposition = x;
                    int z = 0;
                    isempty = false;
                    correct = false;
                    int counterdirection = 0;
                    while (isempty == false && emptyposition - z >= 0 && emptyposition + z < n)
                    {
                        if (results[emptyposition + z][0] == max + 1)
                        {
                            isempty = true;
                            counterdirection = 1;
                        }
                        else if (results[emptyposition - z][0] == max + 1)
                        {
                            isempty = true;
                            counterdirection = -1;
                        }
                        z++;
                    }
                    if (isempty == false)
                    {
                        if (emptyposition - z < 0)
                            counterdirection = 1;
                        else
                            counterdirection = -1;
                    }

                    if (counterdirection == 1)
                    {
                        while (correct == false && x < n)
                        {
                            if (results[x][0] == max + 1)
                            {
                                results[x][0] = temp;
                                results[x][1] = temp3;
                                correct = true;
                                if (x > n / 2)
                                    counterup--;
                                else
                                {
                                    counterdown--;
                                }
                            }
                            else
                            {
                                if (temp < results[x][0])
                                {
                                    swap(temp, results[x][0]);
                                    swap(temp3, results[x][1]);
                                }
                                x++;
                            }


                        }
                    }
                    else
                    {
                        correct = false;
                        while (correct == false && x2 >= 0)
                        {
                            if (results[x2][0] == max + 1)
                            {
                                results[x2][0] = temp;
                                results[x2][1] = temp3;
                                correct = true;
                                if (x2 > n / 2)
                                    counterup--;
                                else counterdown--;

                            }
                            else
                            {
                                if (temp >= results[x2][0])
                                {
                                    swap(temp, results[x2][0]);
                                    swap(temp3, results[x2][1]);
                                }
                                x2--;

                            }



                        }

                    }




                }


            }


        }
    }
    int counter = 0;
    double* values = new double[n];
    for (int i = 0;i < n; i++)
    {
        for (int j = 0; j < results[i][1]; j++)
        {
            values[counter] = results[i][0];
            counter++;
        }
    }
    return values;

}
int main()
{
    int ints[n];


    for (int i = 0;i < n;i++)
    {
        double z = rand() % n;
        ints[i] = z;

    }
    double* ptr = CzupajlosPercentageSort(ints);
    cout << "CPS!";

}

// Author: Piotr Czupajlo
// CzupajlosPercentageSort