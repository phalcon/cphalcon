
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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_phalcon.h"
#include "phalcon.h"

#include "Zend/zend_operators.h"
#include "Zend/zend_exceptions.h"
#include "Zend/zend_interfaces.h"

#include "kernel/main.h"
#include "kernel/memory.h"

#include "kernel/object.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/array.h"

/**
 * Phalcon\Flash\Session
 *
 * Temporarily stores the messages in session, then messages can be printed in the next request
 */


/**
 * Phalcon\Flash\Session initializer
 */
PHALCON_INIT_CLASS(Phalcon_Flash_Session){

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Flash, Session, flash_session, "phalcon\\flash", phalcon_flash_session_method_entry, 0);

	zend_declare_property_null(phalcon_flash_session_ce, SL("_dependencyInjector"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_flash_session_ce TSRMLS_CC, 2, phalcon_flashinterface_ce, phalcon_di_injectionawareinterface_ce);

	return SUCCESS;
}

/**
 * Sets the dependency injector
 *
 * @param Phalcon\DiInterface $dependencyInjector
 */
PHP_METHOD(Phalcon_Flash_Session, setDI){

	zval *dependency_injector;

	phalcon_fetch_params(0, 1, 0, &dependency_injector);
	
	phalcon_update_property_zval(this_ptr, SL("_dependencyInjector"), dependency_injector TSRMLS_CC);
	
}

/**
 * Returns the internal dependency injector
 *
 * @return Phalcon\DiInterface
 */
PHP_METHOD(Phalcon_Flash_Session, getDI){


	RETURN_MEMBER(this_ptr, "_dependencyInjector");
}

/**
 * Returns the messages stored in session
 *
 * @param boolean $remove
 * @return array
 */
PHP_METHOD(Phalcon_Flash_Session, _getSessionMessages){

	zval *remove, *dependency_injector, *service;
	zval *session, *index_name, *messages;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &remove);
	
	PHALCON_OBS_VAR(dependency_injector);
	phalcon_read_property_this(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_flash_exception_ce, "A dependency injection container is required to access the 'session' service");
		return;
	}
	
	PHALCON_INIT_VAR(service);
	ZVAL_STRING(service, "session", 1);
	
	PHALCON_INIT_VAR(session);
	PHALCON_CALL_METHOD_PARAMS_1(session, dependency_injector, "getshared", service);
	
	PHALCON_INIT_VAR(index_name);
	ZVAL_STRING(index_name, "_flashMessages", 1);
	
	PHALCON_INIT_VAR(messages);
	PHALCON_CALL_METHOD_PARAMS_1(messages, session, "get", index_name);
	if (PHALCON_IS_TRUE(remove)) {
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(session, "remove", index_name);
	}
	
	
	RETURN_CCTOR(messages);
}

/**
 * Stores the messages in session
 *
 * @param array $messages
 */
PHP_METHOD(Phalcon_Flash_Session, _setSessionMessages){

	zval *messages = NULL, *dependency_injector, *service;
	zval *session, *index_name;
	zval *r0 = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &messages);
	
	PHALCON_SEPARATE_PARAM(messages);
	
	PHALCON_OBS_VAR(dependency_injector);
	phalcon_read_property_this(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_flash_exception_ce, "A dependency injection container is required to access the 'session' service");
		return;
	}
	
	PHALCON_INIT_VAR(service);
	ZVAL_STRING(service, "session", 1);
	
	PHALCON_INIT_VAR(session);
	PHALCON_CALL_METHOD_PARAMS_1(session, dependency_injector, "getshared", service);
	
	PHALCON_INIT_VAR(index_name);
	ZVAL_STRING(index_name, "_flashMessages", 1);
	
	PHALCON_INIT_VAR(r0);
	PHALCON_CALL_METHOD_PARAMS_2(r0, session, "set", index_name, messages);
	PHALCON_CPY_WRT(messages, r0);
	
	RETURN_CCTOR(messages);
}

/**
 * Adds a message to the session flasher
 *
 * @param string $type
 * @param string $message
 */
PHP_METHOD(Phalcon_Flash_Session, message){

	zval *type, *message, *remove, *messages = NULL;
	zval *a0 = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 0, &type, &message);
	
	PHALCON_INIT_VAR(remove);
	ZVAL_BOOL(remove, 0);
	
	PHALCON_INIT_VAR(messages);
	PHALCON_CALL_METHOD_PARAMS_1(messages, this_ptr, "_getsessionmessages", remove);
	if (Z_TYPE_P(messages) != IS_ARRAY) { 
		PHALCON_INIT_NVAR(messages);
		array_init(messages);
	}
	
	if (!phalcon_array_isset(messages, type)) {
		PHALCON_INIT_VAR(a0);
		array_init(a0);
		phalcon_array_update_zval(&messages, type, &a0, PH_COPY | PH_SEPARATE TSRMLS_CC);
	}
	
	phalcon_array_update_append_multi_2(&messages, type, message, 0 TSRMLS_CC);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(this_ptr, "_setsessionmessages", messages);
	
	PHALCON_MM_RESTORE();
}

/**
 * Returns the messages in the session flasher
 *
 * @param string $type
 * @param boolean $remove
 * @return array
 */
PHP_METHOD(Phalcon_Flash_Session, getMessages){

	zval *type = NULL, *remove = NULL, *messages, *return_messages;
	zval *empty_arr;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 2, &type, &remove);
	
	if (!type) {
		PHALCON_INIT_VAR(type);
	}
	
	if (!remove) {
		PHALCON_INIT_VAR(remove);
		ZVAL_BOOL(remove, 1);
	}
	
	PHALCON_INIT_VAR(messages);
	PHALCON_CALL_METHOD_PARAMS_1(messages, this_ptr, "_getsessionmessages", remove);
	if (Z_TYPE_P(messages) == IS_ARRAY) { 
		if (Z_TYPE_P(type) == IS_STRING) {
			if (phalcon_array_isset(messages, type)) {
				PHALCON_OBS_VAR(return_messages);
				phalcon_array_fetch(&return_messages, messages, type, PH_NOISY_CC);
				RETURN_CCTOR(return_messages);
			}
		}
	
		RETURN_CCTOR(messages);
	}
	
	PHALCON_INIT_VAR(empty_arr);
	array_init(empty_arr);
	
	RETURN_CTOR(empty_arr);
}

/**
 * Prints the messages in the session flasher
 *
 * @param string $type
 * @param boolean $remove
 */
PHP_METHOD(Phalcon_Flash_Session, output){

	zval *remove = NULL, *messages, *message = NULL, *type = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 1, &remove);
	
	if (!remove) {
		PHALCON_INIT_VAR(remove);
		ZVAL_BOOL(remove, 1);
	}
	
	PHALCON_INIT_VAR(messages);
	PHALCON_CALL_METHOD_PARAMS_1(messages, this_ptr, "_getsessionmessages", remove);
	if (Z_TYPE_P(messages) == IS_ARRAY) { 
	
		if (!phalcon_is_iterable(messages, &ah0, &hp0, 0, 0 TSRMLS_CC)) {
			return;
		}
	
		while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
			PHALCON_GET_FOREACH_KEY(type, ah0, hp0);
			PHALCON_GET_FOREACH_VALUE(message);
	
			PHALCON_CALL_METHOD_PARAMS_2_NORETURN(this_ptr, "outputmessage", type, message);
	
			zend_hash_move_forward_ex(ah0, &hp0);
		}
	
	}
	
	PHALCON_MM_RESTORE();
}

