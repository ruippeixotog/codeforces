namespace D2 {
    open Microsoft.Quantum.MachineLearning;

    function ClassifierStructure() : ControlledRotation[] {
        return [
            ControlledRotation((0, new Int[0]), PauliX, 0),
            ControlledRotation((0, new Int[0]), PauliY, 1),
            ControlledRotation((0, new Int[0]), PauliZ, 2)
        ];
    }

    operation Solve() : (ControlledRotation[], (Double[], Double)) {
        return (
            ClassifierStructure(),
            ([1.1572271786022337, 0.5911819419014795, 5.319029338759881], 0.1694)
        );
    }
}
