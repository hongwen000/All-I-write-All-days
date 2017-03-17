data M a        =   Raise Exception | Return a
type Exception  =   String
unit            ::  a -> M a
unit a          =   Return a
mmap             ::  M a -> (a -> M b) -> M b
mmap m k        =   case m of
                        Raise e -> Raise e
                        Return a -> k a
raise           ::  Exception -> M a
raise e         =   Raise e 
