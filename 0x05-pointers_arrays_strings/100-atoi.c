#include "main.h"

/**
 * _atoi - Converts a string to an integer.
 * @s: The string to be converted.
 *
 * Return: The converted integer.
 */
int _atoi(const char *s)
{
    unsigned int i = 0;
    int j;
    int sign = 1; // Default positive

    for (j = 0; s[j]; j++)
    {
        if (s[j] >= '0' && s[j] <= '9')
        {
            i = i * 10 + s[j] - '0';
        }
        else if (s[j] == '-')
        {
            // Toggle the sign only if we haven't encountered any digits yet
            if (i == 0)
            {
                sign *= -1;
            }
            else
            {
                // If we encounter '-' after digits, break the loop
                break;
            }
        }
        else if (i > 0)
        {
            // Break if we encounter a non-digit after parsing digits
            break;
        }
    }

    return (i * sign);
}
