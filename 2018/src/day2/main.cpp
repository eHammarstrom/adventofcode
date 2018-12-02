#include <fstream>
#include <iostream>
#include <map>
#include <ostream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

void solveA(vector<string> Lines) {
  pair<int, int> IdCount(0, 0);
  for (string Line : Lines) {
    map<char, int> Letters;

    for (char C : Line) {
      Letters[C]++;
    }

    bool C2 = false;
    bool C3 = false;
    for (auto &&[Key, Value] : Letters) {
      if (C2 && C3)
        break;

      if (Value == 3 && !C3) {
        ++IdCount.first;
        C3 = true;
      } else if (Value == 2 && !C2) {
        ++IdCount.second;
        C2 = true;
      }
    }
  }

  cout << IdCount.first * IdCount.second << '\n';
}

void solveB(vector<string> Lines) {
  int IdLength = Lines[0].length();

  string Answer;
  for (auto IA = Lines.begin(); IA < Lines.end(); ++IA) {
    string A = *IA;
    for (auto IB = IA + 1; IB < Lines.end(); ++IB) {
      string B = *IB;

      int Diffs = 0;
      for (int I = 0; I < IdLength && Diffs < 2; ++I) {
        if (A[I] != B[I]) {
          ++Diffs;
        }
      }

      if (Diffs == 1) {
        // building here is faster than while diffing
        for (int I = 0; I < IdLength; ++I) {
          if (A[I] == B[I]) {
            Answer += A[I];
          }
        }
        goto done;
      }
    }
  }
done:
  cout << Answer << '\n';
}

int main() {
  stringstream Buffer;
  Buffer << std::cin.rdbuf();

  vector<string> Lines;
  string Line;
  while (std::getline(Buffer, Line)) {
    Lines.push_back(Line);
  }

  // solveA(Lines);
  solveB(Lines);

  return 0;
}
