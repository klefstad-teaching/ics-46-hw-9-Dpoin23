#include "../src/ladder.h"

void error(string word1, string word2, string msg) {
    cout << "Error with " << word1 << " and " << word2 << " " << msg << endl;
}

bool edit_distance_within(const std::string& str1, const std::string& str2, int d) {
    
}

bool is_adjacent(const string& word1, const string& word2) {
    size_t str1len = word1.length();
    size_t str2len = word2.length();

    if (str1len == str2len) {
        return find_difference(str1len, word1, word2) == 1;
    } else if (str1len == str2len + 1) { // word1 longer
        return find_difference_different_lengths(word2, word1) == 1;
    } else if (str2len == str1len + 1) { // word2 longer
        return find_difference_different_lengths(word1, word2) == 1;
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

}

void load_words(set<string> & word_list, const string& file_name) {
    std::ifstream in(file_name);
    string word;
    while (in >> word)
        word_list.insert(word);
    in.close();
}

void print_word_ladder(const vector<string>& ladder) {
    for (int i = 0; i < ladder.size(); ++i)
        cout << ladder[i] << " ";
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