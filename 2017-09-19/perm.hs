import           Data.List

toTup3 :: [Int] -> (Int, Int, Int)
toTup3 [a, b, c] = (a, b, c)
perm :: [Int] -> [[Int]]
perm [] = [[]]
perm xs = [y : ys | y <- xs, ys <- perm (delete y xs)]
ans :: Int -> [(Int, Int, Int)]
ans n = [(a, b, c) | (a, b, c) <- map toTup3 (perm xs) , a ^ 2 + b ^ 2 == c ^ 2]
  where
    xs = drop (n - 3) [1..n]

