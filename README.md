# Canonical

git submodule init
git submodule update
mkdir build
cd build
cmake ..

Requires the package curl.
If on Windows, download curl and modify the following:
```set(CURL_SRC_DIR "C:/lib/curl-7.86.0_2")```


