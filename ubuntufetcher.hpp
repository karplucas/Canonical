/**
 * ubuntufetcher.hpp
 *
 * A header defining a class for storing / accessing Ubuntu Cloud image information.
 *
 */
#ifndef UBUNTU_FETCHER_HPP
#define UBUNTU_FETCHER_HPP

#include <string>

 /**
  * An Ubuntu information fetcher class.
  */
class UbuntuFetcher {
public:
    UbuntuFetcher();
    ~UbuntuFetcher();
    /**
    * Download the Simplestream data to std::string info.
    */
    std::string download();
    /**
    * Return all AMD64 Ubuntu supported releases.
    */
    std::string supportedReleases();
    /**
    * Return the current LTS Ubuntu version.
    */
    std::string currentVersion();
    /**
    * Return the SHA256 for disk1.img provided.
    */
    std::string imageSHA256();

private:
    const std::string url = "https://cloud-images.ubuntu.com/releases/streams/v1/com.ubuntu.cloud:released:download.json";
    std::string info;
};

#endif  /* UBUNTU_FETCHER_HPP */