FROM composer:2.0.8 as composer
FROM php:8.0-fpm

RUN CPU_CORES="$(getconf _NPROCESSORS_ONLN)";
ENV MAKEFLAGS="-j${CPU_CORES}"

RUN apt update -y && apt install -y \
    wget \
    zip \
    git \
    apt-utils \
    sudo \
    libyaml-dev \
    libicu-dev \
    libgmp-dev \
    libpng-dev \
    libzip-dev && \
    pecl install psr && \
    pecl install -o -f redis && \
    pecl install igbinary && \
    pecl install msgpack && \
    pecl install apcu && \
    pecl install yaml

# Remove this RUN when imagick will be available via pecl
RUN apt install -y libmagickwand-dev && \
    cd /opt && \
    git clone https://github.com/Imagick/imagick && \
    cd imagick && \
    phpize && ./configure && \
    make && make install

RUN curl -s https://raw.githubusercontent.com/phalcon/zephir/development/.ci/install-zephir-parser.sh | bash

RUN docker-php-ext-install zip gmp gd intl && \
    docker-php-ext-enable psr redis igbinary msgpack apcu imagick yaml

COPY --from=composer /usr/bin/composer /usr/local/bin/composer

CMD ["php-fpm"]
