#include <windows.h>

int WINAPI WinMain(
    HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPSTR lpCmdLine,
    int nCmdShow
){
    // 调用API 函数MessageBox
    int nSelect = MessageBox(NULL, TEXT("你好，欢迎来到C语言中文网！"), TEXT("Welcome"), MB_OKCANCEL);
    if(nSelect == IDOK){
        MessageBox(NULL, TEXT("你点击了“确定”按钮"), TEXT("提示"), MB_OK);
    }else{
        MessageBox(NULL, TEXT("你点击了“取消”按钮"), TEXT("提示"), MB_OK);
    }

    return 0;
}