#include "HTTPDownloader.hpp"
#include "ubuntufetcher.hpp"
#include <iostream>
#include <string>
#include <vector>



UbuntuFetcher::UbuntuFetcher(){}
UbuntuFetcher::~UbuntuFetcher(){}

void UbuntuFetcher::download() {
    HTTPDownloader downloader;
    std::string content = downloader.download(url);
    releases = json::parse(content, nullptr, false);
}
void UbuntuFetcher::supportedReleases() {
    std::vector<std::string> supported_amd64;
    for (auto product : releases["products"]) {
        if (product["amd64"] == "amd64" && product["supported"] == "true")
            supported_amd64.push_back(product["release"]);
    }
    return "";
}

void UbuntuFetcher::currentVersion() {
    return "";
}

void UbuntuFetcher::imageSHA256(const std::string &name) {
    return "";
}


//● Return a list of all currently supported Ubuntu releases.
//● Return the current Ubuntu LTS version.
//● Return the sha256 of the disk1.img item of a given Ubuntu release.

int main(int argc, char** argv) {
    UbuntuFetcher fetcher;
    fetcher.download();
}