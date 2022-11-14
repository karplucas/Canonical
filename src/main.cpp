#include "HTTPDownloader.hpp"
#include "ubuntufetcher.hpp"
#include <iostream>
#include <string>
#include <regex>
#include <sstream>
#include <fstream>
#include <stdexcept>


UbuntuFetcher::UbuntuFetcher() {}
UbuntuFetcher::~UbuntuFetcher() {}

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
        throw std::invalid_argument("The json file formatting is not correct.");
    }
}

void UbuntuFetcher::supportedReleases() {
    std::cout << "Currently supported LTS versions: ";
    for (auto product : releases["products"]) {
        if (product["arch"] == "amd64" && product["supported"] == true) {
            std::cout << product["version"] << " ";
        }
    }
    std::cout << std::endl << std::endl;

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

void UbuntuFetcher::imageSHA256(const std::string& name) {
    for (auto product : releases["products"]) {
        if (product["arch"] == "amd64" && product["supported"] == true && product["version"] == name) {
            auto it = product["versions"].items().begin();
            std::cout << "SHA256 for release " << name << " is: " << product["versions"][it.key()]["items"]["disk1.img"]["sha256"] << std::endl << std::endl;
            break;
        }
    }

    std::cout << "Could not find the SHA256 for release " << name << std::endl;
}


void printUsage() {
    std::cout << "Usage: ubuntufetcher" << " [-a] [-c] [-s VERSION]" << std::endl;
    std::cout << std::endl;
    std::cout << "Options:" << std::endl;
    std::cout << std::endl;
    std::cout << "-a                  - Return a list of all currently supported Ubuntu releases." << std::endl;
    std::cout << "-c                  - Return the current Ubuntu LTS version." << std::endl;
    std::cout << "-s [VERSION]        - Return the sha256 of the disk1.img item of a given Ubuntu version. (Ex: 22.04)" << std::endl;
    std::cout << std::endl;

}  

int main(int argc, char** argv) {
    bool a = false, c = false, s = false;
    std::string version = "";

    if (argc == 0)
        printUsage();

    for (auto i = 1; i < argc; ++i) {
        if (strcmp(argv[i], "-a") == 0)
            a = true;
        else if (strcmp(argv[i], "-c") == 0)
            c = true;
        else if (strcmp(argv[i], "-s") == 0){
            i++;
            if (i < argc) {
                s = true;
                version = argv[i];
            }
        }
        else {
            printUsage();
            return EXIT_FAILURE;
        }
    }

    UbuntuFetcher fetcher;
    if (a || c || s)
        fetcher.download();
    else
        printUsage();

    if(a)
        fetcher.supportedReleases();
    if(c)
        fetcher.currentVersion();
    if(s)
        fetcher.imageSHA256(version);

    return EXIT_SUCCESS;
}