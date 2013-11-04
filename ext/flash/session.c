
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
#include "kernel/hash.h"

/**
 * Phalcon\Flash\Session
 *
 * Temporarily stores the messages in session, then messages can be printed in the next request
 */


/**
 * Phalcon\Flash\Session initializer
 */
PHALCON_INIT_CLASS(Phalcon_Flash_Session){

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Flash, Session, flash_session, phalcon_flash_ce, phalcon_flash_session_method_entry, 0);

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
	
	phalcon_update_property_this(this_ptr, SL("_dependencyInjector"), dependency_injector TSRMLS_CC);
	
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
	zval *session, *index_name;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &remove);
	
	dependency_injector = phalcon_fetch_nproperty_this(this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	if (unlikely(Z_TYPE_P(dependency_injector) != IS_OBJECT)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_flash_exception_ce, "A dependency injection container is required to access the 'session' service");
		return;
	}
	
	PHALCON_INIT_VAR(service);
	ZVAL_STRING(service, "session", 1);
	
	PHALCON_INIT_VAR(session);
	phalcon_call_method_p1(session, dependency_injector, "getshared", service);
	PHALCON_VERIFY_INTERFACE(session, phalcon_session_adapterinterface_ce);
	
	PHALCON_INIT_VAR(index_name);
	ZVAL_STRING(index_name, "_flashMessages", 1);
	
	phalcon_return_call_method_p1(session, "get", index_name);
	if (PHALCON_IS_TRUE(remove)) {
		phalcon_call_method_p1_noret(session, "remove", index_name);
	}
	
	RETURN_MM();
}

/**
 * Stores the messages in session
 *
 * @param array $messages
 */
PHP_METHOD(Phalcon_Flash_Session, _setSessionMessages){

	zval *messages, *dependency_injector, *service;
	zval *session, *index_name;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &messages);
	
	dependency_injector = phalcon_fetch_nproperty_this(this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	if (unlikely(Z_TYPE_P(dependency_injector) != IS_OBJECT)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_flash_exception_ce, "A dependency injection container is required to access the 'session' service");
		return;
	}
	
	PHALCON_INIT_VAR(service);
	ZVAL_STRING(service, "session", 1);
	
	PHALCON_INIT_VAR(session);
	phalcon_call_method_p1(session, dependency_injector, "getshared", service);
	PHALCON_VERIFY_INTERFACE(session, phalcon_session_adapterinterface_ce);
	
	PHALCON_INIT_VAR(index_name);
	ZVAL_STRING(index_name, "_flashMessages", 1);
	phalcon_call_method_p2_noret(session, "set", index_name, messages);
	
	RETURN_CTOR(messages);
}

/**
 * Adds a message to the session flasher
 *
 * @param string $type
 * @param string $message
 */
PHP_METHOD(Phalcon_Flash_Session, message){

	zval *type, *message, *messages = NULL, *empty_array;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 0, &type, &message);
	
	PHALCON_INIT_VAR(messages);
	phalcon_call_method_p1(messages, this_ptr, "_getsessionmessages", PHALCON_GLOBAL(z_false));
	if (Z_TYPE_P(messages) != IS_ARRAY) { 
		PHALCON_INIT_NVAR(messages);
		array_init(messages);
	}
	
	if (!phalcon_array_isset(messages, type)) {
		PHALCON_INIT_VAR(empty_array);
		array_init(empty_array);
		phalcon_array_update_zval(&messages, type, &empty_array, PH_COPY);
	}
	
	phalcon_array_update_append_multi_2(&messages, type, message, 0);
	phalcon_call_method_p1_noret(this_ptr, "_setsessionmessages", messages);
	
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

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 2, &type, &remove);
	
	if (!type) {
		type = PHALCON_GLOBAL(z_null);
	}
	
	if (!remove) {
		remove = PHALCON_GLOBAL(z_true);
	}
	
	PHALCON_INIT_VAR(messages);
	phalcon_call_method_p1(messages, this_ptr, "_getsessionmessages", remove);
	if (Z_TYPE_P(messages) == IS_ARRAY) { 
		if (likely(Z_TYPE_P(type) == IS_STRING)) {
			if (phalcon_array_isset_fetch(&return_messages, messages, type)) {
				RETURN_CTOR(return_messages);
			}

			RETURN_MM_EMPTY_ARRAY();
		}
	
		RETURN_CCTOR(messages);
	}
	
	RETURN_MM_EMPTY_ARRAY();
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
		remove = PHALCON_GLOBAL(z_true);
	}
	
	PHALCON_INIT_VAR(messages);
	phalcon_call_method_p1(messages, this_ptr, "_getsessionmessages", remove);
	if (Z_TYPE_P(messages) == IS_ARRAY) { 
	
		phalcon_is_iterable(messages, &ah0, &hp0, 0, 0);
	
		while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
			PHALCON_GET_HKEY(type, ah0, hp0);
			PHALCON_GET_HVALUE(message);
	
			phalcon_call_method_p2_noret(this_ptr, "outputmessage", type, message);
	
			zend_hash_move_forward_ex(ah0, &hp0);
		}
	
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * bool \Phalcon\Flash\Session::has(string $type)
 *
 * @see https://github.com/phalcon/cphalcon/issues/1342
 */
PHP_METHOD(Phalcon_Flash_Session, has) {

	zval *type, *messages;

	phalcon_fetch_params(0, 0, 1, &type);

	PHALCON_MM_GROW();
	PHALCON_OBS_VAR(messages);
	phalcon_call_method_p1_ex(messages, &messages, this_ptr, "_getsessionmessages", PHALCON_GLOBAL(z_false));

	RETVAL_BOOL(phalcon_array_isset(messages, type));
	PHALCON_MM_RESTORE();
}
