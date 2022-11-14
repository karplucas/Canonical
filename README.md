# Dependencies:
```
sudo apt install cmake libcurl4-openssl-dev
```
# Build instructions
```
git clone https://github.com/karplucas/Canonical
git submodule init
git submodule update
mkdir build
cd build
cmake ..
make
./ubuntufetcher [-a] [-c] [-s VERSION]
```

Ubuntufetcher requires the curl package.
If on Windows, download curl and modify the following based on where you stored curl:
    ```set(CURL_SRC_DIR "C:/lib/curl-7.86.0_2")```

# Run instructions
    Usage: ./ubuntufetcher [-a] [-c] [-s VERSION]
    
    Options:
    -a             - Return a list of all currently supported Ubuntu releases. 
    -c             - Return the current Ubuntu LTS version." << std::endl;
    -s [VERSION]   - Return the sha256 of the disk1.img item of a given Ubuntu version. (Ex: 22.04)

