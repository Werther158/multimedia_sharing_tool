#include <curl/curl.h>

int curl_test()
{
    CURL *curl;
    /* First step, init curl */
    curl = curl_easy_init();
    if (!curl) {
       return -1;
    }

    return 0;
}
