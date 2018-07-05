#include <iostream>
#include <string>
#include <assert.h>
struct CutedFilename_t {
	std::string CutedFilename[255];
	int used;
};
CutedFilename_t CutedFilename;
int main()
{
    const char *filename = "/ff/";
    //size_t i = 0, j = 0;
    //while(true)
    //{
    //    if(!filename[i] || filename[i] == '/')
    //    {
    //        if(i - j)
    //            CutedFilename.CutedFilename[CutedFilename.used++] = std::string(filename + j + 1, i - j - 1);
    //        j = i;
    //    }
    //    if(!filename[i])
    //        break;
    //    i++;
    //}
    //for(int i = 0; i < CutedFilename.used; ++i)
    //{
    //    std::cout << CutedFilename.CutedFilename[i] << std::endl;
    //}
        size_t i = 0, j = 0;
    while(true)
    {
        if(!filename[i] || filename[i] == '/')
        {
            if(i - j > 1)
            {
                char name[255];
                strncpy(name, filename + j + 1, i - j - 1);
                name[i - j - 1] = 0;
                printf("%zu\n", strlen(name));
            }
            j = i;
        }
        if(!filename[i])
            break;
        i++;
    }
    return 0;
}
