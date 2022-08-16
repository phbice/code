/* failed
stat_a :- stat_a, \+ stat_b.
stat_a :- \+ stat_a, stat_b.
stat_b :- draw(a).
draw(X) :- stat_a, stat_b.
*/