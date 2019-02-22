
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
#include "kernel/array.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/memory.h"
#include "kernel/operators.h"


/**
 * This file is part of the Phalcon.
 *
 * (c) Phalcon Team <team@phalcon.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Helper\Arr
 *
 * This class offers quick array functions throught the framework
 */
ZEPHIR_INIT_CLASS(Phalcon_Helper_Arr) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Helper, Arr, phalcon, helper_arr, phalcon_helper_arr_method_entry, 0);

	return SUCCESS;

}

/**
 * Helper method to get an array element or a default
 */
PHP_METHOD(Phalcon_Helper_Arr, get) {

	zval *collection_param = NULL, *index, index_sub, *defaultValue, defaultValue_sub, value;
	zval collection;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&collection);
	ZVAL_UNDEF(&index_sub);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_UNDEF(&value);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &collection_param, &index, &defaultValue);

	ZEPHIR_OBS_COPY_OR_DUP(&collection, collection_param);


	if (EXPECTED(zephir_array_isset_fetch(&value, &collection, index, 1 TSRMLS_CC))) {
		RETURN_CTOR(&value);
	}
	RETVAL_ZVAL(defaultValue, 1, 0);
	RETURN_MM();

}

/**
 * Helper method to get an array element or a default
 */
PHP_METHOD(Phalcon_Helper_Arr, has) {

	zval *collection_param = NULL, *index, index_sub;
	zval collection;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&collection);
	ZVAL_UNDEF(&index_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &collection_param, &index);

	ZEPHIR_OBS_COPY_OR_DUP(&collection, collection_param);


	RETURN_MM_BOOL(zephir_array_isset(&collection, index));

}

/**
 * Helper method to set an array element
 */
PHP_METHOD(Phalcon_Helper_Arr, set) {

	zval *collection_param = NULL, *value, value_sub, *index = NULL, index_sub, __$null;
	zval collection;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&collection);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&index_sub);
	ZVAL_NULL(&__$null);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &collection_param, &value, &index);

	ZEPHIR_OBS_COPY_OR_DUP(&collection, collection_param);
	if (!index) {
		index = &index_sub;
		index = &__$null;
	}


	if (Z_TYPE_P(index) == IS_NULL) {
		zephir_array_append(&collection, value, PH_SEPARATE, "phalcon/helper/arr.zep", 50);
	} else {
		zephir_array_update_zval(&collection, index, value, PH_COPY | PH_SEPARATE);
	}
	RETURN_CTOR(&collection);

}

