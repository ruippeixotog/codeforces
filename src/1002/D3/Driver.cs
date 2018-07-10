using Microsoft.Quantum.Simulation.Core;
using Microsoft.Quantum.Simulation.Simulators;

namespace Solution
{
  class Driver
  {
    static void Main(string[] args)
    {
      using (var sim = new QuantumSimulator())
      {
        var res = Test.Run(sim).Result;
      }
    }
  }
}
