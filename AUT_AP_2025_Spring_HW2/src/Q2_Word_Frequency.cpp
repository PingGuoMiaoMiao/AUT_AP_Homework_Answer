#include "Q2_Word_Frequency.h"
#include <cctype>
#include <algorithm>

std::map<std::string, int> countWords(const std::string& text) {
    std::map<std::string, int> wordCounts;
    std::string currentWord;

    auto addWord = [&]() {
        if (!currentWord.empty()) {
            wordCounts[currentWord]++;
            currentWord.clear();
        }
    };

    for (char c : text) {
        if (isalnum(c)) {
            currentWord += tolower(c);
        }
        else if (!currentWord.empty()) {
            addWord();
        }
    }
    addWord(); // 处理最后一个单词

    return wordCounts;
}