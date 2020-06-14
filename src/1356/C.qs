namespace C {
    open Microsoft.Quantum.Arithmetic;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Diagnostics;
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Math;
    open Microsoft.Quantum.Measurement;

    operation Solve (qs : Qubit[]) : Unit {
        using (aux = Qubit()) {
            repeat {
                ApplyToEach(H, qs);
                (ControlledOnInt(0, X))(qs, aux);
            }
            until (MResetZ(aux) == Zero)
            fixup {
                ResetAll(qs);
            }
        }
    }

    @Test("QuantumSimulator")
    operation Test () : Unit {
        using (qubits = Qubit[2]) {
            Solve(qubits);
            AssertProbInt(1, 1.0 / 3.0, LittleEndian(qubits), 1e-4);
            AssertProbInt(2, 1.0 / 3.0, LittleEndian(qubits), 1e-4);
            AssertProbInt(3, 1.0 / 3.0, LittleEndian(qubits), 1e-4);
            ResetAll(qubits);
        }
    }
}
