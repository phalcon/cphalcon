
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
#include "kernel/array.h"
#include "kernel/fcall.h"

/**
 * Phalcon\Annotations\Adapter initializer
 */
PHALCON_INIT_CLASS(Phalcon_Annotations_Adapter){

	PHALCON_REGISTER_CLASS(Phalcon\\Annotations, Adapter, annotations_adapter, phalcon_annotations_adapter_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(phalcon_annotations_adapter_ce, SL("_annotations"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;
}

/**
 * x
 *
 * @
 */
PHP_METHOD(Phalcon_Annotations_Adapter, get){

	zval *class_name, *annotations, *class_annotations = NULL;
	zval *reader, *parsed_annotations;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &class_name) == FAILURE) {
		RETURN_MM_NULL();
	}

	PHALCON_OBS_VAR(annotations);
	phalcon_read_property(&annotations, this_ptr, SL("_annotations"), PH_NOISY_CC);
	if (Z_TYPE_P(annotations) == IS_ARRAY) { 
		if (phalcon_array_isset(annotations, class_name)) {
			PHALCON_OBS_VAR(class_annotations);
			phalcon_array_fetch(&class_annotations, annotations, class_name, PH_NOISY_CC);
			RETURN_CCTOR(class_annotations);
		}
	}
	
	PHALCON_INIT_NVAR(class_annotations);
	PHALCON_CALL_METHOD_PARAMS_1(class_annotations, this_ptr, "read", class_name);
	if (Z_TYPE_P(class_annotations) == IS_NULL) {
	
		PHALCON_INIT_VAR(reader);
		object_init_ex(reader, phalcon_annotations_reader_ce);
	
		PHALCON_INIT_VAR(parsed_annotations);
		PHALCON_CALL_METHOD_PARAMS_1(parsed_annotations, reader, "parse", class_name);
		if (Z_TYPE_P(parsed_annotations) == IS_ARRAY) { 
			PHALCON_INIT_NVAR(class_annotations);
			object_init_ex(class_annotations, phalcon_annotations_reflection_ce);
			PHALCON_CALL_METHOD_PARAMS_1_NORETURN(class_annotations, "__construct", parsed_annotations);
	
			phalcon_update_property_array(this_ptr, SL("_annotations"), class_name, class_annotations TSRMLS_CC);
			PHALCON_CALL_METHOD_PARAMS_2_NORETURN(this_ptr, "write", class_name, class_annotations);
		}
	}
	
	
	RETURN_CCTOR(class_annotations);
}

