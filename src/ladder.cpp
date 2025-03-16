#include "../src/ladder.h"

void error(string word1, string word2, string msg) {
    cout << "Error with " << word1 << " and " << word2 << " " << msg << endl;
}

bool edit_distance_within(const std::string& str1, const std::string& str2, int d) {
    int len1 = str1.length();
    int len2 = str2.length();
    if (abs(len1 - len2) > d) return false;

    vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));

    for (int i = 0; i <= len1; ++i) dp[i][0] = i;
    for (int j = 0; j <= len2; ++j) dp[0][j] = j;

    for (int i = 1; i <= len2; ++i) {
        for (int j = 1; j <= len1; ++j) {
            int cost = (str1[i-1] == str2[j-i]) ? 0 : 1;
            
            dp[i][j] = min({dp[i-1][j] + 1,
                            dp[i][j-1] + 1,
                            dp[i-1][j-1] + cost
                            });
        }
    }

    return dp[len1][len2] <= d;
}

bool is_adjacent(const string& word1, const string& word2) {
    size_t str1len = word1.length();
    size_t str2len = word2.length();

    if (str1len == str2len) {
        return find_difference(str1len, word1, word2) <= 1;
    } else if (str1len == str2len + 1) { // word1 longer
        return find_difference_different_lengths(word2, word1) <= 1;
    } else if (str2len == str1len + 1) { // word2 longer
        return find_difference_different_lengths(word1, word2) <= 1;
    } 
    // differ by two or more letters
    return false;
}

int find_difference(size_t length, const string& word1, const string& word2) {
    int difference = 0;
    for (size_t i = 0; i < length; ++i) {
            if (word1[i] != word2[i])
                ++difference;
        }
    return difference;
}

int find_difference_different_lengths(const string& shorter, const string& longer) {
    size_t short_length = shorter.length();
    size_t long_length = longer.length();
    size_t i = 0, j = 0;
    int difference = 0;

    while (i < short_length && j < long_length) {
        if (shorter[i] != longer[j]) {
            ++difference;
            ++j;
        } else {
            ++i;
            ++j;
        }
    }
    return difference;
}

vector<string> generate_word_ladder(const string& begin_word, const string& end_word, const set<string>& word_list) {
    if (begin_word == end_word) 
        error(begin_word, end_word, "Begin and end are the same.");

    queue<vector<string>> lq;
    lq.push({begin_word});

    set<string> visited;
    visited.insert(begin_word);

    while (!lq.empty()) {
        vector<string> ladder = lq.front();
        lq.pop();
        string last = ladder.back();
        for (const string& word : word_list) {
            if (is_adjacent(last, word) && visited.find(word) == visited.end()) {
                visited.insert(word);
                vector<string> new_ladder = ladder;
                new_ladder.push_back(word);

                if (word == end_word)
                    return new_ladder;

                lq.push(new_ladder);
            }
        }
    }
    return {};
}

void load_words(set<string> & word_list, const string& file_name) {
    std::ifstream in(file_name);
    string word;
    while (in >> word)
        word_list.insert(word);
    in.close();
}

void print_word_ladder(const vector<string>& ladder) {
    if (ladder.size() > 0) {
        cout << "Word ladder found: ";
        for (int i = 0; i < ladder.size(); ++i)
            cout << ladder[i] << " ";
        cout << endl;
    } else {
        cout << "No word ladder found." << endl;
    }
}

void verify_word_ladder() {
    set<string> word_list;
    load_words(word_list, "words.txt");
    assert(generate_word_ladder("cat", "dog", word_list).size() == 4);
    assert(generate_word_ladder("marty", "curls", word_list).size() == 6);
    assert(generate_word_ladder("code", "data", word_list).size() == 6);
    assert(generate_word_ladder("work", "play", word_list).size() == 6);
    assert(generate_word_ladder("sleep", "awake", word_list).size() == 8);
    assert(generate_word_ladder("car", "cheat", word_list).size() == 4);
}