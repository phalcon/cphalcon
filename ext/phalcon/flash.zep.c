
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
#include "kernel/fcall.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/concat.h"
#include "kernel/string.h"


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

	zend_declare_property_null(phalcon_flash_ce, SL("_escaperService"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_bool(phalcon_flash_ce, SL("_autoescape"), 1, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_flash_ce, SL("_dependencyInjector"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_flash_ce, SL("_messages"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_flash_ce TSRMLS_CC, 1, phalcon_flashinterface_ce);
	zend_class_implements(phalcon_flash_ce TSRMLS_CC, 1, phalcon_di_injectionawareinterface_ce);
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
	zephir_update_property_this(getThis(), SL("_cssClasses"), cssClasses TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns the autoescape mode in generated html
 */
PHP_METHOD(Phalcon_Flash, getAutoescape) {

	

	RETURN_MEMBER(getThis(), "_autoescape");

}

/**
 * Set the autoescape mode in generated html
 */
PHP_METHOD(Phalcon_Flash, setAutoescape) {

	zval *autoescape_param = NULL;
	zend_bool autoescape;

	zephir_fetch_params(0, 1, 0, &autoescape_param);

	autoescape = zephir_get_boolval(autoescape_param);


	if (autoescape) {
		zephir_update_property_this(getThis(), SL("_autoescape"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	} else {
		zephir_update_property_this(getThis(), SL("_autoescape"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	}
	RETURN_THISW();

}

/**
 * Returns the Escaper Service
 */
PHP_METHOD(Phalcon_Flash, getEscaperService) {

	zval *escaper = NULL, *dependencyInjector = NULL, *_0$$3 = NULL, *_1$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(escaper);
	zephir_read_property_this(&escaper, this_ptr, SL("_escaperService"), PH_NOISY_CC);
	if (Z_TYPE_P(escaper) != IS_OBJECT) {
		ZEPHIR_CALL_METHOD(&_0$$3, this_ptr, "getdi", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(dependencyInjector, _0$$3);
		ZEPHIR_INIT_VAR(_1$$3);
		ZVAL_STRING(_1$$3, "escaper", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_0$$3, dependencyInjector, "getshared", NULL, 0, _1$$3);
		zephir_check_temp_parameter(_1$$3);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(escaper, _0$$3);
		zephir_update_property_this(getThis(), SL("_escaperService"), escaper TSRMLS_CC);
	}
	RETURN_CCTOR(escaper);

}

/**
 * Sets the Escaper Service
 */
PHP_METHOD(Phalcon_Flash, setEscaperService) {

	zval *escaperService;

	zephir_fetch_params(0, 1, 0, &escaperService);



	zephir_update_property_this(getThis(), SL("_escaperService"), escaperService TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Sets the dependency injector
 */
PHP_METHOD(Phalcon_Flash, setDI) {

	zval *dependencyInjector;

	zephir_fetch_params(0, 1, 0, &dependencyInjector);



	zephir_update_property_this(getThis(), SL("_dependencyInjector"), dependencyInjector TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Returns the internal dependency injector
 */
PHP_METHOD(Phalcon_Flash, getDI) {

	zval *di = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(di);
	zephir_read_property_this(&di, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	if (Z_TYPE_P(di) != IS_OBJECT) {
		ZEPHIR_CALL_CE_STATIC(&di, phalcon_di_ce, "getdefault", &_0, 1);
		zephir_check_call_status();
	}
	RETURN_CCTOR(di);

}

/**
 * Set whether the output must be implicitly flushed to the output or returned as string
 */
PHP_METHOD(Phalcon_Flash, setImplicitFlush) {

	zval *implicitFlush_param = NULL;
	zend_bool implicitFlush;

	zephir_fetch_params(0, 1, 0, &implicitFlush_param);

	implicitFlush = zephir_get_boolval(implicitFlush_param);


	if (implicitFlush) {
		zephir_update_property_this(getThis(), SL("_implicitFlush"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	} else {
		zephir_update_property_this(getThis(), SL("_implicitFlush"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	}
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


	if (automaticHtml) {
		zephir_update_property_this(getThis(), SL("_automaticHtml"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	} else {
		zephir_update_property_this(getThis(), SL("_automaticHtml"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	}
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


	zephir_update_property_this(getThis(), SL("_cssClasses"), cssClasses TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Shows a HTML error message
 *
 *<code>
 * $flash->error("This is an error");
 *</code>
 */
PHP_METHOD(Phalcon_Flash, error) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
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
 * $flash->notice("This is an information");
 *</code>
 */
PHP_METHOD(Phalcon_Flash, notice) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
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
 * $flash->success("The process was finished successfully");
 *</code>
 */
PHP_METHOD(Phalcon_Flash, success) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *message, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &message);



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
 * $flash->warning("Hey, this is important");
 *</code>
 */
PHP_METHOD(Phalcon_Flash, warning) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
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
 * $flash->outputMessage("error", $message);
 *</code>
 *
 * @param string|array message
 * @return string|void
 */
PHP_METHOD(Phalcon_Flash, outputMessage) {

	HashTable *_3$$9;
	HashPosition _2$$9;
	zend_bool automaticHtml = 0, implicitFlush = 0, autoEscape = 0;
	zephir_fcall_cache_entry *_5 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *type_param = NULL, *message, *content = NULL, *cssClasses = NULL, *classes = NULL, *typeClasses = NULL, *eol = NULL, *msg = NULL, *htmlMessage = NULL, *escaper = NULL, *preparedMsg = NULL, *_0 = NULL, *_1$$5, **_4$$9;
	zval *type = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &type_param, &message);

	zephir_get_strval(type, type_param);


	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("_automaticHtml"), PH_NOISY_CC);
	automaticHtml = zephir_get_boolval(_0);
	ZEPHIR_OBS_NVAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("_autoescape"), PH_NOISY_CC);
	autoEscape = zephir_get_boolval(_0);
	if (automaticHtml == 1) {
		ZEPHIR_OBS_VAR(classes);
		zephir_read_property_this(&classes, this_ptr, SL("_cssClasses"), PH_NOISY_CC);
		ZEPHIR_OBS_VAR(typeClasses);
		if (zephir_array_isset_fetch(&typeClasses, classes, type, 0 TSRMLS_CC)) {
			ZEPHIR_INIT_VAR(cssClasses);
			if (Z_TYPE_P(typeClasses) == IS_ARRAY) {
				ZEPHIR_INIT_VAR(_1$$5);
				zephir_fast_join_str(_1$$5, SL(" "), typeClasses TSRMLS_CC);
				ZEPHIR_CONCAT_SVS(cssClasses, " class=\"", _1$$5, "\"");
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
	if (autoEscape == 1) {
		ZEPHIR_CALL_METHOD(&escaper, this_ptr, "getescaperservice", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_OBS_NVAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("_implicitFlush"), PH_NOISY_CC);
	implicitFlush = zephir_get_boolval(_0);
	if (Z_TYPE_P(message) == IS_ARRAY) {
		if (implicitFlush == 0) {
			ZEPHIR_INIT_VAR(content);
			ZVAL_STRING(content, "", 1);
		}
		zephir_is_iterable(message, &_3$$9, &_2$$9, 0, 0, "phalcon/flash.zep", 288);
		for (
		  ; zend_hash_get_current_data_ex(_3$$9, (void**) &_4$$9, &_2$$9) == SUCCESS
		  ; zend_hash_move_forward_ex(_3$$9, &_2$$9)
		) {
			ZEPHIR_GET_HVALUE(msg, _4$$9);
			if (autoEscape == 1) {
				ZEPHIR_CALL_METHOD(&preparedMsg, escaper, "escapehtml", &_5, 0, msg);
				zephir_check_call_status();
			} else {
				ZEPHIR_CPY_WRT(preparedMsg, msg);
			}
			if (automaticHtml == 1) {
				ZEPHIR_INIT_NVAR(htmlMessage);
				ZEPHIR_CONCAT_SVSVSV(htmlMessage, "<div", cssClasses, ">", preparedMsg, "</div>", eol);
			} else {
				ZEPHIR_CPY_WRT(htmlMessage, preparedMsg);
			}
			if (implicitFlush == 1) {
				zend_print_zval(htmlMessage, 0);
			} else {
				zephir_concat_self(&content, htmlMessage TSRMLS_CC);
				zephir_update_property_array_append(this_ptr, SL("_messages"), htmlMessage TSRMLS_CC);
			}
		}
		if (implicitFlush == 0) {
			RETURN_CCTOR(content);
		}
	} else {
		if (autoEscape == 1) {
			ZEPHIR_CALL_METHOD(&preparedMsg, escaper, "escapehtml", NULL, 0, message);
			zephir_check_call_status();
		} else {
			ZEPHIR_CPY_WRT(preparedMsg, message);
		}
		if (automaticHtml == 1) {
			ZEPHIR_INIT_NVAR(htmlMessage);
			ZEPHIR_CONCAT_SVSVSV(htmlMessage, "<div", cssClasses, ">", preparedMsg, "</div>", eol);
		} else {
			ZEPHIR_CPY_WRT(htmlMessage, preparedMsg);
		}
		if (implicitFlush == 1) {
			zend_print_zval(htmlMessage, 0);
		} else {
			zephir_update_property_array_append(this_ptr, SL("_messages"), htmlMessage TSRMLS_CC);
			RETURN_CCTOR(htmlMessage);
		}
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Clears accumulated messages when implicit flush is disabled
 */
PHP_METHOD(Phalcon_Flash, clear) {

	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_property_this(getThis(), SL("_messages"), _0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

