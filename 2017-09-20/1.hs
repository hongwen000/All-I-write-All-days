main :: IO ()
main = readLn >>= \name -> putStrLn ("hello " ++ name)
