#include "HTTPDownloader.hpp"
#include "ubuntufetcher.hpp"
#include <iostream>
#include <string>
#include <regex>
#include <sstream>
#include <fstream>



UbuntuFetcher::UbuntuFetcher(){}
UbuntuFetcher::~UbuntuFetcher(){}

void UbuntuFetcher::download() {
    HTTPDownloader downloader;
    std::string content = downloader.download(url);

    try
    {
        // parsing input with a syntax error
        releases = json::parse(content);
    }
    catch (json::parse_error& e)
    {
        // output exception information
        std::cout << "message: " << e.what() << '\n'
            << "exception id: " << e.id << '\n'
            << "byte position of error: " << e.byte << std::endl;
    }
}

void UbuntuFetcher::supportedReleases() {
    std::cout << "Currently supported LTS versions: " << std::endl;
    for (auto product : releases["products"]) {
        if (product["arch"] == "amd64" && product["supported"] == true) {
            std::cout << "\t\t\t\t" << product["version"] << std::endl;
        }
    }
    std::cout << std::endl;
    
}

void UbuntuFetcher::currentVersion() {
    std::string current;
    json temp = releases["products"];
    std::reverse(temp.begin(), temp.end());
    for (auto product : temp) {
        if (product["arch"] == "amd64" && product["supported"] == true) {
            std::cout << "The current Ubuntu LTS version is: " << product["version"] << std::endl << std::endl;
            break;
        }
    }
}

void UbuntuFetcher::imageSHA256(const std::string &name) {
    for (auto product : releases["products"]) {
        if (product["arch"] == "amd64" && product["supported"] == true && product["version"] == name) {
            auto it = product["versions"].items().begin();
            std::cout << "SHA256 for release: " << name << " is: " << product["versions"][it.key()]["items"]["disk1.img"]["sha256"] << std::endl << std::endl;
            break;
        }
    }
}


//● Return a list of all currently supported Ubuntu releases.
//● Return the current Ubuntu LTS version.
//● Return the sha256 of the disk1.img item of a given Ubuntu release.

int main(int argc, char** argv) {
    UbuntuFetcher fetcher;
    fetcher.download();
    fetcher.supportedReleases();
    fetcher.currentVersion();
    fetcher.imageSHA256("22.04");
}