## **LICZEBNIKI CHURCHA**

Liczby naturalne Churcha to konstrukcja w rachunku lambda. Podstawą budowania liczb w ten sposób jest zdefiniowanie zera:

`zero = lambda f: lambda x: x`

Kolejne liczby możemy zdefiniować za pomocą "successora" (który po prostu dodaje kolejne wywołanie funkcji przez co jest ona o jeden większa) lub przez dwa parametry f oraz x:

```
one = (successor)(zero)
five = lambda f: lambda x: f(f(f(f(f(x)))))
ten = lambda f: lambda x: f(f(f(f(f(f(f(f(f(f(x))))))))))
```

Teraz możemy zdefiniować parę operacji arytmetycznych na tych liczebnikach.

Dodawanie dwóch liczb Churcha "a" i "b" polega na a-krotnym zaaplikowaniu "successora" do liczby b i tak powstaje suma:

```
def addition(a,b):
  return lambda f: lambda x: a(f)(b(f)(x))
```

Mnożenie działa na podobnych zasadach tzn. "b" razy dodajemy "a" w funkcji, czyli działa tak jak zwykłe mnożenie:

```
def multiplication(a,b):
  return lambda f: lambda x: a(b(f))(x)
```

Potęgowanie jest rozwiniętym mnożeniem tzn. b-krotnie mnożymy przez liczbę "a":

```
def exponentiation(a,b):
  return lambda f: lambda x: (a)(b)(f)(x)
```

Tak przygotowany kod możemy przetestować, a do tego potrzebna nam funkcja, która przekonwertuje liczebniki Churcha na liczby dziesiętne. Polega ona na tym, iż wywołuje procedurę zdefiniowanej liczby i funkcje zwiększającą o jeden oraz zero:

```
def convertion(p):
  return p(lambda x: x+1)(0)
```

Teraz możemy przetestować nasz program.
