FROM composer:2.0.8 as composer
FROM php:7.4-fpm

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
    pecl install imagick

RUN curl -s https://raw.githubusercontent.com/phalcon/zephir/development/.ci/install-zephir-parser.sh | bash

RUN docker-php-ext-install zip gmp gd intl pdo_mysql pdo_pgsql && \
    docker-php-ext-enable psr redis igbinary msgpack apcu imagick yaml

COPY --from=composer /usr/bin/composer /usr/local/bin/composer

CMD ["php-fpm"]
