
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
#include "kernel/array.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/concat.h"
#include "kernel/string.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
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

	ZEPHIR_REGISTER_CLASS(Phalcon, Flash, phalcon, flash, phalcon_flash_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_bool(phalcon_flash_ce, SL("_autoescape"), 1, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_bool(phalcon_flash_ce, SL("_automaticHtml"), 1, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_flash_ce, SL("_cssClasses"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(phalcon_flash_ce, SL("_customTemplate"), "", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_flash_ce, SL("_dependencyInjector"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_flash_ce, SL("_escaperService"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_bool(phalcon_flash_ce, SL("_implicitFlush"), 1, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_flash_ce, SL("_messages"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_flash_ce TSRMLS_CC, 1, phalcon_flashinterface_ce);
	zend_class_implements(phalcon_flash_ce TSRMLS_CC, 1, phalcon_di_injectionawareinterface_ce);
	return SUCCESS;

}

/**
 * Phalcon\Flash constructor
 */
PHP_METHOD(Phalcon_Flash, __construct) {

	zval *cssClasses = NULL, cssClasses_sub, __$null, _0$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&cssClasses_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &cssClasses);

	if (!cssClasses) {
		cssClasses = &cssClasses_sub;
		ZEPHIR_CPY_WRT(cssClasses, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(cssClasses);
	}


	if (Z_TYPE_P(cssClasses) != IS_ARRAY) {
		ZEPHIR_INIT_VAR(&_0$$3);
		zephir_create_array(&_0$$3, 4, 0 TSRMLS_CC);
		add_assoc_stringl_ex(&_0$$3, SL("error"), SL("errorMessage"));
		add_assoc_stringl_ex(&_0$$3, SL("notice"), SL("noticeMessage"));
		add_assoc_stringl_ex(&_0$$3, SL("success"), SL("successMessage"));
		add_assoc_stringl_ex(&_0$$3, SL("warning"), SL("warningMessage"));
		ZEPHIR_CPY_WRT(cssClasses, &_0$$3);
	}
	zephir_update_property_zval(this_ptr, SL("_cssClasses"), cssClasses);
	ZEPHIR_MM_RESTORE();

}

/**
 * Clears accumulated messages when implicit flush is disabled
 */
PHP_METHOD(Phalcon_Flash, clear) {

	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	zephir_update_property_zval(this_ptr, SL("_messages"), &_0);
	ZEPHIR_MM_RESTORE();

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
	zval *message_param = NULL, _0;
	zval message;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &message_param);

	zephir_get_strval(&message, message_param);


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "error");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "message", NULL, 0, &_0, &message);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns the autoescape mode in generated html
 */
PHP_METHOD(Phalcon_Flash, getAutoescape) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_autoescape");

}

/**
 * Returns the custom template set
 */
PHP_METHOD(Phalcon_Flash, getCustomTemplate) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_customTemplate");

}

/**
 * Returns the internal dependency injector
 */
PHP_METHOD(Phalcon_Flash, getDI) {

	zval di;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&di);

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&di);
	zephir_read_property(&di, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	if (Z_TYPE_P(&di) != IS_OBJECT) {
		ZEPHIR_CALL_CE_STATIC(&di, phalcon_di_ce, "getdefault", &_0, 0);
		zephir_check_call_status();
	}
	RETURN_CCTOR(&di);

}

/**
 * Returns the Escaper Service
 */
PHP_METHOD(Phalcon_Flash, getEscaperService) {

	zval escaper, dependencyInjector, _0$$3, _1$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&escaper);
	ZVAL_UNDEF(&dependencyInjector);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&escaper);
	zephir_read_property(&escaper, this_ptr, SL("_escaperService"), PH_NOISY_CC);
	if (Z_TYPE_P(&escaper) != IS_OBJECT) {
		ZEPHIR_CALL_METHOD(&_0$$3, this_ptr, "getdi", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&dependencyInjector, &_0$$3);
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "escaper");
		ZEPHIR_CALL_METHOD(&_0$$3, &dependencyInjector, "getshared", NULL, 0, &_1$$3);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&escaper, &_0$$3);
		zephir_update_property_zval(this_ptr, SL("_escaperService"), &escaper);
	}
	RETURN_CCTOR(&escaper);

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
	zval *message_param = NULL, _0;
	zval message;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &message_param);

	zephir_get_strval(&message, message_param);


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "notice");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "message", NULL, 0, &_0, &message);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Set the autoescape mode in generated html
 */
PHP_METHOD(Phalcon_Flash, setAutoescape) {

	zval *autoescape_param = NULL, __$true, __$false;
	zend_bool autoescape;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);

	zephir_fetch_params(0, 1, 0, &autoescape_param);

	autoescape = zephir_get_boolval(autoescape_param);


	if (autoescape) {
		zephir_update_property_zval(this_ptr, SL("_autoescape"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("_autoescape"), &__$false);
	}
	RETURN_THISW();

}

/**
 * Set if the output must be implicitly formatted with HTML
 */
PHP_METHOD(Phalcon_Flash, setAutomaticHtml) {

	zval *automaticHtml_param = NULL, __$true, __$false;
	zend_bool automaticHtml;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);

	zephir_fetch_params(0, 1, 0, &automaticHtml_param);

	automaticHtml = zephir_get_boolval(automaticHtml_param);


	if (automaticHtml) {
		zephir_update_property_zval(this_ptr, SL("_automaticHtml"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("_automaticHtml"), &__$false);
	}
	RETURN_THISW();

}

/**
 * Set an array with CSS classes to format the messages
 */
PHP_METHOD(Phalcon_Flash, setCssClasses) {

	zval *cssClasses_param = NULL;
	zval cssClasses;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&cssClasses);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &cssClasses_param);

	ZEPHIR_OBS_COPY_OR_DUP(&cssClasses, cssClasses_param);


	zephir_update_property_zval(this_ptr, SL("_cssClasses"), &cssClasses);
	RETURN_THIS();

}

/**
 * Set an custom template for showing the messages
 */
PHP_METHOD(Phalcon_Flash, setCustomTemplate) {

	zval *customTemplate_param = NULL;
	zval customTemplate;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&customTemplate);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &customTemplate_param);

	if (UNEXPECTED(Z_TYPE_P(customTemplate_param) != IS_STRING && Z_TYPE_P(customTemplate_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'customTemplate' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(customTemplate_param) == IS_STRING)) {
		zephir_get_strval(&customTemplate, customTemplate_param);
	} else {
		ZEPHIR_INIT_VAR(&customTemplate);
		ZVAL_EMPTY_STRING(&customTemplate);
	}


	zephir_update_property_zval(this_ptr, SL("_customTemplate"), &customTemplate);
	RETURN_THIS();

}

/**
 * Sets the dependency injector
 */
PHP_METHOD(Phalcon_Flash, setDI) {

	zval *dependencyInjector, dependencyInjector_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&dependencyInjector_sub);

	zephir_fetch_params(0, 1, 0, &dependencyInjector);



	zephir_update_property_zval(this_ptr, SL("_dependencyInjector"), dependencyInjector);
	RETURN_THISW();

}

/**
 * Sets the Escaper Service
 */
PHP_METHOD(Phalcon_Flash, setEscaperService) {

	zval *escaperService, escaperService_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&escaperService_sub);

	zephir_fetch_params(0, 1, 0, &escaperService);



	zephir_update_property_zval(this_ptr, SL("_escaperService"), escaperService);
	RETURN_THISW();

}

/**
 * Set whether the output must be implicitly flushed to the output or returned as string
 */
PHP_METHOD(Phalcon_Flash, setImplicitFlush) {

	zval *implicitFlush_param = NULL, __$true, __$false;
	zend_bool implicitFlush;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);

	zephir_fetch_params(0, 1, 0, &implicitFlush_param);

	implicitFlush = zephir_get_boolval(implicitFlush_param);


	if (implicitFlush) {
		zephir_update_property_zval(this_ptr, SL("_implicitFlush"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("_implicitFlush"), &__$false);
	}
	RETURN_THISW();

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
	zval *message_param = NULL, _0;
	zval message;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &message_param);

	zephir_get_strval(&message, message_param);


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "success");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "message", NULL, 0, &_0, &message);
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

	zend_bool implicitFlush = 0;
	zephir_fcall_cache_entry *_3 = NULL, *_4 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *type_param = NULL, *message, message_sub, content, msg, htmlMessage, preparedMsg, _0, *_1$$3, _2$$3;
	zval type;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&message_sub);
	ZVAL_UNDEF(&content);
	ZVAL_UNDEF(&msg);
	ZVAL_UNDEF(&htmlMessage);
	ZVAL_UNDEF(&preparedMsg);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &type_param, &message);

	zephir_get_strval(&type, type_param);


	ZEPHIR_OBS_VAR(&_0);
	zephir_read_property(&_0, this_ptr, SL("_implicitFlush"), PH_NOISY_CC);
	implicitFlush = zephir_get_boolval(&_0);
	if (Z_TYPE_P(message) == IS_ARRAY) {
		if (implicitFlush == 0) {
			ZEPHIR_INIT_VAR(&content);
			ZVAL_STRING(&content, "");
		}
		zephir_is_iterable(message, 0, "phalcon/flash.zep", 267);
		if (Z_TYPE_P(message) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(message), _1$$3)
			{
				ZEPHIR_INIT_NVAR(&msg);
				ZVAL_COPY(&msg, _1$$3);
				ZEPHIR_CALL_METHOD(&preparedMsg, this_ptr, "prepareescapedmessage", &_3, 59, &msg);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&htmlMessage, this_ptr, "preparehtmlmessage", &_4, 60, &type, &preparedMsg);
				zephir_check_call_status();
				if (implicitFlush == 1) {
					zend_print_zval(&htmlMessage, 0);
				} else {
					zephir_concat_self(&content, &htmlMessage TSRMLS_CC);
					zephir_update_property_array_append(this_ptr, SL("_messages"), &htmlMessage);
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, message, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_2$$3, message, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_2$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&msg, message, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&preparedMsg, this_ptr, "prepareescapedmessage", &_3, 59, &msg);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&htmlMessage, this_ptr, "preparehtmlmessage", &_4, 60, &type, &preparedMsg);
					zephir_check_call_status();
					if (implicitFlush == 1) {
						zend_print_zval(&htmlMessage, 0);
					} else {
						zephir_concat_self(&content, &htmlMessage TSRMLS_CC);
						zephir_update_property_array_append(this_ptr, SL("_messages"), &htmlMessage);
					}
				ZEPHIR_CALL_METHOD(NULL, message, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&msg);
		if (implicitFlush == 0) {
			RETURN_CCTOR(&content);
		}
	} else {
		ZEPHIR_CALL_METHOD(&preparedMsg, this_ptr, "prepareescapedmessage", &_3, 59, message);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&htmlMessage, this_ptr, "preparehtmlmessage", &_4, 60, &type, &preparedMsg);
		zephir_check_call_status();
		if (implicitFlush == 1) {
			zend_print_zval(&htmlMessage, 0);
		} else {
			zephir_update_property_array_append(this_ptr, SL("_messages"), &htmlMessage);
			RETURN_CCTOR(&htmlMessage);
		}
	}
	ZEPHIR_MM_RESTORE();

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
	zval *message_param = NULL, _0;
	zval message;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &message_param);

	zephir_get_strval(&message, message_param);


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "warning");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "message", NULL, 0, &_0, &message);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Phalcon_Flash, getTemplate) {

	zval *cssClassses_param = NULL, _0, _1, _2$$3, _3$$4, _4$$5;
	zval cssClassses;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&cssClassses);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &cssClassses_param);

	zephir_get_strval(&cssClassses, cssClassses_param);


	zephir_read_property(&_0, this_ptr, SL("_customTemplate"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, "");
	if (ZEPHIR_IS_IDENTICAL(&_1, &_0)) {
		ZEPHIR_SINIT_VAR(_2$$3);
		ZVAL_STRING(&_2$$3, "");
		if (ZEPHIR_IS_IDENTICAL(&_2$$3, &cssClassses)) {
			ZEPHIR_INIT_VAR(&_3$$4);
			ZEPHIR_GET_CONSTANT(&_3$$4, "PHP_EOL");
			ZEPHIR_CONCAT_SV(return_value, "<div>%message%</div>", &_3$$4);
			RETURN_MM();
		} else {
			ZEPHIR_INIT_VAR(&_4$$5);
			ZEPHIR_GET_CONSTANT(&_4$$5, "PHP_EOL");
			ZEPHIR_CONCAT_SV(return_value, "<div class=\"%cssClass%\">%message%</div>", &_4$$5);
			RETURN_MM();
		}
	}
	RETURN_MM_MEMBER(getThis(), "_customTemplate");

}

/**
 * Returns the message escaped if the autoEscape is true, otherwise the
 * original message is returned
 */
PHP_METHOD(Phalcon_Flash, prepareEscapedMessage) {

	zend_bool autoEscape = 0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *message_param = NULL, escaper, _0;
	zval message;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&escaper);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &message_param);

	zephir_get_strval(&message, message_param);


	ZEPHIR_OBS_VAR(&_0);
	zephir_read_property(&_0, this_ptr, SL("_autoescape"), PH_NOISY_CC);
	autoEscape = zephir_get_boolval(&_0);
	if (autoEscape == 1) {
		ZEPHIR_CALL_METHOD(&escaper, this_ptr, "getescaperservice", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_RETURN_CALL_METHOD(&escaper, "escapehtml", NULL, 0, &message);
		zephir_check_call_status();
		RETURN_MM();
	} else {
		RETURN_CTOR(&message);
	}

}

/**
 * Prepares the HTML output for the message. If automaticHtml is not set then
 * the original message is returned
 */
PHP_METHOD(Phalcon_Flash, prepareHtmlMessage) {

	zval _1$$3, _3$$3;
	zend_bool automaticHtml = 0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *type_param = NULL, *message_param = NULL, classes, cssClasses, typeClasses, _0, _2$$3, _4$$3;
	zval type, message;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&classes);
	ZVAL_UNDEF(&cssClasses);
	ZVAL_UNDEF(&typeClasses);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &type_param, &message_param);

	zephir_get_strval(&type, type_param);
	zephir_get_strval(&message, message_param);


	ZEPHIR_OBS_VAR(&_0);
	zephir_read_property(&_0, this_ptr, SL("_automaticHtml"), PH_NOISY_CC);
	automaticHtml = zephir_get_boolval(&_0);
	if (automaticHtml == 1) {
		ZEPHIR_OBS_VAR(&classes);
		zephir_read_property(&classes, this_ptr, SL("_cssClasses"), PH_NOISY_CC);
		ZEPHIR_OBS_VAR(&typeClasses);
		if (zephir_array_isset_fetch(&typeClasses, &classes, &type, 0 TSRMLS_CC)) {
			if (Z_TYPE_P(&typeClasses) == IS_ARRAY) {
				ZEPHIR_INIT_VAR(&cssClasses);
				zephir_fast_join_str(&cssClasses, SL(" "), &typeClasses TSRMLS_CC);
			} else {
				ZEPHIR_CPY_WRT(&cssClasses, &typeClasses);
			}
		} else {
			ZEPHIR_INIT_NVAR(&cssClasses);
			ZVAL_STRING(&cssClasses, "");
		}
		ZEPHIR_INIT_VAR(&_1$$3);
		zephir_create_array(&_1$$3, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "%cssClass%");
		zephir_array_fast_append(&_1$$3, &_2$$3);
		ZEPHIR_INIT_NVAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "%message%");
		zephir_array_fast_append(&_1$$3, &_2$$3);
		ZEPHIR_INIT_VAR(&_3$$3);
		zephir_create_array(&_3$$3, 2, 0 TSRMLS_CC);
		zephir_array_fast_append(&_3$$3, &cssClasses);
		zephir_array_fast_append(&_3$$3, &message);
		ZEPHIR_CALL_METHOD(&_4$$3, this_ptr, "gettemplate", NULL, 61, &cssClasses);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_2$$3);
		zephir_fast_str_replace(&_2$$3, &_1$$3, &_3$$3, &_4$$3 TSRMLS_CC);
		RETURN_CCTOR(&_2$$3);
	} else {
		RETURN_CTOR(&message);
	}

}

