
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/concat.h"


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
/**
 * Phalcon\Flash
 *
 * Shows HTML notifications related to different circumstances. Classes can be stylized using CSS
 *
 *<code>
 * $flash->success("The record was successfully deleted");
 * $flash->error("Cannot open the file");
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Flash) {

	ZEPHIR_REGISTER_CLASS(Phalcon, Flash, phalcon, flash, phalcon_flash_method_entry, 0);

	zend_declare_property_null(phalcon_flash_ce, SL("_cssClasses"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_flash_ce, SL("_implicitFlush"), 1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_flash_ce, SL("_automaticHtml"), 1, ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Phalcon\Flash constructor
 *
 * @param array cssClasses
 */
PHP_METHOD(Phalcon_Flash, __construct) {

	zval *cssClasses = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &cssClasses);

	if (!cssClasses) {
		ZEPHIR_CPY_WRT(cssClasses, ZEPHIR_GLOBAL(global_null));
	}
	ZEPHIR_SEPARATE_PARAM(cssClasses);


	if ((Z_TYPE_P(cssClasses) != IS_ARRAY)) {
		ZEPHIR_INIT_NVAR(cssClasses);
		array_init(cssClasses);
		add_assoc_stringl_ex(cssClasses, SS("error"), SL("errorMessage"), 1);
		add_assoc_stringl_ex(cssClasses, SS("notice"), SL("noticeMessage"), 1);
		add_assoc_stringl_ex(cssClasses, SS("success"), SL("successMessage"), 1);
		add_assoc_stringl_ex(cssClasses, SS("warning"), SL("warningMessage"), 1);
	}
	zephir_update_property_this(this_ptr, SL("_cssClasses"), cssClasses TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Set whether the output must be implictly flushed to the output or returned as string
 *
 * @param boolean implicitFlush
 * @return Phalcon\FlashInterface
 */
PHP_METHOD(Phalcon_Flash, setImplicitFlush) {

	zval *implicitFlush_param = NULL;
	zend_bool implicitFlush;

	zephir_fetch_params(0, 1, 0, &implicitFlush_param);

		implicitFlush = zephir_get_boolval(implicitFlush_param);


	zephir_update_property_this(this_ptr, SL("_implicitFlush"), implicitFlush ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Set if the output must be implictily formatted with HTML
 *
 * @param boolean automaticHtml
 * @return Phalcon\FlashInterface
 */
PHP_METHOD(Phalcon_Flash, setAutomaticHtml) {

	zval *automaticHtml_param = NULL;
	zend_bool automaticHtml;

	zephir_fetch_params(0, 1, 0, &automaticHtml_param);

		automaticHtml = zephir_get_boolval(automaticHtml_param);


	zephir_update_property_this(this_ptr, SL("_automaticHtml"), automaticHtml ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Set an array with CSS classes to format the messages
 *
 * @param array cssClasses
 * @return Phalcon\FlashInterface
 */
PHP_METHOD(Phalcon_Flash, setCssClasses) {

	zval *cssClasses;

	zephir_fetch_params(0, 1, 0, &cssClasses);



	if ((Z_TYPE_P(cssClasses) == IS_ARRAY)) {
		zephir_update_property_this(this_ptr, SL("_cssClasses"), cssClasses TSRMLS_CC);
		RETURN_THISW();
	}
	ZEPHIR_THROW_EXCEPTION_STRW(phalcon_flash_exception_ce, "CSS classes must be an Array");
	return;

}

/**
 * Shows a HTML error message
 *
 *<code>
 * $flash->error('This is an error');
 *</code>
 *
 * @param string message
 * @return string
 */
PHP_METHOD(Phalcon_Flash, error) {

	zval *message, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &message);



	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "error", 1);
	zephir_call_method_p2(return_value, this_ptr, "message", _0, message);
	RETURN_MM();

}

/**
 * Shows a HTML notice/information message
 *
 *<code>
 * $flash->notice('This is an information');
 *</code>
 *
 * @param string message
 * @return string
 */
PHP_METHOD(Phalcon_Flash, notice) {

	zval *message, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &message);



	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "notice", 1);
	zephir_call_method_p2(return_value, this_ptr, "message", _0, message);
	RETURN_MM();

}

/**
 * Shows a HTML success message
 *
 *<code>
 * $flash->success('The process was finished successfully');
 *</code>
 *
 * @param string message
 * @return string
 */
PHP_METHOD(Phalcon_Flash, success) {

	zval *message_param = NULL, *_0;
	zval *message = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &message_param);

		zephir_get_strval(message, message_param);


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "success", 1);
	zephir_call_method_p2(return_value, this_ptr, "message", _0, message);
	RETURN_MM();

}

/**
 * Shows a HTML warning message
 *
 *<code>
 * $flash->warning('Hey, this is important');
 *</code>
 *
 * @param string message
 * @return string
 */
PHP_METHOD(Phalcon_Flash, warning) {

	zval *message, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &message);



	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "warning", 1);
	zephir_call_method_p2(return_value, this_ptr, "message", _0, message);
	RETURN_MM();

}

/**
 * Outputs a message formatting it with HTML
 *
 *<code>
 * $flash->outputMessage('error', message);
 *</code>
 *
 * @param string type
 * @param string|array message
 */
PHP_METHOD(Phalcon_Flash, outputMessage) {

	HashTable *_6;
	HashPosition _5;
	zend_bool automaticHtml, implicitFlush;
	zval *type_param = NULL, *message, *content, *cssClasses = NULL, *classes, *typeClasses, *eol, *msg = NULL, *htmlMessage = NULL, *_0, _1, *_2, *_3 = NULL, *_4, **_7, *_8 = NULL, *_9 = NULL, *_10 = NULL;
	zval *type = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &type_param, &message);

		zephir_get_strval(type, type_param);


	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("_automaticHtml"), PH_NOISY_CC);
	automaticHtml = (zephir_get_boolval(_0)) ? 1 : 0;
	if ((automaticHtml == 1)) {
		classes = zephir_fetch_nproperty_this(this_ptr, SL("_cssClasses"), PH_NOISY_CC);
		if (zephir_array_isset_fetch(&typeClasses, classes, type, 1 TSRMLS_CC)) {
			ZEPHIR_INIT_VAR(cssClasses);
			if ((Z_TYPE_P(typeClasses) == IS_ARRAY)) {
				ZEPHIR_SINIT_VAR(_1);
				ZVAL_STRING(&_1, " ", 0);
				ZEPHIR_INIT_VAR(_2);
				zephir_call_func_p2(_2, "join", &_1, typeClasses);
				ZEPHIR_INIT_VAR(_3);
				ZEPHIR_CONCAT_SV(_3, " class=\"", _2);
				ZEPHIR_CONCAT_VS(cssClasses, _3, "\"");
			} else {
				ZEPHIR_INIT_LNVAR(_3);
				ZEPHIR_CONCAT_SV(_3, " class=\"", typeClasses);
				ZEPHIR_CONCAT_VS(cssClasses, _3, "\"");
			}
		} else {
			ZEPHIR_INIT_NVAR(cssClasses);
			ZVAL_STRING(cssClasses, "", 1);
		}
		ZEPHIR_INIT_VAR(eol);
		ZVAL_STRING(eol, "\n", 1);
	}
	ZEPHIR_OBS_VAR(_4);
	zephir_read_property_this(&_4, this_ptr, SL("_implicitFlush"), PH_NOISY_CC);
	implicitFlush = (zephir_get_boolval(_4)) ? 1 : 0;
	if ((Z_TYPE_P(message) == IS_ARRAY)) {
		if ((implicitFlush == 0)) {
			ZEPHIR_INIT_VAR(content);
			ZVAL_STRING(content, "", 1);
		}
		zephir_is_iterable(message, &_6, &_5, 0, 0);
		for (
			; zend_hash_get_current_data_ex(_6, (void**) &_7, &_5) == SUCCESS
			; zend_hash_move_forward_ex(_6, &_5)
		) {
			ZEPHIR_GET_HVALUE(msg, _7);
			if ((automaticHtml == 1)) {
				ZEPHIR_INIT_LNVAR(_3);
				ZEPHIR_CONCAT_SV(_3, "<div", cssClasses);
				ZEPHIR_INIT_LNVAR(_8);
				ZEPHIR_CONCAT_VS(_8, _3, ">");
				ZEPHIR_INIT_LNVAR(_9);
				concat_function(_9, _8, msg TSRMLS_CC);
				ZEPHIR_INIT_LNVAR(_10);
				ZEPHIR_CONCAT_VS(_10, _9, "</div>");
				ZEPHIR_INIT_NVAR(htmlMessage);
				concat_function(htmlMessage, _10, eol TSRMLS_CC);
			} else {
				ZEPHIR_CPY_WRT(htmlMessage, msg);
			}
			if ((implicitFlush == 1)) {
				zend_print_zval(htmlMessage, 0);
			} else {
				zephir_concat_self(&content, htmlMessage TSRMLS_CC);
			}
		}
		if ((implicitFlush == 0)) {
			RETURN_CCTOR(content);
		}
	} else {
		if ((automaticHtml == 1)) {
			ZEPHIR_INIT_LNVAR(_3);
			ZEPHIR_CONCAT_SV(_3, "<div", cssClasses);
			ZEPHIR_INIT_LNVAR(_8);
			ZEPHIR_CONCAT_VS(_8, _3, ">");
			ZEPHIR_INIT_LNVAR(_9);
			concat_function(_9, _8, message TSRMLS_CC);
			ZEPHIR_INIT_LNVAR(_10);
			ZEPHIR_CONCAT_VS(_10, _9, "</div>");
			ZEPHIR_INIT_NVAR(htmlMessage);
			concat_function(htmlMessage, _10, eol TSRMLS_CC);
		} else {
			ZEPHIR_CPY_WRT(htmlMessage, message);
		}
		if ((implicitFlush == 1)) {
			zend_print_zval(htmlMessage, 0);
		} else {
			RETURN_CCTOR(htmlMessage);
		}
	}
	ZEPHIR_MM_RESTORE();

}

