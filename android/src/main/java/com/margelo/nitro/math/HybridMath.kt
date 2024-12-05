class HybridMath : HybridMathSpec() {
    override val memorySize: Long
        get() = 0L
  
    override var pi: Double
      get() = Double.PI
  
    override fun add(a: Double, b: Double): Double {
      return a + b
    }
  }