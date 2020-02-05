#include <iostream>
#include <fstream>
#include <cstring>
#include <linux/input.h>
#include <thread>

using namespace std;

//structure to hold event info
struct input_event event;
struct input_event key_event;
int task_axi()
{
    ifstream file("/dev/input/event9");
    //ifstream key_file("/dev/input/event24");
    //temp storage for event
    char data[sizeof(event)];
    //char key_data[sizeof(key_event)];
    //check if file opened!
    if (file.is_open())
    {

        while (1)
        {
            //lets get to work
            file.read(data, sizeof(event));
            //now copy the data to the struct
            memcpy(&event, data, sizeof(event));
            //now lets read the event
            //event type
            if (event.type == EV_KEY)
            {

                //its a keyboard event
                //was it the esc key?
                if (event.code == KEY_UP)
                {

                    if (event.value == 1)
                        cout << "Up Push" << endl;
                    else
                    {
                        cout << "Up Release" << endl;
                    }
                }
                else if (event.code == KEY_DOWN)
                {

                    if (event.value == 1)
                        cout << "DOwn Push" << endl;
                    else
                    {
                        cout << "DOwn Release" << endl;
                    }
                }
                else if (event.code == KEY_LEFT)
                {

                    if (event.value == 1)
                        cout << "Left Push" << endl;
                    else
                    {
                        cout << "Left Release" << endl;
                    }
                }
                else if (event.code == KEY_RIGHT)
                {

                    if (event.value == 1)
                        cout << "Right Push" << endl;
                    else
                    {
                        cout << "Right Release" << endl;
                    }
                }
                else
                {
                    if (event.value == 1)
                        cout << "A Push" << endl;
                    else
                    {
                        cout << "A Release" << endl;
                    }
                }
            }
        }

        //dont forget to close the file
        file.close();
    }
    else
    {

        cout << "Unable to open file!" << endl;
        return 1;
    }
}

int task_button()
{
    ifstream file("/dev/input/event24");
    //ifstream key_file("/dev/input/event24");
    //temp storage for event
    char data[sizeof(key_event)];
    //char key_data[sizeof(key_event)];
    //check if file opened!
    if (file.is_open())
    {

        while (1)
        {
            //lets get to work
            file.read(data, sizeof(key_event));
            //now copy the data to the struct
            memcpy(&key_event, data, sizeof(key_event));
            //now lets read the event
            //event type
            if (key_event.type == EV_KEY)
            {

                //its a keyboard event
                //was it the esc key?
                if (key_event.code == BTN_SOUTH)
                {

                    if (key_event.value == 1)
                        cout << "Home Push" << endl;
                    else
                    {
                        cout << "Home Release" << endl;
                    }
                }
                else if (key_event.code == BTN_EAST)
                {

                    if (key_event.value == 1)
                        cout << "Back Push" << endl;
                    else
                    {
                        cout << "Back Release" << endl;
                    }
                }
                
            }
        }

        //dont forget to close the file
        file.close();
    }
    else
    {

        cout << "Unable to open file!" << endl;
        return 1;
    }
}

    int main(int argc, char *argv[])
    {

        cout << "Receiving Keyboard Presses!" << endl;

        //open the file for reading
        thread task0(task_axi);
        thread task1(task_button);
        task0.join();
        task1.join();
        return 0;
    }