#!/bin/bash
DESKTOP = /mnt/c/Users/lixin/Desktop
#terminal proxy
export http_proxy=http://127.0.0.1:1080
export https_proxy=http://127.0.0.1:1080
sudo echo Acquire::http::Proxy "http://127.0.0.1:1080/"; >> /etc/apt/apt.conf
#ppa fish shell
sudo apt-add-repository ppa:fish-shell/release-2 -y

#ppa g++
sudo add-apt-repository ppa:ubuntu-toolchain-r/test -y

#git
sudo add-apt-repository ppa:git-core/candidate -y

#g++
sudo add-apt-repository ppa:ubuntu-toolchain-r/test -y

#vim
sudo add-apt-repository ppa:jonathonf/vim -y

#clang
echo deb http://apt.llvm.org/xenial/ llvm-toolchain-xenial-4.0 main >> /tmp/sources.list
echo deb-src http://apt.llvm.org/xenial/ llvm-toolchain-xenial-4.0 main >> /tmp/sources.list
sudo apt-key adv --keyserver keyserver.ubuntu.com --recv-keys 15CF4D18AF4F7421

#163 ppa
echo deb http://mirrors.163.com/ubuntu/ xenial main restricted universe multiverse >> /tmp/sources.list 
echo deb http://mirrors.163.com/ubuntu/ xenial-security main restricted universe multiverse >> /tmp/sources.list 
echo deb http://mirrors.163.com/ubuntu/ xenial-updates main restricted universe multiverse >> /tmp/sources.list 
echo deb http://mirrors.163.com/ubuntu/ xenial-proposed main restricted universe multiverse >> /tmp/sources.list 
echo deb http://mirrors.163.com/ubuntu/ xenial-backports main restricted universe multiverse >> /tmp/sources.list 
echo deb-src http://mirrors.163.com/ubuntu/ xenial main restricted universe multiverse >> /tmp/sources.list 
echo deb-src http://mirrors.163.com/ubuntu/ xenial-security main restricted universe multiverse >> /tmp/sources.list 
echo deb-src http://mirrors.163.com/ubuntu/ xenial-updates main restricted universe multiverse >> /tmp/sources.list 
echo deb-src http://mirrors.163.com/ubuntu/ xenial-proposed main restricted universe multiverse >> /tmp/sources.list 
echo deb-src http://mirrors.163.com/ubuntu/ xenial-backports main restricted universe multiverse >> /tmp/sources.list 

sudo mv -f /tmp/sources.list /etc/apt/

#Font
#https://sourceforge.net/projects/dejavu/?source=typ_redirect

#install
sudo apt-get install openssh-server gdb gdbserver -y
sudo apt-get install gcc-6 g++-6 -y
sudo apt-get install clang-4.0 clang++-4.0 -y
sudo apt-get install clang-format-4.0 -y
sudo apt-get install python python3 python-pip
sudo apt-get install vim
sudo apt-get install fish
sudo apt-get install ctags

#git config
git config --global http.proxy 'socks5://127.0.0.1:1080'
git config --global https.proxy 'socks5://127.0.0.1:1080'
git config --global credential.helper store
git config --global user.name hongwen000
git config --global user.email hongwen000@outlook.com



#ssh
sudo sed -i "s/UsePrivilegeSeparation yes/UsePrivilegeSeperation no/g" /etc/ssh/sshd_config
sudo sed -i "s/PasswordAuthentication no/PasswordAuthentication yes/g" /etc/ssh/sshd_config

#fish and vim config
cd /tmp
git clone https://github.com/hongwen000/fish-functions.git
cd fish-functions
#set -gx https_proxy "http://127.0.0.1:1080"
#set -gx http_proxy "http://127.0.0.1:1080"
curl -L https://get.oh-my.fish | fish
omf install l
mkdir -p ~/.config/fish/functions/
cp -R *.fish ~/.config/fish/functions/
cp .vimrc ~/.vimrc
git clone https://github.com/VundleVim/Vundle.vim.git ~/.vim/bundle/Vundle.vim
