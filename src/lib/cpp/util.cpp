#include "../hpp/util.hpp"

void stringToConstChar(string nomeString)
{
    const char *novoNome = nomeString.data();
    int length = nomeString.size();
    length = (length < M ? length : M - 1);
    strncpy(nomeString, novoNome, length);
    nomeString[length] = '\0';
}
