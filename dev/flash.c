
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
#include "kernel/operators.h"
#include "kernel/memory.h"

#include "zend_operators.h"
#include "zend_exceptions.h"
#include "zend_interfaces.h"

/**
 * Phalcon_Flash
 *
 * Shows HTML notifications related to different circustances. Classes can be stylized using CSS
 */

PHP_METHOD(Phalcon_Flash, _showMessage){

	zval *message = NULL, *classes = NULL, *css_classes = NULL, *msg = NULL;
	zval *c0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &message, &classes) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (Z_TYPE_P(classes) == IS_ARRAY) { 
		PHALCON_INIT_VAR(c0);
		ZVAL_STRING(c0, " ", 1);
		PHALCON_ALLOC_ZVAL_MM(r0);
		phalcon_fast_join(r0, c0, classes TSRMLS_CC);
		PHALCON_CPY_WRT(css_classes, r0);
	} else {
		PHALCON_CPY_WRT(css_classes, classes);
	}
	if (Z_TYPE_P(message) == IS_ARRAY) { 
		if (phalcon_valid_foreach(message TSRMLS_CC)) {
			ah0 = Z_ARRVAL_P(message);
			zend_hash_internal_pointer_reset_ex(ah0, &hp0);
			fes_3b3c_0:
			if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
				goto fee_3b3c_0;
			}
			PHALCON_INIT_VAR(msg);
			ZVAL_ZVAL(msg, *hd, 1, 0);
			PHALCON_INIT_VAR(r3);
			PHALCON_CONCAT_LEFT(r3, "<div class=\"", css_classes);
			PHALCON_INIT_VAR(r2);
			PHALCON_CONCAT_VBOTH(r2, r3, "\">", msg);
			PHALCON_INIT_VAR(t0);
			zend_get_constant("PHP_EOL", strlen("PHP_EOL"), t0 TSRMLS_CC);
			PHALCON_INIT_VAR(r1);
			PHALCON_CONCAT_VBOTH(r1, r2, "</div>", t0);
			zend_print_zval(r1, 0);
			zend_hash_move_forward_ex(ah0, &hp0);
			goto fes_3b3c_0;
			fee_3b3c_0:
			if(0){ };
		}
	} else {
		PHALCON_ALLOC_ZVAL_MM(r6);
		PHALCON_CONCAT_LEFT(r6, "<div class=\"", css_classes);
		PHALCON_ALLOC_ZVAL_MM(r5);
		PHALCON_CONCAT_VBOTH(r5, r6, "\">", message);
		PHALCON_ALLOC_ZVAL_MM(t1);
		zend_get_constant("PHP_EOL", strlen("PHP_EOL"), t1 TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(r4);
		PHALCON_CONCAT_VBOTH(r4, r5, "</div>", t1);
		zend_print_zval(r4, 0);
	}
	
	PHALCON_MM_RESTORE();
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

	zval *message = NULL, *classes = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &message, &classes) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!classes) {
		PHALCON_INIT_VAR(classes);
		ZVAL_STRING(classes, "errorMessage", 1);
	}
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_SELF_PARAMS_2(r0, this_ptr, "_showmessage", message, classes);
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

	zval *message = NULL, *classes = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &message, &classes) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!classes) {
		PHALCON_INIT_VAR(classes);
		ZVAL_STRING(classes, "noticeMessage", 1);
	}
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_SELF_PARAMS_2(r0, this_ptr, "_showmessage", message, classes);
	PHALCON_RETURN_DZVAL(r0);
}

/**
 * Shows a HTML success message
 *
 * 
 *
 * @param string $message
 * @param string $classes
 * @return string
 */
PHP_METHOD(Phalcon_Flash, success){

	zval *message = NULL, *classes = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &message, &classes) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!classes) {
		PHALCON_INIT_VAR(classes);
		ZVAL_STRING(classes, "successMessage", 1);
	}
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_SELF_PARAMS_2(r0, this_ptr, "_showmessage", message, classes);
	PHALCON_RETURN_DZVAL(r0);
}

/**
 * Shows a HTML warning message
 *
 * 
 * 
 *
 * @param string $message
 * @param string $classes
 * @return string
 */
PHP_METHOD(Phalcon_Flash, warning){

	zval *message = NULL, *classes = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &message, &classes) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!classes) {
		PHALCON_INIT_VAR(classes);
		ZVAL_STRING(classes, "warningMessage", 1);
	}
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_SELF_PARAMS_2(r0, this_ptr, "_showmessage", message, classes);
	PHALCON_RETURN_DZVAL(r0);
}

