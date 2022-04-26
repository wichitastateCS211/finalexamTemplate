# This container is built on top of the Linux distribution Fedora. Fedora was
# chosen for having the required minimum versions or better of the software
# we'll be using. It's also more stable than Arch, no matter what people on
# Reddit say.
FROM fedora:35
LABEL Name=llvm+neovim Version=0.2
WORKDIR /root

# The sed command allows us to view the documentation (man pages) of the tools
# we'll be using. They're disabled by default because the genearl idea of a
# container is to package one app and the required environment **only**. Our
# environment happens to benefit from having the documentation available.
SHELL ["/bin/bash", "-o", "pipefail", "-l", "-c"]
RUN sed -i '/^tsflag*/d' /etc/dnf/dnf.conf

# These commands update the image and install the tools we'll need. Some quick
# highligts:
#   clang + llvm: These packages give us the compiler, supporting libraries, and
#                 tools needed to compile and run the code we'll be writing.
#   neovim: This is the Command Line Interface (CLI) text editor. You'll be able
#           to attach containers to VS Code, but you can also launch the
#           container and just write code in neovim if you want. I encourage
#           practicing with the CLI.
#   tmux: Another great CLI tool that, once learned, makes the CLI a very
#         productive environment.
#   git: Used to get and submit homework assignments. Also a valuable tool used
#        used widely in industry.
#   starship: Changes the appearance of the prompt.
RUN dnf -y upgrade && \
    dnf group install -y "C Development Tools and Libraries" && \
    dnf install -y \
        clang \
        clang-devel \
        clang-tools-extra \
        cmake \
        fd-find \
        git \
        libcxx \
        libcxx-devel \
        libcxxabi \
        libcxxabi-devel \
        lld \
        lld-devel \
        lldb \
        lldb-devel \
        llvm \
        llvm-devel \
        man-pages \
        man-db \
        man \
        neovim \
        ninja-build \
        nodejs \
        python3-pip \
        ripgrep \
        starship \
        tmux \
        which

RUN git clone https://gitlab.com/sweenish/dotfiles.git /root/.dotfiles
WORKDIR /root/.dotfiles
RUN git submodule init && \
    git submodule update

# TODO handle missing files properly
# Plug in config files
WORKDIR /root
RUN mv .bash_profile .bash_profile.BAK && \
    mv .bashrc .bashrc.BAK && \
    ln -s .dotfiles/.bash_profile .bash_profile && \
    ln -s .dotfiles/.bashrc .bashrc && \
    ln -s .dotfiles/.bashrc.d .bashrc.d && \
    ln -s .dotfiles/.config .config && \
    ln -s .dotfiles/.tmux.conf .tmux.conf && \
    ln -s .dotfiles/.tmux .tmux

# Download and install plugin manager I'm using with neovim
RUN git clone --depth 1 https://github.com/wbthomason/packer.nvim \
 /root/.local/share/nvim/site/pack/packer/start/packer.nvim

# Install the plugins to neovim
WORKDIR /root/.config/nvim
RUN mv init.vim backup.init && \
    echo "lua require('plugins')" > init.vim && \
    nvim --headless -c 'autocmd User PackerComplete quitall' -c 'PackerSync'  && \
    rm init.vim && \
    mv backup.init init.vim && \
    nvim +"TSInstall cpp" +"TSInstall python" +qall

# Install plugins for tmux
WORKDIR /root
RUN .tmux/plugins/tpm/bin/install_plugins

# Set up a few python things
RUN python3 -m pip install -U pip && \
    python3 -m pip install pyright && \
    python3 -m pip install pipx --force && \
    python3 -m pipx ensurepath && \
    pipx install black && \
    pipx install poetry && \
    pipx install tmuxp

CMD ["/bin/bash"]
