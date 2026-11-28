# syntax=docker/dockerfile:1
#
# PHP debug image (PHP 8.6 by default). For local debugging only.
#
# This image compiles PHP again from the source of the official image, NTS,
# with debug information. It has pcov, gdb and valgrind. Xdebug is optional
# (XDEBUG_REF). The extensions are the same as in the CI unit jobs.
#
# Instructions: resources/docker/debug/README.md
#
ARG PHP_VERSION=8.6
# Optional base image digest (sha256:...). If empty, the tag is used.
ARG PHP_DIGEST=

FROM php:${PHP_VERSION}-cli${PHP_DIGEST:+@${PHP_DIGEST}}

ARG UID=1000
ARG GID=1000
ARG USER=phalcon
ARG GROUP=phalcon
# 1: --enable-debug (-O0, assertions, memory checks). 0: release flags with -g.
ARG PHP_DEBUG=1
# 1: --enable-address-sanitizer. Do not use this build with valgrind.
ARG PHP_ASAN=0
# Xdebug git branch, tag or commit to install (for example master or 3.5.0).
# Empty: no Xdebug.
ARG XDEBUG_REF=

ENV LANG=en_US.UTF-8 \
    LANGUAGE=en_US.UTF-8 \
    LC_ALL=en_US.UTF-8 \
    COMPOSER_HOME=/app/.composer \
    COMPOSER_ALLOW_SUPERUSER=1

# PHP does not free all memory at exit. With PHP_ASAN=1, the leak check stops
# each php command with an error. The other ASan checks stay on.
ENV ASAN_OPTIONS=detect_leaks=0

# hadolint ignore=DL3022
COPY --from=composer/composer:2 --chmod=0755 /usr/bin/composer /usr/bin/composer

SHELL [ "/bin/bash", "-o", "pipefail", "-c" ]

# PIE installs the PECL extensions. It is only available during this step.
# hadolint ignore=DL3003,DL3008
RUN --mount=type=bind,from=ghcr.io/php/pie:1-bin,source=/pie,target=/usr/local/bin/pie \
    --mount=type=cache,target=/var/cache/apt,sharing=locked \
    --mount=type=cache,target=/var/lib/apt/lists,sharing=locked <<EOT
set -eux
# Add user and group
groupadd -g "${GID}" "${GROUP}"
useradd -l -u "${UID}" -g "${GID}" -d /app "${USER}"
usermod -s /bin/bash "${USER}"
install -d -m 0770 -o "${USER}" -g "${GROUP}" /app
# Toolchain, debug tools and the libraries for PHP and the extensions
apt-get update
apt-get install -yq --no-install-recommends \
    ${PHPIZE_DEPS} \
    gdb \
    git \
    libargon2-dev \
    libcurl4-openssl-dev \
    libfreetype-dev \
    libgmp-dev \
    libicu-dev \
    libjpeg-dev \
    libmagickwand-dev \
    libmemcached-dev \
    libonig-dev \
    libpng-dev \
    libpq-dev \
    libreadline-dev \
    libsodium-dev \
    libsqlite3-dev \
    libssl-dev \
    libtool \
    libwebp-dev \
    libxml2-dev \
    libxpm-dev \
    libxslt1-dev \
    libyaml-dev \
    libzip-dev \
    locales \
    nano \
    sudo \
    unzip \
    valgrind \
    wget \
    zip \
    zlib1g-dev
# Compile PHP again. The configure options are the options of the
# official image, without ZTS and without FPM.
php_cflags="${PHP_CFLAGS} -g"
php_options=()
if [ "${PHP_DEBUG}" = "1" ]; then
    php_cflags="-fstack-protector-strong -fpic -fpie -O0 -g -D_LARGEFILE_SOURCE -D_FILE_OFFSET_BITS=64"
    php_options+=(--enable-debug)
fi
if [ "${PHP_ASAN}" = "1" ]; then
    php_options+=(--enable-address-sanitizer)
fi
# The extensions of the original build do not load in the new build
rm -rf "$(php-config --extension-dir)"
docker-php-source extract
cd /usr/src/php
CFLAGS="${php_cflags}" CPPFLAGS="${php_cflags}" LDFLAGS="${PHP_LDFLAGS}" ./configure \
    --build="$(dpkg-architecture --query DEB_BUILD_GNU_TYPE)" \
    --sysconfdir=/usr/local/etc \
    --with-config-file-path="${PHP_INI_DIR}" \
    --with-config-file-scan-dir="${PHP_INI_DIR}/conf.d" \
    --enable-option-checking=fatal \
    --with-mhash \
    --enable-mysqlnd \
    --with-password-argon2 \
    --with-sodium=shared \
    --with-pdo-sqlite=/usr \
    --with-sqlite3=/usr \
    --with-curl \
    --with-iconv \
    --with-openssl \
    --with-readline \
    --with-zlib \
    --disable-phpdbg \
    --with-libdir="lib/$(dpkg-architecture --query DEB_BUILD_MULTIARCH)" \
    --disable-cgi \
    --disable-zend-signals \
    "${php_options[@]}"
make -j"$(nproc)"
make install
# Keep a clean source tree at the build path, for gdb and for the extensions
cd /
docker-php-source delete
docker-php-source extract
cp -p "${PHP_INI_DIR}/php.ini-production" "${PHP_INI_DIR}/php.ini"
# Extensions. The CI unit jobs use the same extensions.
docker-php-ext-configure gd --with-freetype \
    --with-jpeg=/usr/include/ \
    --with-xpm \
    --with-webp \
    --enable-gd
docker-php-ext-install \
    gd \
    gettext \
    gmp \
    intl \
    mbstring \
    mysqli \
    pcntl \
    pdo_mysql \
    pdo_pgsql \
    pgsql \
    xsl \
    zip
# PHP versions that are not released yet (PHP 8.6 when this was written): the
# extension releases do not compile, so the development branches are used. For
# a released PHP version, use the releases, for example
# "pie install igbinary/igbinary" and "pie install pecl/yaml".
pie install --no-cache igbinary/igbinary:dev-master
pie install --no-cache apcu/apcu:dev-master
pie install --no-cache imagick/imagick:dev-master
pie install --no-cache phpredis/phpredis:dev-develop --enable-redis-igbinary
pie install --no-cache pecl/yaml:dev-php7
pie install --no-cache msgpack/msgpack-php:dev-master
pie install --no-cache php-memcached/php-memcached:dev-master
# pcov: the PECL release with the PHP 8.6 patch of the CI builds
# (shivammathur/php-builder, scripts/patch-extensions.sh). PHP 8.6 removed the
# INI_BOOL, INI_INT and INI_STR macros. For an older PHP version, or a pcov
# release that has the fix, remove the sed commands. The source stays for gdb.
mkdir -p /usr/src/pcov
curl -fsSL https://pecl.php.net/get/pcov-1.0.12.tgz | tar -xz --strip-components=1 -C /usr/src/pcov
cd /usr/src/pcov
sed -i 's/INI_BOOL(/zend_ini_bool_literal(/g' pcov.c
sed -i 's/INI_INT(/zend_ini_long_literal(/g' pcov.c
sed -i 's/INI_STR(/zend_ini_string_literal(/g' pcov.c
phpize
./configure --enable-pcov
make -j"$(nproc)"
make install
docker-php-ext-enable pcov
cd /
# Xdebug from git (optional). The source stays for gdb.
if [ -n "${XDEBUG_REF}" ]; then
    git clone https://github.com/xdebug/xdebug.git /usr/src/xdebug
    cd /usr/src/xdebug
    git checkout "${XDEBUG_REF}"
    phpize
    ./configure --enable-xdebug
    make -j"$(nproc)"
    make install
    docker-php-ext-enable xdebug
    git config --system --add safe.directory /usr/src/xdebug
    cd /
fi
# gdb: load the PHP macros (zbacktrace, printzv) and the PHP scripts
printf 'set auto-load safe-path /\nsource /usr/src/php/.gdbinit\n' > /app/.gdbinit
chown "${USER}:${GROUP}" /app/.gdbinit
# Locales for gettext/Translate tests
sed -i -e 's/# de_DE.UTF-8 UTF-8/de_DE.UTF-8 UTF-8/' /etc/locale.gen
sed -i -e 's/# el_GR.UTF-8 UTF-8/el_GR.UTF-8 UTF-8/' /etc/locale.gen
sed -i -e 's/# en_US.UTF-8 UTF-8/en_US.UTF-8 UTF-8/' /etc/locale.gen
sed -i -e 's/# es_ES.UTF-8 UTF-8/es_ES.UTF-8 UTF-8/' /etc/locale.gen
sed -i -e 's/# ru_RU.UTF-8 UTF-8/ru_RU.UTF-8 UTF-8/' /etc/locale.gen
dpkg-reconfigure --frontend=noninteractive locales
update-locale LANG=en_US.UTF-8
# Unlimited memory for builds/tests
echo 'memory_limit = -1' > /usr/local/etc/php/conf.d/zz-memory.ini
# Passwordless sudo for the phalcon group
echo "%${GROUP} ALL=(ALL) NOPASSWD:ALL" > /etc/sudoers.d/phalcon
chmod 0440 /etc/sudoers.d/phalcon
# Composer home owned by the user
mkdir -p "${COMPOSER_HOME}"
chown -R "${USER}:${GROUP}" "${COMPOSER_HOME}"
# Make the dirs `make install` writes to (extension dir + headers) writable so the user can install
chown -R "${USER}:${GROUP}" "$(php-config --extension-dir)" "$(php-config --include-dir)" /usr/local/etc/php/conf.d
# Own the WORKDIR so the user can create `.zephir`/`ext` dirs during `zephir build`
mkdir -p /srv
chown "${USER}:${GROUP}" /srv
EOT

COPY --chown=${USER}:${GROUP} resources/docker/develop/.bashrc /app/.bashrc
COPY resources/docker/develop/extra.ini /usr/local/etc/php/conf.d/extra.ini

WORKDIR /srv
USER ${USER}

# The image has no server. Keep the container running for `docker exec`.
CMD [ "sleep", "infinity" ]
