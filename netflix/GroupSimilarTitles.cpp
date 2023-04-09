#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class GroupSimilarTitles {
public:
    GroupSimilarTitles() {}
    
    string generate_key(string title) {
        int count[26] = {0};
        for (char ch : title) {
            count[ch - 'a'] += 1;
        }
    
        string title_key = "";
        for (int i = 0; i < 26; i++) {
            title_key += "#" + to_string(count[i]);
        }
    
        return title_key;
    }
    
    map<string, vector<string>> group_titles(vector<string> titles) {
        map<string, vector<string>> grouped_titles_map;
    
        for (string title : titles) {
            string title_key = generate_key(title);
            if (grouped_titles_map.find(title_key) == grouped_titles_map.end()) {
                grouped_titles_map[title_key] = vector<string>();
            }
            grouped_titles_map[title_key].push_back(title);
        }
    
        return grouped_titles_map;
    }
};

int main() {
    vector<string> titles = {"dule", "dlue", "speed", "duel", "cars", "rasc", "depse"};
    string query = "deul";

    GroupSimilarTitles group_similar_titles;
    map<string, vector<string>> grouped_titles_map = group_similar_titles.group_titles(titles);
    vector<string> group = grouped_titles_map[group_similar_titles.generate_key(query)];
    for (string title : group) {
        cout << title << " ";
    }
    cout << endl;

    return 0;
}
