def add(a, b): 
    return a + b
    
def subtract(a, b): 
    return a - b
    
def multiply(a, b): 
    return a * b
    
def divide(a, b): 
    return a / b
    
def power(a, b): 
    return a ** b

def safe_zone(func, a, b):
    try:
        return func(a, b)
    except ZeroDivisionError: 
        return "Cannot divide by zero!"
    except (TypeError, ValueError):
        return "Please enter numeric values."
    except OverflowError:
        return "Numbers are too large"
    except Exception as e:
        return f"Unexpected error: {e}"
#I prefer built-in functions for exception handling which are ZeroDivisionError, TypeError, ValueError, OverflowError

operations = {
    '+': ('Addition', add),
    '-': ('Subtraction', subtract),
    '*': ('Multiplication', multiply),
    '/': ('Division', divide),
    '**': ('Exponentiation', power)
}

def calculator():
    while True:
        try:
            num1 = float(input("Enter first number, please: "))
            num2 = float(input("Enter second number please: "))
        except ValueError:
            print("Please enter numeric values")
            continue
            
        op = input("Operations: +, -, *, /, ** \nYour choice: ")

        if op not in operations:
            print("Invalid operation symbol!")
            continue

        func = operations[op][1]  # fonksiyonu al
        result = safe_zone(func, num1, num2)
        print(f"Result: {num1} {op} {num2} = {result}")
        
        cont = input("Try again? (y/n): ").strip().lower()
        if cont != 'y':
            print("End of calculation")
            break

calculator()
