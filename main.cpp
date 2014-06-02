#include <cstdlib>
#include <iostream>
#include <fstream>
#include <ctime>
#include <vector>
#include <string>
#include "truck.h"
#include "motorcycle.h"

using namespace std;

void delay(int);
void help();

int main(int argc, char* argv[]){
    vector<Vehicle*> race_vehicles; //create new vector of vehicle pointers
    srand(time(NULL));//create new srand
    int race_distance = 0;//create variable for race distance
    int speed_of_race = 0;//create fast or slow
    Vehicle* v;
    
    //read arguments
    //check for -tm #
    //check for -s or -f
    if (argc == 1){
      cout << "need more info! help?" << endl;
      help();
      return 1; 
    }

    for (int i = 1; i < argc; i++){
        string in = argv[i];

        if(in == "-tm"){
            if((i+1 > argc) || (atoi(argv[i + 1]) == 0) || (atoi(argv[i + 1]) > 40)){
                cout << "Invalid input for miles!" << endl;
                help();
                return 1;
            }
            race_distance = atoi(argv[i + 1]);
        }
        else if(in == "-s"){
            speed_of_race = 3;
        }
        else if(in == "-f"){
            speed_of_race = 1;
        }
    }
    //end of arg check
    
    //open file
    //check if open correctly
    ifstream in_file("vehicles.dat");
    if (in_file.fail()){
        cout << "could not open file!" << endl;
        return 1;
    }


    //use while loop and read file and store into new objects depending on first char
        //if first character is t
            // push vector back by adding new truck instance with variables
        //else if it's a m
            // push vector back by adding new morotorcycle instance with variables from file
        //end else if
    //end while loop
    
    char type;
    string name;
    char symbol;
    float speed_of_vehicle;
    float wheel_radius;

    while(in_file >> type){
        if(type == 't'){
          //get values and make moto
            in_file >> name >> symbol >> speed_of_vehicle >> wheel_radius;
            race_vehicles.push_back(new Truck(name, symbol, speed_of_vehicle, wheel_radius, false));
        }
        else if(type == 'm'){
          //get values and make moto
            in_file >> name >> symbol >> speed_of_vehicle >> wheel_radius;
            race_vehicles.push_back(new Motorcycle(name, symbol, speed_of_vehicle, wheel_radius));
        }  
    }

    
    //display racers with for loop going through vecotr use mapnip
    //for every instance
    // unrefecnce pointer.display();
    //end loop
    cout << endl << endl << endl;
    cout << "We have the following racers that will race for " << race_distance <<" miles!" << endl;
    for(int i = 0; i < race_vehicles.size(); i++){
        v = race_vehicles[i];
        v->display();
    }
    
    //loop until race is finished

    int miles_gone = 0;
    bool over = false;
    vector<int> winners_index;
    while(!over){
        for(int i = 0; i < race_vehicles.size(); i++){
            miles_gone = race_vehicles.at(i)->go(speed_of_race);
            for(int x = 0; x < miles_gone; x++){
                cout << ".";
            }
            cout << race_vehicles.at(i)->getSymbol() << endl;

            
            if(miles_gone >= race_distance){
                winners_index.push_back(i);
                over = true;
            }            
        }
            cout << endl << endl;
            delay(speed_of_race);
    }
    //print out number of miles traved with (.) then symbol of object
    //newline
    //wait certain amount of time
    //check to see if we have a winner
    //if yes then end the loop
    //end loop
   
    //display winner/winners
    //have them honk their horn/horns
        cout << "the winner is ..." << endl;
        for(int i = 0; i < winners_index.size(); i++){
            race_vehicles.at(winners_index[i])->display();
            race_vehicles.at(winners_index[i])->honkHorn();
        }

    //delete the pointers using deconstructors
    for(int i = 0; i < race_vehicles.size(); i++){
        v = race_vehicles[i];
        v->~Vehicle(); // BB -1 delete v;
    }
    
    return 0;
}


void delay(int speed_of_race){
    //delay fucntion
    bool delayed = false;
    long start_time = time(NULL);
    long end_time;
    long elapsed_time;

    while(!delayed){
        end_time = time(NULL);
        elapsed_time = end_time - start_time;

        if(elapsed_time >= speed_of_race){
            delayed = true;
        }//end if
    }//end while

}

void help(){
    //give user help on what arguments to pass in/ range of inputs
    cout << endl << endl;
    cout << "Please insert the following command line arguments: " << endl;
    cout << "\"-tm #\" will determine the total miles required. range 0 < # < 40" << endl;
    cout << "\"-f\" or \"-s\" will determine speed of delay between each frame." << endl;
    cout << "example: \"a.out -tm 25 -f\"" << endl;
    cout << endl << endl;
}
// BB 116 / 120 
