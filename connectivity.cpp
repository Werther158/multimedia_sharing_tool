#include <connectivity.h>
#include <curl/curl.h>
#include <curl/easy.h>
#include <sstream>
#include <iostream>

using namespace std;

size_t write_data(void *ptr, size_t size, size_t nmemb, void *stream) {
    string data((const char*) ptr, (size_t) size * nmemb);
    *((stringstream*) stream) << data;
    return size * nmemb;
}

Connectivity::Connectivity() {
}

Connectivity::~Connectivity() {
}

string Connectivity::getPublicIp() {
    void* curl;
    curl = curl_easy_init();
    curl_easy_setopt(curl, CURLOPT_URL, "https://api.ipify.org/");
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
    curl_easy_setopt(curl, CURLOPT_NOSIGNAL, 1);
    curl_easy_setopt(curl, CURLOPT_ACCEPT_ENCODING, "deflate");
    std::stringstream out;
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &out);
    /* Perform the request, res will get the return code */
    CURLcode res = curl_easy_perform(curl);
    /* Check for errors */
    if (res != CURLE_OK) {
        fprintf(stderr, "curl_easy_perform() failed: %s\n",
                curl_easy_strerror(res));
    }
    curl_easy_cleanup(curl);
    return out.str();
}
