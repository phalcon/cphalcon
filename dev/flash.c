
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
#include "kernel/memory.h"

#include "zend_operators.h"
#include "zend_exceptions.h"
#include "zend_interfaces.h"

/**
 * Phalcon_Flash
 *
 * Shows HTML notifications related to diferent circustances. Classes can be stylized using CSS
 */

PHP_METHOD(Phalcon_Flash, _showMessage){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *c0 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE) {
		RETURN_NULL();
	}

	
	if (Z_TYPE_P(v1) == IS_ARRAY) { 
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_INIT_VAR(c0);
		ZVAL_STRING(c0, " ", 1);
		PHALCON_CALL_FUNC_PARAMS_2(r0, "join", c0, v1, 0x00D);
		PHALCON_CPY_WRT(v2, r0);
	} else {
		PHALCON_CPY_WRT(v2, v1);
	}
	if (Z_TYPE_P(v0) == IS_ARRAY) { 
		if (Z_TYPE_P(v0) != IS_ARRAY) {
			php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
		} else {
			ah0 = Z_ARRVAL_P(v0);
			zend_hash_internal_pointer_reset_ex(ah0, &hp0);
			fes55:
			if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
				goto fee55;
			}
			v3 = *hd;
			Z_REFCOUNT_P(v3);
			PHALCON_INIT_VAR(r3);
			PHALCON_CONCAT_LEFT(r3, "<div class=\"", v2);
			PHALCON_INIT_VAR(r2);
			PHALCON_CONCAT_VBOTH(r2, r3, "\">", v3);
			PHALCON_INIT_VAR(t0);
			zend_get_constant("PHP_EOL", strlen("PHP_EOL"), t0 TSRMLS_CC);
			PHALCON_INIT_VAR(r1);
			PHALCON_CONCAT_VBOTH(r1, r2, "</div>", t0);
			zend_print_zval(r1, 0);
			zend_hash_move_forward_ex(ah0, &hp0);
			goto fes55;
			fee55:
			if(0){ };
		}
	} else {
		PHALCON_ALLOC_ZVAL_MM(r6);
		PHALCON_CONCAT_LEFT(r6, "<div class=\"", v2);
		PHALCON_ALLOC_ZVAL_MM(r5);
		PHALCON_CONCAT_VBOTH(r5, r6, "\">", v0);
		PHALCON_ALLOC_ZVAL_MM(t1);
		zend_get_constant("PHP_EOL", strlen("PHP_EOL"), t1 TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(r4);
		PHALCON_CONCAT_VBOTH(r4, r5, "</div>", t1);
		zend_print_zval(r4, 0);
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Shows a HTML error message
 *
 * 
 *
 * @param string $message
 * @param string $classes
 * @return string
 */
PHP_METHOD(Phalcon_Flash, error){

	zval *v0 = NULL, *v1 = NULL;
	zval *r0 = NULL;
	zval *p0[] = { NULL, NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &v0, &v1) == FAILURE) {
		RETURN_NULL();
	}

	
	if (!v1) {
		PHALCON_INIT_VAR(v1);
		ZVAL_STRING(v1, "errorMessage", 1);
	}
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	Z_ADDREF_P(v0);
	p0[0] = v0;
	Z_ADDREF_P(v1);
	p0[1] = v1;
	PHALCON_CALL_SELF_PARAMS(r0, this_ptr, "_showmessage", 2, p0);
	Z_DELREF_P(p0[0]);
	Z_DELREF_P(p0[1]);
	PHALCON_RETURN_DZVAL(r0);
}

/**
 * Shows a HTML notice/information message
 *
     * 
 *
 * @param string $message
 * @param string $classes
 * @return string
 */
PHP_METHOD(Phalcon_Flash, notice){

	zval *v0 = NULL, *v1 = NULL;
	zval *r0 = NULL;
	zval *p0[] = { NULL, NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &v0, &v1) == FAILURE) {
		RETURN_NULL();
	}

	
	if (!v1) {
		PHALCON_INIT_VAR(v1);
		ZVAL_STRING(v1, "noticeMessage", 1);
	}
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	Z_ADDREF_P(v0);
	p0[0] = v0;
	Z_ADDREF_P(v1);
	p0[1] = v1;
	PHALCON_CALL_SELF_PARAMS(r0, this_ptr, "_showmessage", 2, p0);
	Z_DELREF_P(p0[0]);
	Z_DELREF_P(p0[1]);
	PHALCON_RETURN_DZVAL(r0);
}

/**
 * Shows a HTML sucess message
 *
 * 
 *
 * @param string $message
 * @param string $classes
 * @return string
 */
PHP_METHOD(Phalcon_Flash, success){

	zval *v0 = NULL, *v1 = NULL;
	zval *r0 = NULL;
	zval *p0[] = { NULL, NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &v0, &v1) == FAILURE) {
		RETURN_NULL();
	}

	
	if (!v1) {
		PHALCON_INIT_VAR(v1);
		ZVAL_STRING(v1, "successMessage", 1);
	}
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	Z_ADDREF_P(v0);
	p0[0] = v0;
	Z_ADDREF_P(v1);
	p0[1] = v1;
	PHALCON_CALL_SELF_PARAMS(r0, this_ptr, "_showmessage", 2, p0);
	Z_DELREF_P(p0[0]);
	Z_DELREF_P(p0[1]);
	PHALCON_RETURN_DZVAL(r0);
}

/**
 * Shows a HTML warning message
 *
 * 
 *
 * @param string $message
 * @param string $classes
 * @return string
 */
PHP_METHOD(Phalcon_Flash, warning){

	zval *v0 = NULL, *v1 = NULL;
	zval *r0 = NULL;
	zval *p0[] = { NULL, NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &v0, &v1) == FAILURE) {
		RETURN_NULL();
	}

	
	if (!v1) {
		PHALCON_INIT_VAR(v1);
		ZVAL_STRING(v1, "warningMessage", 1);
	}
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	Z_ADDREF_P(v0);
	p0[0] = v0;
	Z_ADDREF_P(v1);
	p0[1] = v1;
	PHALCON_CALL_SELF_PARAMS(r0, this_ptr, "_showmessage", 2, p0);
	Z_DELREF_P(p0[0]);
	Z_DELREF_P(p0[1]);
	PHALCON_RETURN_DZVAL(r0);
}

