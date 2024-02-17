t = int(input())

case = 0

for i in range(0, t):
    case += 1
    winner = ""
    digits = []
    # record 3,6,9 counts
    count = 0  
    sum = 0          
    num = input()
    for j in range(0, len(num)):
        digit = int(num[j])
        digits.append(digit)
        sum += digit
        if digit % 3 == 0:
            count += 1
    
    if sum % 3 == 0:
        if count % 2 == 1:
            winner = "S"
        else:
            winner = "T"

    else:
        for j in range(0, len(num)):
            if (sum - digits[j]) % 3 == 0:
                if count % 2 == 1:
                    winner = "T"
                else:
                    winner = "S"
                break
        if winner == "":
            winner = "T"
    
    print(f"Case {case}: {winner}")

    
    
