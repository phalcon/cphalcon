
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
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/operators.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/hash.h"


/**
 * Phalcon\Flash\Session
 *
 * Temporarily stores the messages in session, then messages can be printed in the next request
 */
ZEPHIR_INIT_CLASS(Phalcon_Flash_Session) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Flash, Session, phalcon, flash_session, phalcon_flash_ce, phalcon_flash_session_method_entry, 0);

	zend_declare_property_null(phalcon_flash_session_ce, SL("_dependencyInjector"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_flash_session_ce TSRMLS_CC, 1, phalcon_flashinterface_ce);
	zend_class_implements(phalcon_flash_session_ce TSRMLS_CC, 1, phalcon_di_injectionawareinterface_ce);
	return SUCCESS;

}

/**
 * Sets the dependency injector
 */
PHP_METHOD(Phalcon_Flash_Session, setDI) {

	zval *dependencyInjector, dependencyInjector_sub;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&dependencyInjector_sub);

	zephir_fetch_params(0, 1, 0, &dependencyInjector);



	zephir_update_property_zval(this_ptr, SL("_dependencyInjector"), dependencyInjector);

}

/**
 * Returns the internal dependency injector
 */
PHP_METHOD(Phalcon_Flash_Session, getDI) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "_dependencyInjector");

}

/**
 * Returns the messages stored in session
 */
PHP_METHOD(Phalcon_Flash_Session, _getSessionMessages) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *remove_param = NULL, *type = NULL, type_sub, __$null, dependencyInjector, session, messages, returnMessages, _0, _1, _2, _4$$6, _5$$7;
	zend_bool remove, _3;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&type_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&dependencyInjector);
	ZVAL_UNDEF(&session);
	ZVAL_UNDEF(&messages);
	ZVAL_UNDEF(&returnMessages);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4$$6);
	ZVAL_UNDEF(&_5$$7);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &remove_param, &type);

	remove = zephir_get_boolval(remove_param);
	if (!type) {
		type = &type_sub;
		type = &__$null;
	}


	zephir_read_property(&_0, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&dependencyInjector, &_0);
	if (Z_TYPE_P(&dependencyInjector) != IS_OBJECT) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_flash_exception_ce, "A dependency injection container is required to access the 'session' service", "phalcon/flash/session.zep", 64);
		return;
	}
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "session");
	ZEPHIR_CALL_METHOD(&_1, &dependencyInjector, "getshared", NULL, 0, &_2);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&session, &_1);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "_flashMessages");
	ZEPHIR_CALL_METHOD(&messages, &session, "get", NULL, 0, &_2);
	zephir_check_call_status();
	_3 = Z_TYPE_P(type) == IS_STRING;
	if (_3) {
		_3 = zephir_array_isset(&messages, type);
	}
	if (_3) {
		ZEPHIR_OBS_VAR(&returnMessages);
		if (!(zephir_array_isset_fetch(&returnMessages, &messages, type, 0 TSRMLS_CC))) {
			ZEPHIR_INIT_NVAR(&returnMessages);
			array_init(&returnMessages);
		}
		if (remove == 1) {
			zephir_array_unset(&messages, type, PH_SEPARATE);
			ZEPHIR_INIT_VAR(&_4$$6);
			ZVAL_STRING(&_4$$6, "_flashMessages");
			ZEPHIR_CALL_METHOD(NULL, &session, "set", NULL, 0, &_4$$6, &messages);
			zephir_check_call_status();
		}
		RETURN_CCTOR(returnMessages);
	}
	if (remove == 1) {
		ZEPHIR_INIT_VAR(&_5$$7);
		ZVAL_STRING(&_5$$7, "_flashMessages");
		ZEPHIR_CALL_METHOD(NULL, &session, "remove", NULL, 0, &_5$$7);
		zephir_check_call_status();
	}
	RETURN_CCTOR(messages);

}

/**
 * Stores the messages in session
 */
PHP_METHOD(Phalcon_Flash_Session, _setSessionMessages) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *messages_param = NULL, dependencyInjector, session, _0, _1, _2;
	zval messages;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&messages);
	ZVAL_UNDEF(&dependencyInjector);
	ZVAL_UNDEF(&session);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &messages_param);

	ZEPHIR_OBS_VAR_ONCE(&messages);
	ZVAL_COPY(&messages, messages_param);


	zephir_read_property(&_0, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&dependencyInjector, &_0);
	if (Z_TYPE_P(&dependencyInjector) != IS_OBJECT) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_flash_exception_ce, "A dependency injection container is required to access the 'session' service", "phalcon/flash/session.zep", 97);
		return;
	}
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "session");
	ZEPHIR_CALL_METHOD(&_1, &dependencyInjector, "getshared", NULL, 0, &_2);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&session, &_1);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "_flashMessages");
	ZEPHIR_CALL_METHOD(NULL, &session, "set", NULL, 0, &_2, &messages);
	zephir_check_call_status();
	RETURN_CTOR(messages);

}

/**
 * Adds a message to the session flasher
 */
PHP_METHOD(Phalcon_Flash_Session, message) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *type_param = NULL, *message_param = NULL, messages, _0, _1$$4;
	zval type, message;
	ZEPHIR_INIT_THIS();

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

	int ZEPHIR_LAST_CALL_STATUS;
	zval *type = NULL, type_sub, __$null, messages, _0;
	ZEPHIR_INIT_THIS();

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

	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool remove;
	zval *type = NULL, type_sub, *remove_param = NULL, __$null, _0;
	ZEPHIR_INIT_THIS();

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

	zend_string *_3$$3;
	zend_ulong _2$$3;
	zephir_fcall_cache_entry *_4 = NULL, *_5 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *remove_param = NULL, type, message, messages, _0, *_1$$3;
	zend_bool remove;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&messages);
	ZVAL_UNDEF(&_0);

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
		zephir_is_iterable(&messages, 0, "phalcon/flash/session.zep", 161);
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&messages), _2$$3, _3$$3, _1$$3)
		{
			ZEPHIR_INIT_NVAR(&type);
			if (_3$$3 != NULL) { 
				ZVAL_STR_COPY(&type, _3$$3);
			} else {
				ZVAL_LONG(&type, _2$$3);
			}
			ZEPHIR_INIT_NVAR(&message);
			ZVAL_COPY(&message, _1$$3);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "outputmessage", &_4, 0, &type, &message);
			zephir_check_call_status();
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&message);
		ZEPHIR_INIT_NVAR(&type);
	}
	ZEPHIR_CALL_PARENT(NULL, phalcon_flash_session_ce, this_ptr, "clear", &_5, 205);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Clear messages in the session messenger
 */
PHP_METHOD(Phalcon_Flash_Session, clear) {

	zval _0;
	zephir_fcall_cache_entry *_1 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZVAL_BOOL(&_0, 1);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "_getsessionmessages", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_CALL_PARENT(NULL, phalcon_flash_session_ce, this_ptr, "clear", &_1, 205);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

