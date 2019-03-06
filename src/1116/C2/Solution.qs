namespace Solution {
  open Microsoft.Quantum.Primitive;
  open Microsoft.Quantum.Canon;
  open Microsoft.Quantum.Extensions.Convert;
  open Microsoft.Quantum.Extensions.Math;

  function ShouldRun (p : Int, pMax: Int): Bool {
    mutable go = true;
    for(i in p+1..pMax) {
      if(i % p == 0) {
        set go = false;
      }
    }
    return go;
  }

  // operation Or (x : Qubit[], y : Qubit) : Unit {
  //   body (...) {
  //     ApplyToEachCA(X, x);
  //     (Controlled X)(x, y);
  //     X(y);
  //     ApplyToEachCA(X, x);
  //   }
  //   adjoint auto;
  // }

  operation SolveP (x : Qubit[], y : Qubit, p : Int, pMax: Int) : Unit {
    body (...) {
      if (ShouldRun(p, pMax)) {
        let N = Length(x);
        using(ancs = Qubit[p]) {
          for(i in 0..p-1) {
            (Controlled X)(x[i..p..N-1], ancs[i]);
            ApplyToEachCA(X, x[i..p..N-1]);
            (Controlled X)(x[i..p..N-1], ancs[i]);
          }
          (Controlled X)(ancs, y);
          for(i in 0..p-1) {
            (Controlled X)(x[i..p..N-1], ancs[i]);
            ApplyToEachCA(X, x[i..p..N-1]);
            (Controlled X)(x[i..p..N-1], ancs[i]);
          }
        }
      }
    }
    adjoint auto;
    controlled auto;
  }

  operation SolveP2 (x : Qubit[], y : Qubit, p : Int, pMax: Int) : Unit {
    body (...) {
      if(p != 0) {
        using (anc = Qubit()) {
          SolveP(x, anc, p, pMax);
          CNOT(anc, y);

          X(anc);
          let op = SolveP2(_, y, p-1, pMax);
          (Controlled op)([anc], x);
          X(anc);

          SolveP(x, anc, p, pMax);
        }
      }
    }
    adjoint auto;
    controlled auto;
  }

  operation Solve (x : Qubit[], y : Qubit) : Unit {
    body (...) {
      SolveP2(x, y, Length(x)-1, Length(x)-1);
      // let N = Length(x);
      // using (ancs = Qubit[N-1]) {
      //   for(p in 1..N-1) {
      //     SolveP(x, ancs[p-1], p, N-1);
      //   }
      //   Or(ancs, y);
      //   for(p in 1..N-1) {
      //     SolveP(x, ancs[p-1], p, N-1);
      //   }
      // }
    }
    adjoint auto;
  }
}
