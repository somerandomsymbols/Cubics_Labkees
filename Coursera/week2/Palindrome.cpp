#include <bits/stdc++.h>

using namespace std;

template <class T>
ostream& operator << (ostream& os, const vector<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class T>
ostream& operator << (ostream& os, const set<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class K, class V>
ostream& operator << (ostream& os, const map<K, V>& m) {
  os << "{";
  bool first = true;
  for (const auto& kv : m) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << kv.first << ": " << kv.second;
  }
  return os << "}";
}

template<class T, class U>
void AssertEqual(const T& t, const U& u, const string& hint = {}) {
  if (t != u) {
    ostringstream os;
    os << "Assertion failed: " << t << " != " << u;
    if (!hint.empty()) {
       os << " hint: " << hint;
    }
    throw runtime_error(os.str());
  }
}

void Assert(bool b, const string& hint) {
  AssertEqual(b, true, hint);
}

class TestRunner {
public:
  template <class TestFunc>
  void RunTest(TestFunc func, const string& test_name) {
    try {
      func();
      cerr << test_name << " OK" << endl;
    } catch (exception& e) {
      ++fail_count;
      cerr << test_name << " fail: " << e.what() << endl;
    } catch (...) {
      ++fail_count;
      cerr << "Unknown exception caught" << endl;
    }
  }

  ~TestRunner() {
    if (fail_count > 0) {
      cerr << fail_count << " unit tests failed. Terminate" << endl;
      exit(1);
    }
  }

private:
  int fail_count = 0;
};

bool IsPalindrom(const string& str) {
  // Вы можете вставлять сюда различные реализации функции,
  // чтобы проверить, что ваши тесты пропускают корректный код
  // и ловят некорректный
}

int main()
{
    Assert(IsPalindrom(""), "");
    Assert(IsPalindrom("a"), "");
    Assert(IsPalindrom(" "), "");

    for (char a = 32; a < 35; ++a)
    {
        for (char b = 32; b < 35; ++b)
        {
            for (char c = 32; c < 35; ++c)
            {
                for (char d = 32; d < 35; ++d)
                {
                    for (char e = 32; e < 35; ++e)
                    {
                        string s = "";
                        s.push_back(a);
                        s.push_back(b);
                        s.push_back(c);
                        s.push_back(d);
                        s.push_back(e);
                        Assert((a == e && b == d) == IsPalindrom(s), s);

                        for (char f = 32; f < 35; ++f)
                        {
                            string h = s;
                            h.push_back(f);
                            Assert((a == f && b == e && c == d) == IsPalindrom(h), h);
                        }
                    }
                }
            }
        }
    }
    return 0;
}
