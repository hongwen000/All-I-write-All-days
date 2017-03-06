#include <stdlib.h>
#include <string.h>
 
struct line {
       int length;
          char contents[0]; // C99的玩法是：char contents[]; 没有指定数组长度
};
 
int main(){
        int this_length=10;
            struct line *thisline = (struct line *)
                                     malloc (sizeof (struct line) + this_length);
                thisline->length = this_length;
                    memset(thisline->contents, 'a', this_length);
                        return 0;
}
