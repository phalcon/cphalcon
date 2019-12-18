
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *
 * Implementation of this file has been influenced by Zend Diactoros
 * @link    https://github.com/zendframework/zend-diactoros
 * @license https://github.com/zendframework/zend-diactoros/blob/master/LICENSE.md
 */
/**
 * Common methods
 */
ZEPHIR_INIT_CLASS(Phalcon_Http_Message_AbstractCommon) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Http\\Message, AbstractCommon, phalcon, http_message_abstractcommon, phalcon_http_message_abstractcommon_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	return SUCCESS;

}

/**
 * Returns a new instance having set the parameter
 *
 * @param mixed  $element
 * @param string $property
 *
 * @return mixed
 */
PHP_METHOD(Phalcon_Http_Message_AbstractCommon, cloneInstance) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval property;
	zval *element, element_sub, *property_param = NULL, newInstance;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&element_sub);
	ZVAL_UNDEF(&newInstance);
	ZVAL_UNDEF(&property);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &element, &property_param);

	zephir_get_strval(&property, property_param);


	ZEPHIR_INIT_VAR(&newInstance);
	if (zephir_clone(&newInstance, this_ptr) == FAILURE) {
		RETURN_MM();
	}
	zephir_update_property_zval_zval(&newInstance, &property, element);
	RETURN_CCTOR(&newInstance);

}

/**
 * Checks the element passed if it is a string
 *
 * @param mixed $element
 */
PHP_METHOD(Phalcon_Http_Message_AbstractCommon, checkStringParameter) {

	zval *element, element_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&element_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &element);



	if (Z_TYPE_P(element) != IS_STRING) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(phalcon_http_message_exception_invalidargumentexception_ce, "Method requires a string argument", "phalcon/Http/Message/AbstractCommon.zep", 52);
		return;
	}

}

/**
 * Checks the element passed; assigns it to the property and returns a
 * clone of the object back
 *
 * @param mixed  $element
 * @param string $property
 *
 * @return mixed
 */
PHP_METHOD(Phalcon_Http_Message_AbstractCommon, processWith) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval property;
	zval *element, element_sub, *property_param = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&element_sub);
	ZVAL_UNDEF(&property);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &element, &property_param);

	zephir_get_strval(&property, property_param);


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkstringparameter", NULL, 19, element);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "cloneinstance", NULL, 20, element, &property);
	zephir_check_call_status();
	RETURN_MM();

}

