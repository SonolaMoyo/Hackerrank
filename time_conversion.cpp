#include <bits/stdc++.h>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string timeConversion(string s) {
    string militaryTime;
    vector<string> tokens;
    istringstream iss(s);
    string token;
    
    // split time
    while(getline(iss, token, ':'))
    {
        tokens.push_back(token);
    }
    
    // discover AM and PM then operate on them
    string backstring = tokens[2];
    if(backstring.substr(2,3) == "AM")
    {
        if(tokens[0] == "12")
        {
            tokens[0] = "00";
        }
        militaryTime = tokens[0] + ":" + tokens[1] + ":" + tokens[2].substr(0,2); 
    }
    else if(backstring.substr(2,3) == "PM")
    {
        if(tokens[0] == "12")
        {
            tokens[0] = "00";
        }
        int firsttime = stoi(tokens[0]) + 12;
        militaryTime = to_string(firsttime) + ":" + tokens[1] + ":" + tokens[2].substr(0,2);
    }
    
    return militaryTime;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
