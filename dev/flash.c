
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

#include "Zend/zend_operators.h"
#include "Zend/zend_exceptions.h"
#include "Zend/zend_interfaces.h"

#include "kernel/main.h"
#include "kernel/memory.h"

#include "kernel/fcall.h"
#include "kernel/concat.h"

/**
 * Phalcon\Flash
 *
 * Shows HTML notifications related to different circumstances. Classes can be stylized using CSS
 *
 *
 */

PHP_METHOD(Phalcon_Flash, _showMessage){

	zval *message = NULL, *classes = NULL, *css_classes = NULL, *eol = NULL, *msg = NULL;
	zval *c0 = NULL;
	zval *r0 = NULL, *r1 = NULL;
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
		PHALCON_INIT_VAR(css_classes);
		phalcon_fast_join(css_classes, c0, classes TSRMLS_CC);
	} else {
		PHALCON_CPY_WRT(css_classes, classes);
	}
	
	PHALCON_INIT_VAR(eol);
	zend_get_constant(SL("PHP_EOL"), eol TSRMLS_CC);
	if (Z_TYPE_P(message) == IS_ARRAY) { 
		if (!phalcon_valid_foreach(message TSRMLS_CC)) {
			return;
		}
		
		ah0 = Z_ARRVAL_P(message);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_3b3c_0:
			if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
				goto fee_3b3c_0;
			}
			
			PHALCON_INIT_VAR(msg);
			ZVAL_ZVAL(msg, *hd, 1, 0);
			PHALCON_INIT_VAR(r0);
			PHALCON_CONCAT_SVSVSV(r0, "<div class=\"", css_classes, "\">", msg, "</div>", eol);
			zend_print_zval(r0, 1);
			zend_hash_move_forward_ex(ah0, &hp0);
			goto fes_3b3c_0;
		fee_3b3c_0:
		if(0){}
		
	} else {
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_CONCAT_SVSVSV(r1, "<div class=\"", css_classes, "\">", message, "</div>", eol);
		zend_print_zval(r1, 1);
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Shows a HTML error message
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
		PHALCON_ALLOC_ZVAL_MM(classes);
		ZVAL_STRING(classes, "errorMessage", 1);
	}
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_SELF_PARAMS_2(r0, this_ptr, "_showmessage", message, classes);
	RETURN_CTOR(r0);
}

/**
 * Shows a HTML notice/information message
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
		PHALCON_ALLOC_ZVAL_MM(classes);
		ZVAL_STRING(classes, "noticeMessage", 1);
	}
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_SELF_PARAMS_2(r0, this_ptr, "_showmessage", message, classes);
	RETURN_CTOR(r0);
}

/**
 * Shows a HTML success message
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
		PHALCON_ALLOC_ZVAL_MM(classes);
		ZVAL_STRING(classes, "successMessage", 1);
	}
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_SELF_PARAMS_2(r0, this_ptr, "_showmessage", message, classes);
	RETURN_CTOR(r0);
}

/**
 * Shows a HTML warning message
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
		PHALCON_ALLOC_ZVAL_MM(classes);
		ZVAL_STRING(classes, "warningMessage", 1);
	}
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_SELF_PARAMS_2(r0, this_ptr, "_showmessage", message, classes);
	RETURN_CTOR(r0);
}

