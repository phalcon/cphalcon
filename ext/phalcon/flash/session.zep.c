
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
	zval *remove_param = NULL, *type = NULL, *dependencyInjector = NULL, *session = NULL, *messages = NULL, *returnMessages = NULL, *_0 = NULL, *_1 = NULL, *_2$$5, *_3$$6;
	zend_bool remove;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &remove_param, &type);

	remove = zephir_get_boolval(remove_param);
	if (!type) {
		type = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getdi", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(dependencyInjector, _0);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "session", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_0, dependencyInjector, "getshared", NULL, 0, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(session, _0);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "_flashMessages", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&messages, session, "get", NULL, 0, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	if (Z_TYPE_P(type) == IS_STRING) {
		ZEPHIR_OBS_VAR(returnMessages);
		if (zephir_array_isset_fetch(&returnMessages, messages, type, 0 TSRMLS_CC)) {
			if (remove == 1) {
				zephir_array_unset(&messages, type, PH_SEPARATE);
				ZEPHIR_INIT_VAR(_2$$5);
				ZVAL_STRING(_2$$5, "_flashMessages", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(NULL, session, "set", NULL, 0, _2$$5, messages);
				zephir_check_temp_parameter(_2$$5);
				zephir_check_call_status();
			}
			RETURN_CCTOR(returnMessages);
		}
		array_init(return_value);
		RETURN_MM();
	}
	if (remove == 1) {
		ZEPHIR_INIT_VAR(_3$$6);
		ZVAL_STRING(_3$$6, "_flashMessages", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, session, "remove", NULL, 0, _3$$6);
		zephir_check_temp_parameter(_3$$6);
		zephir_check_call_status();
	}
	RETURN_CCTOR(messages);

}

/**
 * Stores the messages in session
 */
PHP_METHOD(Phalcon_Flash_Session, _setSessionMessages) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *messages_param = NULL, *dependencyInjector = NULL, *session = NULL, *_0 = NULL, *_1 = NULL;
	zval *messages = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &messages_param);

	messages = messages_param;


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getdi", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(dependencyInjector, _0);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "session", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_0, dependencyInjector, "getshared", NULL, 0, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(session, _0);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "_flashMessages", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, session, "set", NULL, 0, _1, messages);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	RETURN_CTOR(messages);

}

/**
 * Adds a message to the session flasher
 */
PHP_METHOD(Phalcon_Flash_Session, message) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *type_param = NULL, *message_param = NULL, *messages = NULL, *_0, *_1$$4;
	zval *type = NULL, *message = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &type_param, &message_param);

	zephir_get_strval(type, type_param);
	zephir_get_strval(message, message_param);


	ZEPHIR_INIT_VAR(_0);
	ZVAL_BOOL(_0, 0);
	ZEPHIR_CALL_METHOD(&messages, this_ptr, "_getsessionmessages", NULL, 0, _0);
	zephir_check_call_status();
	if (Z_TYPE_P(messages) != IS_ARRAY) {
		ZEPHIR_INIT_NVAR(messages);
		array_init(messages);
	}
	if (!(zephir_array_isset(messages, type))) {
		ZEPHIR_INIT_VAR(_1$$4);
		array_init(_1$$4);
		zephir_array_update_zval(&messages, type, &_1$$4, PH_COPY | PH_SEPARATE);
	}
	zephir_array_update_multi(&messages, &message TSRMLS_CC, SL("za"), 2, type);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "_setsessionmessages", NULL, 0, messages);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Checks whether there are messages
 */
PHP_METHOD(Phalcon_Flash_Session, has) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *type = NULL, *messages = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &type);

	if (!type) {
		type = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_BOOL(_0, 0);
	ZEPHIR_CALL_METHOD(&messages, this_ptr, "_getsessionmessages", NULL, 0, _0);
	zephir_check_call_status();
	if (Z_TYPE_P(messages) == IS_ARRAY) {
		if (Z_TYPE_P(type) == IS_STRING) {
			RETURN_MM_BOOL(zephir_array_isset(messages, type));
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
	zval *type = NULL, *remove_param = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &type, &remove_param);

	if (!type) {
		type = ZEPHIR_GLOBAL(global_null);
	}
	if (!remove_param) {
		remove = 1;
	} else {
		remove = zephir_get_boolval(remove_param);
	}


	ZEPHIR_INIT_VAR(_0);
	if (remove) {
		ZVAL_BOOL(_0, 1);
	} else {
		ZVAL_BOOL(_0, 0);
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "_getsessionmessages", NULL, 0, _0, type);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Prints the messages in the session flasher
 */
PHP_METHOD(Phalcon_Flash_Session, output) {

	HashTable *_2$$3;
	HashPosition _1$$3;
	zephir_fcall_cache_entry *_4 = NULL, *_5 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *remove_param = NULL, *type = NULL, *message = NULL, *messages = NULL, *_0, **_3$$3;
	zend_bool remove;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &remove_param);

	if (!remove_param) {
		remove = 1;
	} else {
		remove = zephir_get_boolval(remove_param);
	}


	ZEPHIR_INIT_VAR(_0);
	if (remove) {
		ZVAL_BOOL(_0, 1);
	} else {
		ZVAL_BOOL(_0, 0);
	}
	ZEPHIR_CALL_METHOD(&messages, this_ptr, "_getsessionmessages", NULL, 0, _0);
	zephir_check_call_status();
	if (Z_TYPE_P(messages) == IS_ARRAY) {
		zephir_is_iterable(messages, &_2$$3, &_1$$3, 0, 0, "phalcon/flash/session.zep", 136);
		for (
		  ; zend_hash_get_current_data_ex(_2$$3, (void**) &_3$$3, &_1$$3) == SUCCESS
		  ; zend_hash_move_forward_ex(_2$$3, &_1$$3)
		) {
			ZEPHIR_GET_HMKEY(type, _2$$3, _1$$3);
			ZEPHIR_GET_HVALUE(message, _3$$3);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "outputmessage", &_4, 0, type, message);
			zephir_check_call_status();
		}
	}
	ZEPHIR_CALL_PARENT(NULL, phalcon_flash_session_ce, getThis(), "clear", &_5, 217);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Clear messages in the session messenger
 */
PHP_METHOD(Phalcon_Flash_Session, clear) {

	zval *_0;
	zephir_fcall_cache_entry *_1 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	ZVAL_BOOL(_0, 1);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "_getsessionmessages", NULL, 0, _0);
	zephir_check_call_status();
	ZEPHIR_CALL_PARENT(NULL, phalcon_flash_session_ce, getThis(), "clear", &_1, 217);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

