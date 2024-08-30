#include <iostream>
#include <fstream>
#include <string>
#include <curl/curl.h>
#include <nlohmann/json.hpp> // Library for JSON parsing // کتابخانه برای تجزیه JSON

using json = nlohmann::json; // Define alias for JSON namespace // تعریف یک نام مستعار برای فضای نام JSON

// Define your VirusTotal API key here // کلید API خود را اینجا قرار دهید
std::string apiKey = "YOUR_API_KEY";

// Callback function to handle data received from the server // تابع callback برای مدیریت داده‌های دریافتی از سرور
size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* s) {
    size_t newLength = size * nmemb;
    try {
        s->append((char*)contents, newLength);
    } catch(std::bad_alloc &e) {
        // Handle memory allocation errors // مدیریت خطاهای تخصیص حافظه
        return 0;
    }
    return newLength;
}

// Function to upload a file to VirusTotal // تابع برای آپلود یک فایل به VirusTotal
void uploadFileToVirusTotal(const std::string& filePath) {
    CURL* curl;
    CURLcode res;
    
    // Initialize CURL // مقداردهی اولیه CURL
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl) {
        struct curl_httppost* formpost = nullptr;
        struct curl_httppost* lastptr = nullptr;
        struct curl_slist* headerlist = nullptr;
        std::string response;

        // Set up the API key header // تنظیم هدر کلید API
        std::string apiKeyHeader = "x-apikey: " + apiKey;
        headerlist = curl_slist_append(headerlist, apiKeyHeader.c_str());

        // Add the file to the POST form // افزودن فایل به فرم POST
        curl_formadd(&formpost,
                     &lastptr,
                     CURLFORM_COPYNAME, "file",
                     CURLFORM_FILE, filePath.c_str(),
                     CURLFORM_END);

        // Set the URL for the request // تنظیم آدرس URL برای درخواست
        curl_easy_setopt(curl, CURLOPT_URL, "https://www.virustotal.com/api/v3/files");
        curl_easy_setopt(curl, CURLOPT_HTTPPOST, formpost);
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headerlist);

        // Set the callback function to capture the response // تنظیم تابع callback برای دریافت پاسخ
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

        // Perform the request and check for errors // انجام درخواست و بررسی خطاها
        res = curl_easy_perform(curl);

        if(res != CURLE_OK) {
            std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
        } else {
            // Parse the response from VirusTotal // تجزیه پاسخ دریافتی از VirusTotal
            auto jsonResponse = json::parse(response);

            // Check scan results // بررسی نتایج اسکن
            int positives = jsonResponse["data"]["attributes"]["last_analysis_stats"]["malicious"];
            if (positives == 0) {
                std::cout << "The file is clean. No antivirus detected it as malicious." << std::endl;
                // فایل پاک است. هیچ آنتی‌ویروسی آن را به عنوان بدافزار شناسایی نکرده است.
            } else {
                std::cout << "The file was detected as malicious by the following antivirus engines:" << std::endl;
                // فایل توسط آنتی‌ویروس‌های زیر به عنوان بدافزار شناسایی شده است:
                for (auto& engine : jsonResponse["data"]["attributes"]["last_analysis_results"].items()) {
                    if (engine.value()["category"] == "malicious") {
                        std::cout << engine.key() << ": " << engine.value()["result"] << std::endl;
                    }
                }
            }
        }

        // Clean up CURL objects // پاکسازی اشیای CURL
        curl_easy_cleanup(curl);
        curl_formfree(formpost);
        curl_slist_free_all(headerlist);
    }

    // Clean up CURL global environment // پاکسازی محیط عمومی CURL
    curl_global_cleanup();
}

int main() {
    // Get the file path from the user // دریافت مسیر فایل از کاربر
    std::string filePath;
    std::cout << "Enter the file path to upload to VirusTotal: ";
    std::getline(std::cin, filePath);

    // Upload the file to VirusTotal // آپلود فایل به VirusTotal
    uploadFileToVirusTotal(filePath);

    return 0;
}
