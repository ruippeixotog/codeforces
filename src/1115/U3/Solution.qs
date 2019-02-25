namespace Solution {
  open Microsoft.Quantum.Primitive;
  open Microsoft.Quantum.Canon;

  operation Solve (qs : Qubit[]) : Unit {
    let N = Length(qs);
    ApplyToEachCA((Controlled H)([qs[N-1]], _), qs[0..N-2]);
    X(qs[N-1]);
    ApplyToEachCA(CNOT(qs[N-1], _), qs[0..N-2]);
    X(qs[N-1]);
  }
}
