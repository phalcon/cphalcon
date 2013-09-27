
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/exception.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/memory.h"


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
 * Phalcon\Filter
 *
 * The Phalcon\Filter component provides a set of commonly needed data filters. It provides
 * object oriented wrappers to the php filter extension. Also allows the developer to
 * define his/her own filters
 *
 *<code>
 *	$filter = new Phalcon\Filter();
 *	$filter->sanitize("some(one)@exa\\mple.com", "email"); // returns "someone@example.com"
 *	$filter->sanitize("hello<<", "string"); // returns "hello"
 *	$filter->sanitize("!100a019", "int"); // returns "100019"
 *	$filter->sanitize("!100a019.01a", "float"); // returns "100019.01"
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Filter) {

	ZEPHIR_REGISTER_CLASS(Phalcon, Filter, phalcon, filter, phalcon_filter_method_entry, 0);

	zend_declare_property_null(phalcon_filter_ce, SL("_filters"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Adds a user-defined filter
 *
 * @param string name
 * @param callable handler
 * @return Phalcon\Filter
 */
PHP_METHOD(Phalcon_Filter, add) {

	zval *name_param = NULL, *handler;
	zval *name = NULL;

	zephir_fetch_params(0, 2, 0, &name_param, &handler);

		zephir_get_strval(name, name_param);


	if ((Z_TYPE_P(handler) != IS_OBJECT)) {
		ZEPHIR_THROW_EXCEPTION_STRW(phalcon_filter_exception_ce, "Filter must be an object");
		return;
	}
	zephir_update_property_array(this_ptr, SL("_filters"), name, handler TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Sanitizes a value with a specified single or set of filters
 *
 * @param  value
 * @param  filters
 * @return mixed
 */
PHP_METHOD(Phalcon_Filter, sanitize) {

	zval *value, *filters;

	zephir_fetch_params(0, 2, 0, &value, &filters);




}

