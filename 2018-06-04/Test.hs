module Test where
import Data.List
addOne :: Int -> Int
addOne x = x + 1
zs :: [Int]
xs = [4, 5]
ys = [3, 2]
zs = sort xs ++ sort ys
-- == (sort xs) ++ (sort ys)
(++++) :: Int -> Int -> Int
x ++++ y = x ^ 2 + y ^ 2
data Position = MakePosition Double Double | Polar Double Double
distance :: Position -> Position -> Double
{-
distance p1 p2 =
    case p1 of
      MakePosition x1 y1 ->
          case p2 of
            MakePosition x2 y2 -> sqrt ((x1 - x2) ^ 2 + (y1 - y2) ^ 2)
-}
distance (MakePosition x1 y1) (MakePosition x2 y2) =
    sqrt((x1 - x2)^2 + (y1 - y2)^2)
distance (MakePosition x1 y1) (Polar a r) =
    let x2 = r * sin a
        y2 = r * sin a
     in sqrt((x1 - x2)^2 + (y1 - y2)^2)
distance (Polar a r) (MakePosition x2 y2) =
    let x1 = r * sin a
        y1 = r * sin a
     in sqrt((x1 - x2)^2 + (y1 - y2)^2)
distance (Polar a1 r1) (Polar a2 r2) =
    let x1 = r1 * cos a1
        y1 = r1 * sin a1
        x2 = r2 * sin a2
        y2 = r2 * sin a2
     in sqrt((x1 - x2)^2 + (y1 - y2)^2)
pointA :: Position
pointA =  MakePosition 0 0
pointB :: Position
pointB =  MakePosition 3 4
