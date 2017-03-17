data Term = Con Int | Div Term Term
type M a = State -> (a, State)
type State = Int
eval :: Term -> M Int
eval (Con a) x = (a, x)
eval (Div t u) x =  let (a, y) = eval t x in
                    let (b, z) = eval u y in
                    (a `div` b, z + 1)
unit :: a -> M a
unit a = (\x -> (a, x))
mmap :: M a -> (a -> M b) -> M b
mmap m k = (\x -> let (a, y) = m x in
                  let (b, z) = k a y in
                  (b, z))
tick :: M()
tick = (\x -> ((), x + 1)) 
