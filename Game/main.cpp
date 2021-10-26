
#include <iostream>
#include <vector>
using namespace std;


int main()
{
    vector<short int> host_kit_color;
    vector<short int> guest_kit_color;
    unsigned int numerOfTeams;
    short int homeColor;
    short int guestColor;
    unsigned int counter = 0;

    cin >> numerOfTeams;
    

    
    for (int i = 0; i < numerOfTeams; i++)
    {
        cin >> homeColor;
        host_kit_color.push_back(homeColor);

        cin >> guestColor;
        guest_kit_color.push_back(guestColor);
    }

    for (int i = 0; i < numerOfTeams; i++) {
        for (int j = 0; j < numerOfTeams; j++)
        {
            if (host_kit_color[i] == guest_kit_color[j])
            {
                counter++;
            }
        }
    }

    cout << counter;
   
    return 0;
}
