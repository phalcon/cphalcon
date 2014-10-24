
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


/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
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

	ZEPHIR_REGISTER_CLASS(Phalcon\\Paginator\\Adapter, NativeArray, phalcon, paginator_adapter_nativearray, phalcon_paginator_adapter_nativearray_method_entry, 0);

	/**
	 * Number of rows to show in the paginator. By default is null
	 */
	zend_declare_property_null(phalcon_paginator_adapter_nativearray_ce, SL("_limitRows"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Configuration of the paginator
	 */
	zend_declare_property_null(phalcon_paginator_adapter_nativearray_ce, SL("_config"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Current page in paginate
	 */
	zend_declare_property_null(phalcon_paginator_adapter_nativearray_ce, SL("_page"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_paginator_adapter_nativearray_ce TSRMLS_CC, 1, phalcon_paginator_adapterinterface_ce);
	return SUCCESS;

}

/**
 * Phalcon\Paginator\Adapter\NativeArray constructor
 *
 * @param array config
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
 * Set the current page number
 *
 * @param int page
 */
PHP_METHOD(Phalcon_Paginator_Adapter_NativeArray, setCurrentPage) {

	zval *page_param = NULL, *_0;
	int page;

	zephir_fetch_params(0, 1, 0, &page_param);

	page = zephir_get_intval(page_param);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, page);
	zephir_update_property_this(this_ptr, SL("_page"), _0 TSRMLS_CC);

}

/**
 * Returns a slice of the resultset to show in the pagination
 *
 * @return stdClass
 */
PHP_METHOD(Phalcon_Paginator_Adapter_NativeArray, getPaginate) {

	zephir_nts_static zephir_fcall_cache_entry *_4 = NULL, *_7 = NULL;
	double roundedTotal;
	int show, pageNumber, totalPages, number, before, next, ZEPHIR_LAST_CALL_STATUS;
	zval *config, *items, *page, *_0, *_1, _2 = zval_used_for_init, *_3 = NULL, _5, *_6 = NULL, *_8;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(config);
	zephir_read_property_this(&config, this_ptr, SL("_config"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(items);
	zephir_array_fetch_string(&items, config, SL("data"), PH_NOISY, "phalcon/paginator/adapter/nativearray.zep", 108 TSRMLS_CC);
	if (Z_TYPE_P(items) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_paginator_exception_ce, "Invalid data for paginator", "phalcon/paginator/adapter/nativearray.zep", 111);
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
	ZEPHIR_INIT_VAR(page);
	object_init(page);
	number = zephir_fast_count_int(items TSRMLS_CC);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_LONG(&_2, show);
	ZEPHIR_CALL_FUNCTION(&_3, "floatval", &_4, &_2);
	zephir_check_call_status();
	roundedTotal = zephir_safe_div_long_zval(number, _3 TSRMLS_CC);
	totalPages = (int) (roundedTotal);
	if (totalPages != roundedTotal) {
		totalPages++;
	}
	ZEPHIR_SINIT_NVAR(_2);
	ZVAL_LONG(&_2, (show * ((pageNumber - 1))));
	ZEPHIR_SINIT_VAR(_5);
	ZVAL_LONG(&_5, show);
	ZEPHIR_CALL_FUNCTION(&_6, "array_slice", &_7, items, &_2, &_5);
	zephir_check_call_status();
	zephir_update_property_zval(page, SL("items"), _6 TSRMLS_CC);
	if (pageNumber < totalPages) {
		next = (pageNumber + 1);
	} else {
		next = totalPages;
	}
	ZEPHIR_INIT_ZVAL_NREF(_8);
	ZVAL_LONG(_8, next);
	zephir_update_property_zval(page, SL("next"), _8 TSRMLS_CC);
	if (pageNumber > 1) {
		before = (pageNumber - 1);
	} else {
		before = 1;
	}
	ZEPHIR_INIT_ZVAL_NREF(_8);
	ZVAL_LONG(_8, 1);
	zephir_update_property_zval(page, SL("first"), _8 TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_8);
	ZVAL_LONG(_8, before);
	zephir_update_property_zval(page, SL("before"), _8 TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_8);
	ZVAL_LONG(_8, pageNumber);
	zephir_update_property_zval(page, SL("current"), _8 TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_8);
	ZVAL_LONG(_8, totalPages);
	zephir_update_property_zval(page, SL("last"), _8 TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_8);
	ZVAL_LONG(_8, totalPages);
	zephir_update_property_zval(page, SL("total_pages"), _8 TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_8);
	ZVAL_LONG(_8, number);
	zephir_update_property_zval(page, SL("total_items"), _8 TSRMLS_CC);
	RETURN_CCTOR(page);

}

