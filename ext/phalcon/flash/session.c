
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
#include "kernel/array.h"
#include "kernel/hash.h"


/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2013 Phalcon Team (http://www.phalconphp.com)       |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file docs/LICENSE.txt.                        |
 |                                                                        |
 | If you did not receive a copy of the license and are unable to         |
 | obtain it through the world-wide-web, please send an email             |
 | to license@phalconphp.com so we can send you a copy immediately.       |
 +------------------------------------------------------------------------+
 | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
 |          Eduar Carvajal <eduar@phalconphp.com>                         |
 +------------------------------------------------------------------------+
 */
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
 *
 * @param Phalcon\DiInterface dependencyInjector
 */
PHP_METHOD(Phalcon_Flash_Session, setDI) {

	zval *dependencyInjector;

	zephir_fetch_params(0, 1, 0, &dependencyInjector);



	zephir_update_property_this(this_ptr, SL("_dependencyInjector"), dependencyInjector TSRMLS_CC);

}

/**
 * Returns the internal dependency injector
 *
 * @return Phalcon\DiInterface
 */
PHP_METHOD(Phalcon_Flash_Session, getDI) {


	RETURN_MEMBER(this_ptr, "_dependencyInjector");

}

/**
 * Returns the messages stored in session
 *
 * @param boolean remove
 * @return array
 */
PHP_METHOD(Phalcon_Flash_Session, _getSessionMessages) {

	zval *remove_param = NULL, *dependencyInjector, *session = NULL, *messages, *_0, *_1;
	zend_bool remove;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &remove_param);

		remove = zephir_get_boolval(remove_param);


	dependencyInjector = zephir_fetch_nproperty_this(this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	if ((Z_TYPE_P(dependencyInjector) != IS_OBJECT)) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_flash_exception_ce, "A dependency injection container is required to access the 'session' service");
		return;
	}
	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "session", 1);
	zephir_call_method_p1(_0, dependencyInjector, "getshared", _1);
	ZEPHIR_CPY_WRT(session, _0);
	ZEPHIR_INIT_BNVAR(_0);
	ZVAL_STRING(_0, "_flashMessages", 1);
	ZEPHIR_INIT_VAR(messages);
	zephir_call_method_p1(messages, session, "get", _0);
	if ((remove == 1)) {
		ZEPHIR_INIT_BNVAR(_0);
		ZVAL_STRING(_0, "_flashMessages", 1);
		zephir_call_method_p1_noret(session, "remove", _0);
	}
	RETURN_CCTOR(messages);

}

/**
 * Stores the messages in session
 *
 * @param array messages
 */
PHP_METHOD(Phalcon_Flash_Session, _setSessionMessages) {

	zval *messages, *dependencyInjector, *session = NULL, *_0, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &messages);



	dependencyInjector = zephir_fetch_nproperty_this(this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	if ((Z_TYPE_P(dependencyInjector) != IS_OBJECT)) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_flash_exception_ce, "A dependency injection container is required to access the 'session' service");
		return;
	}
	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "session", 1);
	zephir_call_method_p1(_0, dependencyInjector, "getshared", _1);
	ZEPHIR_CPY_WRT(session, _0);
	ZEPHIR_INIT_BNVAR(_0);
	ZVAL_STRING(_0, "_flashMessages", 1);
	zephir_call_method_p2_noret(session, "set", _0, messages);
	RETURN_CCTOR(messages);

}

/**
 * Adds a message to the session flasher
 *
 * @param string type
 * @param string message
 */
PHP_METHOD(Phalcon_Flash_Session, message) {

	zval *type_param = NULL, *message_param = NULL, *messages, *_0;
	zval *type = NULL, *message = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &type_param, &message_param);

		zephir_get_strval(type, type_param);
		zephir_get_strval(message, message_param);


	ZEPHIR_INIT_VAR(messages);
	zephir_call_method_p1(messages, this_ptr, "_getsessionmessages", ZEPHIR_GLOBAL(global_false));
	if ((Z_TYPE_P(messages) != IS_ARRAY)) {
		ZEPHIR_INIT_BNVAR(messages);
		array_init(messages);
	}
	if (!(zephir_array_isset(messages, type))) {
		ZEPHIR_INIT_VAR(_0);
		array_init(_0);
		zephir_array_update_zval(&messages, type, &_0, PH_COPY | PH_SEPARATE);
	}
	zephir_call_method_p1_noret(this_ptr, "_setsessionmessages", messages);
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns the messages in the session flasher
 *
 * @param string type
 * @param boolean remove
 * @return array
 */
PHP_METHOD(Phalcon_Flash_Session, getMessages) {

	zval *type = NULL, *remove = NULL, *messages, *returnMessages, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &type, &remove);

	if (!type) {
		ZEPHIR_CPY_WRT(type, ZEPHIR_GLOBAL(global_null));
	}
	if (!remove) {
		ZEPHIR_CPY_WRT(remove, ZEPHIR_GLOBAL(global_true));
	}


	ZEPHIR_INIT_VAR(messages);
	zephir_call_method_p1(messages, this_ptr, "_getsessionmessages", remove);
	if ((Z_TYPE_P(messages) == IS_ARRAY)) {
		if ((Z_TYPE_P(type) == IS_STRING)) {
			ZEPHIR_OBS_VAR(returnMessages);
			if (zephir_array_isset_fetch(&returnMessages, messages, type TSRMLS_CC)) {
				ZEPHIR_OBS_VAR(_0);
				zephir_array_fetch(&_0, messages, type, PH_NOISY TSRMLS_CC);
				RETURN_CCTOR(_0);
			}
		}
		RETURN_CCTOR(messages);
	}
	array_init(return_value);
	RETURN_MM();

}

/**
 * Prints the messages in the session flasher
 *
 * @param boolean remove
 */
PHP_METHOD(Phalcon_Flash_Session, output) {

	zend_function *_3 = NULL;
	HashTable *_1;
	HashPosition _0;
	zval *remove_param = NULL, *type = NULL, *message = NULL, *messages, **_2;
	zend_bool remove;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &remove_param);

	if (!remove_param) {
		remove = 1;
	} else {
		remove = zephir_get_boolval(remove_param);
	}


	ZEPHIR_INIT_VAR(messages);
	zephir_call_method_p1(messages, this_ptr, "_getsessionmessages", (remove ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false)));
	if ((Z_TYPE_P(messages) == IS_ARRAY)) {
		zephir_is_iterable(messages, &_1, &_0, 0, 0);
		for (
			; zend_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
			; zend_hash_move_forward_ex(_1, &_0)
		) {
			ZEPHIR_GET_HMKEY(type, _1, _0);
			ZEPHIR_GET_HVALUE(message, _2);
			zephir_call_method_p2_cache_noret(this_ptr, "outputmessage", &_3, type, message);
		}
	}
	ZEPHIR_MM_RESTORE();

}

