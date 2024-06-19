/*
MIT License

Copyright (c) 2024 davidgaroro

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

// Includes
#include <windows.h>               // Windows API
#include <iostream>                // Input/Output
#include <conio.h>                 // Console input
#pragma comment(lib, "user32.lib") // Window functions

void printHeader()
{
    std::cout
        << " ***********************************************************\n"
        << " ** Rocket League Auto Drops v1.0.0\n"
        << " ** Copyright (c) 2024 davidgaroro\n"
        << " ** https://github.com/davidgaroro/rocket-league-auto-drops\n"
        << " ***********************************************************\n\n";
}

int main()
{
    // Set the title of the console window
    SetConsoleTitleA("Rocket League Auto Drops");

    // Create an array of two INPUT and initialize all elements
    INPUT inputs[2] = {};

    // Configure KeyDown Enter
    inputs[0].type = INPUT_KEYBOARD;
    inputs[0].ki.wScan = 0x1C;                 // Virtual key code for Enter
    inputs[0].ki.dwFlags = KEYEVENTF_SCANCODE; // Scan code usage

    // Configure KeyUp Enter
    inputs[1].type = INPUT_KEYBOARD;
    inputs[1].ki.wScan = 0x1C;                                   // Virtual key code for Enter
    inputs[1].ki.dwFlags = KEYEVENTF_SCANCODE | KEYEVENTF_KEYUP; // Scan code and key release

    // Display instructions
    printHeader();
    std::cout
        << " Automatically open Rocket League drops.\n\n"

        << " This program simulates Enter key press every second (only in Rocket League).\n\n"

        << " How it works:\n"
        << "  1. Open Rocket League\n"
        << "  2. Go to Garage > Inventory > Reward Items\n"
        << "  3. Select the drops you want to open\n"
        << "  4. Return to this program (Alt+Tab)\n\n"

        << "  Press any key to start...";

    // Wait for user to press a key
    _getch();

    std::cout
        << "\n\n  5. Return to Rocket League and place your mouse cursor over the \"Yes\" button in the \"Open Drop\" message\n"
        << "  6. Don't move your mouse position and wait for the drops to open\n"
        << "  7. To stop the program, close this window\n\n"

        << " IMPORTANT: When you are done, close this program or it will continue pressing Enter.\n\n"

        << " Enjoy it! :)";

    // Pause 5 seconds
    Sleep(5000);

    // Start loop
    HWND hwnd;
    do
    {
        // Check if the Rocket League window is active
        hwnd = FindWindowA("LaunchUnrealUWindowsClient", NULL);

        // std::cout << hwnd << "\n";
        if (hwnd == GetForegroundWindow())
        {
            // Simulate pressing and releasing the Enter key
            SendInput(2, inputs, sizeof(INPUT));
        }
        // Wait 1 second between loops
        Sleep(1000);
    } while (hwnd);

    // Clear console
    system("cls");

    printHeader();
    std::cout << " Rocket League is closed. Press any key to exit...";

    // Wait for user to press a key
    _getch();

    // Exit the program
    return 0;
}
