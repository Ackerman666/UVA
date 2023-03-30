instructions = int(input())
stack = []

for i in range(0, instructions):
    s = input().split(" ")
    if s[0] == "Sleep":
        stack.append(s[1])
    elif s[0] == "Test":
        if len(stack) > 0 :
            print(stack[-1])
        else:
            print("Not in a dream")
    elif s[0] == "Kick" and len(stack) > 0:
        stack.pop()
