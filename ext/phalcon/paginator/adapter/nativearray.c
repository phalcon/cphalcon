
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
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"


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

	zval *config, *page, *limit;

	zephir_fetch_params(0, 1, 0, &config);



	zephir_update_property_this(this_ptr, SL("_config"), config TSRMLS_CC);
	if (zephir_array_isset_string_fetch(&limit, config, SS("limit"), 1 TSRMLS_CC)) {
		zephir_update_property_this(this_ptr, SL("_limitRows"), limit TSRMLS_CC);
	}
	if (zephir_array_isset_string_fetch(&page, config, SS("page"), 1 TSRMLS_CC)) {
		zephir_update_property_this(this_ptr, SL("_page"), page TSRMLS_CC);
	}

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
	zephir_update_property_zval(this_ptr, SL("_page"), _0 TSRMLS_CC);

}

/**
 * Returns a slice of the resultset to show in the pagination
 *
 * @return stdClass
 */
PHP_METHOD(Phalcon_Paginator_Adapter_NativeArray, getPaginate) {

	double roundedTotal;
	int show, pageNumber, totalPages, number, before, next;
	zval *config, *items, *page, *_0, *_1, _2, _3, *_4, *_5;

	ZEPHIR_MM_GROW();

	config = zephir_fetch_nproperty_this(this_ptr, SL("_config"), PH_NOISY_CC);
	zephir_array_fetch_string(&items, config, SL("data"), PH_NOISY | PH_READONLY TSRMLS_CC);
	if ((Z_TYPE_P(items) != IS_ARRAY)) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_paginator_exception_ce, "Invalid data for paginator");
		return;
	}
	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("_limitRows"), PH_NOISY_CC);
	show = zephir_get_intval(_0);
	ZEPHIR_OBS_VAR(_1);
	zephir_read_property_this(&_1, this_ptr, SL("_page"), PH_NOISY_CC);
	pageNumber = zephir_get_intval(_1);
	if ((pageNumber <= 0)) {
		pageNumber = 1;
	}
	ZEPHIR_INIT_VAR(page);
	object_init(page);
	number = zephir_fast_count_int(items TSRMLS_CC);
	roundedTotal = (double) ((number / show));
	totalPages = zephir_get_intval(roundedTotal);
	if ((totalPages != roundedTotal)) {
		totalPages++;
	}
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_LONG(&_2, (show * ((pageNumber - 1))));
	ZEPHIR_SINIT_VAR(_3);
	ZVAL_LONG(&_3, show);
	ZEPHIR_INIT_VAR(_4);
	zephir_call_func_p3(_4, "array_slice", items, &_2, &_3);
	zephir_update_property_zval(page, SL("items"), _4 TSRMLS_CC);
	if ((pageNumber < totalPages)) {
		next = (pageNumber + 1);
	} else {
		next = totalPages;
	}
	ZEPHIR_INIT_ZVAL_NREF(_5);
	ZVAL_LONG(_5, next);
	zephir_update_property_zval(page, SL("next"), _5 TSRMLS_CC);
	if ((pageNumber > 1)) {
		before = (pageNumber - 1);
	} else {
		before = 1;
	}
	ZEPHIR_INIT_ZVAL_NREF(_5);
	ZVAL_LONG(_5, 1);
	zephir_update_property_zval(page, SL("first"), _5 TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_5);
	ZVAL_LONG(_5, before);
	zephir_update_property_zval(page, SL("before"), _5 TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_5);
	ZVAL_LONG(_5, pageNumber);
	zephir_update_property_zval(page, SL("current"), _5 TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_5);
	ZVAL_LONG(_5, totalPages);
	zephir_update_property_zval(page, SL("last"), _5 TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_5);
	ZVAL_LONG(_5, totalPages);
	zephir_update_property_zval(page, SL("total_pages"), _5 TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_5);
	ZVAL_LONG(_5, number);
	zephir_update_property_zval(page, SL("total_items"), _5 TSRMLS_CC);
	RETURN_CCTOR(page);

}

