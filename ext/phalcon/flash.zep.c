
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
#include "kernel/array.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "kernel/string.h"
#include "kernel/hash.h"


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

	ZEPHIR_REGISTER_CLASS(Phalcon, Flash, phalcon, flash, phalcon_flash_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(phalcon_flash_ce, SL("_cssClasses"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_bool(phalcon_flash_ce, SL("_implicitFlush"), 1, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_bool(phalcon_flash_ce, SL("_automaticHtml"), 1, ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Phalcon\Flash constructor
 */
PHP_METHOD(Phalcon_Flash, __construct) {

	zval *cssClasses = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &cssClasses);

	if (!cssClasses) {
		ZEPHIR_CPY_WRT(cssClasses, ZEPHIR_GLOBAL(global_null));
	} else {
		ZEPHIR_SEPARATE_PARAM(cssClasses);
	}


	if (Z_TYPE_P(cssClasses) != IS_ARRAY) {
		ZEPHIR_INIT_NVAR(cssClasses);
		zephir_create_array(cssClasses, 4, 0 TSRMLS_CC);
		add_assoc_stringl_ex(cssClasses, SS("error"), SL("errorMessage"), 1);
		add_assoc_stringl_ex(cssClasses, SS("notice"), SL("noticeMessage"), 1);
		add_assoc_stringl_ex(cssClasses, SS("success"), SL("successMessage"), 1);
		add_assoc_stringl_ex(cssClasses, SS("warning"), SL("warningMessage"), 1);
	}
	zephir_update_property_this(this_ptr, SL("_cssClasses"), cssClasses TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Set whether the output must be implicitly flushed to the output or returned as string
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
 * Set if the output must be implicitly formatted with HTML
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
 */
PHP_METHOD(Phalcon_Flash, setCssClasses) {

	zval *cssClasses_param = NULL;
	zval *cssClasses = NULL;

	zephir_fetch_params(0, 1, 0, &cssClasses_param);

	cssClasses = cssClasses_param;



	zephir_update_property_this(this_ptr, SL("_cssClasses"), cssClasses TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Shows a HTML error message
 *
 *<code>
 * $flash->error('This is an error');
 *</code>
 */
PHP_METHOD(Phalcon_Flash, error) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *message, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &message);



	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "error", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "message", NULL, 0, _0, message);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Shows a HTML notice/information message
 *
 *<code>
 * $flash->notice('This is an information');
 *</code>
 */
PHP_METHOD(Phalcon_Flash, notice) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *message, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &message);



	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "notice", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "message", NULL, 0, _0, message);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Shows a HTML success message
 *
 *<code>
 * $flash->success('The process was finished successfully');
 *</code>
 */
PHP_METHOD(Phalcon_Flash, success) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *message_param = NULL, *_0;
	zval *message = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &message_param);

	zephir_get_strval(message, message_param);


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "success", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "message", NULL, 0, _0, message);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Shows a HTML warning message
 *
 *<code>
 * $flash->warning('Hey, this is important');
 *</code>
 */
PHP_METHOD(Phalcon_Flash, warning) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *message, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &message);



	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "warning", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "message", NULL, 0, _0, message);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Outputs a message formatting it with HTML
 *
 *<code>
 * $flash->outputMessage('error', message);
 *</code>
 *
 * @param string|array message
 */
PHP_METHOD(Phalcon_Flash, outputMessage) {

	HashTable *_3;
	HashPosition _2;
	zend_bool automaticHtml, implicitFlush;
	zval *type_param = NULL, *message, *content, *cssClasses = NULL, *classes, *typeClasses, *eol = NULL, *msg = NULL, *htmlMessage = NULL, *_0 = NULL, *_1, **_4;
	zval *type = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &type_param, &message);

	zephir_get_strval(type, type_param);


	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("_automaticHtml"), PH_NOISY_CC);
	automaticHtml = zephir_get_boolval(_0);
	if (automaticHtml == 1) {
		ZEPHIR_OBS_VAR(classes);
		zephir_read_property_this(&classes, this_ptr, SL("_cssClasses"), PH_NOISY_CC);
		ZEPHIR_OBS_VAR(typeClasses);
		if (zephir_array_isset_fetch(&typeClasses, classes, type, 0 TSRMLS_CC)) {
			ZEPHIR_INIT_VAR(cssClasses);
			if (Z_TYPE_P(typeClasses) == IS_ARRAY) {
				ZEPHIR_INIT_VAR(_1);
				zephir_fast_join_str(_1, SL(" "), typeClasses TSRMLS_CC);
				ZEPHIR_CONCAT_SVS(cssClasses, " class=\"", _1, "\"");
			} else {
				ZEPHIR_CONCAT_SVS(cssClasses, " class=\"", typeClasses, "\"");
			}
		} else {
			ZEPHIR_INIT_NVAR(cssClasses);
			ZVAL_STRING(cssClasses, "", 1);
		}
		ZEPHIR_INIT_VAR(eol);
		ZEPHIR_GET_CONSTANT(eol, "PHP_EOL");
	}
	ZEPHIR_OBS_NVAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("_implicitFlush"), PH_NOISY_CC);
	implicitFlush = zephir_get_boolval(_0);
	if (Z_TYPE_P(message) == IS_ARRAY) {
		if (implicitFlush == 0) {
			ZEPHIR_INIT_VAR(content);
			ZVAL_STRING(content, "", 1);
		}
		zephir_is_iterable(message, &_3, &_2, 0, 0, "phalcon/flash.zep", 200);
		for (
		  ; zephir_hash_get_current_data_ex(_3, (void**) &_4, &_2) == SUCCESS
		  ; zephir_hash_move_forward_ex(_3, &_2)
		) {
			ZEPHIR_GET_HVALUE(msg, _4);
			if (automaticHtml == 1) {
				ZEPHIR_INIT_NVAR(htmlMessage);
				ZEPHIR_CONCAT_SVSVSV(htmlMessage, "<div", cssClasses, ">", msg, "</div>", eol);
			} else {
				ZEPHIR_CPY_WRT(htmlMessage, msg);
			}
			if (implicitFlush == 1) {
				zend_print_zval(htmlMessage, 0);
			} else {
				zephir_concat_self(&content, htmlMessage TSRMLS_CC);
			}
		}
		if (implicitFlush == 0) {
			RETURN_CCTOR(content);
		}
	} else {
		if (automaticHtml == 1) {
			ZEPHIR_INIT_NVAR(htmlMessage);
			ZEPHIR_CONCAT_SVSVSV(htmlMessage, "<div", cssClasses, ">", message, "</div>", eol);
		} else {
			ZEPHIR_CPY_WRT(htmlMessage, message);
		}
		if (implicitFlush == 1) {
			zend_print_zval(htmlMessage, 0);
		} else {
			RETURN_CCTOR(htmlMessage);
		}
	}
	ZEPHIR_MM_RESTORE();

}

