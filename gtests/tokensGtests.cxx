/*
 * Copyright (c) 2015, Roman Meyta <theshrodingerscat@gmail.com>
 * All rights reserved
 */

#include <string>
#include <vector>

#include <gtest/gtest.h>

#include "tokens.h"

using namespace std;

TEST(libtokens_tests, tokenizeBySplitter) {
    const string commaString = "red,yellow, green,  brown , pink, grey, black ";
    vector<string> collorsVector = {"red", "yellow", "green", "brown", "pink",
                                    "grey", "black"};

    auto collorsTokens = tokenize(commaString, ',');
    for (size_t i = 0; i < collorsVector.size(); ++i) {
        ASSERT_TRUE(i < collorsTokens.size());
        if (i >= collorsTokens.size()) {
            break;
        }
        ASSERT_TRUE(trimCopy(collorsTokens[i]) == collorsVector[i]);
    }
}

TEST(libtokens_tests, tokenizeBySplitters) {
    const string commaString = "red,yellow; green#  brown $ pink@ grey* black ";
    vector<string> collorsVector = {"red", "yellow", "green", "brown", "pink",
                                    "grey", "black"};

    auto collorsTokens = tokenize(commaString, ",;#$@*");
    for (size_t i = 0; i < collorsVector.size(); ++i) {
        ASSERT_TRUE(i < collorsTokens.size());
        if (i >= collorsTokens.size()) {
            break;
        }
        ASSERT_TRUE(trimCopy(collorsTokens[i]) == collorsVector[i]);
    }
}

TEST(libtokens_tests, tokenizeByString) {
    const string commaString = "red<splitter>yellow<splitter> green<splitter>  "
            "brown <splitter> pink<splitter> grey<splitter> black ";
    vector<string> collorsVector = {"red", "yellow", "green", "brown", "pink",
                                    "grey", "black"};

    auto collorsTokens = tokenizeByString(commaString, "<splitter>");
    for (size_t i = 0; i < collorsVector.size(); ++i) {
        ASSERT_TRUE(i < collorsTokens.size());
        if (i >= collorsTokens.size()) {
            break;
        }
        ASSERT_TRUE(trimCopy(collorsTokens[i]) == collorsVector[i]);
    }
}