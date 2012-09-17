
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2012 Phalcon Team (http://www.phalconphp.com)       |
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
#include "kernel/array.h"

/**
 * Phalcon\Flash\Session
 *
 * Temporarily stores the messages in session, then messages can be printed in the next request
 */

/**
 * Sets the dependency injector
 *
 * @param Phalcon\DI $dependencyInjector
 */
PHP_METHOD(Phalcon_Flash_Session, setDI){

	zval *dependency_injector = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &dependency_injector) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_dependencyInjector"), dependency_injector TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Returns the internal dependency injector
 *
 * @return Phalcon\DI
 */
PHP_METHOD(Phalcon_Flash_Session, getDI){

	zval *dependency_injector = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(dependency_injector);
	phalcon_read_property(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	
	RETURN_CCTOR(dependency_injector);
}

/**
 * Returns the messages stored in session
 *
 * @param boolean $remove
 * @return array
 */
PHP_METHOD(Phalcon_Flash_Session, _getSessionMessages){

	zval *remove = NULL, *dependency_injector = NULL, *service = NULL;
	zval *session = NULL, *index_name = NULL, *messages = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &remove) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(dependency_injector);
	phalcon_read_property(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_flash_exception_ce, "A dependency injection container is required to access the 'session' service");
		return;
	}
	
	PHALCON_INIT_VAR(service);
	ZVAL_STRING(service, "session", 1);
	
	PHALCON_INIT_VAR(session);
	PHALCON_CALL_METHOD_PARAMS_1(session, dependency_injector, "getshared", service, PH_NO_CHECK);
	
	PHALCON_INIT_VAR(index_name);
	ZVAL_STRING(index_name, "_flashMessages", 1);
	
	PHALCON_INIT_VAR(messages);
	PHALCON_CALL_METHOD_PARAMS_1(messages, session, "get", index_name, PH_NO_CHECK);
	if (Z_TYPE_P(remove) == IS_BOOL && Z_BVAL_P(remove)) {
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(session, "remove", index_name, PH_NO_CHECK);
	}
	
	
	RETURN_CCTOR(messages);
}

/**
 * Stores the messages in session
 *
 * @param array $messages
 */
PHP_METHOD(Phalcon_Flash_Session, _setSessionMessages){

	zval *messages = NULL, *dependency_injector = NULL, *service = NULL;
	zval *session = NULL, *index_name = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &messages) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_SEPARATE_PARAM(messages);
	
	PHALCON_INIT_VAR(dependency_injector);
	phalcon_read_property(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_flash_exception_ce, "A dependency injection container is required to access the 'session' service");
		return;
	}
	
	PHALCON_INIT_VAR(service);
	ZVAL_STRING(service, "session", 1);
	
	PHALCON_INIT_VAR(session);
	PHALCON_CALL_METHOD_PARAMS_1(session, dependency_injector, "getshared", service, PH_NO_CHECK);
	
	PHALCON_INIT_VAR(index_name);
	ZVAL_STRING(index_name, "_flashMessages", 1);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD_PARAMS_2(r0, session, "set", index_name, messages, PH_NO_CHECK);
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

	zval *type = NULL, *message = NULL, *remove = NULL, *messages = NULL;
	zval *a0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &type, &message) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(remove);
	ZVAL_BOOL(remove, 0);
	
	PHALCON_INIT_VAR(messages);
	PHALCON_CALL_METHOD_PARAMS_1(messages, this_ptr, "_getsessionmessages", remove, PH_NO_CHECK);
	if (Z_TYPE_P(messages) != IS_ARRAY) { 
		PHALCON_INIT_VAR(messages);
		array_init(messages);
	}
	
	eval_int = phalcon_array_isset(messages, type);
	if (!eval_int) {
		PHALCON_ALLOC_ZVAL_MM(a0);
		array_init(a0);
		phalcon_array_update_zval(&messages, type, &a0, PH_COPY | PH_SEPARATE TSRMLS_CC);
	}
	
	phalcon_array_update_append_multi_2(&messages, type, message, 0 TSRMLS_CC);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(this_ptr, "_setsessionmessages", messages, PH_NO_CHECK);
	
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

	zval *type = NULL, *remove = NULL, *messages = NULL, *return_messages = NULL;
	zval *empty_arr = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|zz", &type, &remove) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!type) {
		PHALCON_ALLOC_ZVAL_MM(type);
		ZVAL_NULL(type);
	}
	
	if (!remove) {
		PHALCON_ALLOC_ZVAL_MM(remove);
		ZVAL_BOOL(remove, 1);
	}
	
	PHALCON_INIT_VAR(messages);
	PHALCON_CALL_METHOD_PARAMS_1(messages, this_ptr, "_getsessionmessages", remove, PH_NO_CHECK);
	if (Z_TYPE_P(messages) == IS_ARRAY) { 
		if (Z_TYPE_P(type) == IS_STRING) {
			eval_int = phalcon_array_isset(messages, type);
			if (eval_int) {
				PHALCON_INIT_VAR(return_messages);
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

	zval *remove = NULL, *messages = NULL, *message = NULL, *type = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *hash_index;
	uint hash_index_len;
	ulong hash_num;
	int hash_type;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &remove) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!remove) {
		PHALCON_ALLOC_ZVAL_MM(remove);
		ZVAL_BOOL(remove, 1);
	}
	
	PHALCON_INIT_VAR(messages);
	PHALCON_CALL_METHOD_PARAMS_1(messages, this_ptr, "_getsessionmessages", remove, PH_NO_CHECK);
	if (Z_TYPE_P(messages) == IS_ARRAY) { 
		if (!phalcon_valid_foreach(messages TSRMLS_CC)) {
			return;
		}
		
		ah0 = Z_ARRVAL_P(messages);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_9dca_0:
			if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
				goto fee_9dca_0;
			}
			
			PHALCON_INIT_VAR(type);
			PHALCON_GET_FOREACH_KEY(type, ah0, hp0);
			PHALCON_INIT_VAR(message);
			ZVAL_ZVAL(message, *hd, 1, 0);
			PHALCON_CALL_METHOD_PARAMS_2_NORETURN(this_ptr, "outputmessage", type, message, PH_NO_CHECK);
			zend_hash_move_forward_ex(ah0, &hp0);
			goto fes_9dca_0;
		fee_9dca_0:
		if(0){}
		
	}
	
	PHALCON_MM_RESTORE();
}

