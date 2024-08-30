VirusTotal File Uploader

Description

This C++ program allows you to upload a file to VirusTotal and view the scan results. It helps you determine if your file is flagged as malicious by any antivirus engines.

Dependencies

libcurl: For handling HTTP requests.
nlohmann/json: For parsing JSON responses.
Installation (Linux)

sudo apt-get install libcurl4-openssl-dev
sudo apt-get install nlohmann-json3-dev




Usage

Compile and run the program.
Enter the path of the file you want to upload.
The scan results will be displayed:
If the file is clean, a suitable message will be shown.
If the file is flagged as malicious, the names of the antivirus engines that detected it will be listed.
Note

Replace "YOUR_API_KEY" in the source code with your actual VirusTotal API key before using the program.
