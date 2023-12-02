#include <bits/stdc++.h>
#include <fstream>

using namespace std;

string getFirstAndLastDigit(string str) {
  vector<string> nums = {"one","two","three","four","five","six","seven","eight","nine"};
  vector<string> nums1 = {"eno","owt","eerht","ruof","evif","xis","neves","thgie","enin"};
  map<string,int> map;
  int count = 1;
  for(auto x : nums) {
    map[x] = count;
    count++;
  }
  string d1, d2;
  int start = 0;
  int end = str.length() - 1;

  string temp = "";
  int i = 0;
  for(i = start; i < str.length(); i++) {    
    if(isdigit(str[i])) {
      d1 = str[i];
      break;
    }
  }

  for(int j = 0; j <= i; j++) {
    bool flag = false;
    temp += str[j];
      for(auto x : nums) {
        if(temp.find(x) != string::npos) {
          flag = true;
          d1 = x;
          break;
        }
      }
      if(flag) {
        break;
      }
  }

  if(!isdigit(d1[0])) {
    d1 = to_string(map[d1]);
  }


  for (i = end; i >= 0 ; i--)
  {
    if(isdigit(str[i])) {
      d2 = str[i];
      break;
    }
  }
  temp = "";
  if(i == -1) {
    i = 0;
  }
  for(int j = end; j >= i; j--) {
    temp += str[j];
    bool flag = false;
      for(auto x : nums1) {
        if(temp.find(x) != string::npos) {
          // cout<<d2<<" "<<x<<endl;
          flag = true;
          reverse(x.begin(),x.end());
          d2 = x;
          break;
        }
      }
      if(flag) {
        break;
      }
  }

  if(!isdigit(d2[0])) {
    d2 = to_string(map[d2]);
  }

  cout<<d1<<" "<<d2<<endl;

  return d1 + d2; 
}

int main(int argc, char const *argv[])
{
    ifstream newfile; // Declare an input file stream object
    newfile.open("input.txt"); // Open a file named "input.txt"

    int ans = 0;
    if (newfile.is_open()) {
        string tp;
        while (getline(newfile, tp)) {
            ans += stoi(getFirstAndLastDigit(tp));
        }
        cout <<ans<<endl;
        newfile.close();
    } else {
        cout << "Unable to open file\n";
    }

    return 0;

}
