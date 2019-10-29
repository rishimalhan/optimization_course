\ENCODING=ISO-8859-1
\Problem name: IloCplex

Minimize
 obj: d(0)
Subject To
 c1: - 2 d(0) + 2 d(5) + 2 d(3) <= 0
 c2: - 2 d(0) + 2 d(6) + 2 d(4) <= 0
 c3: - d(5) <= 0
 c4: - d(6) <= 0
 c5: - d(3) <= 0
 c6: - d(4) <= 0
 c7: - 2 d(5) - 2 d(3) + d(1) + 2 d(2) <= 13
 c8: - 2 d(6) - 2 d(4) + d(1) - 12 d(2) <= 29
End
