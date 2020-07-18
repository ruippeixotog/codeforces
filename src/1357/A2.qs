namespace A2 {
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Diagnostics;
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Measurement;

    operation Solve (unitary : (Qubit[] => Unit is Adj+Ctl)) : Int {
        mutable res = 0;
        using (qubits = Qubit[2]) {
            X(qubits[1]);
            unitary(qubits);
            Reset(qubits[1]);
            if(MResetZ(qubits[0]) == One) {
                set res += 2;
            }
            X(qubits[0]);
            unitary(qubits);
            Reset(qubits[0]);
            if(MResetZ(qubits[1]) == One) {
                set res += 1;
            }
        }
        return res;
    }

    @Test("QuantumSimulator")
    operation Test () : Unit {
        for (_ in 0..100) {
            Fact(Solve(I) == 0, "Solve(I) was not 0");
            Fact(Solve(CNOT12) == 1, "Solve(CNOT12) was not 1");
            Fact(Solve(CNOT21) == 2, "Solve(CNOT21) was not 2");
            Fact(Solve(SWAP12) == 3, "Solve(SWAP12) was not 3");
        }
    }

    operation I(qs : Qubit[]): Unit is Adj+Ctl {
    }

    operation CNOT12(qs : Qubit[]): Unit is Adj+Ctl {
        CNOT(qs[0], qs[1]);
    }

    operation CNOT21(qs : Qubit[]): Unit is Adj+Ctl {
        CNOT(qs[1], qs[0]);
    }

    operation SWAP12(qs : Qubit[]): Unit is Adj+Ctl {
        SWAP(qs[0], qs[1]);
    }
}
