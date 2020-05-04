
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
 * For the full copyright and license information, please view the
 * LICENSE.txt file that was distributed with this source code.
 */
/**
 * This is an implementation of the Phalcon\Flash\FlashInterface that
 * temporarily stores the messages in session, then messages can be printed in
 * the next request.
 */
ZEPHIR_INIT_CLASS(Phalcon_Flash_Session) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Flash, Session, phalcon, flash_session, phalcon_flash_abstractflash_ce, phalcon_flash_session_method_entry, 0);

	return SUCCESS;

}

/**
 * Clear messages in the session messenger
 */
PHP_METHOD(Phalcon_Flash_Session, clear) {

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
 */
PHP_METHOD(Phalcon_Flash_Session, getMessages) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool remove;
	zval *type = NULL, type_sub, *remove_param = NULL, __$null, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&type_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);

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
 */
PHP_METHOD(Phalcon_Flash_Session, has) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *type = NULL, type_sub, __$null, messages, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&type_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&messages);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &type);

	if (!type) {
		type = &type_sub;
		type = &__$null;
	}


	ZVAL_BOOL(&_0, 0);
	ZEPHIR_CALL_METHOD(&messages, this_ptr, "getsessionmessages", NULL, 0, &_0);
	zephir_check_call_status();
	if (Z_TYPE_P(type) != IS_STRING) {
		RETURN_MM_BOOL(1);
	}
	RETURN_MM_BOOL(zephir_array_isset(&messages, type));

}

/**
 * Adds a message to the session flasher
 *
 * @return null|string|void
 */
PHP_METHOD(Phalcon_Flash_Session, message) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *type_param = NULL, *message_param = NULL, messages, _0, _1$$3;
	zval type, message;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&messages);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &type_param, &message_param);

	zephir_get_strval(&type, type_param);
	zephir_get_strval(&message, message_param);


	ZVAL_BOOL(&_0, 0);
	ZEPHIR_CALL_METHOD(&messages, this_ptr, "getsessionmessages", NULL, 0, &_0);
	zephir_check_call_status();
	if (!(zephir_array_isset(&messages, &type))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		array_init(&_1$$3);
		zephir_array_update_zval(&messages, &type, &_1$$3, PH_COPY | PH_SEPARATE);
	}
	zephir_array_update_multi(&messages, &message, SL("za"), 2, &type);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setsessionmessages", NULL, 0, &messages);
	zephir_check_call_status();
	RETURN_MM_NULL();

}

/**
 * Prints the messages in the session flasher
 */
PHP_METHOD(Phalcon_Flash_Session, output) {

	zend_string *_4;
	zend_ulong _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_5 = NULL, *_6 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *remove_param = NULL, type, message, messages, _0, *_1, _2;
	zend_bool remove;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&messages);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);

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
	zephir_is_iterable(&messages, 0, "phalcon/Flash/Session.zep", 91);
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
 */
PHP_METHOD(Phalcon_Flash_Session, getSessionMessages) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *remove_param = NULL, *type = NULL, type_sub, __$null, session, messages, returnMessages, _0, _1$$6, _2$$7;
	zend_bool remove;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&type_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&session);
	ZVAL_UNDEF(&messages);
	ZVAL_UNDEF(&returnMessages);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$6);
	ZVAL_UNDEF(&_2$$7);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &remove_param, &type);

	remove = zephir_get_boolval(remove_param);
	if (!type) {
		type = &type_sub;
		type = &__$null;
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
	if (Z_TYPE_P(type) == IS_STRING) {
		ZEPHIR_OBS_VAR(&returnMessages);
		if (zephir_array_isset_fetch(&returnMessages, &messages, type, 0)) {
			if (remove) {
				zephir_array_unset(&messages, type, PH_SEPARATE);
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
 */
PHP_METHOD(Phalcon_Flash_Session, setSessionMessages) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *messages_param = NULL, session, _0;
	zval messages;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&messages);
	ZVAL_UNDEF(&session);
	ZVAL_UNDEF(&_0);

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
 */
PHP_METHOD(Phalcon_Flash_Session, getSessionService) {

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

	zephir_read_property(&_0, this_ptr, SL("sessionService"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_0)) {
		RETURN_MM_MEMBER(getThis(), "sessionService");
	}
	zephir_read_property(&_1, this_ptr, SL("container"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&container, &_1);
	if (UNEXPECTED(Z_TYPE_P(&container) != IS_OBJECT)) {
		ZEPHIR_INIT_VAR(&_2$$4);
		object_init_ex(&_2$$4, phalcon_flash_exception_ce);
		ZEPHIR_INIT_VAR(&_5$$4);
		ZVAL_STRING(&_5$$4, "the 'session' service");
		ZEPHIR_CALL_CE_STATIC(&_3$$4, phalcon_flash_exception_ce, "containerservicenotfound", &_4, 0, &_5$$4);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_2$$4, "__construct", NULL, 6, &_3$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_2$$4, "phalcon/Flash/Session.zep", 160);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&_7);
	ZVAL_STRING(&_7, "session");
	ZEPHIR_CALL_METHOD(&_6, &container, "has", NULL, 0, &_7);
	zephir_check_call_status();
	if (UNEXPECTED(zephir_is_true(&_6))) {
		ZEPHIR_INIT_VAR(&_9$$5);
		ZVAL_STRING(&_9$$5, "session");
		ZEPHIR_CALL_METHOD(&_8$$5, &container, "getshared", NULL, 0, &_9$$5);
		zephir_check_call_status();
		RETURN_CCTOR(&_8$$5);
	} else {
		ZEPHIR_INIT_VAR(&_10$$6);
		object_init_ex(&_10$$6, phalcon_flash_exception_ce);
		ZEPHIR_INIT_VAR(&_12$$6);
		ZVAL_STRING(&_12$$6, "the 'session' service");
		ZEPHIR_CALL_CE_STATIC(&_11$$6, phalcon_flash_exception_ce, "containerservicenotfound", &_4, 0, &_12$$6);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_10$$6, "__construct", NULL, 6, &_11$$6);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_10$$6, "phalcon/Flash/Session.zep", 168);
		ZEPHIR_MM_RESTORE();
		return;
	}

}

