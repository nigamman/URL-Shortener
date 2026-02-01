#ifndef URL_SHORTENER_H
#define URL_SHORTENER_H

#include <unordered_map>
#include <string>
#include <ctime>

using namespace std;

class UrlShortener {
private:
    long long idCounter;
    unordered_map<long long, string> idToUrl;
    unordered_map<string, long long> shortToId;
    unordered_map<long long, time_t> expiry;

    string base62Encode(long long id);
    bool isExpired(long long id);

public:
    UrlShortener();
    string encode(const string& longUrl, int ttl = -1);
    string decode(const string& shortUrl);
};

#endif
