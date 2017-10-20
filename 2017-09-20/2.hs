addIfPresent :: Maybe Int -> Maybe Int -> Maybe Int
addIfPresent mx my = do
    x <- mx
    y <- my
    return (x + y)
