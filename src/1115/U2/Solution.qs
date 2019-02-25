namespace Solution {
  open Microsoft.Quantum.Primitive;
  open Microsoft.Quantum.Canon;

  operation Solve (qs : Qubit[]) : Unit {
    for(i in 0..Length(qs)-1) {
      if(i != 1) {
        H(qs[i]);
      }
    }
  }
}
