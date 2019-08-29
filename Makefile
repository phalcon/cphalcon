######################################################
#        SYSTEM MAKE FILE                            #
######################################################
# Use this to allow quick/easy modifications and/or  #
# updates to the software. Requires make to be       #
# installed.                                         #
#                                                    #
# Note: This assumes you already have PHP setup and  #
#   properly configured in your path environment     #
######################################################
# Windows                                            #
#                                                    #
# http://gnuwin32.sourceforge.net/downlinks/make.php #
######################################################
# OS X / Linux                                       #
#                                                    #
# Likely Already Installed. Otherwise use the os's   #
# package manager (IE: apt-get, brew, macports, etc) #
######################################################

CACHE_PATH := cache
BIN_PATH := bin
NODE_MODULES := node_modules

PHP-CS-FIXER_URL := https://cs.sensiolabs.org/download/php-cs-fixer-v2.phar

COMPOSER_ACTION ?= install
COMPOSER_OPTIONS ?= $(COMPOSER_EXTRA_OPTIONS) --ignore-platform-reqs

TEST_EXTRA_OPTIONS ?= --ext DotReporter
TEST_OPTIONS ?= --fail-fast $(TEST_EXTRA_OPTIONS)
TEST_ENABLE_COVERAGE=false
TEST_COVERAGE ?=

PHP_IDE_CONFIG = PHP_IDE_CONFIG='serverName=zephir.test'

DOCKER_IMAGE ?= twistersfury/zephir:phalcon
DOCKER_EXTRA_OPTIONS ?=

DEBUG_ENABLE ?= false

ifneq ($(TEST_ENABLE_COVERAGE),false)
	TEST_COVERAGE := --coverage --coverage-html
endif

APP_DIRECTORY ?= /app
DOCKER_COMMAND ?= docker run --rm -it -v $(CURDIR):$(APP_DIRECTORY) -w $(APP_DIRECTORY) --env $(PHP_IDE_CONFIG) $(DOCKER_EXTRA_OPTIONS) $(DOCKER_IMAGE)
PHP_REMOTE_HOST := host.docker.internal

ifneq ($(DEBUG_ENABLE),false)
	PHP_ARGS ?= -d xdebug.remote_enable=1 -d xdebug.remote_autostart=1 -d xdebug.remote_host=$(PHP_REMOTE_HOST)
endif

######################################################
#                 Default Run Command                #
######################################################
.PHONY: default
default: analyse

######################################################
#               Hard File Dependencies               #
######################################################

# Primary Cache Directory
$(CACHE_PATH):
	mkdir -p $(CACHE_PATH)

# Primary Bin Directory
$(BIN_PATH):
	mkdir -p $(BIN_PATH)

# Composer Dependencies
vendor: composer.json
	make composer-install

# Binaries
vendor/codeception/codeception/codecept: | vendor

$(BIN_PATH)/.docker-login: | $(BIN_PATH)
	docker login registry.gitlab.com
	touch $@

# Docker Installation
$(BIN_PATH)/.docker: | $(BIN_PATH)
	which docker || (echo "Docker Is Not Installed" && exit 1)
	touch $(BIN_PATH)/.docker

ext/modules/phalcon.so: $(shell find ./phalcon -type f -name "*.zep")
	make build

vendor/codeception/codeception/codecept: | vendor
vendor/phalcon/zephir/zephir: | vendor

######################################################
#            Installation Dependencies               #
######################################################

.PHONY: clean composer install

install: vendor

clean: zephir-clean docker-clean
	rm -rf $(BIN_PATH)
	rm -rf $(CACHE_PATH)
	rm -rf vendor
	rm -f compile.log
	rm -f compile-errors.log

######################################################
#                  Composer Commands                 #
######################################################

.PHONY: composer composer-install composer-dump-autoload

composer-install: COMPOSER_COMMAND=install
composer-install: COMPOSER_OPTIONS=--ignore-platform-reqs
composer-install: composer

composer-dump-autoload: COMPOSER_COMMAND=dump-autoload
composer-dump-autoload: COMPOSER_OPTIONS=
composer-dump-autoload: composer

composer: DOCKER_IMAGE=composer:latest
composer: $(BIN_PATH)/.docker composer.json
	$(DOCKER_COMMAND) php $(PHP_ARGS) /usr/bin/composer $(COMPOSER_COMMAND) $(COMPOSER_OPTIONS)


######################################################
#                  Zephir Commands                   #
######################################################

.PHONY: zephir-clean clean-build build stubs compile generate

clean-build: zephir-clean build

zephir-clean: vendor/phalcon/zephir/zephir
	$(DOCKER_COMMAND) php $(PHP_ARGS) /composer/vendor/bin/zephir clean

build: vendor/phalcon/zephir/zephir
	$(DOCKER_COMMAND) php $(PHP_ARGS) /composer/vendor/bin/zephir build
	make stubs

generate: vendor/phalcon/zephir/zephir
	$(DOCKER_COMMAND) php $(PHP_ARGS) /composer/vendor/bin/zephir generate
	make stubs

compile: generate
	$(DOCKER_COMMAND) php $(PHP_ARGS) /composer/vendor/bin/zephir compile
	make stubs

stubs: vendor/phalcon/zephir/zephir
	$(DOCKER_COMMAND) php $(PHP_ARGS) /composer/vendor/bin/zephir stub

######################################################
#                  Testing Commands                  #
######################################################

.PHONY: analyse test test-unit

# Run All Testing/QA
analyse: test

# Run All Testing
test: DOCKER_EXTRA_OPTIONS=-v $$(pwd)/ext/modules/phalcon.so:/usr/local/lib/php/extensions/no-debug-non-zts-20180731/phalcon.so
test: vendor/codeception/codeception/codecept ext/modules/phalcon.so
	$(DOCKER_COMMAND) php $(PHP_ARGS) $(PHP_EXTRA_ARGS) ./vendor/codeception/codeception/codecept run $(TEST_OPTIONS) $(TEST_COVERAGE)

# Run Just The Unit Suite
test-unit: DOCKER_EXTRA_OPTIONS=-v $$(pwd)/ext/modules/phalcon.so:/usr/local/lib/php/extensions/no-debug-non-zts-20180731/phalcon.so
test-unit: vendor/codeception/codeception/codecept ext/modules/phalcon.so
	$(DOCKER_COMMAND) php $(PHP_ARGS) $(PHP_EXTRA_ARGS) ./vendor/codeception/codeception/codecept run unit $(TEST_OPTIONS) $(TEST_COVERAGE)

# Build Codecept
codecept-build: vendor/codeception/codeception/codecept
	$(DOCKER_COMMAND) php $(PHP_ARGS) $(PHP_EXTRA_ARGS) ./vendor/codeception/codeception/codecept build

