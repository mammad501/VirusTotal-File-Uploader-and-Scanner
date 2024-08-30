VirusTotal File Uploader and Scanner
Overview
This C++ program allows users to upload a file to VirusTotal and check whether it is clean or has been flagged as malicious by any antivirus engines. The program uses the libcurl library to make HTTP requests and the nlohmann/json library to parse JSON responses.

Features
File Upload: The program accepts a file path from the user and uploads the file to VirusTotal for analysis.
Virus Scanning: It retrieves the scan results from VirusTotal and checks whether the file has been detected as malicious.
User-Friendly Output: Based on the scan results, the program provides a simple and clear message to the user:
If the file is clean, the program informs the user that no antivirus engine has flagged the file as malicious.
If the file is detected as malicious, the program lists the antivirus engines that flagged the file and provides the detection names.
Dependencies
The program relies on the following libraries:

libcurl: Used for handling HTTP requests.
nlohmann/json: Used for parsing JSON responses from VirusTotal.
Installation of Dependencies
Linux (Ubuntu/Debian):
bash
Copy code
sudo apt-get install libcurl4-openssl-dev
sudo apt-get install nlohmann-json3-dev
Windows:
Download and install libcurl from https://curl.se/windows/.
Download the nlohmann/json header file from https://github.com/nlohmann/json.
Usage
Compile the Program: Compile the C++ code using your preferred compiler, ensuring that libcurl and nlohmann/json are properly linked.

Run the Program: Run the executable. The program will prompt you to enter the file path of the file you want to upload to VirusTotal.

Enter the File Path: After entering the file path, the program will upload the file to VirusTotal, retrieve the scan results, and display them.

Example Output
If the file is clean:

csharp
Copy code
The file is clean. No antivirus detected it as malicious.
If the file is detected as malicious:

vbnet
Copy code
The file was detected as malicious by the following antivirus engines:
Avast: Win32:Malware-gen
Kaspersky: Trojan.Win32.Generic
BitDefender: Gen:Variant.Ursu.3451
API Key
To use this program, you must have a VirusTotal API key. Replace "YOUR_API_KEY" in the source code with your actual API key. You can obtain an API key by signing up on the VirusTotal website.

Disclaimer
This program is for educational purposes only. Always use VirusTotal responsibly and ensure that you have the right to upload files for scanning.

