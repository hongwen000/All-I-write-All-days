module Library where
type Person = String
type Book   = String
type Datebase = [(Person, Book)]
exampleBase :: Datebase
exampleBase
    = [("Alice", "Tintin"), ("Anna", "Little Women")
        ,("darid", "C++ Prime")]
books       :: Datebase -> Person -> [Book]
borrowers   :: Datebase -> Book -> [Person]
borrowed    :: Datebase -> Book -> Bool
numBorrwed :: Datebase -> Person -> Int
makeLoan    :: Datebase -> Person -> Book -> Datebase
returnLoan  :: Datebase -> Person -> Book -> Datebase
books dBase pers
    = [book | (person, book) <- dBase, person == pers]
borrowers dBase bk
    = [person | (person, book) <- dBase, book == bk]
borrowed dBase bk
    = bk `elem` borrewedBase
    where borrewedBase = [book | (_, book) <- dBase]
numBorrwed dBase pers
    = length borrewedBase
    where borrewedBase = books dBase pers
makeLoan dBase pers bk
    = (pers, bk) : dBase
returnLoan dBase pers bk
    = [pair | pair <- dBase, pair /= (pers, bk)]

