data Tree a = Leaf | Node (Tree a) a (Tree a)

insert x Leaf = Node Leaf x Leaf
insert x (Node t y s)
    | x <= y = Node (insert x t) y s
    | x > y  = Node t y (insert x s)

toList Leaf = []
toList (Node t x s) = toList t ++ [x] ++ toList s

treesort :: Ord a => [a] -> [a]
treesort = toList . foldr insert Leaf
