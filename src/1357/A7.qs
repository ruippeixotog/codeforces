namespace A7 {
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Convert;
    open Microsoft.Quantum.Diagnostics;
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Math;
    open Microsoft.Quantum.Measurement;

    operation Aux (unitary1 : (Qubit => Unit is Ctl), unitary2 : (Qubit => Unit is Ctl)): Result {
        using (qs = Qubit[2]) {
            H(qs[0]);
            (Controlled unitary1)([qs[0]], qs[1]);
            (Controlled unitary2)([qs[0]], qs[1]);
            H(qs[0]);
            return MResetZ(qs[0]);
        }
    }

    operation Solve (unitary : (Qubit => Unit is Adj+Ctl)) : Int {
        if (Aux(unitary, unitary) == One) {
            return Aux(unitary, BoundCA([Z, X])) == One ? 3 | 1;
        } else {
            return Aux(unitary, Y) == One ? 2 | 0;
        }
    }

    @Test("QuantumSimulator")
    operation Test () : Unit {
        for (i in 0..100) {
            Fact(Solve(Y) == 0, "Solve(Y) was not 0");
            Fact(Solve(BoundCA([Z, X, R(PauliI, 2.0 * PI(), _)])) == 1, "Solve(-XZ) was not 1");
            Fact(Solve(BoundCA([Y, R(PauliI, 2.0 * PI(), _)])) == 2, "Solve(-Y) was not 2");
            Fact(Solve(BoundCA([Z, X])) == 3, "Solve(XZ) was not 3");
        }
    }
}
