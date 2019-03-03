
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
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/operators.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Flash\Session
 *
 * Temporarily stores the messages in session, then messages can be printed in the next request
 */
ZEPHIR_INIT_CLASS(Phalcon_Flash_Session) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Flash, Session, phalcon, flash_session, phalcon_flash_ce, phalcon_flash_session_method_entry, 0);

	return SUCCESS;

}

/**
 * Returns the messages stored in session
 */
PHP_METHOD(Phalcon_Flash_Session, _getSessionMessages) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *remove_param = NULL, *type = NULL, type_sub, __$null, dependencyInjector, session, messages, returnMessages, _0, _1, _2$$5, _3$$6;
	zend_bool remove;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&type_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&dependencyInjector);
	ZVAL_UNDEF(&session);
	ZVAL_UNDEF(&messages);
	ZVAL_UNDEF(&returnMessages);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_3$$6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &remove_param, &type);

	remove = zephir_get_boolval(remove_param);
	if (!type) {
		type = &type_sub;
		type = &__$null;
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getdi", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&dependencyInjector, &_0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "session");
	ZEPHIR_CALL_METHOD(&_0, &dependencyInjector, "getshared", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&session, &_0);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "_flashMessages");
	ZEPHIR_CALL_METHOD(&messages, &session, "get", NULL, 0, &_1);
	zephir_check_call_status();
	if (Z_TYPE_P(type) == IS_STRING) {
		ZEPHIR_OBS_VAR(&returnMessages);
		if (zephir_array_isset_fetch(&returnMessages, &messages, type, 0 TSRMLS_CC)) {
			if (remove == 1) {
				zephir_array_unset(&messages, type, PH_SEPARATE);
				ZEPHIR_INIT_VAR(&_2$$5);
				ZVAL_STRING(&_2$$5, "_flashMessages");
				ZEPHIR_CALL_METHOD(NULL, &session, "set", NULL, 0, &_2$$5, &messages);
				zephir_check_call_status();
			}
			RETURN_CCTOR(&returnMessages);
		}
		array_init(return_value);
		RETURN_MM();
	}
	if (remove == 1) {
		ZEPHIR_INIT_VAR(&_3$$6);
		ZVAL_STRING(&_3$$6, "_flashMessages");
		ZEPHIR_CALL_METHOD(NULL, &session, "remove", NULL, 0, &_3$$6);
		zephir_check_call_status();
	}
	RETURN_CCTOR(&messages);

}

/**
 * Stores the messages in session
 */
PHP_METHOD(Phalcon_Flash_Session, _setSessionMessages) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *messages_param = NULL, dependencyInjector, session, _0, _1;
	zval messages;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&messages);
	ZVAL_UNDEF(&dependencyInjector);
	ZVAL_UNDEF(&session);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &messages_param);

	ZEPHIR_OBS_COPY_OR_DUP(&messages, messages_param);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getdi", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&dependencyInjector, &_0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "session");
	ZEPHIR_CALL_METHOD(&_0, &dependencyInjector, "getshared", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&session, &_0);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "_flashMessages");
	ZEPHIR_CALL_METHOD(NULL, &session, "set", NULL, 0, &_1, &messages);
	zephir_check_call_status();
	RETURN_CTOR(&messages);

}

/**
 * Adds a message to the session flasher
 */
PHP_METHOD(Phalcon_Flash_Session, message) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *type_param = NULL, *message_param = NULL, messages, _0, _1$$4;
	zval type, message;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&messages);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &type_param, &message_param);

	zephir_get_strval(&type, type_param);
	zephir_get_strval(&message, message_param);


	ZVAL_BOOL(&_0, 0);
	ZEPHIR_CALL_METHOD(&messages, this_ptr, "_getsessionmessages", NULL, 0, &_0);
	zephir_check_call_status();
	if (Z_TYPE_P(&messages) != IS_ARRAY) {
		ZEPHIR_INIT_NVAR(&messages);
		array_init(&messages);
	}
	if (!(zephir_array_isset(&messages, &type))) {
		ZEPHIR_INIT_VAR(&_1$$4);
		array_init(&_1$$4);
		zephir_array_update_zval(&messages, &type, &_1$$4, PH_COPY | PH_SEPARATE);
	}
	zephir_array_update_multi(&messages, &message TSRMLS_CC, SL("za"), 2, &type);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "_setsessionmessages", NULL, 0, &messages);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Checks whether there are messages
 */
PHP_METHOD(Phalcon_Flash_Session, has) {

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
	ZEPHIR_CALL_METHOD(&messages, this_ptr, "_getsessionmessages", NULL, 0, &_0);
	zephir_check_call_status();
	if (Z_TYPE_P(&messages) == IS_ARRAY) {
		if (Z_TYPE_P(type) == IS_STRING) {
			RETURN_MM_BOOL(zephir_array_isset(&messages, type));
		}
		RETURN_MM_BOOL(1);
	}
	RETURN_MM_BOOL(0);

}

/**
 * Returns the messages in the session flasher
 */
PHP_METHOD(Phalcon_Flash_Session, getMessages) {

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
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "_getsessionmessages", NULL, 0, &_0, type);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Prints the messages in the session flasher
 */
PHP_METHOD(Phalcon_Flash_Session, output) {

	zend_string *_4$$3;
	zend_ulong _3$$3;
	zephir_fcall_cache_entry *_5 = NULL, *_6 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *remove_param = NULL, type, message, messages, _0, *_1$$3, _2$$3;
	zend_bool remove;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&messages);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2$$3);

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
	ZEPHIR_CALL_METHOD(&messages, this_ptr, "_getsessionmessages", NULL, 0, &_0);
	zephir_check_call_status();
	if (Z_TYPE_P(&messages) == IS_ARRAY) {
		zephir_is_iterable(&messages, 0, "phalcon/flash/session.zep", 127);
		if (Z_TYPE_P(&messages) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&messages), _3$$3, _4$$3, _1$$3)
			{
				ZEPHIR_INIT_NVAR(&type);
				if (_4$$3 != NULL) { 
					ZVAL_STR_COPY(&type, _4$$3);
				} else {
					ZVAL_LONG(&type, _3$$3);
				}
				ZEPHIR_INIT_NVAR(&message);
				ZVAL_COPY(&message, _1$$3);
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "outputmessage", &_5, 0, &type, &message);
				zephir_check_call_status();
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &messages, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_2$$3, &messages, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_2$$3)) {
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
	}
	ZEPHIR_CALL_PARENT(NULL, phalcon_flash_session_ce, getThis(), "clear", &_6, 0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Clear messages in the session messenger
 */
PHP_METHOD(Phalcon_Flash_Session, clear) {

	zval _0;
	zephir_fcall_cache_entry *_1 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZVAL_BOOL(&_0, 1);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "_getsessionmessages", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_CALL_PARENT(NULL, phalcon_flash_session_ce, getThis(), "clear", &_1, 0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

