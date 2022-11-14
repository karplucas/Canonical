/**
 * ubuntufetcher.hpp
 *
 * A header defining a class for storing / accessing Ubuntu Cloud image information.
 *
 */
#ifndef UBUNTU_FETCHER_HPP
#define UBUNTU_FETCHER_HPP

#include <string>
#include <nlohmann/json.hpp>

using json = nlohmann::json;


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
    void download();
    /**
    * Return all AMD64 Ubuntu supported releases.
    */
    void supportedReleases();
    /**
    * Return the current LTS Ubuntu version.
    */
    void currentVersion();
    /**
    * Return the SHA256 for disk1.img provided.
    */
    void imageSHA256(const std::string& name);

private:
    const std::string url = "https://cloud-images.ubuntu.com/releases/streams/v1/com.ubuntu.cloud:released:download.json";
    json releases;

};

#endif  /* UBUNTU_FETCHER_HPP */