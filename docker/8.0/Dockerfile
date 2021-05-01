FROM composer:2.0.8 as composer
FROM php:8.0-fpm

RUN CPU_CORES="$(getconf _NPROCESSORS_ONLN)";
ENV MAKEFLAGS="-j${CPU_CORES}"

ADD ./extra.ini /usr/local/etc/php/conf.d/

# Update
RUN apt update -y && \
    apt install -y \
        apt-utils \
        gettext \
        git \
        libgmp-dev \
        libicu-dev \
        libmagickwand-dev \
        libmemcached-dev \
        libpng-dev \
        libpq-dev \
        libyaml-dev \
        libzip-dev \
        locales \
        nano \
        sudo \
        wget \
        zip

# PECL Packages
RUN pecl install psr && \
    pecl install -o -f redis && \
    pecl install igbinary && \
    pecl install msgpack && \
    pecl install apcu && \
    pecl install yaml && \
    pecl install memcached && \
    pecl install xdebug

# Remove this RUN when imagick will be available via pecl
RUN cd /opt && \
    git clone https://github.com/Imagick/imagick && \
    cd imagick && \
    phpize && ./configure && \
    make && make install

# Locale
RUN sed -i -e 's/# de_DE.UTF-8 UTF-8/de_DE.UTF-8 UTF-8/' /etc/locale.gen && \
    sed -i -e 's/# el_GR.UTF-8 UTF-8/el_GR.UTF-8 UTF-8/' /etc/locale.gen && \
    sed -i -e 's/# en_US.UTF-8 UTF-8/en_US.UTF-8 UTF-8/' /etc/locale.gen && \
    sed -i -e 's/# es_ES.UTF-8 UTF-8/es_ES.UTF-8 UTF-8/' /etc/locale.gen && \
    sed -i -e 's/# ru_RU.UTF-8 UTF-8/ru_RU.UTF-8 UTF-8/' /etc/locale.gen && \
    dpkg-reconfigure --frontend=noninteractive locales && \
    update-locale LANG=en_US.UTF-8

# Locale Environment
ENV LANG=en_US.UTF-8 \
    LANGUAGE=en_US.UTF-8 \
    LC_ALL=en_US.UTF-8

# Zephir Parser
RUN cd /opt && \
    curl -s https://raw.githubusercontent.com/phalcon/zephir/development/.ci/install-zephir-parser.sh | bash

# Install PHP extensions
RUN docker-php-ext-configure gd --with-freetype --with-jpeg=/usr/include/ --enable-gd

RUN docker-php-ext-install \
        gd \
        gettext \
        gmp \
        intl \
        pdo_mysql \
        pdo_pgsql \
        zip

# Install PHP extensions
RUN docker-php-ext-enable \
        psr \
        gettext \
        redis \
        igbinary \
        msgpack \
        apcu \
        imagick \
        yaml \
        memcached \
        xdebug

# Composer
COPY --from=composer /usr/bin/composer /usr/local/bin/composer

# Bash script with helper aliases
COPY ./.bashrc /root/.bashrc

CMD ["php-fpm"]
