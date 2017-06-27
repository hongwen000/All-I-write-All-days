#terminal proxy
#export http_proxy=http://127.0.0.1:1080
#export https_proxy=http://127.0.0.1:1080
#sudo echo Acquire::http::Proxy "http://127.0.0.1:1080/"; >> /etc/apt/apt.conf
#ppa fish shell
sudo apt-get update
sudo apt-get install software-properties-common python-software-properties -y

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
echo deb http://apt.llvm.org/xenial/ llvm-toolchain-xenial-4.0 main >> /etc/apt/sources.list
echo deb-src http://apt.llvm.org/xenial/ llvm-toolchain-xenial-4.0 main >> /etc/apt//sources.list
sudo apt-key adv --keyserver keyserver.ubuntu.com --recv-keys 15CF4D18AF4F7421


#Font
#https://sourceforge.net/projects/dejavu/?source=typ_redirect

#install
sudo apt-get update
sudo apt-get install python-pip
sudo pip install shadowsocks
sudo apt-get install polipo -y
sudo mv -f polipo-config /etc/polipo/config
sudo apt-get install openssh-server gdb gdbserver -y
sudo apt-get install gcc-6 g++-6 -y
sudo apt-get install clang-4.0 clang++-4.0 -y
sudo apt-get install clang-format-4.0 -y
sudo apt-get install python python3 python-pip
sudo apt-get install vim
sudo apt-get install fish
sudo apt-get install ctags
sudo apt-get install libapache2-mod-php libapache2-mod-php7.0 php php-cgi php-common php-curl php-gd php-imagick php-intl php-mbstring php-mcrypt php-mysql php-pear php-sqlite3 php-xml php-xml-parser php-zip php7.0 php7.0-cgi php7.0-cli php7.0-common php7.0-curl php7.0-fpm php7.0-gd php7.0-intl php7.0-json php7.0-mbstring php7.0-mcrypt php7.0-mysql php7.0-opcache php7.0-readline php7.0-sqlite3 php7.0-xml php7.0-zip 
sudo apt-get install apache2 mariadb-server
#git config
git config --global http.proxy 'socks5://127.0.0.1:1080'
git config --global https.proxy 'socks5://127.0.0.1:1080'
git config --global credential.helper store
git config --global user.name hongwen000
git config --global user.email hongwen000@outlook.com




#fish and vim config
cd /tmp
git clone https://github.com/hongwen000/fish-functions.git
cd fish-functions
#set -gx https_proxy "http://127.0.0.1:1080"
#set -gx http_proxy "http://127.0.0.1:1080"
curl -L https://get.oh-my.fish | fish
mkdir -p ~/.config/fish/functions/
cp -R *.fish ~/.config/fish/functions/
cp vimrc ~/.vimrc
git clone https://github.com/VundleVim/Vundle.vim.git ~/.vim/bundle/Vundle.vim
curl -fLo ~/.vim/autoload/plug.vim --create-dirs \
    https://raw.githubusercontent.com/junegunn/vim-plug/master/plug.vim