ARG PHP_VERSION=8.4

FROM php:${PHP_VERSION}-fpm AS base

# This part installs the required php extensions to compile phalcon.
# Additional extensions that are mostly used are installed here too.

ARG PHP_VERSION=8.4
ARG UID=1000
ARG GID=1000
ARG USER=phalcon
ARG GROUP=phalcon

# hadolint ignore=DL3022
COPY --from=ghcr.io/mlocati/php-extension-installer /usr/bin/install-php-extensions /usr/local/bin/

SHELL [ "/bin/bash", "-o", "pipefail", "-c" ]

RUN set -eux \
# Add user and group
    && groupadd -g "${GID}" "${GROUP}" \
    && useradd -l -u "${UID}" -g "${GID}" -d /app "${USER}" \
    && usermod -s /bin/bash "${USER}" \
    && mkdir /app \
    && chown "${USER}":"${GROUP}" /app \
    && chmod 0770 /app \
    && apt-get update \
    && apt-get install -yq --no-install-recommends libfcgi-bin=2.* \
# Install base extensions
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
# Copy ini file \
    && mv /usr/local/etc/php/php.ini-production /usr/local/etc/php/php.ini \
# Write ini files
    && sed -i -e "s/;error_log = syslog/error_log = \/proc\/self\/fd\/2/" /usr/local/etc/php/php.ini \
# Write fpm file
    && sed -i -e "/error_log = .*/c\error_log = \/proc\/self\/fd\/2" /usr/local/etc/php-fpm.conf \
    && sed -i -e "/;pid = .*/c\pid = /run/php/php-fpm.pid" /usr/local/etc/php-fpm.conf \
# Write fpm pool
    && sed -i -e "s/^;clear_env = no$/clear_env = no/" /usr/local/etc/php-fpm.d/www.conf \
    && sed -i -e "s/;owner = www-data/owner = ${USER}/g" /usr/local/etc/php-fpm.d/www.conf \
    && sed -i -e "s/;user = www-data/user = ${USER}/g" /usr/local/etc/php-fpm.d/www.conf \
    && sed -i -e "s/;group = www-data/group = ${GROUP}/g" /usr/local/etc/php-fpm.d/www.conf \
# Load healthcheck script \
    && curl -o /usr/local/bin/php-fpm-healthcheck \
      https://raw.githubusercontent.com/renatomefi/php-fpm-healthcheck/master/php-fpm-healthcheck \
    && chown "${USER}":"${GROUP}" /usr/local/bin/php-fpm-healthcheck \
    && chmod 0770 /usr/local/bin/php-fpm-healthcheck \
    && echo "pm.status_path = /status" >> /usr/local/etc/php-fpm.d/zz-docker.conf \
# Set correct pid file location and permissions \
    && mkdir -p /run/php \
    && chown "${USER}":"${GROUP}" /run/php \
    && chmod 0770 /run/php \
# Cleanup
   && apt-get autoremove --purge -y \
   && apt-get autoclean -y \
   && apt-get clean -y \
   && rm -rf /tmp/* /var/tmp/* \
   && find /var/cache/apt/archives /var/lib/apt/lists -not -name lock -type f -delete \
   && find /var/cache -type f -delete \
   && find /var/log -type f -delete

HEALTHCHECK --interval=5s --timeout=1s \
    CMD php-fpm-healthcheck || exit 1

FROM base AS dev

# This part prepares a dev environment to compile phalcon from zephir

# hadolint ignore=DL3022
COPY --from=composer/composer:2 --chown=${USER}:${GROUP} --chmod=0775 /usr/bin/composer /usr/bin/composer

WORKDIR /srv

SHELL [ "/bin/bash", "-o", "pipefail", "-c" ]

RUN set -eux \
    && apt-get update \
    && apt-get install -yq --no-install-recommends zip=3.* unzip=6.* \
    && echo 'memory_limit = -1' > "$(php-config --ini-dir)/90-memory.ini" \
    && install-php-extensions zephir_parser \
# Cleanup
   && apt-get autoclean -y \
   && apt-get clean -y \
   && rm -rf /tmp/* /var/tmp/*

FROM dev AS phalcon

# This part compiles phalcon from zephir code. It should not be used for anything else.
# It should also not be used as base for anything else.

COPY ./ /srv

RUN set -eux \
    && rm -rf /srv/vendor \
# This is a cleanup for local tests and if a previous build has failed.
    && find /srv -type f -iname '*.dep' -exec rm {} \;\
    && composer global require phalcon/zephir:dev-development \
    && /root/.composer/vendor/bin/zephir fullclean \
    && /root/.composer/vendor/bin/zephir build \
    && cat compile-errors.log

FROM base AS prod

# This part builds the last step required for production image.

ARG PHALCON_VERSION="v5.10.0"

ENV PATH=/app/bin:/app:${PATH} \
    PHP_VERSION=${PHP_VERSION} \
    PHALCON_VERSION=${PHALCON_VERSION}

LABEL org.opencontainers.image.title="Phalcon ${PHALCON_VERSION} with php ${PHP_VERSION}"
LABEL org.opencontainers.image.description="Docker image including Phalcon and PHP on Debian Bookworm"
LABEL org.opencontainers.image.authors="Phalcon Team <team@phalcon.io>"
LABEL org.opencontainers.image.vendor="Phalcon PHP Framework"
LABEL org.opencontainers.image.licenses="BSD-3-Clause"
LABEL org.opencontainers.image.version="${PHALCON_VERSION}-php${PHP_VERSION}"
LABEL org.opencontainers.image.url="https://github.com/phalcon/cphalcon/tree/${PHALCON_VERSION}/docker/Dockerfile"
LABEL org.opencontainers.image.source="https://github.com/phalcon/cphalcon/"

COPY --from=phalcon /srv/ext/modules/phalcon.so /tmp/phalcon.so

SHELL [ "/bin/bash", "-o", "pipefail", "-c" ]

RUN set -eux \
# Install phalcon \
    && mv /tmp/phalcon.so "$(php-config --extension-dir)/phalcon.so" \
    && echo "extension=phalcon.so" > /usr/local/etc/php/conf.d/70-phalcon.ini \
# Cleanup
   && rm -rf /tmp/* /var/tmp/* /srv /root/.composer /usr/bin/composer \
   && apt-get autoremove --purge -y curl \
   && apt-get autoclean -y \
   && apt-get clean -y \
   && rm -rf /tmp/* /var/tmp/* \
   && find /var/cache/apt/archives /var/lib/apt/lists -not -name lock -type f -delete \
   && find /var/cache -type f -delete \
   && find /var/log -type f -delete

WORKDIR /app

USER ${USER}
