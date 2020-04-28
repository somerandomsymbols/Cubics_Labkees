#include <bits/stdc++.h>

using namespace std;

vector<string> SplitIntoWords(const string& s)
{
    int j = 0;
    vector<string> v;

    for (int i = 0; i < s.length(); ++i)
        if (s[i] == ' ')
            v.push_back(s.substr(j, i - j)),
            j = i + 1;

    v.push_back(s.substr(j, s.length() - j));
    return v;
}

int main() {
  string s = "C Cpp Java Python";

  vector<string> words = SplitIntoWords(s);
  cout << words.size() << " ";
  for (auto it = begin(words); it != end(words); ++it) {
    if (it != begin(words)) {
      cout << "/";
    }
    cout << *it;
  }
  cout << endl;

  return 0;
}
