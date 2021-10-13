from cs50 import get_int


def main():
    
    # get the credit card number
    num = get_int("Number: ")
    
    # if the number checksum is valid print the company name
    if check(num):
        companyName(int(str(num)[0:2]))  # passing only the first two digit 
    else:
        print("INVALID\n")


# run the checksum algorithm
def check(num):

    Sum = 0
    
    # reverse and loop through the digits
    for i, n in enumerate(reversed(str(num))):
        
        # add only the last digits 
        if i % 2 == 0:
            Sum += int(n)
        else:
            for j in str(int(n)*2):
                Sum += int(j)

    if Sum % 10 == 0:
        return True
    else:
        return False
        

# determine the company name based on the first two numbers
def companyName(num):

    if (num == 34 or num == 37):
        print("AMEX\n")
    elif (num > 50 and num < 56):
        print("MASTERCARD\n")
    else:
        print("VISA\n")


main()