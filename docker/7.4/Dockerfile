FROM composer:latest as composer
FROM php:7.4-fpm

# Compilation parameters
RUN CPU_CORES="$(getconf _NPROCESSORS_ONLN)";
ENV MAKEFLAGS="-j${CPU_CORES}"

ADD ./extra.ini /usr/local/etc/php/conf.d/

# User/Group globals
ENV MY_USER="phalcon" \
	MY_GROUP="phalcon" \
	MY_UID="1000" \
	MY_GID="1000" \
	PHP_VERSION="7.4" \
	LANG=en_US.UTF-8 \
    LANGUAGE=en_US.UTF-8 \
    LC_ALL=en_US.UTF-8

# User and Group
RUN set -eux && \
	groupadd -g ${MY_GID} -r ${MY_GROUP} && \
	useradd -u ${MY_UID} -m -s /bin/bash -g ${MY_GROUP} ${MY_USER}

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
RUN pecl install -o -f redis && \
    pecl install psr \
      igbinary \
      msgpack \
      apcu \
      yaml \
      imagick \
      memcached \
      xdebug \
      zephir_parser

# Locale
RUN sed -i -e 's/# de_DE.UTF-8 UTF-8/de_DE.UTF-8 UTF-8/' /etc/locale.gen && \
    sed -i -e 's/# el_GR.UTF-8 UTF-8/el_GR.UTF-8 UTF-8/' /etc/locale.gen && \
    sed -i -e 's/# en_US.UTF-8 UTF-8/en_US.UTF-8 UTF-8/' /etc/locale.gen && \
    sed -i -e 's/# es_ES.UTF-8 UTF-8/es_ES.UTF-8 UTF-8/' /etc/locale.gen && \
    sed -i -e 's/# ru_RU.UTF-8 UTF-8/ru_RU.UTF-8 UTF-8/' /etc/locale.gen && \
    dpkg-reconfigure --frontend=noninteractive locales && \
    update-locale LANG=en_US.UTF-8

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
        xdebug \
        zephir_parser

# Composer
COPY --from=composer /usr/bin/composer /usr/local/bin/composer
# Bash script with helper aliases
COPY ./.bashrc /root/.bashrc

CMD ["php-fpm"]
