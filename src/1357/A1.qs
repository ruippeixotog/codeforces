namespace A1 {
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Diagnostics;
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Measurement;

    operation Solve (unitary : (Qubit[] => Unit is Adj+Ctl)) : Int {
        using (qubits = Qubit[2]) {
            X(qubits[0]);
            unitary(qubits);
            X(qubits[0]);
            if(MResetZ(qubits[1]) == One) {
                return 0;
            }
        }
        return 1;
    }

    @Test("QuantumSimulator")
    operation Test () : Unit {
        for (_ in 0..100) {
            Fact(Solve(CNOT12) == 0, "Solve(CNOT12) was not 0");
            Fact(Solve(CNOT21) == 1, "Solve(CNOT21) was not 1");
        }
    }

    operation CNOT12(qs : Qubit[]): Unit is Adj+Ctl {
        CNOT(qs[0], qs[1]);
    }

    operation CNOT21(qs : Qubit[]): Unit is Adj+Ctl {
        CNOT(qs[1], qs[0]);
    }
}
