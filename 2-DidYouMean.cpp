#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

#include <algorithm>

typedef std::vector<std::string> strVec;

// Store the stdin in a vector
strVec readStdin ()
{
    std::string line;
    strVec stdin;

    // While not EOF
    while ( getline(std::cin, line) )
    {
        // Add line to the vector
        stdin.push_back (line);
    }

    return stdin;
}

bool sameLetters (std::string w1, std::string w2)
{
    std::sort (w1.begin(), w1.end());
    std::sort (w2.begin(), w2.end());

    return w1 == w2;
}

strVec getSuggestions (std::string dictName, std::string word)
{
    std::ifstream dict ( dictName.c_str() );
    std::string line;
    strVec suggestions;

    while ( getline(dict, line) )
    {
        if ( line.size() == word.size() &&
            sameLetters(line, word) &&
            line != word)
        {
            suggestions.push_back (line);
        }
    }

    std::sort (suggestions.begin(), suggestions.end());

    return suggestions;
}

int str2int (std::string str)
{
    std::stringstream ss;
    int n;
    ss << str;
    ss >> n;

    return n;
}

int main ()
{
    strVec stdin = readStdin ();

    std::string dictName = stdin [1];
    int qty = str2int (stdin[3]);

    for (int i=5; i<qty+5; ++i)
    {
        strVec suggestions = getSuggestions (dictName, stdin[i]);

        std::cout << stdin [i] << " ->";
        for (strVec::iterator it=suggestions.begin(); it!=suggestions.end(); ++it)
        {
            std::cout << " " << *it;
        }
        std::cout << std::endl;
    }
}
