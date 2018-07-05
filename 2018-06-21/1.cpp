#include <string>
#include <iostream>
using namespace std;
struct DirectoryEntry_t {
    uint8_t Filename[8];
    uint8_t Extension[3];
    uint8_t Attributes;
    uint8_t Reserved;
    uint8_t CreationTimeMs;
    uint16_t CreationTime;
    uint16_t CreationDate;
    uint16_t LastAccessTime;
    uint16_t ClusterLow;
    uint16_t ModifiedTime;
    uint16_t ModifiedDate;
    uint16_t FirstCluster;
    uint32_t FileSize;
} __attribute__((__packed__));
int main()
{
    auto filename = "/T";
    DirectoryEntry_t entry;
        uint32_t cluster;
    const char *name;
    const char *ext;
    name = strrchr(filename, '/');
    if(name == nullptr)
    {
        return -1;
    }
    name = name + 1;
    ext = strrchr(filename, '.');
    size_t ext_len;
    size_t name_len;
    if(ext == nullptr)
    {
        ext_len = 0;
        name_len = strlen(name);
    }
    else
    {
        ext = ext + 1;
        ext_len = strlen(ext);
        name_len = strlen(name) - ext_len - 1;
    }
    //const char *name;
    //const char *ext;
    //name = strrchr(filename, '/')+1;
    //ext = strrchr(filename, '.')+1;
    //auto ext_len = strlen(ext);
    //auto name_len = strlen(name) - ext_len - 1;
    cout << ext_len<< endl;
    cout << name_len<< endl;
    strncpy((char*)entry.Filename, name, name_len < 8 ? name_len : 8);
    strncpy((char*)entry.Extension, ext ? ext : "   ", 3);
    entry.Filename[7] = 0;
    cout << entry.Filename<< endl;
    cout << entry.Extension<< endl;
    unsigned char no_log[32] = {
	0x4E, 0x4F, 0x5F, 0x4C, 0x4F, 0x47, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x08, 0xA2, 0xCF, 0x84,
	0xD5, 0x4C, 0xD5, 0x4C, 0x00, 0x00, 0xCF, 0x84, 0xD5, 0x4C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
unsigned char my[32] = {
	0x74, 0x6F, 0x77, 0x72, 0x69, 0x74, 0x65, 0x20, 0x74, 0x20, 0x20, 0x20, 0x08, 0x6F, 0x70, 0xAE,
	0x47, 0x49, 0x47, 0x49, 0x00, 0x00, 0x71, 0xAE, 0x47, 0x49, 0x03, 0x00, 0x18, 0x00, 0x00, 0x00
};
    DirectoryEntry_t* f1 = (DirectoryEntry_t*)no_log;
    DirectoryEntry_t* f2 = (DirectoryEntry_t*)my;
}
