
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
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

#include "flash.h"
#include "flashinterface.h"
#include "flash/exception.h"

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/string.h"
#include "kernel/concat.h"

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
zend_class_entry *phalcon_flash_ce;

PHP_METHOD(Phalcon_Flash, __construct);
PHP_METHOD(Phalcon_Flash, setImplicitFlush);
PHP_METHOD(Phalcon_Flash, setAutomaticHtml);
PHP_METHOD(Phalcon_Flash, setCssClasses);
PHP_METHOD(Phalcon_Flash, error);
PHP_METHOD(Phalcon_Flash, notice);
PHP_METHOD(Phalcon_Flash, success);
PHP_METHOD(Phalcon_Flash, warning);
PHP_METHOD(Phalcon_Flash, outputMessage);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_flash___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, cssClasses)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_flash_setimplicitflush, 0, 0, 1)
	ZEND_ARG_INFO(0, implicitFlush)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_flash_setautomatichtml, 0, 0, 1)
	ZEND_ARG_INFO(0, automaticHtml)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_flash_setcssclasses, 0, 0, 1)
	ZEND_ARG_INFO(0, cssClasses)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_flash_outputmessage, 0, 0, 2)
	ZEND_ARG_INFO(0, type)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

static const zend_function_entry phalcon_flash_method_entry[] = {
	PHP_ME(Phalcon_Flash, __construct, arginfo_phalcon_flash___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Flash, setImplicitFlush, arginfo_phalcon_flash_setimplicitflush, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Flash, setAutomaticHtml, arginfo_phalcon_flash_setautomatichtml, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Flash, setCssClasses, arginfo_phalcon_flash_setcssclasses, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Flash, error, arginfo_phalcon_flashinterface_error, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Flash, notice, arginfo_phalcon_flashinterface_notice, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Flash, success, arginfo_phalcon_flashinterface_success, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Flash, warning, arginfo_phalcon_flashinterface_warning, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Flash, outputMessage, arginfo_phalcon_flash_outputmessage, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

/**
 * Phalcon\Flash initializer
 */
PHALCON_INIT_CLASS(Phalcon_Flash){

	PHALCON_REGISTER_CLASS(Phalcon, Flash, flash, phalcon_flash_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(phalcon_flash_ce, SL("_cssClasses"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_flash_ce, SL("_implicitFlush"), 1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_flash_ce, SL("_automaticHtml"), 1, ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;
}

/**
 * Phalcon\Flash constructor
 *
 * @param array $cssClasses
 */
PHP_METHOD(Phalcon_Flash, __construct){

	zval *css_classes = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 1, &css_classes);
	
	if (!css_classes) {
		PHALCON_INIT_VAR(css_classes);
	} else {
		PHALCON_SEPARATE_PARAM(css_classes);
	}
	
	if (Z_TYPE_P(css_classes) != IS_ARRAY) { 
		PHALCON_INIT_NVAR(css_classes);
		array_init_size(css_classes, 4);
		add_assoc_stringl_ex(css_classes, SS("error"), SL("errorMessage"), 1);
		add_assoc_stringl_ex(css_classes, SS("notice"), SL("noticeMessage"), 1);
		add_assoc_stringl_ex(css_classes, SS("success"), SL("successMessage"), 1);
		add_assoc_stringl_ex(css_classes, SS("warning"), SL("warningMessage"), 1);
	}
	phalcon_update_property_this(this_ptr, SL("_cssClasses"), css_classes TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Set whether the output must be implictly flushed to the output or returned as string
 *
 * @param boolean $implicitFlush
 * @return Phalcon\FlashInterface
 */
PHP_METHOD(Phalcon_Flash, setImplicitFlush){

	zval *implicit_flush;

	phalcon_fetch_params(0, 1, 0, &implicit_flush);
	
	phalcon_update_property_this(this_ptr, SL("_implicitFlush"), implicit_flush TSRMLS_CC);
	RETURN_THISW();
}

/**
 * Set if the output must be implictily formatted with HTML
 *
 * @param boolean $automaticHtml
 * @return Phalcon\FlashInterface
 */
PHP_METHOD(Phalcon_Flash, setAutomaticHtml){

	zval *automatic_html;

	phalcon_fetch_params(0, 1, 0, &automatic_html);
	
	phalcon_update_property_this(this_ptr, SL("_automaticHtml"), automatic_html TSRMLS_CC);
	RETURN_THISW();
}

/**
 * Set an array with CSS classes to format the messages
 *
 * @param array $cssClasses
 * @return Phalcon\FlashInterface
 */
PHP_METHOD(Phalcon_Flash, setCssClasses){

	zval *css_classes;

	phalcon_fetch_params(0, 1, 0, &css_classes);
	
	if (Z_TYPE_P(css_classes) == IS_ARRAY) { 
		phalcon_update_property_this(this_ptr, SL("_cssClasses"), css_classes TSRMLS_CC);
		RETURN_THISW();
	}
	PHALCON_THROW_EXCEPTION_STRW(phalcon_flash_exception_ce, "CSS classes must be an Array");
	return;
}

static void phalcon_flash_message_helper(INTERNAL_FUNCTION_PARAMETERS, const char *stype)
{
	zval **msg, *type;

	phalcon_fetch_params_ex(1, 0, &msg);

	PHALCON_ALLOC_GHOST_ZVAL(type);
	ZVAL_STRING(type, stype, 1);

	PHALCON_RETURN_CALL_METHODW(getThis(), "message", type, *msg);
}

/**
 * Shows a HTML error message
 *
 *<code>
 * $flash->error('This is an error');
 *</code>
 *
 * @param string $message
 * @return string
 */
PHP_METHOD(Phalcon_Flash, error)
{
	phalcon_flash_message_helper(INTERNAL_FUNCTION_PARAM_PASSTHRU, "error");
}

/**
 * Shows a HTML notice/information message
 *
 *<code>
 * $flash->notice('This is an information');
 *</code>
 *
 * @param string $message
 * @return string
 */
PHP_METHOD(Phalcon_Flash, notice)
{
	phalcon_flash_message_helper(INTERNAL_FUNCTION_PARAM_PASSTHRU, "notice");
}

/**
 * Shows a HTML success message
 *
 *<code>
 * $flash->success('The process was finished successfully');
 *</code>
 *
 * @param string $message
 * @return string
 */
PHP_METHOD(Phalcon_Flash, success)
{
	phalcon_flash_message_helper(INTERNAL_FUNCTION_PARAM_PASSTHRU, "success");
}

/**
 * Shows a HTML warning message
 *
 *<code>
 * $flash->warning('Hey, this is important');
 *</code>
 *
 * @param string $message
 * @return string
 */
PHP_METHOD(Phalcon_Flash, warning)
{
	phalcon_flash_message_helper(INTERNAL_FUNCTION_PARAM_PASSTHRU, "warning");
}

/**
 * Outputs a message formatting it with HTML
 *
 *<code>
 * $flash->outputMessage('error', $message);
 *</code>
 *
 * @param string $type
 * @param string $message
 */
PHP_METHOD(Phalcon_Flash, outputMessage){

	zval *type, *message, *automatic_html, *classes;
	zval *type_classes, *joined_classes, *css_classes = NULL;
	zval *implicit_flush, *content, *msg = NULL, *html_message = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	int flag_automatic_html;
	int flag_implicit_flush;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 0, &type, &message);

	automatic_html      = phalcon_fetch_nproperty_this(this_ptr, SL("_automaticHtml"), PH_NOISY TSRMLS_CC);
	flag_automatic_html = zend_is_true(automatic_html);
	if (flag_automatic_html) {

		classes = phalcon_fetch_nproperty_this(this_ptr, SL("_cssClasses"), PH_NOISY TSRMLS_CC);

		PHALCON_INIT_VAR(css_classes);
		if (phalcon_array_isset_fetch(&type_classes, classes, type)) {
			if (Z_TYPE_P(type_classes) == IS_ARRAY) {
				PHALCON_INIT_VAR(joined_classes);
				phalcon_fast_join_str(joined_classes, SL(" "), type_classes TSRMLS_CC);

				PHALCON_CONCAT_SVS(css_classes, " class=\"", joined_classes, "\"");
			} else {
				PHALCON_CONCAT_SVS(css_classes, " class=\"", type_classes, "\"");
			}
		} else {
			ZVAL_EMPTY_STRING(css_classes);
		}
	}

	implicit_flush      = phalcon_fetch_nproperty_this(this_ptr, SL("_implicitFlush"), PH_NOISY TSRMLS_CC);
	flag_implicit_flush = zend_is_true(implicit_flush);
	if (Z_TYPE_P(message) == IS_ARRAY) {

		/**
		 * We create the message with implicit flush or other
		 */
		if (!flag_implicit_flush) {
			PHALCON_INIT_VAR(content);
			ZVAL_EMPTY_STRING(content);
		}

		/**
		 * We create the message with implicit flush or other
		 */
		phalcon_is_iterable(message, &ah0, &hp0, 0, 0);

		while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {

			PHALCON_GET_HVALUE(msg);

			/**
			 * We create the applying formatting or not
			 */
			if (flag_automatic_html) {
				PHALCON_INIT_NVAR(html_message);
				PHALCON_CONCAT_SVSVS(html_message, "<div", css_classes, ">", msg, "</div>" PHP_EOL);
			} else {
				PHALCON_CPY_WRT(html_message, msg);
			}

			if (flag_implicit_flush) {
				zend_print_zval(html_message, 0);
			} else {
				phalcon_concat_self(&content, html_message TSRMLS_CC);
			}

			zend_hash_move_forward_ex(ah0, &hp0);
		}

		/**
		 * We return the message as string if the implicit_flush is turned off
		 */
		if (!flag_implicit_flush) {
			RETURN_CTOR(content);
		}
	} else {
		/**
		 * We create the applying formatting or not
		 */
		if (flag_automatic_html) {
			PHALCON_INIT_NVAR(html_message);
			PHALCON_CONCAT_SVSVS(html_message, "<div", css_classes, ">", message, "</div>" PHP_EOL);
		} else {
			PHALCON_CPY_WRT(html_message, message);
		}

		/**
		 * We return the message as string if the implicit_flush is turned off
		 */
		if (flag_implicit_flush) {
			zend_print_zval(html_message, 0);
		} else {
			RETURN_CCTOR(html_message);
		}
	}

	PHALCON_MM_RESTORE();
}
