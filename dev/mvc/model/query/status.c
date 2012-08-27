
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
#include "kernel/fcall.h"

PHP_METHOD(Phalcon_Mvc_Model_Query_Status, __construct){

	zval *success = NULL, *model = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &success, &model) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_success"), success TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, SL("_model"), model TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

PHP_METHOD(Phalcon_Mvc_Model_Query_Status, getModel){

	zval *model = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(model);
	phalcon_read_property(&model, this_ptr, SL("_model"), PH_NOISY_CC);
	
	RETURN_CCTOR(model);
}

PHP_METHOD(Phalcon_Mvc_Model_Query_Status, getMessages){

	zval *model = NULL, *messages = NULL, *empty_arr = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(model);
	phalcon_read_property(&model, this_ptr, SL("_model"), PH_NOISY_CC);
	if (Z_TYPE_P(model) != IS_NULL) {
		PHALCON_INIT_VAR(messages);
		PHALCON_CALL_METHOD(messages, model, "getmessages", PH_NO_CHECK);
		
		RETURN_CCTOR(messages);
	}
	
	PHALCON_INIT_VAR(empty_arr);
	array_init(empty_arr);
	
	RETURN_CTOR(empty_arr);
}

PHP_METHOD(Phalcon_Mvc_Model_Query_Status, success){

	zval *success = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(success);
	phalcon_read_property(&success, this_ptr, SL("_success"), PH_NOISY_CC);
	
	RETURN_CCTOR(success);
}

