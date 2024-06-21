# Rocket League Auto Drops

Automatically open Rocket League drops.

This program simulates Enter key press every second (only in Rocket League).

## Download

Link: [rocket-league-auto-drops.zip](https://github.com/davidgaroro/rocket-league-auto-drops/releases/download/v1.0.0/rocket-league-auto-drops-1.0.0.zip)

Note: Update Windows Defender if it's detected as a virus.

## How it works:

1. Open Rocket League
2. Go to **Garage > Inventory > Reward Items**
3. Select the drops you want to open
4. Return to the program (Alt+Tab) and **press any key to start**
5. Return to Rocket League and **place your mouse cursor over the "Yes" button** in the "Open Drop" message
6. **Don't move your mouse position** and wait for the drops to open
7. To stop the program, close the program window

![image](https://github.com/davidgaroro/rocket-league-auto-drops/assets/13784162/b922cbd1-d67c-451b-ada7-ead9938e1a0c)

## Estimated time

Table with the estimated time it takes to open the drops.

| Minutes | Drops |
| ------- | ----- |
| 1       | 6     |
| 5       | 30    |
| 10      | 60    |
| 15      | 90    |
| 30      | 180   |
| 60      | 360   |

## Source Code

Link: [rocket-league-auto-drops.cpp](rocket-league-auto-drops.cpp)

```c++

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

// Start loop
HWND hwnd;
do
{
    // Get Rocket League window
    hwnd = FindWindowA("LaunchUnrealUWindowsClient", NULL);

    // Check if the Rocket League window is active
    if (hwnd == GetForegroundWindow())
    {
        // Simulate pressing and releasing the Enter key
        SendInput(2, inputs, sizeof(INPUT));
    }
    // Wait 1 second between loops
    Sleep(1000);
} while (hwnd);
```

## Built With

Developed with [C++ for Visual Studio Code](https://code.visualstudio.com/docs/languages/cpp)

## VirusTotal

https://www.virustotal.com/gui/file/0f925301df418c82a3739ded34ae8e07a02ef60cf131776c416b5dfbe16850b8

This program has been flagged by some antivirus engines on VirusTotal.

These are false positives due to the nature of the code, which simulates keyboard inputs.

## Disclaimer

This project is not endorsed by Rocket League or Psyonix LLC.

## Donation

[![Donate](https://img.shields.io/badge/Donate-PayPal-green.svg)](https://www.paypal.com/donate?hosted_button_id=T7CVYXY994KHJ)

## License

[MIT](LICENSE)
