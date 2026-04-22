#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <queue>
#include <vector>
#include <cctype>

using namespace std;

struct Compare
{
    bool operator()(pair<string,int> a, pair<string,int> b)
    {
        if (a.second == b.second)
            return a.first > b.first;   // lexicographic

        return a.second < b.second;     // higher frequency first
    }
};

int main()
{
    ifstream file("text.txt");

    string text;
    getline(file, text);

    map<string,int> words;

    string separators = " ,?!.";
    size_t start = 0;

    while (start < text.size())
    {
        start = text.find_first_not_of(separators, start);

        if (start == string::npos)
            break;

        size_t end = text.find_first_of(separators, start);

        string word;

        if (end == string::npos)
        {
            word = text.substr(start);
            start = text.size();
        }
        else
        {
            word = text.substr(start, end - start);
            start = end;
        }

        // lowercase conversion
        for (char &c : word)
            c = tolower(c);

        words[word]++;
    }

    priority_queue<pair<string,int>, vector<pair<string,int>>, Compare> pq;

    for (auto &it : words)
        pq.push(it);

    while (!pq.empty())
    {
        auto p = pq.top();
        pq.pop();

        cout << p.first << " => " << p.second << endl;
    }

    return 0;
}