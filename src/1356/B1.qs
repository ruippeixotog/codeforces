namespace B1 {
    open Microsoft.Quantum.Arithmetic;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Diagnostics;
    open Microsoft.Quantum.Intrinsic;

    operation Solve (register : LittleEndian) : Unit is Adj+Ctl {
        ApplyToEachCA(X, register!);
        X(register![0]);
        for (i in 1..Length(register!) - 1) {
            Controlled X(register![0..i - 1], register![i]);
        }
        ApplyToEachCA(X, register!);
    }

    @Test("QuantumSimulator")
    operation Test () : Unit {
        TestInput(3, 5);
        TestInput(4, 5);
        TestInput(3, 0);
        TestInput(3, 7);
    }

    operation TestInput (bits: Int, value: Int) : Unit {
        using (qubits = Qubit[bits]) {
            IncrementByInteger(value, LittleEndian(qubits));
            Solve(LittleEndian(qubits));
            IncrementByInteger(-value - 1, LittleEndian(qubits));
            AssertAllZero(qubits);
        }
    }
}
