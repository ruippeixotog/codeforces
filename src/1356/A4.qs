namespace A4 {
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Diagnostics;
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Measurement;

    operation Solve (unitary : (Qubit[] => Unit is Adj+Ctl)) : Int {
        using (qubits = Qubit[2]) {
            unitary(qubits);
            if(MResetZ(qubits[1]) == One) {
                return 0;
            }
        }
        return 1;
    }

    @Test("QuantumSimulator")
    operation Test () : Unit {
        for (_ in 0..100) {
            Fact(Solve(ApplyToElementCA(X, 1, _)) == 0, "Solve(I⊗X) was not 0");
            Fact(Solve(CNOTArr) == 1, "Solve(S) was not 1");
        }
    }

    operation CNOTArr (qs : Qubit[]): Unit is Adj+Ctl {
        CNOT(qs[0], qs[1]);
    }
}
