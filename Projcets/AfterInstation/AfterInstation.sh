#terminal proxy
#set -gx https_proxy "http://127.0.0.1:1080"
#set -gx http_proxy "http://127.0.0.1:1080"
#g++
sudo add-apt-repository ppa:ubuntu-toolchain-r/test

#Font
#https://sourceforge.net/projects/dejavu/?source=typ_redirect

#git
git config --global http.proxy 'socks5://127.0.0.1:1080'
git config --global https.proxy 'socks5://127.0.0.1:1080'
git config credential.helper store

#fish
curl -L https://get.oh-my.fish | fish
omf install l


