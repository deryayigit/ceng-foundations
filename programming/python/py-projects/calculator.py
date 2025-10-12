def add(a, b): 
    return a + b
    
def subtract(a, b): 
    return a - b
    
def multiply(a, b): 
    return a * b
    
def divide(a, b): 
    return a / b
    
def pow(a, b): 
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
        return f"Unexcepted error: {e}"
#I prefer built-in functions for exception handling which are ZeroDivisionError, TypeError, ValueError, OverflowError

operations = {
    '+': add,
    '-': subtract,
    '*': multiply,
    '/': divide,
    '**': power
}

def get_number(n):
    while True:
        value = input(n)
        try:
            return float(value)
        except ValueError:
            print("Invalid number, try again please.")
        
def calculator():
    while True:
        num1 = get_number("Enter first number: ")
        num2 = get_number("Enter second number: ")
        op = input("Choose operation: ")
        
        if op not in operations:
            print("Invalid operation!")
            continue
        
        result = safe_operation(operations[op], num1, num2)
        print(f"Result: {num1} {op} {num2} = {result}")
        
        cont = input("Try again? (y/n): ").strip().lower()
        if cont != 'y':
            print("End of calculation")
            break
    
    if __name__ == "__main__":
        calculator()
        
