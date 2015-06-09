
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
 *<code>
 *	$paginator = new \Phalcon\Paginator\Adapter\Model(
 *		array(
 *			"data"  => array(
 *				array('id' => 1, 'name' => 'Artichoke'),
 *				array('id' => 2, 'name' => 'Carrots'),
 *				array('id' => 3, 'name' => 'Beet'),
 *				array('id' => 4, 'name' => 'Lettuce'),
 *				array('id' => 5, 'name' => '')
 *			),
 *			"limit" => 2,
 *			"page"  => $currentPage
 *		)
 *	);
 *</code>
 *
 */
ZEPHIR_INIT_CLASS(Phalcon_Paginator_Adapter_NativeArray) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Paginator\\Adapter, NativeArray, phalcon, paginator_adapter_nativearray, phalcon_paginator_adapter_ce, phalcon_paginator_adapter_nativearray_method_entry, 0);

	/**
	 * Configuration of the paginator
	 */
	zend_declare_property_null(phalcon_paginator_adapter_nativearray_ce, SL("_config"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_paginator_adapter_nativearray_ce TSRMLS_CC, 1, phalcon_paginator_adapterinterface_ce);
	return SUCCESS;

}

/**
 * Phalcon\Paginator\Adapter\NativeArray constructor
 */
PHP_METHOD(Phalcon_Paginator_Adapter_NativeArray, __construct) {

	zval *config_param = NULL, *page, *limit;
	zval *config = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &config_param);

	zephir_get_arrval(config, config_param);


	zephir_update_property_this(this_ptr, SL("_config"), config TSRMLS_CC);
	if (zephir_array_isset_string_fetch(&limit, config, SS("limit"), 1 TSRMLS_CC)) {
		zephir_update_property_this(this_ptr, SL("_limitRows"), limit TSRMLS_CC);
	}
	if (zephir_array_isset_string_fetch(&page, config, SS("page"), 1 TSRMLS_CC)) {
		zephir_update_property_this(this_ptr, SL("_page"), page TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns a slice of the resultset to show in the pagination
 */
PHP_METHOD(Phalcon_Paginator_Adapter_NativeArray, getPaginate) {

	double roundedTotal;
	int show, pageNumber, totalPages, number, before, next, ZEPHIR_LAST_CALL_STATUS;
	zval *config, *items = NULL, *page, *_0, *_1, _2 = zval_used_for_init, *_3 = NULL, _4, *_5 = NULL, *_6;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(config);
	zephir_read_property_this(&config, this_ptr, SL("_config"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(items);
	zephir_array_fetch_string(&items, config, SL("data"), PH_NOISY, "phalcon/paginator/adapter/nativearray.zep", 87 TSRMLS_CC);
	if (Z_TYPE_P(items) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_paginator_exception_ce, "Invalid data for paginator", "phalcon/paginator/adapter/nativearray.zep", 90);
		return;
	}
	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("_limitRows"), PH_NOISY_CC);
	show = zephir_get_intval(_0);
	ZEPHIR_OBS_VAR(_1);
	zephir_read_property_this(&_1, this_ptr, SL("_page"), PH_NOISY_CC);
	pageNumber = zephir_get_intval(_1);
	if (pageNumber <= 0) {
		pageNumber = 1;
	}
	number = zephir_fast_count_int(items TSRMLS_CC);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_LONG(&_2, show);
	ZEPHIR_CALL_FUNCTION(&_3, "floatval", NULL, 297, &_2);
	zephir_check_call_status();
	roundedTotal = zephir_safe_div_long_zval(number, _3 TSRMLS_CC);
	totalPages = (int) (roundedTotal);
	if (totalPages != roundedTotal) {
		totalPages++;
	}
	ZEPHIR_SINIT_NVAR(_2);
	ZVAL_LONG(&_2, (show * ((pageNumber - 1))));
	ZEPHIR_SINIT_VAR(_4);
	ZVAL_LONG(&_4, show);
	ZEPHIR_CALL_FUNCTION(&_5, "array_slice", NULL, 368, items, &_2, &_4);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(items, _5);
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
	ZEPHIR_INIT_VAR(page);
	object_init(page);
	zephir_update_property_zval(page, SL("items"), items TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_6);
	ZVAL_LONG(_6, 1);
	zephir_update_property_zval(page, SL("first"), _6 TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_6);
	ZVAL_LONG(_6, before);
	zephir_update_property_zval(page, SL("before"), _6 TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_6);
	ZVAL_LONG(_6, pageNumber);
	zephir_update_property_zval(page, SL("current"), _6 TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_6);
	ZVAL_LONG(_6, totalPages);
	zephir_update_property_zval(page, SL("last"), _6 TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_6);
	ZVAL_LONG(_6, next);
	zephir_update_property_zval(page, SL("next"), _6 TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_6);
	ZVAL_LONG(_6, totalPages);
	zephir_update_property_zval(page, SL("total_pages"), _6 TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_6);
	ZVAL_LONG(_6, number);
	zephir_update_property_zval(page, SL("total_items"), _6 TSRMLS_CC);
	_6 = zephir_fetch_nproperty_this(this_ptr, SL("_limitRows"), PH_NOISY_CC);
	zephir_update_property_zval(page, SL("limit"), _6 TSRMLS_CC);
	RETURN_CCTOR(page);

}

