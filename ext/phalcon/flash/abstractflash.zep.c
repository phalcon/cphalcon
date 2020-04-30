
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/concat.h"
#include "kernel/string.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Shows HTML notifications related to different circumstances. Classes can be
 * stylized using CSS
 *
 *```php
 * $flash->success("The record was successfully deleted");
 * $flash->error("Cannot open the file");
 *```
 */
ZEPHIR_INIT_CLASS(Phalcon_Flash_AbstractFlash) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Flash, AbstractFlash, phalcon, flash_abstractflash, phalcon_di_abstractinjectionaware_ce, phalcon_flash_abstractflash_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/**
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_flash_abstractflash_ce, SL("autoescape"), 1, ZEND_ACC_PROTECTED);

	/**
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_flash_abstractflash_ce, SL("automaticHtml"), 1, ZEND_ACC_PROTECTED);

	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_flash_abstractflash_ce, SL("cssClasses"), ZEND_ACC_PROTECTED);

	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_flash_abstractflash_ce, SL("customTemplate"), "", ZEND_ACC_PROTECTED);

	/**
	 * @var EscaperInterface | null
	 */
	zend_declare_property_null(phalcon_flash_abstractflash_ce, SL("escaperService"), ZEND_ACC_PROTECTED);

	/**
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_flash_abstractflash_ce, SL("implicitFlush"), 1, ZEND_ACC_PROTECTED);

	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_flash_abstractflash_ce, SL("messages"), ZEND_ACC_PROTECTED);

	/**
	 * @var SessionInterface | null
	 */
	zend_declare_property_null(phalcon_flash_abstractflash_ce, SL("sessionService"), ZEND_ACC_PROTECTED);

	phalcon_flash_abstractflash_ce->create_object = zephir_init_properties_Phalcon_Flash_AbstractFlash;

	zend_class_implements(phalcon_flash_abstractflash_ce, 1, phalcon_flash_flashinterface_ce);
	return SUCCESS;

}

/**
 */
PHP_METHOD(Phalcon_Flash_AbstractFlash, getAutoescape) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "autoescape");

}

/**
 */
PHP_METHOD(Phalcon_Flash_AbstractFlash, getCssClasses) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "cssClasses");

}

/**
 */
PHP_METHOD(Phalcon_Flash_AbstractFlash, getCustomTemplate) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "customTemplate");

}

/**
 * Phalcon\Flash constructor
 */
PHP_METHOD(Phalcon_Flash_AbstractFlash, __construct) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *escaper = NULL, escaper_sub, *session = NULL, session_sub, __$null;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&escaper_sub);
	ZVAL_UNDEF(&session_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &escaper, &session);

	if (!escaper) {
		escaper = &escaper_sub;
		escaper = &__$null;
	}
	if (!session) {
		session = &session_sub;
		session = &__$null;
	}


	zephir_update_property_zval(this_ptr, ZEND_STRL("escaperService"), escaper);
	zephir_update_property_zval(this_ptr, ZEND_STRL("sessionService"), session);
	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 4, 0);
	add_assoc_stringl_ex(&_0, SL("error"), SL("errorMessage"));
	add_assoc_stringl_ex(&_0, SL("notice"), SL("noticeMessage"));
	add_assoc_stringl_ex(&_0, SL("success"), SL("successMessage"));
	add_assoc_stringl_ex(&_0, SL("warning"), SL("warningMessage"));
	zephir_update_property_zval(this_ptr, ZEND_STRL("cssClasses"), &_0);
	ZEPHIR_MM_RESTORE();

}

/**
 * Clears accumulated messages when implicit flush is disabled
 */
PHP_METHOD(Phalcon_Flash_AbstractFlash, clear) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	zephir_update_property_zval(this_ptr, ZEND_STRL("messages"), &_0);
	ZEPHIR_MM_RESTORE();

}

/**
 * Shows a HTML error message
 *
 *```php
 * $flash->error("This is an error");
 *```
 */
PHP_METHOD(Phalcon_Flash_AbstractFlash, error) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
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
 * Returns the Escaper Service
 */
PHP_METHOD(Phalcon_Flash_AbstractFlash, getEscaperService) {

	zval container, _0, _1, _6, _7, _2$$4, _3$$4, _5$$4, _8$$5, _9$$5, _10$$6, _11$$6, _12$$6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_4 = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&container);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_UNDEF(&_11$$6);
	ZVAL_UNDEF(&_12$$6);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("escaperService"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_0)) {
		RETURN_MM_MEMBER(getThis(), "escaperService");
	}
	zephir_read_property(&_1, this_ptr, SL("container"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&container, &_1);
	if (UNEXPECTED(Z_TYPE_P(&container) != IS_OBJECT)) {
		ZEPHIR_INIT_VAR(&_2$$4);
		object_init_ex(&_2$$4, phalcon_flash_exception_ce);
		ZEPHIR_INIT_VAR(&_5$$4);
		ZVAL_STRING(&_5$$4, "the 'escaper' service");
		ZEPHIR_CALL_CE_STATIC(&_3$$4, phalcon_flash_exception_ce, "containerservicenotfound", &_4, 0, &_5$$4);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_2$$4, "__construct", NULL, 6, &_3$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_2$$4, "phalcon/Flash/AbstractFlash.zep", 121);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&_7);
	ZVAL_STRING(&_7, "escaper");
	ZEPHIR_CALL_METHOD(&_6, &container, "has", NULL, 0, &_7);
	zephir_check_call_status();
	if (UNEXPECTED(zephir_is_true(&_6))) {
		ZEPHIR_INIT_VAR(&_9$$5);
		ZVAL_STRING(&_9$$5, "escaper");
		ZEPHIR_CALL_METHOD(&_8$$5, &container, "getshared", NULL, 0, &_9$$5);
		zephir_check_call_status();
		RETURN_CCTOR(&_8$$5);
	} else {
		ZEPHIR_INIT_VAR(&_10$$6);
		object_init_ex(&_10$$6, phalcon_flash_exception_ce);
		ZEPHIR_INIT_VAR(&_12$$6);
		ZVAL_STRING(&_12$$6, "the 'escaper' service");
		ZEPHIR_CALL_CE_STATIC(&_11$$6, phalcon_flash_exception_ce, "containerservicenotfound", &_4, 0, &_12$$6);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_10$$6, "__construct", NULL, 6, &_11$$6);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_10$$6, "phalcon/Flash/AbstractFlash.zep", 129);
		ZEPHIR_MM_RESTORE();
		return;
	}

}

/**
 * Shows a HTML notice/information message
 *
 *```php
 * $flash->notice("This is an information");
 *```
 */
PHP_METHOD(Phalcon_Flash_AbstractFlash, notice) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
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
 * Set the autoescape mode in generated HTML
 */
PHP_METHOD(Phalcon_Flash_AbstractFlash, setAutoescape) {

	zval *autoescape_param = NULL, __$true, __$false;
	zend_bool autoescape;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);

	zephir_fetch_params_without_memory_grow(1, 0, &autoescape_param);

	autoescape = zephir_get_boolval(autoescape_param);


	if (autoescape) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("autoescape"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("autoescape"), &__$false);
	}
	RETURN_THISW();

}

/**
 * Set if the output must be implicitly formatted with HTML
 */
PHP_METHOD(Phalcon_Flash_AbstractFlash, setAutomaticHtml) {

	zval *automaticHtml_param = NULL, __$true, __$false;
	zend_bool automaticHtml;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);

	zephir_fetch_params_without_memory_grow(1, 0, &automaticHtml_param);

	automaticHtml = zephir_get_boolval(automaticHtml_param);


	if (automaticHtml) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("automaticHtml"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("automaticHtml"), &__$false);
	}
	RETURN_THISW();

}

/**
 * Set an array with CSS classes to format the messages
 */
PHP_METHOD(Phalcon_Flash_AbstractFlash, setCssClasses) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *cssClasses_param = NULL;
	zval cssClasses;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&cssClasses);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &cssClasses_param);

	ZEPHIR_OBS_COPY_OR_DUP(&cssClasses, cssClasses_param);


	zephir_update_property_zval(this_ptr, ZEND_STRL("cssClasses"), &cssClasses);
	RETURN_THIS();

}

/**
 * Set an custom template for showing the messages
 */
PHP_METHOD(Phalcon_Flash_AbstractFlash, setCustomTemplate) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *customTemplate_param = NULL;
	zval customTemplate;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&customTemplate);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &customTemplate_param);

	if (UNEXPECTED(Z_TYPE_P(customTemplate_param) != IS_STRING && Z_TYPE_P(customTemplate_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'customTemplate' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(customTemplate_param) == IS_STRING)) {
		zephir_get_strval(&customTemplate, customTemplate_param);
	} else {
		ZEPHIR_INIT_VAR(&customTemplate);
		ZVAL_EMPTY_STRING(&customTemplate);
	}


	zephir_update_property_zval(this_ptr, ZEND_STRL("customTemplate"), &customTemplate);
	RETURN_THIS();

}

/**
 * Sets the Escaper Service
 */
PHP_METHOD(Phalcon_Flash_AbstractFlash, setEscaperService) {

	zval *escaperService, escaperService_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&escaperService_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &escaperService);



	zephir_update_property_zval(this_ptr, ZEND_STRL("escaperService"), escaperService);
	RETURN_THISW();

}

/**
 * Set whether the output must be implicitly flushed to the output or
 * returned as string
 */
PHP_METHOD(Phalcon_Flash_AbstractFlash, setImplicitFlush) {

	zval *implicitFlush_param = NULL, __$true, __$false;
	zend_bool implicitFlush;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);

	zephir_fetch_params_without_memory_grow(1, 0, &implicitFlush_param);

	implicitFlush = zephir_get_boolval(implicitFlush_param);


	if (implicitFlush) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("implicitFlush"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("implicitFlush"), &__$false);
	}
	RETURN_THISW();

}

/**
 * Shows a HTML success message
 *
 *```php
 * $flash->success("The process was finished successfully");
 *```
 */
PHP_METHOD(Phalcon_Flash_AbstractFlash, success) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
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
 *```php
 * $flash->outputMessage("error", $message);
 *```
 *
 * @param string|array message
 * @return string|void
 */
PHP_METHOD(Phalcon_Flash_AbstractFlash, outputMessage) {

	zend_bool implicitFlush = 0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
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
	zephir_read_property(&_0, this_ptr, SL("implicitFlush"), PH_NOISY_CC);
	implicitFlush = zephir_get_boolval(&_0);
	if (Z_TYPE_P(message) == IS_ARRAY) {
		if (!(implicitFlush)) {
			ZEPHIR_INIT_VAR(&content);
			ZVAL_STRING(&content, "");
		}
		zephir_is_iterable(message, 0, "phalcon/Flash/AbstractFlash.zep", 269);
		if (Z_TYPE_P(message) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(message), _1$$3)
			{
				ZEPHIR_INIT_NVAR(&msg);
				ZVAL_COPY(&msg, _1$$3);
				ZEPHIR_CALL_METHOD(&preparedMsg, this_ptr, "prepareescapedmessage", &_3, 98, &msg);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&htmlMessage, this_ptr, "preparehtmlmessage", &_4, 99, &type, &preparedMsg);
				zephir_check_call_status();
				if (implicitFlush) {
					zend_print_zval(&htmlMessage, 0);
				} else {
					zephir_concat_self(&content, &htmlMessage);
					zephir_update_property_array_append(this_ptr, SL("messages"), &htmlMessage);
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
					ZEPHIR_CALL_METHOD(&preparedMsg, this_ptr, "prepareescapedmessage", &_3, 98, &msg);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&htmlMessage, this_ptr, "preparehtmlmessage", &_4, 99, &type, &preparedMsg);
					zephir_check_call_status();
					if (implicitFlush) {
						zend_print_zval(&htmlMessage, 0);
					} else {
						zephir_concat_self(&content, &htmlMessage);
						zephir_update_property_array_append(this_ptr, SL("messages"), &htmlMessage);
					}
				ZEPHIR_CALL_METHOD(NULL, message, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&msg);
		if (!(implicitFlush)) {
			RETURN_CCTOR(&content);
		}
	} else {
		ZEPHIR_CALL_METHOD(&preparedMsg, this_ptr, "prepareescapedmessage", &_3, 98, message);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&htmlMessage, this_ptr, "preparehtmlmessage", &_4, 99, &type, &preparedMsg);
		zephir_check_call_status();
		if (implicitFlush) {
			zend_print_zval(&htmlMessage, 0);
		} else {
			zephir_update_property_array_append(this_ptr, SL("messages"), &htmlMessage);
			RETURN_CCTOR(&htmlMessage);
		}
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Shows a HTML warning message
 *
 *```php
 * $flash->warning("Hey, this is important");
 *```
 */
PHP_METHOD(Phalcon_Flash_AbstractFlash, warning) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
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

PHP_METHOD(Phalcon_Flash_AbstractFlash, getTemplate) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
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


	zephir_read_property(&_0, this_ptr, SL("customTemplate"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "");
	if (ZEPHIR_IS_IDENTICAL(&_1, &_0)) {
		ZEPHIR_INIT_VAR(&_2$$3);
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
	RETURN_MM_MEMBER(getThis(), "customTemplate");

}

/**
 * Returns the message escaped if the autoEscape is true, otherwise the
 * original message is returned
 */
PHP_METHOD(Phalcon_Flash_AbstractFlash, prepareEscapedMessage) {

	zend_bool autoEscape = 0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
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
	zephir_read_property(&_0, this_ptr, SL("autoescape"), PH_NOISY_CC);
	autoEscape = zephir_get_boolval(&_0);
	if (!(autoEscape)) {
		RETURN_CTOR(&message);
	}
	ZEPHIR_CALL_METHOD(&escaper, this_ptr, "getescaperservice", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&escaper, "escapehtml", NULL, 0, &message);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Prepares the HTML output for the message. If automaticHtml is not set
 * then the original message is returned
 */
PHP_METHOD(Phalcon_Flash_AbstractFlash, prepareHtmlMessage) {

	zval _1, _3;
	zend_bool automaticHtml = 0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *type_param = NULL, *message_param = NULL, classes, cssClasses, typeClasses, _0, _2, _4;
	zval type, message;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&classes);
	ZVAL_UNDEF(&cssClasses);
	ZVAL_UNDEF(&typeClasses);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &type_param, &message_param);

	zephir_get_strval(&type, type_param);
	zephir_get_strval(&message, message_param);


	ZEPHIR_OBS_VAR(&_0);
	zephir_read_property(&_0, this_ptr, SL("automaticHtml"), PH_NOISY_CC);
	automaticHtml = zephir_get_boolval(&_0);
	if (!(automaticHtml)) {
		RETURN_CTOR(&message);
	}
	ZEPHIR_OBS_VAR(&classes);
	zephir_read_property(&classes, this_ptr, SL("cssClasses"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(&typeClasses);
	if (zephir_array_isset_fetch(&typeClasses, &classes, &type, 0)) {
		if (Z_TYPE_P(&typeClasses) == IS_ARRAY) {
			ZEPHIR_INIT_VAR(&cssClasses);
			zephir_fast_join_str(&cssClasses, SL(" "), &typeClasses);
		} else {
			ZEPHIR_CPY_WRT(&cssClasses, &typeClasses);
		}
	} else {
		ZEPHIR_INIT_NVAR(&cssClasses);
		ZVAL_STRING(&cssClasses, "");
	}
	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 2, 0);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "%cssClass%");
	zephir_array_fast_append(&_1, &_2);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "%message%");
	zephir_array_fast_append(&_1, &_2);
	ZEPHIR_INIT_VAR(&_3);
	zephir_create_array(&_3, 2, 0);
	zephir_array_fast_append(&_3, &cssClasses);
	zephir_array_fast_append(&_3, &message);
	ZEPHIR_CALL_METHOD(&_4, this_ptr, "gettemplate", NULL, 100, &cssClasses);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_2);
	zephir_fast_str_replace(&_2, &_1, &_3, &_4);
	RETURN_CCTOR(&_2);

}

zend_object *zephir_init_properties_Phalcon_Flash_AbstractFlash(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _2, _1$$3, _3$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("messages"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zend_update_property(Z_OBJCE_P(this_ptr), this_ptr, ZEND_STRL("messages"), &_1$$3);
		}
		zephir_read_property(&_2, this_ptr, SL("cssClasses"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zend_update_property(Z_OBJCE_P(this_ptr), this_ptr, ZEND_STRL("cssClasses"), &_3$$4);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

