namespace Solution {
  open Microsoft.Quantum.Primitive;
  open Microsoft.Quantum.Canon;

  operation Solve (x : Qubit[], y : Qubit) : Unit {
    body (...) {
      ApplyToEachCA(X, x);
      (Controlled X)(x, y);
      X(y);
      ApplyToEachCA(X, x);
    }
    adjoint auto;
  }
}
