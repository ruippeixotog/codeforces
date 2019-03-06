namespace Solution {
  open Microsoft.Quantum.Primitive;
  open Microsoft.Quantum.Canon;
  open Microsoft.Quantum.Extensions.Convert;
  open Microsoft.Quantum.Extensions.Math;

  operation WState_Arbitrary (qs : Qubit[]) : Unit {
    body (...) {
      let N = Length(qs);
      let head = qs[0];
      if(N == 1) {
        X(head);
      } else {
        Ry(2.0 * ArcCos(Sqrt(1.0 / ToDouble(N))), head);
        (Controlled WState_Arbitrary)([head], qs[1..N-1]);
        X(head);
      }
    }
    controlled auto;
  }

  operation Solve (qs : Qubit[]) : Unit {
    using(ancs = Qubit[3]) {
      WState_Arbitrary(ancs);
      SWAP(ancs[0], qs[0]);
      SWAP(ancs[1], qs[1]);
      ApplyToEach(X, qs);
      CCNOT(qs[0], qs[1], ancs[2]);
      ApplyToEach(X, qs);
    }
  }
}
