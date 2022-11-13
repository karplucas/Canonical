#include "HTTPDownloader.hpp"
#include <iostream>
#include <string>

const std::string ubuntu_url = "https://cloud-images.ubuntu.com/releases/streams/v1/com.ubuntu.cloud:released:download.json";

int main(int argc, char** argv) {
    HTTPDownloader downloader;
    std::string content = downloader.download(ubuntu_url);
    std::cout << content << std::endl;
}