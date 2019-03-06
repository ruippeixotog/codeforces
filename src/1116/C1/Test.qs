namespace Solution {
  open Microsoft.Quantum.Primitive;
  open Microsoft.Quantum.Canon;
  open Microsoft.Quantum.Extensions.Diagnostics;

  operation Set(qs: Qubit[], state: Bool[]): Unit {
    for(i in 0..Length(qs)-1) {
      if(state[i]) {
        X(qs[i]);
      }
    }
  }

  operation AssertOracleResult(input: Bool[], output: Bool, oracle: ((Qubit[], Qubit) => Unit)): Unit {

    let N = Length(input);
    using (qs = Qubit[N+1]) {
      Set(qs[0..N-1], input);
      Solve(qs[0..N-1], qs[N]);
      for(i in 0..N-1) {
        AssertResultEqual(
          M(qs[i]),
          input[i] ? One | Zero,
          $"Input {input} was modified on bit {i}");
      }
      AssertResultEqual(
        M(qs[N]),
        output ? One | Zero,
        $"Wrong output for input {input}. Expected {output}");
      ResetAll(qs);
    }
  }
   
  operation Test() : Unit {
    AssertOracleResult([true, false, true, false], true, Solve);
    AssertOracleResult([false, true, false], true, Solve);
    AssertOracleResult([true, true, true, false], false, Solve);
  }
}
