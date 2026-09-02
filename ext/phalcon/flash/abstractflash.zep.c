
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
#include "kernel/string.h"
#include "kernel/concat.h"


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
 * @phpstan-import-type flash_messages from FlashTypes
 * @phpstan-import-type flash_css_classes from FlashTypes
 */
ZEPHIR_INIT_CLASS(Phalcon_Flash_AbstractFlash)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Flash, AbstractFlash, phalcon, flash_abstractflash, phalcon_di_abstractinjectionaware_ce, phalcon_flash_abstractflash_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	{
		zval _zc0;
		ZVAL_BOOL(&_zc0, 1);
		zephir_declare_typed_property(phalcon_flash_abstractflash_ce, SL("autoescape"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_BOOL, NULL, 0);
	}

	{
		zval _zc0;
		ZVAL_BOOL(&_zc0, 1);
		zephir_declare_typed_property(phalcon_flash_abstractflash_ce, SL("automaticHtml"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_BOOL, NULL, 0);
	}

	/**
	 * @phpstan-var flash_css_classes
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_flash_abstractflash_ce, SL("cssClasses"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

	/**
	 * @phpstan-var flash_css_classes
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_flash_abstractflash_ce, SL("cssIconClasses"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

	{
		zval _zc0;
		ZVAL_STRINGL(&_zc0, "", sizeof("") - 1);
		zephir_declare_typed_property(phalcon_flash_abstractflash_ce, SL("customTemplate"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_STRING, NULL, 0);
	}

	{
		zval _zc0;
		ZVAL_NULL(&_zc0);
		zephir_declare_typed_property(phalcon_flash_abstractflash_ce, SL("escaperService"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_NULL, SL("Phalcon\\Html\\Escaper\\EscaperInterface"));
	}

	{
		zval _zc0;
		ZVAL_BOOL(&_zc0, 1);
		zephir_declare_typed_property(phalcon_flash_abstractflash_ce, SL("implicitFlush"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_BOOL, NULL, 0);
	}

	/**
	 * @phpstan-var flash_messages
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_flash_abstractflash_ce, SL("messages"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

	{
		zval _zc0;
		ZVAL_NULL(&_zc0);
		zephir_declare_typed_property(phalcon_flash_abstractflash_ce, SL("sessionService"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_NULL, SL("Phalcon\\Session\\ManagerInterface"));
	}

	zend_class_implements(phalcon_flash_abstractflash_ce, 1, phalcon_flash_flashinterface_ce);
	return SUCCESS;
}

/**
 * AbstractFlash constructor.
 */
PHP_METHOD(Phalcon_Flash_AbstractFlash, __construct)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *escaper = NULL, escaper_sub, *session = NULL, session_sub, __$null;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&escaper_sub);
	ZVAL_UNDEF(&session_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("escaperService", 14, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("sessionService", 14, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("cssClasses", 10, 1);
	}

	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 2)
		Z_PARAM_OPTIONAL
		Z_PARAM_OBJECT_OF_CLASS_OR_NULL(escaper, zephir_get_internal_ce(SL("phalcon\\html\\escaper\\escaperinterface")))
		Z_PARAM_OBJECT_OF_CLASS_OR_NULL(session, zephir_get_internal_ce(SL("phalcon\\session\\managerinterface")))
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 2, &escaper, &session);
	if (!escaper) {
		escaper = &escaper_sub;
		escaper = &__$null;
	}
	if (!session) {
		session = &session_sub;
		session = &__$null;
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 202, escaper);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 203, session);
	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 4, 0);
	add_assoc_stringl_ex(&_0, SL("error"), SL("errorMessage"));
	add_assoc_stringl_ex(&_0, SL("notice"), SL("noticeMessage"));
	add_assoc_stringl_ex(&_0, SL("success"), SL("successMessage"));
	add_assoc_stringl_ex(&_0, SL("warning"), SL("warningMessage"));
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 204, &_0);
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
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("messages", 8, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 205, &_0);
	ZEPHIR_MM_RESTORE();
}

/**
 * Shows a HTML error message
 *
 *```php
 * $flash->error("This is an error");
 *```
 */
PHP_METHOD(Phalcon_Flash_AbstractFlash, error)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval message_zv, _0;
	zend_string *message = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message_zv);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(message)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&message_zv);
	ZVAL_STR_COPY(&message_zv, message);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "error");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "message", NULL, 0, &_0, &message_zv);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Returns the flag that defines whether to automatically escape content or not
 */
PHP_METHOD(Phalcon_Flash_AbstractFlash, getAutoescape)
{

	RETURN_MEMBER(getThis(), "autoescape");
}

/**
 * Returns the flag that defines whether to automatically use HTML or not
 */
PHP_METHOD(Phalcon_Flash_AbstractFlash, getAutomaticHtml)
{

	RETURN_MEMBER(getThis(), "automaticHtml");
}

/**
 * Returns the array of the CSS classes for formatting messages. The key is
 * the type of message and the value is the CSS class
 *
 * @phpstan-return flash_css_classes
 */
PHP_METHOD(Phalcon_Flash_AbstractFlash, getCssClasses)
{

	RETURN_MEMBER_TYPED(getThis(), "cssClasses", IS_ARRAY);
}

/**
 * Returns the array of the icon CSS classes for formatting messages. The
 * key is the type of message and the value is the icon CSS class
 *
 * @phpstan-return flash_css_classes
 */
PHP_METHOD(Phalcon_Flash_AbstractFlash, getCssIconClasses)
{

	RETURN_MEMBER_TYPED(getThis(), "cssIconClasses", IS_ARRAY);
}

/**
 * Returns the custom template for formatting messages

 */
PHP_METHOD(Phalcon_Flash_AbstractFlash, getCustomTemplate)
{

	RETURN_MEMBER_TYPED(getThis(), "customTemplate", IS_STRING);
}

/**
 * Returns the Escaper Service
 *
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
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("escaperService", 14, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("container", 9, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 202, PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_0) != IS_NULL) {
		RETURN_MM_MEMBER(getThis(), "escaperService");
	}
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_1, 206, PH_NOISY_CC | PH_READONLY);
	_2 = Z_TYPE_P(&_1) != IS_NULL;
	if (_2) {
		zephir_read_property_cached(&_3, this_ptr, _zephir_prop_1, 206, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_5);
		ZVAL_STRING(&_5, "escaper");
		ZEPHIR_CALL_METHOD(&_4, &_3, "has", NULL, 0, &_5);
		zephir_check_call_status();
		_2 = ZEPHIR_IS_TRUE_IDENTICAL(&_4);
	}
	if (_2) {
		zephir_read_property_cached(&_6$$4, this_ptr, _zephir_prop_1, 206, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_8$$4);
		ZVAL_STRING(&_8$$4, "escaper");
		ZEPHIR_CALL_METHOD(&_7$$4, &_6$$4, "getshared", NULL, 0, &_8$$4);
		zephir_check_call_status();
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 202, &_7$$4);
		RETURN_MM_MEMBER(getThis(), "escaperService");
	}
	ZEPHIR_INIT_NVAR(&_5);
	object_init_ex(&_5, phalcon_flash_exceptions_escaperserviceunavailable_ce);
	ZEPHIR_CALL_METHOD(NULL, &_5, "__construct", NULL, 192);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_5, "phalcon/Flash/AbstractFlash.zep", 163);
	ZEPHIR_MM_RESTORE();
	return;
}

/**
 * Outputs a message. Delivery semantics differ per implementation:
 * `Direct` renders and emits immediately, `Session` stores the raw
 * message for output on a later request.
 */
PHP_METHOD(Phalcon_Flash_AbstractFlash, message)
{
}

/**
 * Shows a HTML notice/information message
 *
 *```php
 * $flash->notice("This is an information");
 *```
 */
PHP_METHOD(Phalcon_Flash_AbstractFlash, notice)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval message_zv, _0;
	zend_string *message = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message_zv);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(message)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&message_zv);
	ZVAL_STR_COPY(&message_zv, message);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "notice");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "message", NULL, 0, &_0, &message_zv);
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
 * @throws Exception
 */
PHP_METHOD(Phalcon_Flash_AbstractFlash, outputMessage)
{
	zend_bool _0, _8;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_4 = NULL, *_5 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval type_zv, *message = NULL, message_sub, content, html, item, prepared, *_3, _7, _1$$3, _2$$4, _6$$5, _9$$8;
	zend_string *type = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&type_zv);
	ZVAL_UNDEF(&message_sub);
	ZVAL_UNDEF(&content);
	ZVAL_UNDEF(&html);
	ZVAL_UNDEF(&item);
	ZVAL_UNDEF(&prepared);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_9$$8);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("implicitFlush", 13, 1);
	}

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(type)
		Z_PARAM_ZVAL(message)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	message = ZEND_CALL_ARG(execute_data, 2);
	zephir_memory_observe(&type_zv);
	ZVAL_STR_COPY(&type_zv, type);
	ZEPHIR_SEPARATE_PARAM(message);
	ZEPHIR_INIT_VAR(&content);
	ZVAL_STRING(&content, "");
	_0 = Z_TYPE_P(message) != IS_ARRAY;
	if (_0) {
		_0 = Z_TYPE_P(message) != IS_STRING;
	}
	if (_0) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_flash_exceptions_flashmessagenotstringorarray_ce);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 193);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Flash/AbstractFlash.zep", 201);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (Z_TYPE_P(message) != IS_ARRAY) {
		ZEPHIR_INIT_VAR(&_2$$4);
		zephir_create_array(&_2$$4, 1, 0);
		zephir_array_fast_append(&_2$$4, message);
		ZEPHIR_CPY_WRT(message, &_2$$4);
	}
	zephir_is_iterable(message, 0, "phalcon/Flash/AbstractFlash.zep", 227);
	if (Z_TYPE_P(message) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(message), _3)
		{
			ZEPHIR_INIT_NVAR(&item);
			ZVAL_COPY(&item, _3);
			ZEPHIR_CALL_METHOD(&prepared, this_ptr, "prepareescapedmessage", &_4, 194, &item);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&html, this_ptr, "preparehtmlmessage", &_5, 195, &type_zv, &prepared);
			zephir_check_call_status();
			zephir_read_property_cached(&_6$$5, this_ptr, _zephir_prop_0, 207, PH_NOISY_CC | PH_READONLY);
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
		_8 = 1;
		while (1) {
			if (_8) {
				_8 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, message, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_7, message, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_7)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&item, message, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&prepared, this_ptr, "prepareescapedmessage", &_4, 194, &item);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&html, this_ptr, "preparehtmlmessage", &_5, 195, &type_zv, &prepared);
				zephir_check_call_status();
				zephir_read_property_cached(&_9$$8, this_ptr, _zephir_prop_0, 207, PH_NOISY_CC | PH_READONLY);
				if (ZEPHIR_IS_TRUE_IDENTICAL(&_9$$8)) {
					zend_print_zval(&html, 0);
				} else {
					zephir_concat_self(&content, &html);
					zephir_update_property_array_append(this_ptr, SL("messages"), &html);
				}
		}
	}
	ZEPHIR_INIT_NVAR(&item);
	RETURN_CCTOR(&content);
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
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("autoescape", 10, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(autoescape)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &autoescape_param);
	if (autoescape) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 208, &__$true);
	} else {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 208, &__$false);
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
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("automaticHtml", 13, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(automaticHtml)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &automaticHtml_param);
	if (automaticHtml) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 209, &__$true);
	} else {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 209, &__$false);
	}
	RETURN_THISW();
}

/**
 * Set an array with CSS classes to format the messages
 *
 * @phpstan-param flash_css_classes $cssClasses
 */
PHP_METHOD(Phalcon_Flash_AbstractFlash, setCssClasses)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *cssClasses_param = NULL;
	zval cssClasses;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&cssClasses);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("cssClasses", 10, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(cssClasses, cssClasses_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &cssClasses_param);
	zephir_get_arrval(&cssClasses, cssClasses_param);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 204, &cssClasses);
	RETURN_THIS();
}

/**
 * Set an array with CSS classes to format the icon messages
 *
 * @phpstan-param flash_css_classes $cssIconClasses
 */
PHP_METHOD(Phalcon_Flash_AbstractFlash, setCssIconClasses)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *cssIconClasses_param = NULL;
	zval cssIconClasses;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&cssIconClasses);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("cssIconClasses", 14, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(cssIconClasses, cssIconClasses_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &cssIconClasses_param);
	zephir_get_arrval(&cssIconClasses, cssIconClasses_param);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 210, &cssIconClasses);
	RETURN_THIS();
}

/**
 * Set a custom template for showing the messages
 */
PHP_METHOD(Phalcon_Flash_AbstractFlash, setCustomTemplate)
{
	zval customTemplate_zv;
	zend_string *customTemplate = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&customTemplate_zv);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("customTemplate", 14, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(customTemplate)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&customTemplate_zv, customTemplate);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 211, &customTemplate_zv);
	RETURN_THISW();
}

/**
 * Sets the Escaper Service
 */
PHP_METHOD(Phalcon_Flash_AbstractFlash, setEscaperService)
{
	zval *escaperService, escaperService_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&escaperService_sub);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("escaperService", 14, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(escaperService, zephir_get_internal_ce(SL("phalcon\\html\\escaper\\escaperinterface")))
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &escaperService);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 202, escaperService);
	RETURN_THISW();
}

/**
 * Set whether the output must be implicitly flushed to the output or
 * returned as string
 *
 * Note: `output()` is an echo API and requires implicit flush to remain
 * enabled (the default). With implicit flush disabled, `message()` returns
 * the rendered string while `output()` does not emit it.
 */
PHP_METHOD(Phalcon_Flash_AbstractFlash, setImplicitFlush)
{
	zval *implicitFlush_param = NULL, __$true, __$false;
	zend_bool implicitFlush;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("implicitFlush", 13, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(implicitFlush)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &implicitFlush_param);
	if (implicitFlush) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 207, &__$true);
	} else {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 207, &__$false);
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
PHP_METHOD(Phalcon_Flash_AbstractFlash, success)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval message_zv, _0;
	zend_string *message = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message_zv);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(message)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&message_zv);
	ZVAL_STR_COPY(&message_zv, message);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "success");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "message", NULL, 0, &_0, &message_zv);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Shows a HTML warning message
 *
 *```php
 * $flash->warning("Hey, this is important");
 *```
 */
PHP_METHOD(Phalcon_Flash_AbstractFlash, warning)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval message_zv, _0;
	zend_string *message = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message_zv);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(message)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&message_zv);
	ZVAL_STR_COPY(&message_zv, message);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "warning");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "message", NULL, 0, &_0, &message_zv);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Checks the collection and returns the content as a string
 * (array is joined)
 *
 * @phpstan-param flash_css_classes $collection
 */
PHP_METHOD(Phalcon_Flash_AbstractFlash, checkClasses)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_string *type = NULL;
	zval *collection_param = NULL, type_zv, content, _0$$4;
	zval collection;

	ZVAL_UNDEF(&collection);
	ZVAL_UNDEF(&type_zv);
	ZVAL_UNDEF(&content);
	ZVAL_UNDEF(&_0$$4);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		ZEPHIR_Z_PARAM_ARRAY(collection, collection_param)
		Z_PARAM_STR(type)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	collection_param = ZEND_CALL_ARG(execute_data, 1);
	zephir_get_arrval(&collection, collection_param);
	zephir_memory_observe(&type_zv);
	ZVAL_STR_COPY(&type_zv, type);
	ZEPHIR_INIT_VAR(&content);
	ZVAL_STRING(&content, "");
	if (zephir_array_isset_value(&collection, &type_zv)) {
		ZEPHIR_OBS_NVAR(&content);
		zephir_array_fetch(&content, &collection, &type_zv, PH_NOISY, "phalcon/Flash/AbstractFlash.zep", 346);
	}
	if (Z_TYPE_P(&content) != IS_ARRAY) {
		ZEPHIR_INIT_VAR(&_0$$4);
		zephir_create_array(&_0$$4, 1, 0);
		zephir_array_fast_append(&_0$$4, &content);
		ZEPHIR_CPY_WRT(&content, &_0$$4);
	}
	zephir_fast_join_str(return_value, SL(" "), &content);
	RETURN_MM();
}

/**
 * Returns the template for the CSS classes (with icon classes). It will
 * either be the custom one (defined) or the default
 */
PHP_METHOD(Phalcon_Flash_AbstractFlash, getTemplate)
{
	zval _3;
	zval divString, iconString, template;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval cssClasses_zv, cssIconClasses_zv, _0, _1, _2;
	zend_string *cssClasses = NULL, *cssIconClasses = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&cssClasses_zv);
	ZVAL_UNDEF(&cssIconClasses_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&divString);
	ZVAL_UNDEF(&iconString);
	ZVAL_UNDEF(&template);
	ZVAL_UNDEF(&_3);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("customTemplate", 14, 1);
	}

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(cssClasses)
		Z_PARAM_STR(cssIconClasses)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&cssClasses_zv);
	ZVAL_STR_COPY(&cssClasses_zv, cssClasses);
	zephir_memory_observe(&cssIconClasses_zv);
	ZVAL_STR_COPY(&cssIconClasses_zv, cssIconClasses);
	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_GET_CONSTANT(&_0, "PHP_EOL");
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_CONCAT_SV(&_1, "<div%divString%>%iconString%%message%</div>", &_0);
	zephir_get_strval(&template, &_1);
	ZEPHIR_INIT_VAR(&divString);
	ZVAL_STRING(&divString, "");
	ZEPHIR_INIT_VAR(&iconString);
	ZVAL_STRING(&iconString, "");
	zephir_read_property_cached(&_2, this_ptr, _zephir_prop_0, 211, PH_NOISY_CC | PH_READONLY);
	if (!(ZEPHIR_IS_EMPTY(&_2))) {
		RETURN_MM_MEMBER_TYPED(getThis(), "customTemplate", IS_STRING);
	}
	if (!(ZEPHIR_IS_EMPTY(&cssClasses_zv))) {
		ZEPHIR_INIT_NVAR(&divString);
		ZVAL_STRING(&divString, " class=\"%cssClass%\"");
		if (!(ZEPHIR_IS_EMPTY(&cssIconClasses_zv))) {
			ZEPHIR_INIT_NVAR(&iconString);
			ZVAL_STRING(&iconString, "<i class=\"%cssIconClass%\"></i> ");
		}
	}
	ZEPHIR_INIT_VAR(&_3);
	zephir_create_array(&_3, 2, 0);
	zephir_array_update_string(&_3, SL("divString"), &divString, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_3, SL("iconString"), &iconString, PH_COPY | PH_SEPARATE);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "tointerpolate", NULL, 0, &template, &_3);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Returns the message escaped if the autoEscape is true, otherwise the
 * original message is returned
 */
PHP_METHOD(Phalcon_Flash_AbstractFlash, prepareEscapedMessage)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval message_zv, escaper, _0;
	zend_string *message = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message_zv);
	ZVAL_UNDEF(&escaper);
	ZVAL_UNDEF(&_0);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("autoescape", 10, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(message)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&message_zv);
	ZVAL_STR_COPY(&message_zv, message);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 208, PH_NOISY_CC | PH_READONLY);
	if (!ZEPHIR_IS_TRUE_IDENTICAL(&_0)) {
		RETURN_STR(zend_string_copy(message));
	}
	ZEPHIR_CALL_METHOD(&escaper, this_ptr, "getescaperservice", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&escaper, "html", NULL, 0, &message_zv);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Prepares the HTML output for the message. If automaticHtml is not set
 * then the original message is returned
 */
PHP_METHOD(Phalcon_Flash_AbstractFlash, prepareHtmlMessage)
{
	zval _8;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval type_zv, message_zv, cssClasses, cssIconClasses, _0, _1, _2, _3, _4, _5, _6, _7;
	zend_string *type = NULL, *message = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&type_zv);
	ZVAL_UNDEF(&message_zv);
	ZVAL_UNDEF(&cssClasses);
	ZVAL_UNDEF(&cssIconClasses);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("automaticHtml", 13, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("cssClasses", 10, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("cssIconClasses", 14, 1);
	}

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(type)
		Z_PARAM_STR(message)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&type_zv);
	ZVAL_STR_COPY(&type_zv, type);
	zephir_memory_observe(&message_zv);
	ZVAL_STR_COPY(&message_zv, message);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 209, PH_NOISY_CC | PH_READONLY);
	if (!ZEPHIR_IS_TRUE_IDENTICAL(&_0)) {
		RETURN_STR(zend_string_copy(message));
	}
	zephir_read_property_cached(&_2, this_ptr, _zephir_prop_1, 204, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "checkclasses", NULL, 196, &_2, &type_zv);
	zephir_check_call_status();
	ZVAL_LONG(&_3, 3);
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "utf-8");
	ZEPHIR_CALL_FUNCTION(&cssClasses, "htmlspecialchars", NULL, 197, &_1, &_3, &_4);
	zephir_check_call_status();
	zephir_read_property_cached(&_3, this_ptr, _zephir_prop_2, 210, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_5, this_ptr, "checkclasses", NULL, 196, &_3, &type_zv);
	zephir_check_call_status();
	ZVAL_LONG(&_6, 3);
	ZEPHIR_INIT_NVAR(&_4);
	ZVAL_STRING(&_4, "utf-8");
	ZEPHIR_CALL_FUNCTION(&cssIconClasses, "htmlspecialchars", NULL, 197, &_5, &_6, &_4);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_7, this_ptr, "gettemplate", NULL, 198, &cssClasses, &cssIconClasses);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_8);
	zephir_create_array(&_8, 3, 0);
	zephir_array_update_string(&_8, SL("cssClass"), &cssClasses, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_8, SL("cssIconClass"), &cssIconClasses, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_8, SL("message"), &message_zv, PH_COPY | PH_SEPARATE);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "tointerpolate", NULL, 0, &_7, &_8);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @param string   $input
 * @param string[] $context
 * @param string   $left
 * @param string   $right
 *
 * @return string
 */
PHP_METHOD(Phalcon_Flash_AbstractFlash, toInterpolate)
{
	zend_bool _6;
	zend_ulong _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval context, replace;
	zval input_zv, *context_param = NULL, left_zv, right_zv, key, value, _0, *_1, _5, _4$$5, _7$$6;
	zend_string *input = NULL, *left = NULL, *right = NULL, *_3;

	ZVAL_UNDEF(&input_zv);
	ZVAL_UNDEF(&left_zv);
	ZVAL_UNDEF(&right_zv);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&context);
	ZVAL_UNDEF(&replace);
	ZEND_PARSE_PARAMETERS_START(1, 4)
		Z_PARAM_STR(input)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(context, context_param)
		Z_PARAM_STR(left)
		Z_PARAM_STR(right)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		context_param = ZEND_CALL_ARG(execute_data, 2);
	}
	zephir_memory_observe(&input_zv);
	ZVAL_STR_COPY(&input_zv, input);
	if (!context_param) {
		ZEPHIR_INIT_VAR(&context);
		array_init(&context);
	} else {
		zephir_get_arrval(&context, context_param);
	}
	if (!left) {
		left = zend_string_init(ZEND_STRL("%"), 0);
		zephir_memory_observe(&left_zv);
		ZVAL_STR(&left_zv, left);
	} else {
		zephir_memory_observe(&left_zv);
	ZVAL_STR_COPY(&left_zv, left);
	}
	if (!right) {
		right = zend_string_init(ZEND_STRL("%"), 0);
		zephir_memory_observe(&right_zv);
		ZVAL_STR(&right_zv, right);
	} else {
		zephir_memory_observe(&right_zv);
	ZVAL_STR_COPY(&right_zv, right);
	}
	ZEPHIR_INIT_VAR(&replace);
	array_init(&replace);
	if (ZEPHIR_IS_EMPTY(&context)) {
		RETURN_MM_STR(zend_string_copy(input));
	}
	ZEPHIR_INIT_VAR(&_0);
	zephir_fast_strpos(&_0, &input_zv, &left_zv, 0 );
	if (ZEPHIR_IS_FALSE_IDENTICAL(&_0)) {
		RETURN_MM_STR(zend_string_copy(input));
	}
	zephir_is_iterable(&context, 0, "phalcon/Traits/Support/Helper/Str/InterpolateTrait.zep", 49);
	if (Z_TYPE_P(&context) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&context), _2, _3, _1)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_3 != NULL) { 
				ZVAL_STR_COPY(&key, _3);
			} else {
				ZVAL_LONG(&key, _2);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _1);
			ZEPHIR_INIT_NVAR(&_4$$5);
			ZEPHIR_CONCAT_VVV(&_4$$5, &left_zv, &key, &right_zv);
			zephir_array_update_zval(&replace, &_4$$5, &value, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &context, "rewind", NULL, 0);
		zephir_check_call_status();
		_6 = 1;
		while (1) {
			if (_6) {
				_6 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &context, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_5, &context, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_5)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, &context, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, &context, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_7$$6);
				ZEPHIR_CONCAT_VVV(&_7$$6, &left_zv, &key, &right_zv);
				zephir_array_update_zval(&replace, &_7$$6, &value, PH_COPY | PH_SEPARATE);
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	ZEPHIR_RETURN_CALL_FUNCTION("strtr", NULL, 4, &input_zv, &replace);
	zephir_check_call_status();
	RETURN_MM();
}

