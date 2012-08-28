
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

#include "kernel/object.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/operators.h"

/**
 * Phalcon\Flash
 *
 * Shows HTML notifications related to different circumstances. Classes can be stylized using CSS
 *
 *
 */

PHP_METHOD(Phalcon_Flash, __construct){

	zval *css_classes = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &css_classes) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!css_classes) {
		PHALCON_ALLOC_ZVAL_MM(css_classes);
		ZVAL_NULL(css_classes);
	} else {
		PHALCON_SEPARATE_PARAM(css_classes);
	}
	
	if (Z_TYPE_P(css_classes) != IS_ARRAY) { 
		PHALCON_INIT_VAR(css_classes);
		array_init(css_classes);
		add_assoc_stringl_ex(css_classes, SL("error")+1, SL("errorMessage"), 1);
		add_assoc_stringl_ex(css_classes, SL("notice")+1, SL("noticeMessage"), 1);
		add_assoc_stringl_ex(css_classes, SL("success")+1, SL("successMessage"), 1);
		add_assoc_stringl_ex(css_classes, SL("warning")+1, SL("warningMessage"), 1);
	}
	phalcon_update_property_zval(this_ptr, SL("_cssClasses"), css_classes TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

PHP_METHOD(Phalcon_Flash, setImplicitFlush){

	zval *implicit_flush = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &implicit_flush) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_implicitFlush"), implicit_flush TSRMLS_CC);
	
	RETURN_CCTOR(this_ptr);
}

PHP_METHOD(Phalcon_Flash, setAutomaticHtml){

	zval *automatic_html = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &automatic_html) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_automaticHtml"), automatic_html TSRMLS_CC);
	
	RETURN_CCTOR(this_ptr);
}

PHP_METHOD(Phalcon_Flash, setCssClasses){

	zval *css_classes = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &css_classes) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (Z_TYPE_P(css_classes) == IS_ARRAY) { 
		phalcon_update_property_zval(this_ptr, SL("_cssClasses"), css_classes TSRMLS_CC);
	} else {
		PHALCON_THROW_EXCEPTION_STR(phalcon_flash_exception_ce, "CSS classes must be an Array");
		return;
	}
	
	RETURN_CCTOR(this_ptr);
}

/**
 * Shows a HTML error message
 *
 * @param string $message
 * @return string
 */
PHP_METHOD(Phalcon_Flash, error){

	zval *message = NULL, *type = NULL, *flash_message = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &message) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(type);
	ZVAL_STRING(type, "error", 1);
	
	PHALCON_INIT_VAR(flash_message);
	PHALCON_CALL_METHOD_PARAMS_2(flash_message, this_ptr, "message", type, message, PH_NO_CHECK);
	
	RETURN_CCTOR(flash_message);
}

/**
 * Shows a HTML notice/information message
 *
 * @param string $message
 * @return string
 */
PHP_METHOD(Phalcon_Flash, notice){

	zval *message = NULL, *type = NULL, *flash_message = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &message) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(type);
	ZVAL_STRING(type, "notice", 1);
	
	PHALCON_INIT_VAR(flash_message);
	PHALCON_CALL_METHOD_PARAMS_2(flash_message, this_ptr, "message", type, message, PH_NO_CHECK);
	
	RETURN_CCTOR(flash_message);
}

/**
 * Shows a HTML success message
 *
 * @param string $message
 * @param string $classes
 * @return string
 */
PHP_METHOD(Phalcon_Flash, success){

	zval *message = NULL, *type = NULL, *flash_message = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &message) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(type);
	ZVAL_STRING(type, "success", 1);
	
	PHALCON_INIT_VAR(flash_message);
	PHALCON_CALL_METHOD_PARAMS_2(flash_message, this_ptr, "message", type, message, PH_NO_CHECK);
	
	RETURN_CCTOR(flash_message);
}

/**
 * Shows a HTML warning message
 *
 * @param string $message
 * @param string $classes
 * @return string
 */
PHP_METHOD(Phalcon_Flash, warning){

	zval *message = NULL, *type = NULL, *flash_message = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &message) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(type);
	ZVAL_STRING(type, "warning", 1);
	
	PHALCON_INIT_VAR(flash_message);
	PHALCON_CALL_METHOD_PARAMS_2(flash_message, this_ptr, "message", type, message, PH_NO_CHECK);
	
	RETURN_CCTOR(flash_message);
}

PHP_METHOD(Phalcon_Flash, outputMessage){

	zval *type = NULL, *message = NULL, *automatic_html = NULL, *classes = NULL;
	zval *type_classes = NULL, *joined_classes = NULL, *css_classes = NULL;
	zval *eol = NULL, *implicit_flush = NULL, *content = NULL, *msg = NULL, *html_message = NULL;
	zval *c0 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &type, &message) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(automatic_html);
	phalcon_read_property(&automatic_html, this_ptr, SL("_automaticHtml"), PH_NOISY_CC);
	if (Z_TYPE_P(automatic_html) == IS_BOOL && Z_BVAL_P(automatic_html)) {
		PHALCON_INIT_VAR(classes);
		phalcon_read_property(&classes, this_ptr, SL("_cssClasses"), PH_NOISY_CC);
		eval_int = phalcon_array_isset(classes, type);
		if (eval_int) {
			PHALCON_INIT_VAR(type_classes);
			phalcon_array_fetch(&type_classes, classes, type, PH_NOISY_CC);
			if (Z_TYPE_P(type_classes) == IS_ARRAY) { 
				PHALCON_INIT_VAR(c0);
				ZVAL_STRING(c0, " ", 1);
				PHALCON_INIT_VAR(joined_classes);
				phalcon_fast_join(joined_classes, c0, type_classes TSRMLS_CC);
				
				PHALCON_INIT_VAR(css_classes);
				PHALCON_CONCAT_SVS(css_classes, " class=\"", joined_classes, "\"");
			} else {
				PHALCON_INIT_VAR(css_classes);
				PHALCON_CONCAT_SVS(css_classes, " class=\"", type_classes, "\"");
			}
		} else {
			PHALCON_INIT_VAR(css_classes);
			ZVAL_STRING(css_classes, "", 1);
		}
		
		PHALCON_INIT_VAR(eol);
		zend_get_constant(SL("PHP_EOL"), eol TSRMLS_CC);
	}
	
	PHALCON_INIT_VAR(implicit_flush);
	phalcon_read_property(&implicit_flush, this_ptr, SL("_implicitFlush"), PH_NOISY_CC);
	if (Z_TYPE_P(message) == IS_ARRAY) { 
		PHALCON_INIT_VAR(t0);
		ZVAL_BOOL(t0, 0);
		PHALCON_ALLOC_ZVAL_MM(r0);
		is_equal_function(r0, implicit_flush, t0 TSRMLS_CC);
		if (zend_is_true(r0)) {
			PHALCON_INIT_VAR(content);
			ZVAL_STRING(content, "", 1);
		}
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
			if (Z_TYPE_P(automatic_html) == IS_BOOL && Z_BVAL_P(automatic_html)) {
				PHALCON_INIT_VAR(html_message);
				PHALCON_CONCAT_SVSVSV(html_message, "<div", css_classes, ">", msg, "</div>", eol);
			} else {
				PHALCON_CPY_WRT(html_message, msg);
			}
			if (Z_TYPE_P(implicit_flush) == IS_BOOL && Z_BVAL_P(implicit_flush)) {
				zend_print_zval(html_message, 1);
			} else {
				phalcon_concat_self(&content, html_message TSRMLS_CC);
			}
			zend_hash_move_forward_ex(ah0, &hp0);
			goto fes_3b3c_0;
		fee_3b3c_0:
		
		PHALCON_INIT_VAR(t1);
		ZVAL_BOOL(t1, 0);
		
		PHALCON_ALLOC_ZVAL_MM(r1);
		is_equal_function(r1, implicit_flush, t1 TSRMLS_CC);
		if (zend_is_true(r1)) {
			
			RETURN_CTOR(content);
		}
	} else {
		if (Z_TYPE_P(automatic_html) == IS_BOOL && Z_BVAL_P(automatic_html)) {
			PHALCON_INIT_VAR(html_message);
			PHALCON_CONCAT_SVSVSV(html_message, "<div", css_classes, ">", message, "</div>", eol);
		} else {
			PHALCON_CPY_WRT(html_message, message);
		}
		if (Z_TYPE_P(implicit_flush) == IS_BOOL && Z_BVAL_P(implicit_flush)) {
			zend_print_zval(html_message, 1);
		} else {
			
			RETURN_CCTOR(html_message);
		}
	}
	
	PHALCON_MM_RESTORE();
}

PHP_METHOD(Phalcon_Flash, message){


	
}

