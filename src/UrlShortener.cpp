<<<<<<< HEAD
#include "UrlShortener.h"
#include <iostream>
#include <algorithm>

static const string BASE62 = 
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

UrlShortener::UrlShortener() {
    idCounter = 1; // start from 1 for clarity
}

string UrlShortener::base62Encode(long long id) {
    string encoded;
    while (id > 0) {
        encoded.push_back(BASE62[id % 62]);
        id /= 62;
    }
    reverse(encoded.begin(), encoded.end());
    return encoded;
}

bool UrlShortener::isExpired(long long id) {
    if (expiry.find(id) == expiry.end()) return false;
    return time(nullptr) > expiry[id];
}

string UrlShortener::encode(const string& longUrl, int ttl) {
    long long id = idCounter++;
    string shortCode = base62Encode(id);

    idToUrl[id] = longUrl;
    shortToId[shortCode] = id;

    if (ttl != -1) {
        expiry[id] = time(nullptr) + ttl;
    }

    return shortCode;
}

string UrlShortener::decode(const string& shortUrl) {
    if (shortToId.find(shortUrl) == shortToId.end()) {
        return "URL not found";
    }

    long long id = shortToId[shortUrl];

    if (isExpired(id)) {
        idToUrl.erase(id);
        shortToId.erase(shortUrl);
        expiry.erase(id);
        return "URL expired";
    }

    return idToUrl[id];
}
=======
#include "UrlShortener.h"
#include <iostream>
#include <algorithm>

static const string BASE62 = 
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

UrlShortener::UrlShortener() {
    idCounter = 1; // start from 1 for clarity
}

string UrlShortener::base62Encode(long long id) {
    string encoded;
    while (id > 0) {
        encoded.push_back(BASE62[id % 62]);
        id /= 62;
    }
    reverse(encoded.begin(), encoded.end());
    return encoded;
}

bool UrlShortener::isExpired(long long id) {
    if (expiry.find(id) == expiry.end()) return false;
    return time(nullptr) > expiry[id];
}

string UrlShortener::encode(const string& longUrl, int ttl) {
    long long id = idCounter++;
    string shortCode = base62Encode(id);

    idToUrl[id] = longUrl;
    shortToId[shortCode] = id;

    if (ttl != -1) {
        expiry[id] = time(nullptr) + ttl;
    }

    return shortCode;
}

string UrlShortener::decode(const string& shortUrl) {
    if (shortToId.find(shortUrl) == shortToId.end()) {
        return "URL not found";
    }

    long long id = shortToId[shortUrl];

    if (isExpired(id)) {
        idToUrl.erase(id);
        shortToId.erase(shortUrl);
        expiry.erase(id);
        return "URL expired";
    }

    return idToUrl[id];
}
>>>>>>> 5d2b9aa247a540e598ee70b48ec0af6e5c9fe062
