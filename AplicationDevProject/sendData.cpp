#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <curl/curl.h>
#include "appdev.h"


void send_date(rock r) {
	CURL* curl;
	CURLcode res;
	char poststr[100]; // 10® chars should be enough for 3 values
	// prepare post data
	sprintf(poststr, "min = % d & max = % d & user = % s", r.min, r.max, r.rname);

	curl = curl_easy_init();
	if (curl) {

		curl_easy_setopt(curl, CURLOPT_URL, "www.cc.puv.fi/~e2202741/test.php");
		curl_easy_setopt(curl, CURLOPT_POSTFIELDS, poststr);

		/* Perform the request, res will get the return code */
		res = curl_easy_perform(curl);
		/* Check for errors */
		if (res != CURLE_OK)
			fprintf(stderr, "curl_easy_perform() failed: % s\n",
				curl_easy_strerror(res));

		curl_easy_cleanup(curl);
	}
}