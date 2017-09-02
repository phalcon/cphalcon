
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
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"


/**
 * Phalcon\Paginator\Adapter\NativeArray
 *
 * Pagination using a PHP array as source of data
 *
 * <code>
 * use Phalcon\Paginator\Adapter\NativeArray;
 *
 * $paginator = new NativeArray(
 *     [
 *         "data"  => [
 *             ["id" => 1, "name" => "Artichoke"],
 *             ["id" => 2, "name" => "Carrots"],
 *             ["id" => 3, "name" => "Beet"],
 *             ["id" => 4, "name" => "Lettuce"],
 *             ["id" => 5, "name" => ""],
 *         ],
 *         "limit" => 2,
 *         "page"  => $currentPage,
 *     ]
 * );
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Paginator_Adapter_NativeArray) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Paginator\\Adapter, NativeArray, phalcon, paginator_adapter_nativearray, phalcon_paginator_adapter_ce, phalcon_paginator_adapter_nativearray_method_entry, 0);

	/**
	 * Configuration of the paginator
	 */
	zend_declare_property_null(phalcon_paginator_adapter_nativearray_ce, SL("_config"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Phalcon\Paginator\Adapter\NativeArray constructor
 */
PHP_METHOD(Phalcon_Paginator_Adapter_NativeArray, __construct) {

	zval *config_param = NULL, page, limit;
	zval config;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&config);
	ZVAL_UNDEF(&page);
	ZVAL_UNDEF(&limit);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &config_param);

	zephir_get_arrval(&config, config_param);


	zephir_update_property_zval(this_ptr, SL("_config"), &config);
	if (zephir_array_isset_string_fetch(&limit, &config, SL("limit"), 1)) {
		zephir_update_property_zval(this_ptr, SL("_limitRows"), &limit);
	}
	if (zephir_array_isset_string_fetch(&page, &config, SL("page"), 1)) {
		zephir_update_property_zval(this_ptr, SL("_page"), &page);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns a slice of the resultset to show in the pagination
 */
PHP_METHOD(Phalcon_Paginator_Adapter_NativeArray, getPaginate) {

	double roundedTotal = 0;
	zval config, items, page, _0, _1, _2, _3, _4, _5;
	zend_long ZEPHIR_LAST_CALL_STATUS, show = 0, pageNumber = 0, totalPages = 0, number = 0, before = 0, next = 0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&config);
	ZVAL_UNDEF(&items);
	ZVAL_UNDEF(&page);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&config);
	zephir_read_property(&config, this_ptr, SL("_config"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(&items);
	zephir_array_fetch_string(&items, &config, SL("data"), PH_NOISY, "phalcon/paginator/adapter/nativearray.zep", 87 TSRMLS_CC);
	if (Z_TYPE_P(&items) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_paginator_exception_ce, "Invalid data for paginator", "phalcon/paginator/adapter/nativearray.zep", 90);
		return;
	}
	ZEPHIR_OBS_VAR(&_0);
	zephir_read_property(&_0, this_ptr, SL("_limitRows"), PH_NOISY_CC);
	show = zephir_get_intval(&_0);
	ZEPHIR_OBS_VAR(&_1);
	zephir_read_property(&_1, this_ptr, SL("_page"), PH_NOISY_CC);
	pageNumber = zephir_get_intval(&_1);
	if (pageNumber <= 0) {
		pageNumber = 1;
	}
	number = zephir_fast_count_int(&items TSRMLS_CC);
	ZVAL_LONG(&_2, show);
	ZEPHIR_CALL_FUNCTION(&_3, "floatval", NULL, 295, &_2);
	zephir_check_call_status();
	roundedTotal = zephir_safe_div_long_zval(number, &_3 TSRMLS_CC);
	totalPages = (int) (roundedTotal);
	if (totalPages != roundedTotal) {
		totalPages++;
	}
	ZVAL_LONG(&_2, (show * ((pageNumber - 1))));
	ZVAL_LONG(&_4, show);
	ZEPHIR_CALL_FUNCTION(&_5, "array_slice", NULL, 367, &items, &_2, &_4);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&items, &_5);
	if (pageNumber < totalPages) {
		next = (pageNumber + 1);
	} else {
		next = totalPages;
	}
	if (pageNumber > 1) {
		before = (pageNumber - 1);
	} else {
		before = 1;
	}
	ZEPHIR_INIT_VAR(&page);
	object_init(&page);
	zephir_update_property_zval(&page, SL("items"), &items);
	ZEPHIR_INIT_ZVAL_NREF(_2);
	ZVAL_LONG(&_2, 1);
	zephir_update_property_zval(&page, SL("first"), &_2);
	ZEPHIR_INIT_ZVAL_NREF(_2);
	ZVAL_LONG(&_2, before);
	zephir_update_property_zval(&page, SL("before"), &_2);
	ZEPHIR_INIT_ZVAL_NREF(_2);
	ZVAL_LONG(&_2, pageNumber);
	zephir_update_property_zval(&page, SL("current"), &_2);
	ZEPHIR_INIT_ZVAL_NREF(_2);
	ZVAL_LONG(&_2, totalPages);
	zephir_update_property_zval(&page, SL("last"), &_2);
	ZEPHIR_INIT_ZVAL_NREF(_2);
	ZVAL_LONG(&_2, next);
	zephir_update_property_zval(&page, SL("next"), &_2);
	ZEPHIR_INIT_ZVAL_NREF(_2);
	ZVAL_LONG(&_2, totalPages);
	zephir_update_property_zval(&page, SL("total_pages"), &_2);
	ZEPHIR_INIT_ZVAL_NREF(_2);
	ZVAL_LONG(&_2, number);
	zephir_update_property_zval(&page, SL("total_items"), &_2);
	zephir_read_property(&_2, this_ptr, SL("_limitRows"), PH_NOISY_CC | PH_READONLY);
	zephir_update_property_zval(&page, SL("limit"), &_2);
	RETURN_CCTOR(&page);

}

