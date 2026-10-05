while True:
    print("\n1. Two Sum Problem.")
    print("2. Valid Parenthesis.")
    print("3. Exit...")

    choice = input("Enter your choice: ")

    if choice == '3':
        print("Program exited.")
        break

    if choice == '1':

        n = int(input("\nEnter number of elements: "))

        nums = []

        for i in range(n):
            elements = int(input(f"Enter element {i + 1}: "))
            nums.append(elements)

        print("nums =", nums)

        target = int(input("Enter the target value: "))

        hashmap = {}
        found = False

        for i in range(len(nums)):

            diff = target - nums[i]

            if diff in hashmap:
                print(f"The two sum indexes of {target}:",
                      [hashmap[diff], i])

                found = True
                break

            hashmap[nums[i]] = i

        if not found:
            print("Not Exist...")

    elif choice == '2':

        s = input("\nEnter the string: ")

        stack = []
        valid = True

        for char in s:

            if char == '(' or char == '[' or char == '{':
                stack.append(char)

            else:

                if not stack:
                    valid = False
                    break

                top = stack.pop()

                if char == ')' and top != '(':
                    valid = False
                    break

                if char == ']' and top != '[':
                    valid = False
                    break

                if char == '}' and top != '{':
                    valid = False
                    break

        if len(stack) != 0:
            valid = False

        print("Valid:", valid)

    else:
        print("Invalid choice!")
