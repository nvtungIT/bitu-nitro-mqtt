class HybridMath : HybridMathSpec {
  var hybridContext = margelo.nitro.HybridContext()
  var memorySize: Int {
    return getSizeOf(self)
  }

  public func add(a: Double, b: Double) throws -> Double {
    return a + b
  }
}