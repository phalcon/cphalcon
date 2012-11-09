
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
  |          Kenji Minamoto <kenji.minamoto@gmail.com>                     |
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

/**
 * Phalcon\Mvc\Collection\Manager initializer
 */
PHALCON_INIT_CLASS(Phalcon_Mvc_Collection_Manager){

	PHALCON_REGISTER_CLASS(Phalcon\\Mvc\\Collection, Manager, mvc_collection_manager, phalcon_mvc_collection_manager_method_entry, 0);

	zend_declare_property_null(phalcon_mvc_collection_manager_ce, SL("_initialized"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;
}

/**
 * Phalcon\Mvc\Collection\Manager constructor
 */
PHP_METHOD(Phalcon_Mvc_Collection_Manager, __construct){


	phalcon_update_property_empty_array(phalcon_mvc_collection_manager_ce, this_ptr, SL("_initialized") TSRMLS_CC);
	
}

PHP_METHOD(Phalcon_Mvc_Collection_Manager, isInitialized){

	zval *collection;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &collection) == FAILURE) {
		RETURN_NULL();
	}

	RETURN_FALSE;
}

PHP_METHOD(Phalcon_Mvc_Collection_Manager, initialize){


	
}

