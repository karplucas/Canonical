#include "HTTPDownloader.hpp"
#include "ubuntufetcher.hpp"
#include <iostream>
#include <string>

UbuntuFetcher::UbuntuFetcher(){}
UbuntuFetcher::~UbuntuFetcher(){}

std::string UbuntuFetcher::download() {
    HTTPDownloader downloader;
    std::string content = downloader.download(url);
    std::cout << content << std::endl;
}


//● Return a list of all currently supported Ubuntu releases.
//● Return the current Ubuntu LTS version.
//● Return the sha256 of the disk1.img item of a given Ubuntu release.

int main(int argc, char** argv) {
    UbuntuFetcher fetcher;
    fetcher.download();
}