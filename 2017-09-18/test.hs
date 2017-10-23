module MyFraction where
import Test.QuickCheck

myGCD :: Integer -> Integer -> Integer
myGCD a 0 = a
myGCD a b = myGCD b (a `mod` b)

type Fraction = (Integer, Integer)

toPositive :: Integer -> Integer
toPositive a
  |a > 0 = a
  |otherwise = -a

adjustsign :: Fraction -> Fraction
adjustsign (a, b)
  |(a > 0) == (b > 0) = (a, b)
  |otherwise = (- toPositive a, toPositive b)

simpilfy :: Fraction -> Fraction
simpilfy (a, b) = adjustsign (a `div` c, b `div` c)
  where c = myGCD a b

ratplus :: Fraction -> Fraction -> Fraction
ratplus (a, b) (c, d) = simpilfy (a * d + c * b, b * d)

ratminus :: Fraction -> Fraction -> Fraction
ratminus (a, b) (c, d) = simpilfy (a * d - c * b, b * d)

rattimes :: Fraction -> Fraction -> Fraction
rattimes (a, b) (c, d) = simpilfy (a * c, b * d)

ratdiv :: Fraction -> Fraction -> Fraction
ratdiv (a, b) (c, d) = rattimes (a, b) (d, c)

ratfloor :: Fraction -> Integer
ratfloor (a, b) = a `div` b

ratfloat :: Fraction -> Float
ratfloat (a, b) = fromInteger a / fromInteger b

rateq :: Fraction -> Fraction -> Bool
rateq (a, b) (c, d) = a * d == b * c

infix 5 <+>
(<+>) :: Fraction -> Fraction -> Fraction
(<+>) (a,b) (c,d) = ratplus (a,b) (c,d)

infix 5 <->
(<->) :: Fraction -> Fraction -> Fraction
(<->) (a,b) (c,d) = ratminus (a,b) (c,d)

infix 6 <-*->
(<-*->) :: Fraction -> Fraction -> Fraction
(<-*->) (a,b) (c,d) = rattimes (a,b) (c,d)

infix 6 </>
(</>) :: Fraction -> Fraction -> Fraction
(</>) (a,b) (c,d) = ratdiv (a,b) (c,d)

infix 4 <==>
(<==>) :: Fraction -> Fraction -> Bool
(<==>) = rateq

prop_ratplus_commutativity :: Fraction -> Fraction -> Property
prop_ratplus_commutativity (a, b) (c, d) = b /= 0 && d /= 0 ==> (a, b) <+> (c, d) <==> (c, d) <+> (a, b)

prop_ratplus_associativity :: Fraction -> Fraction -> Fraction -> Property
prop_ratplus_associativity (a, b) (c, d) (e, f) = b /= 0 && d /= 0 && f /= 0 ==> ((a, b) <+> (c, d)) <+> (e, f) <==> (a, b) <+> ((c, d) <+> (e, f))

prop_ratplus_unit :: Fraction -> Property
prop_ratplus_unit (a,b) = b /= 0 ==> (a, b) <+> (0,1) <==> simpilfy(a, b)

prop_ratminus_reverse :: Fraction -> Fraction -> Property
prop_ratminus_reverse (a, b) (c, d) = b /= 0 && d /= 0 ==> ((a, b) <+> (c, d)) <-> (c, d) <==> (a, b)

prop_ratminus_anticommutativity :: Fraction -> Fraction -> Property
prop_ratminus_anticommutativity (a, b) (c, d) = b /= 0 && d /= 0 ==> (a, b) <-> (c, d) <==> (0, 1) <-> ((c, d) <-> (a, b))


prop_rattimes_commutativity :: Fraction -> Fraction -> Property
prop_rattimes_commutativity (a, b) (c, d) = b /= 0 && d /= 0 ==> (a, b) <-*-> (c, d) <==> (c, d) <-*-> (a, b)

prop_rattimes_associativity :: Fraction -> Fraction -> Fraction -> Property
prop_rattimes_associativity (a, b) (c, d) (e, f) = b /= 0 && d /= 0 && f /= 0 ==> ((a, b) <-*-> (c, d)) <-*-> (e, f) <==> (a, b) <-*-> ((c, d) <-*-> (e, f))

prop_rattimes_unit :: Fraction -> Property
prop_rattimes_unit (a,b) = b /= 0 ==> (a, b) <-*-> (0,1) <==> (0,1)

prop_rattimes_plus_distr :: Fraction -> Fraction -> Fraction ->Property
prop_rattimes_plus_distr (a,b) (c,d) (e,f) = b /= 0 && d /= 0 && f /= 0 ==> (a,b) <-*-> ((c,d) <+> (e,f)) <==> ((a,b) <-*-> (c,d)) <+> ((a,b) <-*-> (e,f))

prop_ratdiv_reverse :: Fraction -> Fraction -> Property
prop_ratdiv_reverse (a, b) (c, d) = b /= 0 && c /= 0 && d /= 0 ==> ((a, b) <-*-> (c, d)) </> (c, d) <==> (a, b)

prop_ratdiv_anticommutativity :: Fraction -> Fraction -> Property
prop_ratdiv_anticommutativity (a, b) (c, d) = a /= 0 && b /= 0 && c /= 0 && d /= 0 ==> (a, b) </> (c, d) <==> (1, 1) </> ((c, d) </> (a, b))

{-
main = do {
    quickCheck prop_ratplus_commutativity
    quickCheck prop_ratplus_associativity
    quickCheck prop_ratplus_unit
    quickCheck prop_ratminus_reverse
    quickCheck prop_ratminus_anticommutativity
    quickCheck prop_rattimes_commutativity
    quickCheck prop_rattimes_plus_distr
    quickCheck prop_rattimes_associativity
    quickCheck prop_rattimes_unit
    quickCheck prop_ratdiv_reverse
    quickCheck prop_ratdiv_anticommutativity

  }

-}
