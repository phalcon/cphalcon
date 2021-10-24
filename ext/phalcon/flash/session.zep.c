
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
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * This is an implementation of the Phalcon\Flash\FlashInterface that
 * temporarily stores the messages in session, then messages can be printed in
 * the next request.
 *
 * Class Session
 *
 * @package Phalcon\Flash
 */
ZEPHIR_INIT_CLASS(Phalcon_Flash_Session)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Flash, Session, phalcon, flash_session, phalcon_flash_abstractflash_ce, phalcon_flash_session_method_entry, 0);

	zephir_declare_class_constant_string(phalcon_flash_session_ce, SL("SESSION_KEY"), "_flashMessages");

	return SUCCESS;
}

/**
 * Clear messages in the session messenger
 *
 * @throws Exception
 */
PHP_METHOD(Phalcon_Flash_Session, clear)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_1 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	ZEPHIR_MM_GROW();

	ZVAL_BOOL(&_0, 1);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "getsessionmessages", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_CALL_PARENT(NULL, phalcon_flash_session_ce, getThis(), "clear", &_1, 0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Returns the messages in the session flasher
 *
 * @param mixed|null $type
 * @param bool       $remove
 *
 * @return array
 * @throws Exception
 */
PHP_METHOD(Phalcon_Flash_Session, getMessages)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool remove;
	zval *type = NULL, type_sub, *remove_param = NULL, __$null, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&type_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 2)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(type)
		Z_PARAM_BOOL(remove)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &type, &remove_param);
	if (!type) {
		type = &type_sub;
		type = &__$null;
	}
	if (!remove_param) {
		remove = 1;
	} else {
		remove = zephir_get_boolval(remove_param);
	}


	if (remove) {
		ZVAL_BOOL(&_0, 1);
	} else {
		ZVAL_BOOL(&_0, 0);
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getsessionmessages", NULL, 0, &_0, type);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Checks whether there are messages
 *
 * @param string|null $type
 *
 * @return bool
 * @throws Exception
 */
PHP_METHOD(Phalcon_Flash_Session, has)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *type_param = NULL, messages, _0;
	zval type;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&messages);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(type)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &type_param);
	if (!type_param) {
		ZEPHIR_INIT_VAR(&type);
	} else {
		zephir_get_strval(&type, type_param);
	}


	ZVAL_BOOL(&_0, 0);
	ZEPHIR_CALL_METHOD(&messages, this_ptr, "getsessionmessages", NULL, 0, &_0);
	zephir_check_call_status();
	if (!(!(ZEPHIR_IS_EMPTY(&type)))) {
		RETURN_MM_BOOL((1 != ZEPHIR_IS_EMPTY(&messages)));
	}
	RETURN_MM_BOOL(zephir_array_isset(&messages, &type));
}

/**
 * Adds a message to the session flasher
 *
 * @param string $type
 * @param mixed  $message
 *
 * @return string|null
 * @throws Exception
 */
PHP_METHOD(Phalcon_Flash_Session, message)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *type_param = NULL, *message, message_sub, messages, _0, _1$$3;
	zval type;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&message_sub);
	ZVAL_UNDEF(&messages);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
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


	ZVAL_BOOL(&_0, 0);
	ZEPHIR_CALL_METHOD(&messages, this_ptr, "getsessionmessages", NULL, 0, &_0);
	zephir_check_call_status();
	if (1 != zephir_array_isset(&messages, &type)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		array_init(&_1$$3);
		zephir_array_update_zval(&messages, &type, &_1$$3, PH_COPY | PH_SEPARATE);
	}
	zephir_array_update_multi(&messages, message, SL("za"), 2, &type);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setsessionmessages", NULL, 0, &messages);
	zephir_check_call_status();
	RETURN_MM_NULL();
}

/**
 * Prints the messages in the session flasher
 *
 * @param bool $remove
 *
 * @throws Exception
 */
PHP_METHOD(Phalcon_Flash_Session, output)
{
	zend_string *_4;
	zend_ulong _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_5 = NULL, *_6 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *remove_param = NULL, message, messages, type, _0, *_1, _2;
	zend_bool remove;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&messages);
	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(remove)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &remove_param);
	if (!remove_param) {
		remove = 1;
	} else {
		remove = zephir_get_boolval(remove_param);
	}


	if (remove) {
		ZVAL_BOOL(&_0, 1);
	} else {
		ZVAL_BOOL(&_0, 0);
	}
	ZEPHIR_CALL_METHOD(&messages, this_ptr, "getsessionmessages", NULL, 0, &_0);
	zephir_check_call_status();
	zephir_is_iterable(&messages, 0, "phalcon/Flash/Session.zep", 117);
	if (Z_TYPE_P(&messages) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&messages), _3, _4, _1)
		{
			ZEPHIR_INIT_NVAR(&type);
			if (_4 != NULL) { 
				ZVAL_STR_COPY(&type, _4);
			} else {
				ZVAL_LONG(&type, _3);
			}
			ZEPHIR_INIT_NVAR(&message);
			ZVAL_COPY(&message, _1);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "outputmessage", &_5, 0, &type, &message);
			zephir_check_call_status();
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &messages, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_2, &messages, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_2)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&type, &messages, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&message, &messages, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "outputmessage", &_5, 0, &type, &message);
				zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &messages, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&message);
	ZEPHIR_INIT_NVAR(&type);
	ZEPHIR_CALL_PARENT(NULL, phalcon_flash_session_ce, getThis(), "clear", &_6, 0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Returns the messages stored in session
 *
 * @param bool       $remove
 * @param mixed|null $type
 *
 * @return array
 * @throws Exception
 */
PHP_METHOD(Phalcon_Flash_Session, getSessionMessages)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval type;
	zval *remove_param = NULL, *type_param = NULL, session, messages, returnMessages, _0, _1$$6, _2$$7;
	zend_bool remove;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&session);
	ZVAL_UNDEF(&messages);
	ZVAL_UNDEF(&returnMessages);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$6);
	ZVAL_UNDEF(&_2$$7);
	ZVAL_UNDEF(&type);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_BOOL(remove)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(type)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &remove_param, &type_param);
	remove = zephir_get_boolval(remove_param);
	if (!type_param) {
		ZEPHIR_INIT_VAR(&type);
	} else {
		zephir_get_strval(&type, type_param);
	}


	ZEPHIR_CALL_METHOD(&session, this_ptr, "getsessionservice", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "_flashMessages");
	ZEPHIR_CALL_METHOD(&messages, &session, "get", NULL, 0, &_0);
	zephir_check_call_status();
	if (Z_TYPE_P(&messages) != IS_ARRAY) {
		ZEPHIR_INIT_NVAR(&messages);
		array_init(&messages);
	}
	if (1 != ZEPHIR_IS_EMPTY(&type)) {
		ZEPHIR_OBS_VAR(&returnMessages);
		if (zephir_array_isset_fetch(&returnMessages, &messages, &type, 0)) {
			if (remove) {
				zephir_array_unset(&messages, &type, PH_SEPARATE);
				ZEPHIR_INIT_VAR(&_1$$6);
				ZVAL_STRING(&_1$$6, "_flashMessages");
				ZEPHIR_CALL_METHOD(NULL, &session, "set", NULL, 0, &_1$$6, &messages);
				zephir_check_call_status();
			}
			RETURN_CCTOR(&returnMessages);
		}
		array_init(return_value);
		RETURN_MM();
	}
	if (remove) {
		ZEPHIR_INIT_VAR(&_2$$7);
		ZVAL_STRING(&_2$$7, "_flashMessages");
		ZEPHIR_CALL_METHOD(NULL, &session, "remove", NULL, 0, &_2$$7);
		zephir_check_call_status();
	}
	RETURN_CCTOR(&messages);
}

/**
 * Stores the messages in session
 *
 * @param array $messages
 *
 * @return array
 * @throws Exception
 */
PHP_METHOD(Phalcon_Flash_Session, setSessionMessages)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *messages_param = NULL, session, _0;
	zval messages;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&messages);
	ZVAL_UNDEF(&session);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(messages)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &messages_param);
	ZEPHIR_OBS_COPY_OR_DUP(&messages, messages_param);


	ZEPHIR_CALL_METHOD(&session, this_ptr, "getsessionservice", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "_flashMessages");
	ZEPHIR_CALL_METHOD(NULL, &session, "set", NULL, 0, &_0, &messages);
	zephir_check_call_status();
	RETURN_CTOR(&messages);
}

/**
 * Returns the Session Service
 *
 * @return ManagerInterface
 * @throws Exception
 */
PHP_METHOD(Phalcon_Flash_Session, getSessionService)
{
	zend_bool _2;
	zval _0, _1, _3, _4, _5, _9, _11, _6$$4, _7$$4, _8$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_10 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$4);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("sessionService"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_0) != IS_NULL) {
		RETURN_MM_MEMBER(getThis(), "sessionService");
	}
	zephir_read_property(&_1, this_ptr, ZEND_STRL("container"), PH_NOISY_CC | PH_READONLY);
	_2 = Z_TYPE_P(&_1) != IS_NULL;
	if (_2) {
		zephir_read_property(&_3, this_ptr, ZEND_STRL("container"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_5);
		ZVAL_STRING(&_5, "session");
		ZEPHIR_CALL_METHOD(&_4, &_3, "has", NULL, 0, &_5);
		zephir_check_call_status();
		_2 = ZEPHIR_IS_TRUE_IDENTICAL(&_4);
	}
	if (_2) {
		zephir_read_property(&_6$$4, this_ptr, ZEND_STRL("container"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_8$$4);
		ZVAL_STRING(&_8$$4, "session");
		ZEPHIR_CALL_METHOD(&_7$$4, &_6$$4, "getshared", NULL, 0, &_8$$4);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, ZEND_STRL("sessionService"), &_7$$4);
		RETURN_MM_MEMBER(getThis(), "sessionService");
	}
	ZEPHIR_INIT_NVAR(&_5);
	object_init_ex(&_5, phalcon_flash_exception_ce);
	ZEPHIR_INIT_VAR(&_11);
	ZVAL_STRING(&_11, "the 'session' service");
	ZEPHIR_CALL_CE_STATIC(&_9, phalcon_flash_exception_ce, "containerservicenotfound", &_10, 0, &_11);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &_5, "__construct", NULL, 8, &_9);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_5, "phalcon/Flash/Session.zep", 205);
	ZEPHIR_MM_RESTORE();
	return;
}

