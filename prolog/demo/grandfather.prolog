child(xiaoming, daming).
child(xiaoming, mei).
child(mei, lan).
child(mei, jun).
child(daming, laoming).
child(daming, lei).
male(daming).
male(jun).
male(laoming).
father(X, Y) :- child(Y, X), male(X).
grandfather(X, Z) :- father(X, Y), father(Y, Z).
