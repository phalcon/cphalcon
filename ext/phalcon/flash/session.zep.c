
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

	zval *dependencyInjector;

	zephir_fetch_params(0, 1, 0, &dependencyInjector);



	zephir_update_property_this(this_ptr, SL("_dependencyInjector"), dependencyInjector TSRMLS_CC);

}

/**
 * Returns the internal dependency injector
 */
PHP_METHOD(Phalcon_Flash_Session, getDI) {

	

	RETURN_MEMBER(this_ptr, "_dependencyInjector");

}

/**
 * Returns the messages stored in session
 */
PHP_METHOD(Phalcon_Flash_Session, _getSessionMessages) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *remove_param = NULL, *type = NULL, *dependencyInjector = NULL, *session = NULL, *messages = NULL, *returnMessages = NULL, *_0, *_1 = NULL, *_2 = NULL, *_4$$6, *_5$$7;
	zend_bool remove, _3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &remove_param, &type);

	remove = zephir_get_boolval(remove_param);
	if (!type) {
		type = ZEPHIR_GLOBAL(global_null);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(dependencyInjector, _0);
	if (Z_TYPE_P(dependencyInjector) != IS_OBJECT) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_flash_exception_ce, "A dependency injection container is required to access the 'session' service", "phalcon/flash/session.zep", 64);
		return;
	}
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "session", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_1, dependencyInjector, "getshared", NULL, 0, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(session, _1);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "_flashMessages", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&messages, session, "get", NULL, 0, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	_3 = Z_TYPE_P(type) == IS_STRING;
	if (_3) {
		_3 = zephir_array_isset(messages, type);
	}
	if (_3) {
		ZEPHIR_OBS_VAR(returnMessages);
		if (!(zephir_array_isset_fetch(&returnMessages, messages, type, 0 TSRMLS_CC))) {
			ZEPHIR_INIT_NVAR(returnMessages);
			array_init(returnMessages);
		}
		if (remove == 1) {
			zephir_array_unset(&messages, type, PH_SEPARATE);
			ZEPHIR_INIT_VAR(_4$$6);
			ZVAL_STRING(_4$$6, "_flashMessages", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(NULL, session, "set", NULL, 0, _4$$6, messages);
			zephir_check_temp_parameter(_4$$6);
			zephir_check_call_status();
		}
		RETURN_CCTOR(returnMessages);
	}
	if (remove == 1) {
		ZEPHIR_INIT_VAR(_5$$7);
		ZVAL_STRING(_5$$7, "_flashMessages", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, session, "remove", NULL, 0, _5$$7);
		zephir_check_temp_parameter(_5$$7);
		zephir_check_call_status();
	}
	RETURN_CCTOR(messages);

}

/**
 * Stores the messages in session
 */
PHP_METHOD(Phalcon_Flash_Session, _setSessionMessages) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *messages_param = NULL, *dependencyInjector = NULL, *session = NULL, *_0, *_1 = NULL, *_2 = NULL;
	zval *messages = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &messages_param);

	messages = messages_param;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(dependencyInjector, _0);
	if (Z_TYPE_P(dependencyInjector) != IS_OBJECT) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_flash_exception_ce, "A dependency injection container is required to access the 'session' service", "phalcon/flash/session.zep", 97);
		return;
	}
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "session", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_1, dependencyInjector, "getshared", NULL, 0, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(session, _1);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "_flashMessages", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, session, "set", NULL, 0, _2, messages);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	RETURN_CTOR(messages);

}

/**
 * Adds a message to the session flasher
 */
PHP_METHOD(Phalcon_Flash_Session, message) {

	int ZEPHIR_LAST_CALL_STATUS;
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

	int ZEPHIR_LAST_CALL_STATUS;
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

	int ZEPHIR_LAST_CALL_STATUS;
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
	int ZEPHIR_LAST_CALL_STATUS;
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
		zephir_is_iterable(messages, &_2$$3, &_1$$3, 0, 0, "phalcon/flash/session.zep", 161);
		for (
		  ; zephir_hash_get_current_data_ex(_2$$3, (void**) &_3$$3, &_1$$3) == SUCCESS
		  ; zephir_hash_move_forward_ex(_2$$3, &_1$$3)
		) {
			ZEPHIR_GET_HMKEY(type, _2$$3, _1$$3);
			ZEPHIR_GET_HVALUE(message, _3$$3);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "outputmessage", &_4, 0, type, message);
			zephir_check_call_status();
		}
	}
	ZEPHIR_CALL_PARENT(NULL, phalcon_flash_session_ce, this_ptr, "clear", &_5, 201);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Clear messages in the session messenger
 */
PHP_METHOD(Phalcon_Flash_Session, clear) {

	zval *_0;
	zephir_fcall_cache_entry *_1 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	ZVAL_BOOL(_0, 1);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "_getsessionmessages", NULL, 0, _0);
	zephir_check_call_status();
	ZEPHIR_CALL_PARENT(NULL, phalcon_flash_session_ce, this_ptr, "clear", &_1, 201);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

