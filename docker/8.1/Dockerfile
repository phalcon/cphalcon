FROM composer:latest AS composer
FROM php:8.1-fpm

COPY ./extra.ini /usr/local/etc/php/conf.d/

# User/Group globals
ENV MY_USER="phalcon" \
	MY_GROUP="phalcon" \
	MY_UID="1000" \
	MY_GID="1000" \
	PHP_VERSION="8.1" \
	LANG=en_US.UTF-8 \
    LANGUAGE=en_US.UTF-8 \
    LC_ALL=en_US.UTF-8

RUN set -eux && \
	groupadd -g ${MY_GID} -r ${MY_GROUP} && \
	useradd -u ${MY_UID} -m -s /bin/bash -g ${MY_GROUP} ${MY_USER} && \
    apt update -y && \
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
        libwebp-dev \
        libxpm-dev \
        libyaml-dev \
        libzip-dev \
        locales \
        nano \
        sudo \
        wget \
        zip && \
    rm -rf /var/lib/apt/lists/* /var/cache/apt/archives/* && \
    pecl install -o -f redis && \
    pecl install igbinary \
      msgpack \
      apcu \
      yaml \
      imagick \
      memcached \
      xdebug \
      zephir_parser && \
    sed -i -e 's/# de_DE.UTF-8 UTF-8/de_DE.UTF-8 UTF-8/' /etc/locale.gen && \
    sed -i -e 's/# el_GR.UTF-8 UTF-8/el_GR.UTF-8 UTF-8/' /etc/locale.gen && \
    sed -i -e 's/# en_US.UTF-8 UTF-8/en_US.UTF-8 UTF-8/' /etc/locale.gen && \
    sed -i -e 's/# es_ES.UTF-8 UTF-8/es_ES.UTF-8 UTF-8/' /etc/locale.gen && \
    sed -i -e 's/# ru_RU.UTF-8 UTF-8/ru_RU.UTF-8 UTF-8/' /etc/locale.gen && \
    dpkg-reconfigure --frontend=noninteractive locales && \
    update-locale LANG=en_US.UTF-8 && \
    docker-php-ext-configure gd --with-freetype  \
    --with-jpeg=/usr/include/  \
    --with-xpm \
    --with-webp \
    --enable-gd && \
    docker-php-ext-install \
        gd \
        gettext \
        gmp \
        intl \
        pdo_mysql \
        pdo_pgsql \
        zip && \
    docker-php-ext-enable \
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
COPY ./.bashrc /home/phalcon/.bashrc

CMD ["php-fpm"]
