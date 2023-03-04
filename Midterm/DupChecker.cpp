#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

// user defined data structure which stores the word like a set also stores the corresponding duplicate count
class UniqueSet
{
private:
    string uniqueWords[64];
    int uniqueCount[64];
    int curr_index;

public:
    UniqueSet()
    {
        curr_index = -1;
        // fill arrays with default values
        fill_n(uniqueWords, 64, "");
        fill_n(uniqueCount, 64, 0);
    }
    // helper functions
    void add(string word)
    {
        int index = getIndex(word);
        if (index == -1)
        {
            curr_index++;
            uniqueWords[curr_index] = word;
            uniqueCount[curr_index] += 1;
        }
        else
        {
            uniqueCount[index] += 1;
        }
    }
    int getIndex(string word)
    {
        for (int i = 0; i < 64; i++)
        {
            if (uniqueWords[i] == word)
            {
                return i;
            }
        }
        return -1;
    }
    string printDuplicates()
    {
        bool duplicateFound = false;
        string outputString = "";
        for (int i = 0; i < 64; i++)
        {
            if (uniqueWords[i] == "")
            {
                break;
            }
            else if (uniqueCount[i] > 1)
            {
                duplicateFound = true;
                outputString += uniqueWords[i] + " " + to_string(uniqueCount[i]) + "\n";
            }
        }
        if (duplicateFound == false)
        {
            return ("No duplicates.");
        }
        else
        {
            return outputString;
        }
    }
};

int main()
{
    // Get input
    string input;
    cout << "Enter the words:";
    getline(cin, input);

    // process input
    string s = input;
    int index = input.find_first_of(" ");
    s.erase(std::remove(s.begin(), s.end(), '.'), s.end());

    // create an object to user defined data structure
    UniqueSet set;
    // fill all the words into data structure
    for (int i = 0; i < 64 && index != -1; i++)
    {
        set.add(s.substr(0, index));
        if (index == s.length())
        {
            break;
        }
        s = s.substr(index + 1);
        index = s.find_first_of(' ');
        if (index == -1)
        {
            index = s.length();
        }
    }
    // print duplicates if any
    cout << set.printDuplicates();
    return 0;
}