#include <iostream>
#include "UrlShortener.h"

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

using namespace std;

int main() {
    UrlShortener shortener;

    string shortUrl1 = shortener.encode(
        "https://www.google.com/search?q=sde+interview", 3);

    string shortUrl2 = shortener.encode(
        "https://leetcode.com/problems");

    cout << "Short URL 1: " << shortUrl1 << endl;
    cout << "Short URL 2: " << shortUrl2 << endl;

    cout << "Decode 1: " << shortener.decode(shortUrl1) << endl;
    cout << "Decode 2: " << shortener.decode(shortUrl2) << endl;

#ifdef _WIN32
    Sleep(4000);
#else
    sleep(4);
#endif

    cout << "Decode after expiry: " 
         << shortener.decode(shortUrl1) << endl;

    return 0;
}
