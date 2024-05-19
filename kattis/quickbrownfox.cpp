#include <bits/stdc++.h>
#define ULL unsigned
using namespace std;

bool debug = 0;

int main(void) {
  ULL n;
  cin >> n;
  getchar();
  for(ULL i=0; i<n; i++) {
    ULL* list;
    list = (ULL *) malloc (26*sizeof(ULL));
    //memset(list, 0, 26);
    for(ULL j=0; j<26; j++) {
      list[j] = 0;
    }
    vector <char> missing;
    string str;
    getline(cin, str);
    if (debug) cout << "str length " << str.length() << endl;
    for(ULL j=0; j<str.length(); j++) {
      char c = str[j];
      if(isalpha(c)) {
        if((c >= 'A')and(c <= 'Z')) {
          list[c-'A'] += 1;
        }
        else {
          list[c-'a'] += 1;
        }
      } 
    }
    //bool yes = 1;
    for(ULL j=0; j<26; j++) {
      if(!list[j]) {
        //yes = 0;
        missing.push_back(j+'a');
      }
    }

    if(debug) {
      for(ULL j=0; j<26; j++) {
        cout << list[j] << " ";
      }
      cout << endl;
    }
    
    if(missing.empty()) {
      cout << "pangram\n";
    }
    else {
      cout << "missing ";
      for(ULL j=0; j<missing.size(); j++) {
        cout << missing[j];
      }
      cout << "\n";
    }
    free(list);
    list = NULL;
  }
  return 0;
}
