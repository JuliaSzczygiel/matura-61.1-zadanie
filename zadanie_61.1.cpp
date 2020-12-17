#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

const int D = 100;

int main()
{
    ifstream filein;
    ofstream fileout;
	filein.open("ciagi.txt");
	fileout.open("wyniki.txt");

    int sequence[1000];
    int HowManyArith = 0;
    int MaxDifference = 0;

    
        for(int a = 0; a < D; a++)
        {
            int length;
            filein >> length;

            for(int i = 0; i < length; i++)
                filein >> sequence[i];
                int Difference = sequence[1] - sequence[0];
                bool arith = true;
                    for(int i = 0; i+1 < length; i++)
                        if (sequence[i+1] - sequence[i] != Difference)
                        {
                            arith = false;
                            break;
                        }
            if (arith)
            {
                HowManyArith++;
                if (Difference>MaxDifference)
                    MaxDifference = Difference;
            }
        }
    
    cout << "Ile jest ciagow arytmetycznych: " << HowManyArith << endl;
    cout << "Jaka jest najwieksza roznica: " << MaxDifference << endl;
    filein.close();
	fileout.close();
}
