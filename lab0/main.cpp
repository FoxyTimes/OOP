#include <fstream>
#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;


void memorizing(float * all_words, map<string, float> * dict, string * word) {
    if (!word->empty()) {
        (*dict)[*word]++;
    }
    *word="";
    (*all_words)++;
}


void calculate_frequencies(ifstream * input, string * str, float * all_words, map<string, float> * dict, vector<pair<string, float>> * frequencies) {
    string word;
    while (getline(*input, *str)) {
        for (char ch : *str) {
            if (ch>='A'&&ch<='Z'||ch>='a'&&ch<='z'||ch>='0'&&ch<='9') {
                word+=ch;
            }
            else {
                memorizing(all_words, dict, &word);
            }
        }
        memorizing(all_words, dict, &word);
    }

    for (auto & i : *dict) {
        (*frequencies).push_back(i);
        sort((*frequencies).begin(), (*frequencies).end(), [](pair<string, float>& a, pair<string, float>& b){
                 return a.second > b.second;
             }
        );
    }
}



int main(int argc, char * argv[]) {

    if (argc!=3) {
        cout << "[app] [in] [out]";
        return 0;
    }

    ifstream input;
    input.open(argv[1]);

    if (!input.is_open()) {
        cout << "error open input file";
        return 1;
    }

    ofstream output;
    output.open(argv[2]);

    if (!output.is_open()) {
        cout << "error open/output input file";
        return 2;
    }

    string str;
    map<string, float> dict;
    vector<pair<string, float>> frequencies;
    float all_words=0;

    calculate_frequencies(&input, &str, &all_words, &dict, &frequencies);

    for (const auto& i : frequencies) {
        output << i.first << "," << (int)i.second << "," << (int)(i.second/all_words*100) << "%" << endl;
    }





    return 0;
}
