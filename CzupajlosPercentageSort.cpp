// Author: Piotr Czupajlo
// CzupajlosPercentageSort
// CzupajlosPercentageSort © 2024 by Piotr Czupajło is licensed under CC BY-NC 4.0.
// To view a copy of this license, visit http://creativecommons.org/licenses/by-nc/4.0/
#include <iostream>
constexpr size_t n = 10000;
using namespace std;
void CzupajlosPercentageSort(int ints[]) {
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

    double section = max - min;


    int* results = new int[n];
    short* results2 = new short[n];

    for (int i = 0; i < n; i++)
    {
        results[i] = max + 1;
        results2[i] = 0;
    }
    //setting the 2d array


    for (int i = 0; i < n; i++)
    {
        double percentage = (ints[i] - min) / section;
        int position = percentage * (n - 1);
        if (results[position] == max + 1 || results[position] == ints[i])
        {
            results[position] = ints[i];
            results2[position]++;
        }
        //if nothing stands on its position
        else {

            //if its the same number it increase the second dimension
            int x = 0;
            bool doineed = true;
            if (results[position] > ints[i])
            {

                for (int s = position; s >= 0; s--)
                {
                    if (ints[i] == results[s])
                    {
                        results2[s]++;
                        doineed = false;
                        s = -1;
                    }
                    else if (ints[i] > results[s] || s == 0 || results[s] == max + 1)
                    {
                        x = s;
                        s = -1;

                    }

                }
            }
            //searching for proper position while going down
            else
            {

                for (int s = position; s < n; s++)
                {
                    if (ints[i] == results[s])
                    {
                        results2[s]++;
                        doineed = false;
                        s = n + 1;
                    }
                    else if (ints[i] < results[s] || s == n - 1)
                    {
                        x = s;
                        s = n + 1;
                    }
                }
            }
            //searching for proper position while going up
            if (doineed == true)
            {
                int temp = ints[i];
                short temp3 = 1;
                int z = 0;
                bool isempty = false;
                int counterdirection = -1;
                if (x > n / 2)
                {
                    while (isempty == false && x + z < n)
                    {
                        if (results[x + z] == max + 1)
                        {
                            isempty = true;
                            counterdirection = 1;

                        }
                        else if (results[x - z] == max + 1)
                        {
                            isempty = true;
                        }
                        z++;
                    }

                }
                else
                {
                    counterdirection = 1;
                    while (isempty == false && x - z >= 0)
                    {
                        if (results[x + z] == max + 1)
                        {
                            isempty = true;

                        }
                        else if (results[x - z] == max + 1)
                        {
                            isempty = true;
                            counterdirection = -1;
                        }
                        z++;
                    }
                }
                //searching for nearest placeholder
                if (counterdirection == 1)
                {
                    while (x < n)
                    {
                        if (results[x] == max + 1)
                        {
                            results[x] = temp;
                            results2[x] = temp3;
                            x = n;
                        }
                        else
                        {
                            if (temp < results[x])
                            {
                                swap(temp, results[x]);
                                swap(temp3, results2[x]);
                            }
                            x++;
                        }


                    }
                }
                //pushing everything up
                else
                {
                    while (x >= 0)
                    {
                        if (results[x] == max + 1)
                        {
                            results[x] = temp;
                            results2[x] = temp3;
                            x = -1;

                        }
                        else
                        {
                            if (temp >= results[x])
                            {
                                swap(temp, results[x]);
                                swap(temp3, results2[x]);
                            }

                            x--;
                        }



                    }

                }
                //pushing everything down







            }


        }
    }
    int counter = 0;
    for (int i = 0;i < n; i++)
    {
        for (int j = 0; j < results2[i]; j++)
        {
            ints[counter] = results[i];
            counter++;
        }
    }
    delete[] results;
    delete[] results2;
    //decoding the array
}
int main()
{
    int ints[n];



        for (int i = 0;i < n;i++)
        {
            double z = rand() % n;
            ints[i] = z;

        }
        CzupajlosPercentageSort(ints);
        for (int i = 0;i < n;i++)
        {
            cout << ints[i] << "\n";

        }
    

    
    cout << "CPS!";

}

// Author: Piotr Czupajlo
// CzupajlosPercentageSort
// CzupajlosPercentageSort © 2024 by Piotr Czupajło is licensed under CC BY-NC 4.0.
// To view a copy of this license, visit http://creativecommons.org/licenses/by-nc/4.0/