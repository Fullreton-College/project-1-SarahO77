#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void getWords(vector<string> &words, ifstream &file){
    string word;
    while( file>> word){
        words.push_back(word);
    }
}
void sortWords(vector<string> &words) {
    sort(words.begin(), words.end());
}
vector<pair<string, int>> getWordsCounts(vector<string> &words){
    vector<pair<string, int>> counts;

    for (int i= 0; i< words.size(); i++){
        int count = 1;

        while ( i + 1 < words.size() && words [i] == words[i + 1]){
            count++;
            i++;
        }
        counts.push_back({words[i], count});

    }
    return counts;
} 
    

int main(){
    ifstream file("homes.txt");
    if(!file){
        cout<<"Error opening file"<< endl;
        return 1;
    }
    vector<string> words;

    getWords(words,file);
    sortWords(words);

    vector<pair<string, int>> counts = getWordsCounts(words);

    for (auto p: counts){
        cout<< p.first << ":"<< p.second <<endl;
    }

    return 0;
}