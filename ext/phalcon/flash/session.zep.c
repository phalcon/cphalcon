
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
#include "kernel/operators.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/array.h"
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
	zval *remove_param = NULL, *dependencyInjector = NULL, *session = NULL, *messages = NULL, *_0, *_1 = NULL, *_2 = NULL;
	zend_bool remove;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &remove_param);

	remove = zephir_get_boolval(remove_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(dependencyInjector, _0);
	if (Z_TYPE_P(dependencyInjector) != IS_OBJECT) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_flash_exception_ce, "A dependency injection container is required to access the 'session' service", "phalcon/flash/session.zep", 63);
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
	if (remove == 1) {
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_STRING(_2, "_flashMessages", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, session, "remove", NULL, 0, _2);
		zephir_check_temp_parameter(_2);
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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_flash_exception_ce, "A dependency injection container is required to access the 'session' service", "phalcon/flash/session.zep", 85);
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
	zval *type_param = NULL, *message_param = NULL, *messages = NULL, *_0 = NULL;
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
		ZEPHIR_INIT_NVAR(_0);
		array_init(_0);
		zephir_array_update_zval(&messages, type, &_0, PH_COPY | PH_SEPARATE);
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
	zval *type = NULL, *remove_param = NULL, *messages = NULL, *returnMessages;

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


	ZEPHIR_CALL_METHOD(&messages, this_ptr, "_getsessionmessages", NULL, 0, (remove ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false)));
	zephir_check_call_status();
	if (Z_TYPE_P(type) != IS_STRING) {
		RETURN_CCTOR(messages);
	}
	if (!(zephir_array_isset_fetch(&returnMessages, messages, type, 1 TSRMLS_CC))) {
		array_init(return_value);
		RETURN_MM();
	}
	RETURN_CTOR(returnMessages);

}

/**
 * Prints the messages in the session flasher
 */
PHP_METHOD(Phalcon_Flash_Session, output) {

	zephir_fcall_cache_entry *_3 = NULL;
	HashTable *_1;
	HashPosition _0;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *remove_param = NULL, *type = NULL, *message = NULL, *messages = NULL, **_2;
	zend_bool remove;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &remove_param);

	if (!remove_param) {
		remove = 1;
	} else {
		remove = zephir_get_boolval(remove_param);
	}


	ZEPHIR_CALL_METHOD(&messages, this_ptr, "_getsessionmessages", NULL, 0, (remove ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false)));
	zephir_check_call_status();
	if (Z_TYPE_P(messages) == IS_ARRAY) {
		zephir_is_iterable(messages, &_1, &_0, 0, 0, "phalcon/flash/session.zep", 161);
		for (
		  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
		  ; zephir_hash_move_forward_ex(_1, &_0)
		) {
			ZEPHIR_GET_HMKEY(type, _1, _0);
			ZEPHIR_GET_HVALUE(message, _2);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "outputmessage", &_3, 0, type, message);
			zephir_check_call_status();
		}
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Clear messages in the session messenger
 */
PHP_METHOD(Phalcon_Flash_Session, clear) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	ZVAL_BOOL(_0, 1);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "_getsessionmessages", NULL, 0, _0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

