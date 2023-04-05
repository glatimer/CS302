#include "network.h"

/* ===============================================================================
                       CS302 Assignment 1 - Genevieve Latimer
   -------------------------------------------------------------------------------
	 main.cpp will manage the client experience of the application
   =============================================================================== */
using namespace std;

// static const int WORD = 40;

int main(void)
{
    // variables
    int choice;
    int response {};
    char option {' '};
    char a_name[SIZE] {' '};
    bool is_wifi {false};

    // login

    // greeting
    do
    {
		cout << "\n---------------------------------------------------" << endl;
		cout << "                 Smart Home Manager                  " << endl;
		cout << "---------------------------------------------------\n" << endl;
		cout << "\n(1) Smart Thermostat \n(2) Smart Security System"
			<< "\n(3) Smart Sound System \n(4) Quit" << endl;
		cout << "\nMake a selection:  ";
		cin >> choice;
		cin.ignore(100, '\n');

		switch (choice)
		{
			case 1:
			{		
			
			// There will never be a need for too many thermostats in one house, 
			// but in the event that we need an upstairs and downstairs thermostat
			// there will be an option for a collection of thermostats
			vector <thermostat> residence;
				thermostat device_1; 
			// ARR_LLL therm_schedule;
			// schedule event;
				char a_mode[SIZE] {' '};
				int new_temp {0};
				int set_temp {0};

				// thermostat menu
				cout << "----------------------------------------------------------------" << endl;
				cout << "                      SMART THERMOSTAT                          " << endl;
				cout << "----------------------------------------------------------------" << endl;
			do  
			{   
				cout << "\n[1] Setup Thermostat"
					<< "\n[2] Set Temperature"
					<< "\n[3] Display Status" 
					// set schedule
					<< "\n[4] Return to Main Menu" 
					<< "\nSelection: ";
				cin >> response;
				cin.ignore(100, '\n');
				if (response == 1) 
				{ 
					cout << "----------------------------------------------------------------" << endl;
					cout << "                          ADD THERMOSTAT                        " << endl;
					cout << "----------------------------------------------------------------" << endl;
					// manual add
					cout << "Name: ";
					cin.get(a_name, SIZE, '\n');
					cin.ignore(100, '\n');

					cout << "Connect to Wifi (y/n)? ";
					cin >> option;
					option = tolower(option);
					if (option == 'y') is_wifi = true;
					else is_wifi = false;


					cout << "Temperature: ";
					cin >> new_temp;
					cin.ignore(100, '\n');

					cout << "Mode (Heat, Cool, Away): ";
					cin.get(a_mode, SIZE, '\n');
					cin.ignore(100, '\n');
					device_1 = thermostat(a_name, is_wifi, new_temp, a_mode); 

					do
					{
						cout << "Would you like to add a temperature sensor to your network?" << endl;
						cout << "(y/n): ";
						cin >> option;
						option = tolower(option);
						if (option == 'y')
						{
							string location {' '};
							cout << "Sensor Location: ";
							cin >> location;
						device_1.add_sensor(location);
						}
					} while (option != 'n');

					residence.push_back(device_1);

				}
				else if (response == 2) 
				{ 
					cout << "----------------------------------------------------------------" << endl;
					cout << "                  SET THERMOSTAT TEMPTERATURE                   " << endl;
					cout << "----------------------------------------------------------------" << endl;
					cout << "Enter the name of the thermostat: ";
					cin.get(a_name, SIZE, '\n');
					cin.ignore(100, '\n');
					for (thermostat item : residence)
					{
					if (item.compare_name(a_name) == true)
					{

						cout << "Set Temperature: ";
						cin >> set_temp;
						new_temp = device_1.set_temperature(set_temp); 
						cout << "The temperature was set to " << new_temp << " degrees." << endl;
					}
					else
					{
						cout << "The thermostat " << a_name << " could not be found." << endl;
					}
					}
				}
				else if (response == 3) 
				{ 
					cout << "----------------------------------------------------------------" << endl;
					cout << "                    THERMOSTAT NETWORK                          " << endl;
					cout << "----------------------------------------------------------------" << endl;
					for (thermostat item : residence)
					{
						cout << endl;
					item.display();
					cout << endl;
					}
				}
			} while (response != 4); 
			break;
			}
			case 2:
			{

				// smart_lock setup
			smart_lock device_2;
			vector <smart_lock> security;
			int PIN_entry {0};

				// smart_lock menu
			do  
			{   
				cout << "\n[1] Setup Smart Lock"
					<< "\n[2] Remote Secure" 
					<< "\n[3] Add PIN"
					<< "\n[4] Remote Check Lock" 
					<< "\n[5] Display Status" 
					<< "\n[6] Return to Main Menu" 
					<< "\nSelection: ";
				cin >> response;
				cin.ignore(100, '\n');
				if (response == 1) 
				{ 
					// smart lock setup
					cout << "----------------------------------------------------------------" << endl;
					cout << "                      SMART LOCK SETUP                          " << endl;
					cout << "----------------------------------------------------------------" << endl;


					cout << "Name: ";
					cin.get(a_name, SIZE, '\n');
					cin.ignore(100, '\n');

					cout << "Connect to Wifi (y/n)? ";
					cin >> option;
					option = tolower(option);
					if (option == 'y') is_wifi = true;
					else is_wifi = false;
					
					cout << "Create Master PIN: ";
					cin >> PIN_entry;
					cin.ignore(100, '\n');


					device_2 = smart_lock(a_name, is_wifi, PIN_entry); 

					do
					{
						cout << "Would you like to add a security sensor to your surveillance network?" << endl;
						cout << "(y/n): ";
						cin >> option;
						option = tolower(option);
						if (option == 'y')
						{
							string location {' '};
							cout << "Sensor Location: ";
							cin >> location;
							cin.ignore(100, '\n');
						device_2.add_sensor(location);
						}
					} while (option != 'n');

					security.push_back(device_2);

				}
				else if (response == 2) 
				{ 
					// remote unlock device
					cout << "----------------------------------------------------------------" << endl;
					cout << "                        REMOTE SECURE                           " << endl;
					cout << "----------------------------------------------------------------" << endl;

					cout << "Enter Smart Lock Name: ";
					cin.get(a_name, SIZE, '\n');
					cin.ignore(100, '\n');

					for (smart_lock item : security)
					{
						// we found the lock to check
					if (item.compare_name(a_name) == true)
					{
						// if the device is locked, ask if user wants to unlock
						if (item.check_lock() == true)
						{
							cout << a_name << " is locked. Would you like to remote unlock?\n";
							cout << "(y/n): ";
							cin >> option;
								cin.ignore(100, '\n');
							option = tolower(option);
							if ('y' == option)
							{
								cout << "---------------------------------------------" << endl;
								cout << "                   UNLOCK                    " << endl;
								cout << "---------------------------------------------" << endl;
								cout << "Enter your PIN: ";
								cin >> PIN_entry;
									cin.ignore(100, '\n');

								bool success = item.unlock(PIN_entry);
								if (success == true)
								{
								cout << a_name << " has been unlocked." << endl;
								}
								else
								{
								cout << "The PIN did not match any records." << endl;
								}
								}
						}
						else 
						{

							cout << a_name << " is unlocked. Would you like to remote lock?\n";
							cout << "(y/n): ";
							cin >> option;
							option = tolower(option);
							if ('y' == option)
							{
								cout << "---------------------------------------------" << endl;
								cout << "                    LOCK                     " << endl;
								cout << "---------------------------------------------" << endl;
								cout << "Enter your PIN: ";
								cin >> PIN_entry;
									cin.ignore(100, '\n');
								bool success = item.lock(PIN_entry);
								if (success == true)
								{
								cout << a_name << " has been locked." << endl;
								}
								else
								{
								cout << "The PIN did not match any records." << endl;
								}
								}
						}

					}
					else
					{
						cout << "The smart_lock " << a_name << " could not be found." << endl;
					}
					}
				}
				else if (response == 3) 
				{ 
					// add new PIN
					cout << "----------------------------------------------------------------" << endl;
					cout << "                        ADD A NEW PIN                          " << endl;
					cout << "----------------------------------------------------------------" << endl;
					cout << "Enter Smart Lock Name: ";
					cin.get(a_name, SIZE, '\n');
					cin.ignore(100, '\n');

					for (auto item : security)
					{
						// we found the requested lock 
						if (item.compare_name(a_name) == true)
						{
							int master_PIN {0};
						cout << "Confirm Master PIN: ";
						cin >> master_PIN;
						// if user correctly enters master PIN
						if (item.compare_masterPIN(master_PIN) == true)
						{
							do
							{
								cout << "Enter new PIN: " << endl;
								cin >> PIN_entry;
								cin.ignore(100, '\n');
								cout << "\n---------- CONFIRM PIN ----------" << endl;
								cout << "New Pin: " << PIN_entry << endl;
								cout << "Is this correct (y/n)? ";
								cin >> option;
								option = toupper(option);
								if ('Y' == option)
								{
									bool confirm = device_2.add_PIN(master_PIN, PIN_entry);
									if (confirm)
									{
										cout << "The PIN " << PIN_entry << " has been added to the list." << endl;
									}
									else 
									{
										cout << "The PIN " << PIN_entry << " could not be added to the list." << endl;
									}
								}
							} while (option == 'N');
						}
						// if the user does not enter the master PIN
						else
						{
							cout << master_PIN << " is not an authorized PIN." << endl;
						}

						}
						// if the lock was not found
						else
						{
							cout << "The smart_lock " << a_name << " could not be found." << endl;
						}
					}
				}
				else if (response == 4) 
				{ 
					// remote check lock
					cout << "----------------------------------------------------------------" << endl;
					cout << "                     REMOTE CHECK LOCK                          " << endl;
					cout << "----------------------------------------------------------------" << endl;
					cout << "Enter Smart Lock Name: ";
					cin.get(a_name, SIZE, '\n');
					cin.ignore(100, '\n');
					
					// find the smart_lock to check
					for (auto item : security)
					{
						// we found the requested lock 
						if (item.compare_name(a_name) == true)
						{
							// check the lock
						if (item.check_lock() == true)
						{
							cout << a_name << " is locked." << endl;
						}
						else 
						{
							cout << a_name << " is unlocked." << endl;
						}
							}
						// smart lock not found
						else 
						{
							cout << "The smart_lock " << a_name << " could not be found." << endl;
						}
					}

				}
				else if (response == 5) 
				{ 
					// display 
					cout << "----------------------------------------------------------------" << endl;
					cout << "                     SECURITY NETWORK                          " << endl;
					cout << "----------------------------------------------------------------" << endl;
					for (auto item : security)
					{
						cout << endl;
					item.display();
					cout << endl;
					}
				}
			} while (response != 6); 
			break;
			}
			case 3:
			{
				// setup smart sound variables
			CLL network;
			smart_sound device_3;
			string new_zone;
			vector <string> zone_list;

			//bool power button

			//int volume_level

			// smart sound menu
			do  
			{   
				cout << "\n[1] Add Smart Speaker to Network"
					<< "\n[2] Power ON/OFF by Zone" 
					<< "\n[3] Remove Select Smart Speaker" 
					<< "\n[4] Display Select Smart Speaker"
					<< "\n[5] Display All Speakers in Network" 
					<< "\n[6] Remove All Speakers in Network" 
					<< "\n[7] Return to Main Menu" 
					<< "\nSelection: ";
				cin >> response;
				cin.ignore(100, '\n');
				if (response == 1) 
				{ 
					// insert speaker into network
					cout << "----------------------------------------------------------------" << endl;
					cout << "                           ADD SPEAKER                          " << endl;
					cout << "----------------------------------------------------------------" << endl;

					cout << "Name: ";
					cin.get(a_name, SIZE, '\n');
					cin.ignore(100, '\n');

					cout << "Connect to Wifi (y/n)? ";
					cin >> option;
					option = tolower(option);
					if (option == 'y') is_wifi = true;
					else is_wifi = false;
					
					cout << "Zone: ";
					cin >> new_zone;
					cin.ignore(100, '\n');


					device_3 = smart_sound(is_wifi, a_name, new_zone); 
					if (network.insert(device_3))
					{
						cout << a_name << " was added to zone: " << new_zone << endl;
					}
					// we want to keep track of the zones created by the user
					// so that we can display them as a reminder, but we don't
					// want duplicates in the list -- don't add if its a dupe
					bool dupe {false};
					for (auto item : zone_list)
					{
					if (item == new_zone)
					{
					dupe = true;
					}
					}
					// add to zone list if not a dupe
					if (!dupe)
					{
					zone_list.push_back(new_zone);
					}
				}
				else if (response == 2) 
				{ 
					// remote unlock device
					cout << "----------------------------------------------------------------" << endl;
					cout << "                        POWER BUTTON                            " << endl;
					cout << "----------------------------------------------------------------" << endl;

					int num {0};
					int i {1};

					cout << "Here is a list of available zones." << endl; 
					for (auto item : zone_list)
					{
						cout << "[" << i << "]";
						cout << item << endl;
					++i;
					}
					cout << "Enter the zone number: ";
					cin >> num;
					cin.ignore(100, '\n');

					new_zone = zone_list[num-1];
					
					cout << "Power \n[1] On \n[2] Off" << endl;
					cout << "Selection: ";
					cin >> num;
					cin.ignore(100, '\n');
					
					int volume = 0;
					if (num == 1)
					{
						//num = 1; // on
						cout << "Enter Volume [1-30]: ";
						cin >> volume;
						cin.ignore(100, '\n');
					}
					else if (num == 2)
					{
						num = 0; // off
						volume = 0;
					}

					// if we don't get a nullptr return
					int count = network.power(new_zone, num, volume);
					if (count > 0)
					{
						if (num == 0)
					{
							cout << new_zone << " was powered off." << endl;
					}
					else 
					{
							cout << new_zone << " was powered on to volume " << volume << endl;
					}
					}
				}
				else if (response == 3) 
				{ 
					// remove by name using retrieval
					cout << "----------------------------------------------------------------" << endl;
					cout << "                        REMOVE BY NAME                          " << endl;
					cout << "----------------------------------------------------------------" << endl;
					cout << "Enter Audio Device Name: ";
					cin.get(a_name, SIZE, '\n');
					cin.ignore(100, '\n');
					int result = network.remove(a_name);
					if (result)
					{
						cout << a_name << " was removed successfully." << endl;
					}
					else
					{
						cout << a_name << " not found." << endl;
					}
				}
				else if (response == 4) 
				{ 
					cout << "----------------------------------------------------------------" << endl;
					cout << "                     DISPLAY ONE AUDIO                          " << endl;
					cout << "----------------------------------------------------------------" << endl;
					cout << "Enter Audio Device Name: ";
					cin.get(a_name, SIZE, '\n');
					cin.ignore(100, '\n');
					network.display_one(a_name);
				}
				else if (response == 5) 
				{ 
					// display 
					cout << "----------------------------------------------------------------" << endl;
					cout << "                   DISPLAY AUDIO NETWORK                        " << endl;
					cout << "----------------------------------------------------------------" << endl;
					network.display_all();
				}
				else if (response == 6) 
				{ 
					// display 
					cout << "----------------------------------------------------------------" << endl;
					cout << "                  CLEAR ALL AUDIO NETWORK                       " << endl;
					cout << "----------------------------------------------------------------" << endl;
					network.remove_all();
				}
			} while (response != 7); 
			break;
			}
			case 4:
			{
				cout << "See you next time!" << endl;
				break;
				}
		}
    } while (choice != 4);
    return 0;
}
