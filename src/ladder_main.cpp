#include "../src/ladder.h"

int main() {
    set<string> word_list;
    load_words(word_list, "words.txt");
    string start;
    string end;
    cin >> start;
    cin >> end;
    vector<string> ladder = generate_word_ladder(start, end, word_list);
    print_word_ladder(ladder);
    return 0;
}