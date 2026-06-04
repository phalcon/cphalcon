# syntax=docker/dockerfile:1
ARG PHP_VERSION=8.4

############################################################
# base — runtime image: PHP-FPM + Phalcon runtime extensions
############################################################
FROM php:${PHP_VERSION}-fpm AS base

ARG UID=1000
ARG GID=1000
ARG USER=phalcon
ARG GROUP=phalcon

# hadolint ignore=DL3022
COPY --from=ghcr.io/mlocati/php-extension-installer /usr/bin/install-php-extensions /usr/local/bin/

SHELL [ "/bin/bash", "-o", "pipefail", "-c" ]

RUN --mount=type=cache,target=/var/cache/apt,sharing=locked \
    --mount=type=cache,target=/var/lib/apt/lists,sharing=locked \
    set -eux \
# Add user and group \
    && groupadd -g "${GID}" "${GROUP}" \
    && useradd -l -u "${UID}" -g "${GID}" -d /app "${USER}" \
    && usermod -s /bin/bash "${USER}" \
    && mkdir -p /app \
    && chown "${USER}:${GROUP}" /app \
    && chmod 0770 /app \
    && apt-get update \
    && apt-get install -yq --no-install-recommends libfcgi-bin=2.* \
# Install runtime extensions \
    && install-php-extensions \
        apcu \
        gettext \
        gd \
        igbinary \
        imagick \
        intl \
        mysqli \
        opcache \
        pdo_mysql \
        pdo_pgsql \
        pgsql \
        redis \
        xsl \
        yaml \
        zip \
# Production php.ini \
    && mv /usr/local/etc/php/php.ini-production /usr/local/etc/php/php.ini \
    && sed -i -e "s/;error_log = syslog/error_log = \/proc\/self\/fd\/2/" /usr/local/etc/php/php.ini \
# FPM logging + pid \
    && sed -i -e "/error_log = .*/c\error_log = \/proc\/self\/fd\/2" /usr/local/etc/php-fpm.conf \
    && sed -i -e "/;pid = .*/c\pid = /run/php/php-fpm.pid" /usr/local/etc/php-fpm.conf \
# FPM pool \
    && sed -i -e "s/^;clear_env = no$/clear_env = no/" /usr/local/etc/php-fpm.d/www.conf \
    && sed -i -e "s/;owner = www-data/owner = ${USER}/g" /usr/local/etc/php-fpm.d/www.conf \
    && sed -i -e "s/;user = www-data/user = ${USER}/g" /usr/local/etc/php-fpm.d/www.conf \
    && sed -i -e "s/;group = www-data/group = ${GROUP}/g" /usr/local/etc/php-fpm.d/www.conf \
# Healthcheck script \
    && curl -fsSL -o /usr/local/bin/php-fpm-healthcheck \
        https://raw.githubusercontent.com/renatomefi/php-fpm-healthcheck/master/php-fpm-healthcheck \
    && chown "${USER}:${GROUP}" /usr/local/bin/php-fpm-healthcheck \
    && chmod 0770 /usr/local/bin/php-fpm-healthcheck \
    && echo "pm.status_path = /status" >> /usr/local/etc/php-fpm.d/zz-docker.conf \
# Pid dir \
    && mkdir -p /run/php \
    && chown "${USER}:${GROUP}" /run/php \
    && chmod 0770 /run/php \
# Cleanup \
    && rm -rf /tmp/* /var/tmp/*

HEALTHCHECK --interval=5s --timeout=1s \
    CMD php-fpm-healthcheck || exit 1

############################################################
# dev — compile + local development environment (non-root)
############################################################
FROM base AS dev

ARG USER=phalcon
ARG GROUP=phalcon

ENV LANG=en_US.UTF-8 \
    LANGUAGE=en_US.UTF-8 \
    LC_ALL=en_US.UTF-8 \
    COMPOSER_HOME=/app/.composer \
    COMPOSER_ALLOW_SUPERUSER=1

# hadolint ignore=DL3022
COPY --from=composer/composer:2 --chmod=0755 /usr/bin/composer /usr/bin/composer
COPY --chown=${USER}:${GROUP} resources/docker/develop/.bashrc /app/.bashrc
COPY resources/docker/develop/extra.ini /usr/local/etc/php/conf.d/extra.ini

SHELL [ "/bin/bash", "-o", "pipefail", "-c" ]

# hadolint ignore=DL3008
RUN --mount=type=cache,target=/var/cache/apt,sharing=locked \
    --mount=type=cache,target=/var/lib/apt/lists,sharing=locked \
    set -eux \
# Toolchain (zephir build) + dev utilities \
    && apt-get update \
    && apt-get install -yq --no-install-recommends \
        autoconf \
        dpkg-dev \
        file \
        g++ \
        gcc \
        git \
        libc-dev \
        locales \
        make \
        nano \
        pkg-config \
        re2c \
        sudo \
        unzip \
        wget \
        zip \
# Dev/test extensions \
    && install-php-extensions \
        gmp \
        memcached \
        msgpack \
        xdebug \
        zephir_parser \
# Locales for gettext/Translate tests \
    && sed -i -e 's/# de_DE.UTF-8 UTF-8/de_DE.UTF-8 UTF-8/' /etc/locale.gen \
    && sed -i -e 's/# el_GR.UTF-8 UTF-8/el_GR.UTF-8 UTF-8/' /etc/locale.gen \
    && sed -i -e 's/# en_US.UTF-8 UTF-8/en_US.UTF-8 UTF-8/' /etc/locale.gen \
    && sed -i -e 's/# es_ES.UTF-8 UTF-8/es_ES.UTF-8 UTF-8/' /etc/locale.gen \
    && sed -i -e 's/# ru_RU.UTF-8 UTF-8/ru_RU.UTF-8 UTF-8/' /etc/locale.gen \
    && dpkg-reconfigure --frontend=noninteractive locales \
    && update-locale LANG=en_US.UTF-8 \
# Unlimited memory for builds/tests \
    && echo 'memory_limit = -1' > /usr/local/etc/php/conf.d/zz-memory.ini \
# Passwordless sudo for the phalcon group \
    && echo "%${GROUP} ALL=(ALL) NOPASSWD:ALL" > /etc/sudoers.d/phalcon \
    && chmod 0440 /etc/sudoers.d/phalcon \
# Composer home owned by the user \
    && mkdir -p "${COMPOSER_HOME}" \
    && chown -R "${USER}:${GROUP}" "${COMPOSER_HOME}" \
# Make the dirs `make install` writes to (extension dir + headers) writable so `cpl` installs as the user \
    && chown -R "${USER}:${GROUP}" "$(php-config --extension-dir)" "$(php-config --include-dir)" /usr/local/etc/php/conf.d \
# Cleanup \
    && rm -rf /tmp/* /var/tmp/*

WORKDIR /srv
USER ${USER}

############################################################
# phalcon — compile the extension (.so) for the prod image
############################################################
FROM dev AS phalcon

ARG USER=phalcon
ARG GROUP=phalcon

COPY --chown=${USER}:${GROUP} ./ /srv

RUN --mount=type=cache,target=/app/.composer/cache,uid=1000,gid=1000 \
    set -eux \
    && rm -rf /srv/vendor \
# Cleanup from any previous (host) build \
    && find /srv -type f -iname '*.dep' -exec rm -f {} \; \
    && composer global require phalcon/zephir:dev-development \
    && "${COMPOSER_HOME}/vendor/bin/zephir" fullclean \
    && "${COMPOSER_HOME}/vendor/bin/zephir" build \
    && cat compile-errors.log

############################################################
# prod — minimal runtime image shipping the compiled .so
############################################################
FROM base AS prod

ARG PHP_VERSION=8.4
ARG PHALCON_VERSION="v5.14.0"
ARG USER=phalcon

ENV PATH=/app/bin:/app:${PATH} \
    PHP_VERSION=${PHP_VERSION} \
    PHALCON_VERSION=${PHALCON_VERSION}

LABEL org.opencontainers.image.title="Phalcon ${PHALCON_VERSION} with php ${PHP_VERSION}"
LABEL org.opencontainers.image.description="Docker image including Phalcon and PHP on Debian Bookworm"
LABEL org.opencontainers.image.authors="Phalcon Team <team@phalcon.io>"
LABEL org.opencontainers.image.vendor="Phalcon PHP Framework"
LABEL org.opencontainers.image.licenses="BSD-3-Clause"
LABEL org.opencontainers.image.version="${PHALCON_VERSION}-php${PHP_VERSION}"
LABEL org.opencontainers.image.url="https://github.com/phalcon/cphalcon/tree/${PHALCON_VERSION}/resources/docker/develop/Dockerfile"
LABEL org.opencontainers.image.source="https://github.com/phalcon/cphalcon/"

COPY --from=phalcon /srv/ext/modules/phalcon.so /tmp/phalcon.so

SHELL [ "/bin/bash", "-o", "pipefail", "-c" ]

RUN --mount=type=cache,target=/var/cache/apt,sharing=locked \
    --mount=type=cache,target=/var/lib/apt/lists,sharing=locked \
    set -eux \
# Install the extension \
    && mv /tmp/phalcon.so "$(php-config --extension-dir)/phalcon.so" \
    && echo "extension=phalcon.so" > /usr/local/etc/php/conf.d/70-phalcon.ini \
# Cleanup \
    && apt-get autoremove --purge -y curl \
    && rm -rf /tmp/* /var/tmp/* /srv

WORKDIR /app
USER ${USER}
