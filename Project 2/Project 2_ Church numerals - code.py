#Code by Kindziak

#!/usr/bin/env python

#definition of zero in Church encoding
zero = lambda f: lambda x: x

#definition of successor
successor = lambda k: lambda f: lambda x: (f)((k)(f)(x))

#Church numerals to ten (for future testing)
one = (successor)(zero)
two = (successor)(one)
three = lambda f: lambda x: f(f(f(x)))
four = lambda f: lambda x: f(f(f(f(x))))
five = lambda f: lambda x: f(f(f(f(f(x)))))
six = lambda f: lambda x: f(f(f(f(f(f(x))))))
seven = lambda f: lambda x: f(f(f(f(f(f(f(x)))))))
eight = lambda f: lambda x: f(f(f(f(f(f(f(f(x))))))))
nine = lambda f: lambda x: f(f(f(f(f(f(f(f(f(x)))))))))
ten = lambda f: lambda x: f(f(f(f(f(f(f(f(f(f(x))))))))))

#creation of functions on Church numerals
def addition(a,b):
  return lambda f: lambda x: a(f)(b(f)(x))
  
def multiplication(a,b):
  return lambda f: lambda x: a(b(f))(x)

def exponentiation(a,b):
  return lambda f: lambda x: (a)(b)(f)(x)
  
#convertion Church numerals into decimal numbers
def convertion(p):
  return p(lambda x: x+1)(0)
  
#testing Church numerals
print ("Zero: ",convertion(zero))
print ("Five: ",convertion(five))
print ("Eight: ",convertion(eight))
print ("Seven: ",eval('convertion((successor)(six))'))
print ("One + nine = ",convertion(addition(one,nine)))
print ("Three * six = ",convertion(multiplication(three,six)))
print ("Two ^ four = ",convertion(exponentiation(two,four)))
