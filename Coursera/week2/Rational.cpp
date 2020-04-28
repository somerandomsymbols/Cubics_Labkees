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

int main()
{
    TestRunner runner;
    Rational a;
    Assert(a.Denominator() == 1 && a.Numerator() == 0,"Default");

    for (int i = -50; i < 50; ++i)
    {
        for (int j = 1; j < 50; ++j)
        {
            int g = __gcd(abs(i),abs(j)), n = i / g, d = j / g;
            Rational b(i,j);
            Assert(b.Denominator() == d && b.Numerator() == n, to_string(i) + " " + to_string(j));
        }

        for (int j = -50; j < 0; ++j)
        {
            int g = -__gcd(abs(i),abs(j)), n = i / g, d = j / g;
            Rational b(i,j);
            Assert(b.Denominator() == d && b.Numerator() == n, to_string(i) + " " + to_string(j));
        }
    }

    return 0;
}
