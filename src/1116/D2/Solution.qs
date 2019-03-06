namespace Solution {
  open Microsoft.Quantum.Primitive;
  open Microsoft.Quantum.Canon;

  // operation ApplySuperset(target: Qubit, ctrls: Qubit[], rest: Qubit[]): Unit {
  //   if(Length(rest) == 0) {
  //     if(Length(ctrls) != 0) {
  //       (Controlled H)(ctrls, target);
  //     }
  //   } else {
  //     ApplySuperset(target, ctrls, rest[1..Length(rest)-1]);
  //     ApplySuperset(target, ctrls + [rest[0]], rest[1..Length(rest)-1]);
  //   }
  // }

  // operation Solve (qs : Qubit[]) : Unit {
  //   let N = Length(qs);
  //   for(i in 0..N-1) {
  //     ApplySuperset(qs[i], qs[1..0], qs[i+1..N-1]);
  //     // for(from in i+1..N-1) {
  //     //   for(to in from..N-1) {
  //     //     // Message($"bit {i} cond on {i+1}..{j}");
  //     //     (Controlled H)(qs[from..to], qs[i]);
  //     //   }
  //     // }
  //   }

  //   (Controlled H)([qs[1]], qs[0]);

  //   (Controlled H)([qs[2]], qs[0]);
  //   (Controlled H)([qs[1], qs[2]], qs[0]);
  //   (Controlled H)([qs[2]], qs[1]);
  // }

  operation Solve (qs : Qubit[]) : Unit {
    for(i in Length(qs)-1..-1..1) {
      (Controlled H)([qs[i]], qs[i - 1]);
    }
  }
}
