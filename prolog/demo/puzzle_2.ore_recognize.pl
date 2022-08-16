ore(iron).
ore(copper).
ore(tin).
student(a).
student(b).
student(c).
index(1).
index(2).
statement(X, a,1) :- \+X=iron.
statement(X, a,2) :- \+X=copper.
statement(X, b,1) :- \+X=iron.
statement(X, b,2) :-   X=tin.
statement(X, c,1) :- \+X=tin.
statement(X, c,2) :-   X=iron.
what_ore(X) :- student(P), student(Q), student(R), ore(X),
    index(I), index(J),
    \+ P=Q, \+ P=R, \+ Q=R, \+ I=J,
    statement(X, P, I), statement(X, P, J),
    statement(X, Q, I), \+statement(X, Q, J),
    \+statement(X, R, I), \+statement(X, R, J).
