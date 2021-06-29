#include "../hpp/util.hpp"

void stringToConstChar(char *novoLocal, string nomeString)
{
    const char *novoNome = nomeString.data();
    int length = nomeString.size();
    length = (length < M ? length : M - 1);
    strncpy(novoLocal, novoNome, length);
    novoLocal[length] = '\0';
}
