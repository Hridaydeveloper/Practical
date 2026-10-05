#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>

using namespace std;

int main()
{
    while (true)
    {
        cout << "\n1. Two Sum Problem." << endl;
        cout << "2. Valid Parenthesis." << endl;
        cout << "3. Exit..." << endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        // Exit
        if (choice == 3)
        {
            cout << "Program exited." << endl;
            break;
        }

        // Two Sum
        if (choice == 1)
        {
            int n;

            cout << "\nEnter number of elements: ";
            cin >> n;

            vector<int> nums;

            for (int i = 0; i < n; i++)
            {
                int element;

                cout << "Enter element " << i + 1 << ": ";
                cin >> element;

                nums.push_back(element);
            }

            cout << "nums = ";

            for (int num : nums)
            {
                cout << num << " ";
            }

            cout << endl;

            int target;
            cout << "Enter the target value: ";
            cin >> target;

            unordered_map<int, int> hashmap;

            bool found = false;

            for (int i = 0; i < nums.size(); i++)
            {
                int diff = target - nums[i];

                if (hashmap.find(diff) != hashmap.end())
                {
                    cout << "The two sum indexes of "
                         << target << ": ["
                         << hashmap[diff] << ", "
                         << i << "]" << endl;

                    found = true;
                    break;
                }

                hashmap[nums[i]] = i;
            }

            if (!found)
            {
                cout << "Not Exist..." << endl;
            }
        }

        // Valid Parentheses
        else if (choice == 2)
        {
            string s;

            cout << "\nEnter the string: ";
            cin >> s;

            stack<char> st;

            bool valid = true;

            for (char ch : s)
            {
                // Opening brackets
                if (ch == '(' || ch == '[' || ch == '{')
                {
                    st.push(ch);
                }

                // Closing brackets
                else
                {
                    if (st.empty())
                    {
                        valid = false;
                        break;
                    }

                    char top = st.top();
                    st.pop();

                    if (ch == ')' && top != '(')
                    {
                        valid = false;
                        break;
                    }

                    if (ch == ']' && top != '[')
                    {
                        valid = false;
                        break;
                    }

                    if (ch == '}' && top != '{')
                    {
                        valid = false;
                        break;
                    }
                }
            }

            if (!st.empty())
            {
                valid = false;
            }

            cout << "Valid: " << boolalpha << valid << endl;
        }

        else
        {
            cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}
