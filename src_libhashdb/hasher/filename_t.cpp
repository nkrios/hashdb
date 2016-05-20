/**
 * \file
 * provide system-specific filename type and conversion function for Windows.
 */

#include <config.h>
// this process of getting WIN32 defined was inspired
// from i686-w64-mingw32/sys-root/mingw/include/windows.h.
// All this to include winsock2.h before windows.h to avoid a warning.
#if defined(__MINGW64__) && defined(__cplusplus)
#  ifndef WIN32
#    define WIN32
#  endif
#endif
#ifdef WIN32
  // including winsock2.h now keeps an included header somewhere from
  // including windows.h first, resulting in a warning.
  #include <winsock2.h>
  #include "fsync.h"      // for simulation of linux fsync
#endif

#include <string>
#include "filename_t.hpp"

namespace hasher {

// get filename in native string type
filename_t utf8_to_native(const std::string &fn8)
#ifdef WIN32
// adapted from http://stackoverflow.com/questions/6693010/problem-using-multibytetowidechar
// MultiByteToWideChar needs Windows.h
{
    int wchars_num = MultiByteToWideChar(CP_UTF8, 0, fn8.c_str(), -1, NULL ,0 );
    if (wchars_num == 0 || wchars_num == 0xfffd) {
        std::cerr << "Invalid UTF8 code in filename.\n";
        return std::wstring(_TEXT(""));
    }

    wchar_t* wstr = new wchar_t[wchars_num];
    MultiByteToWideChar(CP_UTF8, 0, fn8.c_str(), -1, wstr, wchars_num);
    std::wstring fn16(wstr, wchars_num);
    delete[] wstr;
    return fn16;
}
#else
{
return fn8;
}
#endif

} // end namespace hasher

//zz
/*
static std::wstring utf8to16(const std::string &fn8)
{
    std::wstring fn16;
    utf8::utf8to16(fn8.begin(),fn8.end(),back_inserter(fn16));
    return fn16;
}
#if 0
static std::string utf16to8(const std::wstring &fn16)
{
    std::string fn8;
    utf8::utf16to8(fn16.begin(),fn16.end(),back_inserter(fn8));
    return fn8;
}
#endif
*/
