#include <gtest/gtest.h>

#include "../src/dijkstras.h"
#include "../src/ladder.h"

TEST(Ladder, Test) {
  set<string> word_list;
  load_words(word_list, "words.txt");
  EXPECT_TRUE(generate_word_ladder("cat", "dog", word_list).size() == 4);
  EXPECT_TRUE(generate_word_ladder("marty", "curls", word_list).size() == 6);
  EXPECT_TRUE(generate_word_ladder("code", "data", word_list).size() == 6);
  EXPECT_TRUE(generate_word_ladder("work", "play", word_list).size() == 6);
  EXPECT_TRUE(generate_word_ladder("sleep", "awake", word_list).size() == 8);
  EXPECT_TRUE(generate_word_ladder("car", "cheat", word_list).size() == 4);
}
