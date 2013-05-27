
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2013 Phalcon Team (http://www.phalconphp.com)       |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file docs/LICENSE.txt.                        |
 |                                                                        |
 | If you did not receive a copy of the license and are unable to         |
 | obtain it through the world-wide-web, please send an email             |
 | to license@phalconphp.com so we can send you a copy immediately.       |
 +------------------------------------------------------------------------+
 | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
 |          Eduar Carvajal <eduar@phalconphp.com>                         |
 +------------------------------------------------------------------------+
*/

#include "php.h"
#include "php_phalcon.h"
#include "php_main.h"

/**
 * Returns if there is a global cache
 */
int phalcon_di_use_cache(TSRMLS_DC) {
	if (PHALCON_GLOBAL(di.cache_enabled)) {
		if (PHALCON_GLOBAL(di.injector) != NULL) {
			return 1;
		}
	}
	return 0;
}

int phalcon_di_get_default(zval *return_value TSRMLS_DC){
	if (PHALCON_GLOBAL(di.cache_enabled)) {
		if (PHALCON_GLOBAL(di.injector) != NULL) {
			return 1;
		}
	}
	return 0;
}

/**
 * Sets the global injector, if more than one injector is set the
 */
int phalcon_di_set_injector(zval *injector TSRMLS_DC) {
	if (PHALCON_GLOBAL(di.cache_enabled)) {
		if (PHALCON_GLOBAL(di.injector)) {

		}
	}
}

int phalcon_di_has_str(char *name, int name_length TSRMLS_DC){
	if (PHALCON_GLOBAL(di.cache_enabled)) {

	}
	return 0;
}

int phalcon_di_has(zval *service_name TSRMLS_DC){

	if (PHALCON_GLOBAL(di.cache_enabled)) {
		if (Z_TYPE_P(service_name) == IS_STRING) {
			if (!PHALCON_GLOBAL(di.shared_services_cache)) {
				return 0;
			}
		}
	}

	return 0;
}

int phalcon_di_get_shared_str(zval *return_value, char *name, int name_length, zval *arguments TSRMLS_DC){
	if (PHALCON_GLOBAL(di.cache_enabled)) {

	}
	return 0;
}

int phalcon_di_get_shared(zval *return_value, zval *name, zval *arguments TSRMLS_DC){
	if (PHALCON_GLOBAL(di.cache_enabled)) {

	}
	return 0;
}

void phalcon_di_set_shared(zval *service_name, zval *service TSRMLS_DC) {
	if (PHALCON_GLOBAL(di.cache_enabled)) {
		if (Z_TYPE_P(service_name) == IS_STRING) {
			if (!PHALCON_GLOBAL(di.shared_services_cache)) {
				ALLOC_HASHTABLE(PHALCON_GLOBAL(di.shared_services_cache));
				zend_hash_init(PHALCON_GLOBAL(di.shared_services_cache), 0, NULL, ZVAL_PTR_DTOR, 0);
			}
			Z_ADDREF_P(service);
			zend_hash_update(PHALCON_GLOBAL(di.shared_services_cache), Z_STRVAL_P(service_name), Z_STRLEN_P(service_name), service, sizeof(zval *), NULL);
		}
	}
}

void phalcon_di_reset(TSRMLS_DC) {
	if (PHALCON_GLOBAL(di.cache_enabled)) {

	}
}
