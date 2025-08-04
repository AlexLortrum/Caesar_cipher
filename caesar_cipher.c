#include <string.h>

void encrypt(char* message, int key)
{
    int length = strlen(message);
    int offset;
    for (int i = 0; i < length; i++)
    {
        if (message[i] == ' ') continue;
        offset = message[i] + key;
        if (offset > '~')
        {
            offset = offset - 127;
            message[i] = '!' + offset;
        }
        else message[i] = offset;
    }
}

void decrypt(char *message, int key)
{
    int length = strlen(message);
    int offset;
    for (int i = 0; i < length; i++)
    {
        if (message[i] == ' ') continue;
        offset = message[i] - key;
        if (offset < '!') offset = 127 - (key - (message[i] - '!'));
        message[i] = offset;
    }
}
