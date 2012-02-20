
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2012 Phalcon Team (http://www.phalconphp.com)       |
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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_phalcon.h"
#include "phalcon.h"

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/require.h"
#include "kernel/object.h"
#include "kernel/debug.h"
#include "kernel/assert.h"
#include "kernel/array.h"

#include "zend_operators.h"
#include "zend_exceptions.h"
#include "zend_interfaces.h"

/**
 * Php_Config
 *
 * Php_Config is designed to simplify the access to, and the use of, configuration data within applications.
 * It provides a nested object property based user interface for accessing this configuration data within
 * application code.
 *
 * 
 *
 */

/**
 * Php_Config constructor
 *
 * @paramarray $arrayConfig
 * @returnPhp_Config
 */
PHP_METHOD(Phalcon_Config, __construct){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *ac0 = NULL;
	zval *i0 = NULL;
	zval *p0[] = { NULL };
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *index;
	uint index_len;
	ulong num;
	int htype;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	FOREACH_KV(v0, ac0, fes51, fee51, ah0, hp0, v2, v1)
		if (Z_TYPE_P(v1) == IS_ARRAY) { 
			if (!i0) {
				PHALCON_ALLOC_ZVAL(i0);
			} else {
				if (Z_REFCOUNT_P(i0) > 1) {
					{
						zval *orig_ptr = i0;
						if (Z_REFCOUNT_P(orig_ptr) > 1) {
							Z_DELREF_P(orig_ptr);
							ALLOC_ZVAL(i0);
							*i0 = *orig_ptr;
							zval_copy_ctor(i0);
							Z_SET_REFCOUNT_P(i0, 1);
							Z_UNSET_ISREF_P(i0);
						}
					}
				} else {
					FREE_ZVAL(i0);
					PHALCON_ALLOC_ZVAL(i0);
				}
			}
			object_init_ex(i0, phalcon_config_class_entry);
			Z_ADDREF_P(v1);
			p0[0] = v1;
			PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p0, PHALCON_CALL_CHECK);
			{
				zval *copy;
				ALLOC_ZVAL(copy);
				ZVAL_ZVAL(copy, i0, 1, 0);
				Z_SET_REFCOUNT_P(copy, 0);
				phalcon_update_property_zval(this_ptr, Z_STRVAL_P(v2), Z_STRLEN_P(v2), copy TSRMLS_CC);
			}
		} else {
			{
				zval *copy;
				ALLOC_ZVAL(copy);
				ZVAL_ZVAL(copy, v1, 1, 0);
				Z_SET_REFCOUNT_P(copy, 0);
				phalcon_update_property_zval(this_ptr, Z_STRVAL_P(v2), Z_STRLEN_P(v2), copy TSRMLS_CC);
			}
		}
	END_FOREACH(ac0, fes51, fee51, ah0, hp0);
	RETURN_NULL();
}

