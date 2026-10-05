#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>

using namespace std;

int main() {

    while (true) {

        cout << "\n1. TwoSum." << endl;
        cout << "2. Valid Parenthesis." << endl;
        cout << "3. Exit.." << endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;


        // Exit
        if (choice == 3) {
            cout << "Program exited..." << endl;
            break;
        }


        // Two Sum
        if (choice == 1) {

            int n;

            cout << "Enter number of elements: ";
            cin >> n;

            vector<int> nums;

            for (int i = 0; i < n; i++) {

                int element;

                cout << "Enter element " << i + 1 << ": ";
                cin >> element;

                nums.push_back(element);
            }

            int target;

            cout << "Enter target value: ";
            cin >> target;


            bool found = false;

            unordered_map<int, int> hashmap;

            for (int i = 0; i < nums.size(); i++) {

                int diff = target - nums[i];

                if (hashmap.find(diff) != hashmap.end()) {

                    cout << "Result: [" << hashmap[diff] << ", " << i << "]" << endl;

                    found = true;
                    break;
                }

                hashmap[nums[i]] = i;
            }

            if (!found) {
                cout << "Not Found..." << endl;
            }
        }


        // Valid Parentheses
        else if (choice == 2) {

            string s;

            cout << "Enter the string: ";
            cin >> s;

            bool value = true;

            stack<char> st;


            for (char ch : s) {

                // Opening bracket
                if (ch == '(' || ch == '[' || ch == '{') {

                    st.push(ch);
                }

                // Closing bracket
                else {

                    if (st.empty()) {
                        value = false;
                        break;
                    }

                    char top = st.top();

                    st.pop();


                    if (ch == ')' && top != '(') {
                        value = false;
                        break;
                    }

                    if (ch == ']' && top != '[') {
                        value = false;
                        break;
                    }

                    if (ch == '}' && top != '{') {
                        value = false;
                        break;
                    }
                }
            }


            // Opening brackets still remaining
            if (!st.empty()) {
                value = false;
            }

            cout << boolalpha << value << endl;
        }


        else {
            cout << "Invalid Choice!" << endl;
        }
    }

    return 0;
}
