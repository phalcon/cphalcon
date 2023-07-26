
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
 *
 * Class AbstractFlash
 *
 * @package Phalcon\Flash
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
	 * @var SessionInterface|null
	 */
	zend_declare_property_null(phalcon_flash_abstractflash_ce, SL("sessionService"), ZEND_ACC_PROTECTED);
	phalcon_flash_abstractflash_ce->create_object = zephir_init_properties_Phalcon_Flash_AbstractFlash;

	zend_class_implements(phalcon_flash_abstractflash_ce, 1, phalcon_flash_flashinterface_ce);
	return SUCCESS;
}

/**
 * AbstractFlash constructor.
 *
 * @param EscaperInterface|null $escaper
 * @param SessionInterface|null $session
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
		Z_PARAM_OBJECT_OF_CLASS_OR_NULL(escaper, phalcon_html_escaper_escaperinterface_ce)
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
 * @param string $message
 *
 * @return string|null
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
 * @return bool
 */
PHP_METHOD(Phalcon_Flash_AbstractFlash, getAutoescape)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "autoescape");
}

/**
 * @return bool
 */
PHP_METHOD(Phalcon_Flash_AbstractFlash, getAutomaticHtml)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "automaticHtml");
}

/**
 * @return array
 */
PHP_METHOD(Phalcon_Flash_AbstractFlash, getCssClasses)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "cssClasses");
}

/**
 * @return array
 */
PHP_METHOD(Phalcon_Flash_AbstractFlash, getCssIconClasses)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "cssIconClasses");
}

/**
 * @return string
 */
PHP_METHOD(Phalcon_Flash_AbstractFlash, getCustomTemplate)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "customTemplate");
}

/**
 * Returns the Escaper Service
 *
 * @return EscaperInterface
 * @throws Exception
 */
PHP_METHOD(Phalcon_Flash_AbstractFlash, getEscaperService)
{
	zend_bool _2;
	zval _0, _1, _3, _4, _5, _6$$4, _7$$4, _8$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$4);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("escaperService"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_0) != IS_NULL) {
		RETURN_MM_MEMBER(getThis(), "escaperService");
	}
	zephir_read_property(&_1, this_ptr, ZEND_STRL("container"), PH_NOISY_CC | PH_READONLY);
	_2 = Z_TYPE_P(&_1) != IS_NULL;
	if (_2) {
		zephir_read_property(&_3, this_ptr, ZEND_STRL("container"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_5);
		ZVAL_STRING(&_5, "escaper");
		ZEPHIR_CALL_METHOD(&_4, &_3, "has", NULL, 0, &_5);
		zephir_check_call_status();
		_2 = ZEPHIR_IS_TRUE_IDENTICAL(&_4);
	}
	if (_2) {
		zephir_read_property(&_6$$4, this_ptr, ZEND_STRL("container"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_8$$4);
		ZVAL_STRING(&_8$$4, "escaper");
		ZEPHIR_CALL_METHOD(&_7$$4, &_6$$4, "getshared", NULL, 0, &_8$$4);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, ZEND_STRL("escaperService"), &_7$$4);
		RETURN_MM_MEMBER(getThis(), "escaperService");
	}
	ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_flash_exception_ce, "A dependency injection container is required to access the 'escaper' service", "phalcon/Flash/AbstractFlash.zep", 194);
	return;
}

/**
 * Shows a HTML notice/information message
 *
 *```php
 * $flash->notice("This is an information");
 *```
 *
 * @param string $message
 *
 * @return string|null
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
 *
 * @param bool $autoescape
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
 *
 * @param bool $automaticHtml
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
 *
 * @param array $cssClasses
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
 *
 * @param array $cssIconClasses
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
 *
 * @param string $customTemplate
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
 *
 * @param EscaperInterface $escaperService
 */
PHP_METHOD(Phalcon_Flash_AbstractFlash, setEscaperService)
{
	zval *escaperService, escaperService_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&escaperService_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(escaperService, phalcon_html_escaper_escaperinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &escaperService);


	zephir_update_property_zval(this_ptr, ZEND_STRL("escaperService"), escaperService);
	RETURN_THISW();
}

/**
 * Set whether the output must be implicitly flushed to the output or
 * returned as string
 *
 * @param bool $implicitFlush
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
 * @param string $message
 *
 * @return string|null
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
 * @param string $type
 * @param mixed  $message
 *
 * @return string|null
 * @throws Exception
 */
PHP_METHOD(Phalcon_Flash_AbstractFlash, outputMessage)
{
	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_4 = NULL, *_5 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *type_param = NULL, *message = NULL, message_sub, content, html, item, prepared, *_2, _3, _1$$4, _6$$5, _7$$8;
	zval type;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&message_sub);
	ZVAL_UNDEF(&content);
	ZVAL_UNDEF(&html);
	ZVAL_UNDEF(&item);
	ZVAL_UNDEF(&prepared);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$8);
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
	ZEPHIR_SEPARATE_PARAM(message);


	ZEPHIR_INIT_VAR(&content);
	ZVAL_STRING(&content, "");
	_0 = Z_TYPE_P(message) != IS_ARRAY;
	if (_0) {
		_0 = Z_TYPE_P(message) != IS_STRING;
	}
	if (_0) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_flash_exception_ce, "The message must be an array or a string", "phalcon/Flash/AbstractFlash.zep", 334);
		return;
	}
	if (Z_TYPE_P(message) != IS_ARRAY) {
		ZEPHIR_INIT_VAR(&_1$$4);
		zephir_create_array(&_1$$4, 1, 0);
		zephir_array_fast_append(&_1$$4, message);
		ZEPHIR_CPY_WRT(message, &_1$$4);
	}
	zephir_is_iterable(message, 0, "phalcon/Flash/AbstractFlash.zep", 360);
	if (Z_TYPE_P(message) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(message), _2)
		{
			ZEPHIR_INIT_NVAR(&item);
			ZVAL_COPY(&item, _2);
			ZEPHIR_CALL_METHOD(&prepared, this_ptr, "prepareescapedmessage", &_4, 78, &item);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&html, this_ptr, "preparehtmlmessage", &_5, 79, &type, &prepared);
			zephir_check_call_status();
			zephir_read_property(&_6$$5, this_ptr, ZEND_STRL("implicitFlush"), PH_NOISY_CC | PH_READONLY);
			if (ZEPHIR_IS_TRUE_IDENTICAL(&_6$$5)) {
				zend_print_zval(&html, 0);
			} else {
				zephir_concat_self(&content, &html);
				zephir_update_property_array_append(this_ptr, SL("messages"), &html);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, message, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_3, message, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_3)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&item, message, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&prepared, this_ptr, "prepareescapedmessage", &_4, 78, &item);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&html, this_ptr, "preparehtmlmessage", &_5, 79, &type, &prepared);
				zephir_check_call_status();
				zephir_read_property(&_7$$8, this_ptr, ZEND_STRL("implicitFlush"), PH_NOISY_CC | PH_READONLY);
				if (ZEPHIR_IS_TRUE_IDENTICAL(&_7$$8)) {
					zend_print_zval(&html, 0);
				} else {
					zephir_concat_self(&content, &html);
					zephir_update_property_array_append(this_ptr, SL("messages"), &html);
				}
			ZEPHIR_CALL_METHOD(NULL, message, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&item);
	RETURN_CCTOR(&content);
}

/**
 * Shows a HTML warning message
 *
 *```php
 * $flash->warning("Hey, this is important");
 *```
 *
 * @param string $message
 *
 * @return string|null
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
 * Returns the template for the CSS classes (with icon classes). It will
 * either be the custom one (defined) or the default
 *
 * @param string $cssClasses
 * @param string $cssIconClasses
 *
 * @return string
 */
PHP_METHOD(Phalcon_Flash_AbstractFlash, getTemplate)
{
	zval _4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *cssClassses_param = NULL, *cssIconClasses_param = NULL, _0, _1, _2, _3;
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
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
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
	if (!(ZEPHIR_IS_EMPTY(&cssClassses))) {
		ZEPHIR_INIT_NVAR(&divString);
		ZVAL_STRING(&divString, " class=\"%cssClass%\"");
		if (!(ZEPHIR_IS_EMPTY(&cssIconClasses))) {
			ZEPHIR_INIT_NVAR(&iconString);
			ZVAL_STRING(&iconString, "<i class=\"%cssIconClass%\"></i> ");
		}
	}
	zephir_read_property(&_3, this_ptr, ZEND_STRL("interpolator"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_4);
	zephir_create_array(&_4, 2, 0);
	zephir_array_update_string(&_4, SL("divString"), &divString, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_4, SL("iconString"), &iconString, PH_COPY | PH_SEPARATE);
	ZEPHIR_RETURN_CALL_METHOD(&_3, "__invoke", NULL, 0, &template, &_4);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Returns the message escaped if the autoEscape is true, otherwise the
 * original message is returned
 *
 * @param string $message
 *
 * @return string
 * @throws Exception
 */
PHP_METHOD(Phalcon_Flash_AbstractFlash, prepareEscapedMessage)
{
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


	zephir_read_property(&_0, this_ptr, ZEND_STRL("autoescape"), PH_NOISY_CC | PH_READONLY);
	if (!ZEPHIR_IS_TRUE_IDENTICAL(&_0)) {
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
 *
 * @param string $type
 * @param string $message
 *
 * @return string
 */
PHP_METHOD(Phalcon_Flash_AbstractFlash, prepareHtmlMessage)
{
	zval _5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *type_param = NULL, *message_param = NULL, cssClasses, cssIconClasses, _0, _1, _2, _3, _4;
	zval type, message;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&cssClasses);
	ZVAL_UNDEF(&cssIconClasses);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
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
	if (!ZEPHIR_IS_TRUE_IDENTICAL(&_0)) {
		RETURN_CTOR(&message);
	}
	zephir_read_property(&_1, this_ptr, ZEND_STRL("cssClasses"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&cssClasses, this_ptr, "checkclasses", NULL, 80, &_1, &type);
	zephir_check_call_status();
	zephir_read_property(&_2, this_ptr, ZEND_STRL("cssIconClasses"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&cssIconClasses, this_ptr, "checkclasses", NULL, 80, &_2, &type);
	zephir_check_call_status();
	zephir_read_property(&_3, this_ptr, ZEND_STRL("interpolator"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_4, this_ptr, "gettemplate", NULL, 81, &cssClasses, &cssIconClasses);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_5);
	zephir_create_array(&_5, 3, 0);
	zephir_array_update_string(&_5, SL("cssClass"), &cssClasses, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_5, SL("cssIconClass"), &cssIconClasses, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_5, SL("message"), &message, PH_COPY | PH_SEPARATE);
	ZEPHIR_RETURN_CALL_METHOD(&_3, "__invoke", NULL, 0, &_4, &_5);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Checks the collection and returns the content as a string
 * (array is joined)
 *
 * @param array  $collection
 * @param string $type
 *
 * @return string
 */
PHP_METHOD(Phalcon_Flash_AbstractFlash, checkClasses)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval type;
	zval *collection_param = NULL, *type_param = NULL, content, _0$$5, _1$$4;
	zval collection;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&collection);
	ZVAL_UNDEF(&content);
	ZVAL_UNDEF(&_0$$5);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&type);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ARRAY(collection)
		Z_PARAM_STR(type)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &collection_param, &type_param);
	zephir_get_arrval(&collection, collection_param);
	zephir_get_strval(&type, type_param);


	ZEPHIR_INIT_VAR(&content);
	ZVAL_STRING(&content, "");
	if (zephir_array_isset(&collection, &type)) {
		ZEPHIR_OBS_NVAR(&content);
		zephir_array_fetch(&content, &collection, &type, PH_NOISY, "phalcon/Flash/AbstractFlash.zep", 484);
	}
	if (1 != ZEPHIR_IS_EMPTY(&content)) {
		if (Z_TYPE_P(&content) != IS_ARRAY) {
			ZEPHIR_INIT_VAR(&_0$$5);
			zephir_create_array(&_0$$5, 1, 0);
			zephir_array_fast_append(&_0$$5, &content);
			ZEPHIR_CPY_WRT(&content, &_0$$5);
		}
		ZEPHIR_INIT_VAR(&_1$$4);
		zephir_fast_join_str(&_1$$4, SL(" "), &content);
		ZEPHIR_CPY_WRT(&content, &_1$$4);
	}
	RETURN_CCTOR(&content);
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

