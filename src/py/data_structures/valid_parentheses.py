def valid_parentheses(s):
    
    stack = []
    matches = {")": "(", "]": "[", "}": "{"}

    for char in s:
        if char in matches.values():
            stack.append(char)
        if char in matches:
            if len(stack) == 0:
                return False
            else:
                top = stack.pop()
                if matches[char] != top:
                    return False

    # TODO: Examine each character in s.
    # If it is an opening bracket, push it onto stack.
    # If it is a closing bracket:
    #   - Return False if stack is empty.
    #   - Otherwise, pop the top bracket and check for a match.

    # TODO: Return True only if stack is empty at the end.
    return len(stack) == 0


# Test cases
tests = [
    ("()[]{}", True),
    ("([{}])", True),
    ("(]", False),
    ("([)]", False),
    ("(((", False),
    ("", True),
]

for s, expected in tests:
    actual = valid_parentheses(s)
    status = "PASS" if actual == expected else "FAIL"
    print(f"{status}: input={s!r}, expected={expected}, got={actual}")
