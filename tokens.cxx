/*
 * Copyright (c) 2014, Roman Meyta <theshrodingerscat@gmail.com>
 * All rights reserved
 */

#include <algorithm>

#include "tokens.h"

using namespace std;

vector<string> tokenize(const string& str, char splitter) {
	vector<string> strings;
	size_t start = 0, end = 0;

	while (start < str.size()) {
		end = str.find_first_of(splitter, start);
		if (end - start > 0) {
			strings.push_back(str.substr(start, end - start));
		}
		if (end == string::npos) {
			break;
		}
		start = end + sizeof(splitter);
	}
	return strings;
}

vector<string> tokenize(const string& str, const string& splitters) {
	vector<string> tokens;
	size_t start = 0, end = 0;
	while (end < str.length()) {
		end = str.find_first_of(splitters, start);
		tokens.push_back(str.substr(start, end - start));
		start = end + 1;
	}
	return tokens;
}

vector<string> tokenizeByString(const string& str, const string& splitter) {
	vector<string> strings;
	size_t start = 0, end = 0;

	while (start < str.size()) {
		end = str.find(splitter, start);
		if (end - start > 0) {
			strings.push_back(str.substr(start, end - start));
		}
		if (end == string::npos) {
			break;
		}
		start = end + splitter.size();
	}
	return strings;
}

const string ltrimCopy(const string& str) {
	auto start = find_if(str.begin(), str.end(), [] (char c) -> bool {
		return isalnum(c);
	});
	return string(start, str.end());
}

const string rtrimCopy(const string& str) {
	auto end = find_if(str.rbegin(), str.rend(), [] (char c) -> bool {
		return isalnum(c);
	});
	return string(str.begin(), end.base());
}

const string trimCopy(const string& str) {
	return rtrimCopy(ltrimCopy(str));
}
