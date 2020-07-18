namespace A6 {
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Convert;
    open Microsoft.Quantum.Diagnostics;
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Math;
    open Microsoft.Quantum.Measurement;

    operation Solve (unitary : (Qubit => Unit is Adj+Ctl)) : Int {
        using (qs = Qubit[2]) {
            H(qs[0]);
            CNOT(qs[0], qs[1]);
            unitary(qs[0]);
            CNOT(qs[0], qs[1]);
            H(qs[0]);

            let m = (MResetZ(qs[1]) == One ? 2 | 0) + (MResetZ(qs[0]) == One ? 1 | 0);
            let results = [0, 3, 1, 2];
            return results[m];
        }
    }

    @Test("QuantumSimulator")
    operation Test () : Unit {
        for (i in 0..100) {
            Fact(Solve(I) == 0, "Solve(I) was not 0");
            Fact(Solve(X) == 1, "Solve(X) was not 1");
            Fact(Solve(Y) == 2, "Solve(Y) was not 2");
            Fact(Solve(Z) == 3, "Solve(Z) was not 3");
        }
    }
}
