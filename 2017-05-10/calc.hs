_m :: Double
_m        = 0.0
n  :: Double
n        = 3.0
k0_300 :: Double
k0_300   = 2.0E-30
kinf_300 :: Double
kinf_300 = 2.5E-11
k0 :: Double -> Double
k0   t = k0_300   * ( t / 300.0) ** (-3) 
kinf :: Double -> Double
kinf t = kinf_300
kexp :: Double -> Double -> Double
kexp t m = (1.0 + logBase 10.0 ((k0 t) * m / kinf t) ** 2) ** (-1)
k    :: Double -> Double -> Double
k    t m = (k0 t * m / (1 + k0 t * m / kinf t)) * (0.6 ** kexp t m)
