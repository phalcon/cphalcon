
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
#include "kernel/fcall.h"
#include "kernel/array.h"
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
 * For the full copyright and license information, please view the
 * LICENSE.txt file that was distributed with this source code.
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
ZEPHIR_INIT_CLASS(Phalcon_Flash_AbstractFlash)
{
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
	 * @var array
	 */
	zend_declare_property_null(phalcon_flash_abstractflash_ce, SL("cssIconClasses"), ZEND_ACC_PROTECTED);
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
	 * @var Interpolate
	 */
	zend_declare_property_null(phalcon_flash_abstractflash_ce, SL("interpolator"), ZEND_ACC_PROTECTED);
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
PHP_METHOD(Phalcon_Flash_AbstractFlash, getAutoescape)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "autoescape");
}

/**
 */
PHP_METHOD(Phalcon_Flash_AbstractFlash, getCssClasses)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "cssClasses");
}

/**
 */
PHP_METHOD(Phalcon_Flash_AbstractFlash, getCssIconClasses)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "cssIconClasses");
}

/**
 */
PHP_METHOD(Phalcon_Flash_AbstractFlash, getCustomTemplate)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "customTemplate");
}

/**
 * Phalcon\Flash constructor
 */
PHP_METHOD(Phalcon_Flash_AbstractFlash, __construct)
{
	zval _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *escaper = NULL, escaper_sub, *session = NULL, session_sub, __$null, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&escaper_sub);
	ZVAL_UNDEF(&session_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 2)
		Z_PARAM_OPTIONAL
		Z_PARAM_OBJECT_OF_CLASS_OR_NULL(escaper, phalcon_escaper_escaperinterface_ce)
		Z_PARAM_OBJECT_OF_CLASS_OR_NULL(session, phalcon_session_managerinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
#endif


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
	object_init_ex(&_0, phalcon_support_helper_str_interpolate_ce);
	if (zephir_has_constructor(&_0)) {
		ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 0);
		zephir_check_call_status();
	}

	zephir_update_property_zval(this_ptr, ZEND_STRL("interpolator"), &_0);
	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 4, 0);
	add_assoc_stringl_ex(&_1, SL("error"), SL("errorMessage"));
	add_assoc_stringl_ex(&_1, SL("notice"), SL("noticeMessage"));
	add_assoc_stringl_ex(&_1, SL("success"), SL("successMessage"));
	add_assoc_stringl_ex(&_1, SL("warning"), SL("warningMessage"));
	zephir_update_property_zval(this_ptr, ZEND_STRL("cssClasses"), &_1);
	ZEPHIR_MM_RESTORE();
}

/**
 * Clears accumulated messages when implicit flush is disabled
 */
PHP_METHOD(Phalcon_Flash_AbstractFlash, clear)
{
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
 *
 * @return null|string|void
 */
PHP_METHOD(Phalcon_Flash_AbstractFlash, error)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *message_param = NULL, _0;
	zval message;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(message)
	ZEND_PARSE_PARAMETERS_END();
#endif


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
PHP_METHOD(Phalcon_Flash_AbstractFlash, getEscaperService)
{
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

	zephir_read_property(&_0, this_ptr, ZEND_STRL("escaperService"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_0)) {
		RETURN_MM_MEMBER(getThis(), "escaperService");
	}
	zephir_read_property(&_1, this_ptr, ZEND_STRL("container"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&container, &_1);
	if (UNEXPECTED(Z_TYPE_P(&container) != IS_OBJECT)) {
		ZEPHIR_INIT_VAR(&_2$$4);
		object_init_ex(&_2$$4, phalcon_flash_exception_ce);
		ZEPHIR_INIT_VAR(&_5$$4);
		ZVAL_STRING(&_5$$4, "the 'escaper' service");
		ZEPHIR_CALL_CE_STATIC(&_3$$4, phalcon_flash_exception_ce, "containerservicenotfound", &_4, 0, &_5$$4);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_2$$4, "__construct", NULL, 8, &_3$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_2$$4, "phalcon/Flash/AbstractFlash.zep", 135);
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
		ZEPHIR_CALL_METHOD(NULL, &_10$$6, "__construct", NULL, 8, &_11$$6);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_10$$6, "phalcon/Flash/AbstractFlash.zep", 143);
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
 *
 * @return null|string|void
 */
PHP_METHOD(Phalcon_Flash_AbstractFlash, notice)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *message_param = NULL, _0;
	zval message;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(message)
	ZEND_PARSE_PARAMETERS_END();
#endif


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
PHP_METHOD(Phalcon_Flash_AbstractFlash, setAutoescape)
{
	zval *autoescape_param = NULL, __$true, __$false;
	zend_bool autoescape;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(autoescape)
	ZEND_PARSE_PARAMETERS_END();
#endif


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
PHP_METHOD(Phalcon_Flash_AbstractFlash, setAutomaticHtml)
{
	zval *automaticHtml_param = NULL, __$true, __$false;
	zend_bool automaticHtml;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(automaticHtml)
	ZEND_PARSE_PARAMETERS_END();
#endif


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
PHP_METHOD(Phalcon_Flash_AbstractFlash, setCssClasses)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *cssClasses_param = NULL;
	zval cssClasses;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&cssClasses);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(cssClasses)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &cssClasses_param);
	ZEPHIR_OBS_COPY_OR_DUP(&cssClasses, cssClasses_param);


	zephir_update_property_zval(this_ptr, ZEND_STRL("cssClasses"), &cssClasses);
	RETURN_THIS();
}

/**
 * Set an array with CSS classes to format the icon messages
 */
PHP_METHOD(Phalcon_Flash_AbstractFlash, setCssIconClasses)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *cssIconClasses_param = NULL;
	zval cssIconClasses;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&cssIconClasses);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(cssIconClasses)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &cssIconClasses_param);
	ZEPHIR_OBS_COPY_OR_DUP(&cssIconClasses, cssIconClasses_param);


	zephir_update_property_zval(this_ptr, ZEND_STRL("cssIconClasses"), &cssIconClasses);
	RETURN_THIS();
}

/**
 * Set a custom template for showing the messages
 */
PHP_METHOD(Phalcon_Flash_AbstractFlash, setCustomTemplate)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *customTemplate_param = NULL;
	zval customTemplate;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&customTemplate);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(customTemplate)
	ZEND_PARSE_PARAMETERS_END();
#endif


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
	}


	zephir_update_property_zval(this_ptr, ZEND_STRL("customTemplate"), &customTemplate);
	RETURN_THIS();
}

/**
 * Sets the Escaper Service
 */
PHP_METHOD(Phalcon_Flash_AbstractFlash, setEscaperService)
{
	zval *escaperService, escaperService_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&escaperService_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(escaperService, phalcon_escaper_escaperinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &escaperService);


	zephir_update_property_zval(this_ptr, ZEND_STRL("escaperService"), escaperService);
	RETURN_THISW();
}

/**
 * Set whether the output must be implicitly flushed to the output or
 * returned as string
 */
PHP_METHOD(Phalcon_Flash_AbstractFlash, setImplicitFlush)
{
	zval *implicitFlush_param = NULL, __$true, __$false;
	zend_bool implicitFlush;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(implicitFlush)
	ZEND_PARSE_PARAMETERS_END();
#endif


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
 *
 * @return null|string|void
 */
PHP_METHOD(Phalcon_Flash_AbstractFlash, success)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *message_param = NULL, _0;
	zval message;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(message)
	ZEND_PARSE_PARAMETERS_END();
#endif


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
 * @return null|string|void
 */
PHP_METHOD(Phalcon_Flash_AbstractFlash, outputMessage)
{
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
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(type)
		Z_PARAM_ZVAL(message)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &type_param, &message);
	zephir_get_strval(&type, type_param);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("implicitFlush"), PH_NOISY_CC | PH_READONLY);
	implicitFlush = zephir_is_true(&_0);
	if (Z_TYPE_P(message) == IS_ARRAY) {
		if (!(implicitFlush)) {
			ZEPHIR_INIT_VAR(&content);
			ZVAL_STRING(&content, "");
		}
		zephir_is_iterable(message, 0, "phalcon/Flash/AbstractFlash.zep", 297);
		if (Z_TYPE_P(message) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(message), _1$$3)
			{
				ZEPHIR_INIT_NVAR(&msg);
				ZVAL_COPY(&msg, _1$$3);
				ZEPHIR_CALL_METHOD(&preparedMsg, this_ptr, "prepareescapedmessage", &_3, 103, &msg);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&htmlMessage, this_ptr, "preparehtmlmessage", &_4, 104, &type, &preparedMsg);
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
					ZEPHIR_CALL_METHOD(&preparedMsg, this_ptr, "prepareescapedmessage", &_3, 103, &msg);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&htmlMessage, this_ptr, "preparehtmlmessage", &_4, 104, &type, &preparedMsg);
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
		ZEPHIR_CALL_METHOD(&preparedMsg, this_ptr, "prepareescapedmessage", &_3, 103, message);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&htmlMessage, this_ptr, "preparehtmlmessage", &_4, 104, &type, &preparedMsg);
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
 *
 * @return null|string|void
 */
PHP_METHOD(Phalcon_Flash_AbstractFlash, warning)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *message_param = NULL, _0;
	zval message;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(message)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &message_param);
	zephir_get_strval(&message, message_param);


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "warning");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "message", NULL, 0, &_0, &message);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Gets the template (custom or default)
 */
PHP_METHOD(Phalcon_Flash_AbstractFlash, getTemplate)
{
	zval _5;
	zend_bool _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *cssClassses_param = NULL, *cssIconClasses_param = NULL, _0, _1, _2, _4;
	zval cssClassses, cssIconClasses, divString, iconString, template;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&cssClassses);
	ZVAL_UNDEF(&cssIconClasses);
	ZVAL_UNDEF(&divString);
	ZVAL_UNDEF(&iconString);
	ZVAL_UNDEF(&template);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(cssClassses)
		Z_PARAM_STR(cssIconClasses)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &cssClassses_param, &cssIconClasses_param);
	zephir_get_strval(&cssClassses, cssClassses_param);
	zephir_get_strval(&cssIconClasses, cssIconClasses_param);


	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_GET_CONSTANT(&_0, "PHP_EOL");
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_CONCAT_SV(&_1, "<div%divString%>%iconString%%message%</div>", &_0);
	zephir_get_strval(&template, &_1);
	ZEPHIR_INIT_VAR(&divString);
	ZEPHIR_INIT_VAR(&iconString);
	zephir_read_property(&_2, this_ptr, ZEND_STRL("customTemplate"), PH_NOISY_CC | PH_READONLY);
	if (!(ZEPHIR_IS_EMPTY(&_2))) {
		RETURN_MM_MEMBER(getThis(), "customTemplate");
	}
	_3 = !(ZEPHIR_IS_EMPTY(&cssClassses));
	if (!(_3)) {
		_3 = !(ZEPHIR_IS_EMPTY(&cssIconClasses));
	}
	if (_3) {
		ZEPHIR_INIT_NVAR(&divString);
		ZVAL_STRING(&divString, " class=\"%cssClass%\"");
		if (!(ZEPHIR_IS_EMPTY(&cssIconClasses))) {
			ZEPHIR_INIT_NVAR(&iconString);
			ZVAL_STRING(&iconString, "<i class=\"%cssIconClasses%\"></i> ");
		}
	}
	zephir_read_property(&_4, this_ptr, ZEND_STRL("interpolator"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_5);
	zephir_create_array(&_5, 2, 0);
	zephir_array_update_string(&_5, SL("divString"), &divString, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_5, SL("iconString"), &iconString, PH_COPY | PH_SEPARATE);
	ZEPHIR_RETURN_CALL_METHOD(&_4, "__invoke", NULL, 0, &template, &_5);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Returns the message escaped if the autoEscape is true, otherwise the
 * original message is returned
 */
PHP_METHOD(Phalcon_Flash_AbstractFlash, prepareEscapedMessage)
{
	zend_bool autoEscape = 0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *message_param = NULL, escaper, _0;
	zval message;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&escaper);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(message)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &message_param);
	zephir_get_strval(&message, message_param);


	ZEPHIR_OBS_VAR(&_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("autoescape"), PH_NOISY_CC);
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
PHP_METHOD(Phalcon_Flash_AbstractFlash, prepareHtmlMessage)
{
	zval _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *type_param = NULL, *message_param = NULL, classes, cssClasses, cssIconClasses, typeClasses, typeIconClasses, automaticHtml, _0, _1;
	zval type, message;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&classes);
	ZVAL_UNDEF(&cssClasses);
	ZVAL_UNDEF(&cssIconClasses);
	ZVAL_UNDEF(&typeClasses);
	ZVAL_UNDEF(&typeIconClasses);
	ZVAL_UNDEF(&automaticHtml);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(type)
		Z_PARAM_STR(message)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &type_param, &message_param);
	zephir_get_strval(&type, type_param);
	zephir_get_strval(&message, message_param);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("automaticHtml"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&automaticHtml, &_0);
	if (!ZEPHIR_IS_TRUE_IDENTICAL(&automaticHtml)) {
		RETURN_CTOR(&message);
	}
	ZEPHIR_OBS_VAR(&classes);
	zephir_read_property(&classes, this_ptr, ZEND_STRL("cssClasses"), PH_NOISY_CC);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("cssIconClasses"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&cssIconClasses, &_0);
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
	ZEPHIR_OBS_VAR(&typeIconClasses);
	if (zephir_array_isset_fetch(&typeIconClasses, &cssIconClasses, &type, 0)) {
		if (Z_TYPE_P(&typeIconClasses) == IS_ARRAY) {
			ZEPHIR_INIT_NVAR(&cssIconClasses);
			zephir_fast_join_str(&cssIconClasses, SL(" "), &typeIconClasses);
		} else {
			ZEPHIR_CPY_WRT(&cssIconClasses, &typeIconClasses);
		}
	} else {
		ZEPHIR_INIT_NVAR(&cssIconClasses);
		ZVAL_STRING(&cssIconClasses, "");
	}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("interpolator"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "gettemplate", NULL, 105, &cssClasses, &cssIconClasses);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	zephir_create_array(&_2, 3, 0);
	zephir_array_update_string(&_2, SL("cssClass"), &cssClasses, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_2, SL("iconCssClass"), &cssIconClasses, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_2, SL("message"), &message, PH_COPY | PH_SEPARATE);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "__invoke", NULL, 0, &_1, &_2);
	zephir_check_call_status();
	RETURN_MM();
}

zend_object *zephir_init_properties_Phalcon_Flash_AbstractFlash(zend_class_entry *class_type)
{
		zval _0, _2, _4, _1$$3, _3$$4, _5$$5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$5);
	

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("messages"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("messages"), &_1$$3);
		}
		zephir_read_property_ex(&_2, this_ptr, ZEND_STRL("cssIconClasses"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("cssIconClasses"), &_3$$4);
		}
		zephir_read_property_ex(&_4, this_ptr, ZEND_STRL("cssClasses"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_4) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_5$$5);
			array_init(&_5$$5);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("cssClasses"), &_5$$5);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}

