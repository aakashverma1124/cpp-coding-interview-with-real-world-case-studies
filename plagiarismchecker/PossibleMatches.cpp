#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Pair {
public:
    int index;
    string word;
    Pair(int index, string word) {
        this->index = index;
        this->word = word;
    }
};

class PossibleMatches {
private:
    unordered_map<char, vector<Pair>> characterMap;
public:
    int possibleMatches(string S, vector<string>& words) {
        for(char ch = 'a'; ch <= 'z'; ch++)
            characterMap[ch] = vector<Pair>();

        for(string word : words)
            characterMap[word[0]].push_back(Pair(0, word));

        int numOfStudents = 0;
        for(int index = 0; index < S.length(); index++) {
            vector<Pair> lst = characterMap[S[index]];
            characterMap[S[index]].clear();
            for(Pair pair : lst) {
                if(pair.index + 1 == pair.word.length()) numOfStudents += 1;
                else {
                    pair.index += 1;
                    characterMap[pair.word[pair.index]].push_back(pair);
                }
            }
        }

        return numOfStudents;
    }
};

int main() {
    // Driver code
    PossibleMatches pm;
    string plagiarised = "abcde";
    vector<string> students = {"a","bb","acd","ace"};
    cout << "The content was copied from " << pm.possibleMatches(plagiarised, students) << " students" << endl;

    plagiarised = "dsahjpjauf";
    students = {"ahjpjau","ja","ahbwzgqnuk","tnmlanowax"};
    cout << "The content was copied from " << pm.possibleMatches(plagiarised, students) << " students" << endl;

    return 0;
}