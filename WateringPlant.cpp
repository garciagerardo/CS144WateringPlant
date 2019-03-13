/*
 * WateringPlant.cpp
 *
 *  Created on: Feb 1, 2019
 *      Author: jerry
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstdlib>

using namespace std;

/*** Complete this program. ***/

int main()
{
    const int UNITS_PER_CAN = 3;
    const string INPUT_FILE_NAME = "counts.txt";
    int plant_count;

    ifstream input;
    input.open(INPUT_FILE_NAME);
    if (input.fail())
    {
        cout << "Failed to open " << INPUT_FILE_NAME << endl;
        return -1;
    }


    // Loop once for each number of plants read from the input file.
    // Stop when the number of plants is 0 or less.
    // During each loop, simulate Plan Near and Plan Far.
    do
    {
        input >> plant_count;
        if(plant_count == 0) break;

        // Plan Near

        cout << endl;
        cout << "==========================" << endl;
        cout << " Plan Near with " << plant_count << " plants" << endl;
        cout << "==========================" << endl;
        cout << endl;
        cout << "Where      Cum. steps  Water amt.  Cum. step-units" << endl;
        cout << "---------  ----------  ----------  ---------------" << endl;

        int wateringCan = 3;
        int currentPlant = 1;
        int nearSteps = 0, nearStepUnits = 0, spot = 0, farSteps = 0, farStepUnits = 0;

        do{
        	nearSteps = nearSteps + (currentPlant - spot);
        	nearStepUnits = nearStepUnits + (wateringCan * (currentPlant - spot));
        	cout << "Plant  " << currentPlant << setw(10) << nearSteps << setw(10) << wateringCan << setw(15) << nearStepUnits << endl;
        	spot = currentPlant;
        	wateringCan--;

        	if(wateringCan == 0 || currentPlant == plant_count){
        		nearSteps += currentPlant;
        		nearStepUnits += (currentPlant * wateringCan);
        		spot = 0;
        		cout << "FAUCET  " << setw(10) << nearSteps << setw(10)<< wateringCan << setw(15) << nearStepUnits << endl;
        		wateringCan = 3;
        	}
        	currentPlant++;
        }while(currentPlant <= plant_count);
        
        cout << endl << "Plan Near: Total steps = " << nearSteps << ", total step-units = " << nearStepUnits << endl;

        /*** Complete the code for Plan Near. ***/

        // Plan Far

        cout << endl;
        cout << "=========================" << endl;
        cout << " Plan Far with " << plant_count << " plants" << endl;
        cout << "=========================" << endl;
        cout << endl;
        cout << "Where      Cum. steps  Water amt.  Cum. step-units" << endl;
        cout << "---------  ----------  ----------  ---------------" << endl;
        
        /*** Complete the code for Plan Far. ***/

        currentPlant = plant_count;
        spot = 0;

        do{
        	farSteps = farSteps + abs(spot - currentPlant);
        	farStepUnits = farStepUnits + (wateringCan * abs(currentPlant - spot));
        	cout << "Plant  " << currentPlant << setw(10) << farSteps << setw(10) << wateringCan << setw(15) << farStepUnits << endl;
        	spot = currentPlant;
        	wateringCan--;

        	if(wateringCan == 0 || currentPlant == 1){
        		farSteps += currentPlant;
        		farStepUnits += (currentPlant * wateringCan);
        		spot = 0;
        		cout << "FAUCET  " << setw(10) << farSteps << setw(10)<< wateringCan << setw(15) << farStepUnits << endl;
        		wateringCan = 3;
        	}
        	currentPlant--;
        }while(currentPlant > 0);

        cout << endl << "Plan Far: Total steps = " << farSteps << ", total step-units = " << farStepUnits << endl;

        // Which plan is better? Better means fewer step-units.
        cout << endl;
        cout << "*** With " << plant_count << " plants, ";
        if(nearStepUnits < farStepUnits){
        	cout << "Plan Near is better with " << (farStepUnits - nearStepUnits) << " fewer step-units" << endl;
        }
        else{
        	cout << "Plan Far is better with " << (nearStepUnits - farStepUnits) << " fewer step-units" << endl;
        }
        
        /*** Complete the code to determine the better plan. ***/

    } while (plant_count > 0);
    
    return 0;
}
