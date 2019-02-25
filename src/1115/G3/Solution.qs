namespace Solution {
  open Microsoft.Quantum.Primitive;
  open Microsoft.Quantum.Canon;

  operation Solve (x : Qubit[], y : Qubit) : Unit {
    body (...) {
      let N = Length(x);
      using(qs = Qubit[N/2]) {
        for(i in 0..N/2-1) {
          X(qs[i]);
          CNOT(x[i], qs[i]);
          CNOT(x[N-i-1], qs[i]);
        }
        (Controlled X)(qs, y);
        for(i in 0..N/2-1) {
          X(qs[i]);
          CNOT(x[i], qs[i]);
          CNOT(x[N-i-1], qs[i]);
        }
      }
    }
    adjoint auto;
  }
}
