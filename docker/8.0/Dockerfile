FROM composer:2.0.8 as composer
FROM php:8.0-fpm

RUN CPU_CORES="$(getconf _NPROCESSORS_ONLN)";
ENV MAKEFLAGS="-j${CPU_CORES}"

ADD ./extra.ini /usr/local/etc/php/conf.d/

RUN apt update -y && apt install -y \
    nano \
    wget \
    zip \
    git \
    apt-utils \
    sudo \
    libpq-dev \
    libmemcached-dev \
    libmagickwand-dev \
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
    pecl install yaml && \
    pecl install memcached && \
    pecl install xdebug

# Remove this RUN when imagick will be available via pecl
RUN cd /opt && \
    git clone https://github.com/Imagick/imagick && \
    cd imagick && \
    phpize && ./configure && \
    make && make install

RUN cd /opt && \
    curl -s https://raw.githubusercontent.com/phalcon/zephir/development/.ci/install-zephir-parser.sh | bash

RUN docker-php-ext-install zip gmp gd intl pdo_mysql pdo_pgsql && \
    docker-php-ext-enable psr redis igbinary msgpack apcu imagick yaml memcached xdebug

COPY --from=composer /usr/bin/composer /usr/local/bin/composer

CMD ["php-fpm"]
