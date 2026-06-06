
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
#include "kernel/array.h"
#include "kernel/exception.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/concat.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Paginator\Adapter\QueryBuilderCursor
 *
 * Cursor-based (keyset) pagination using a PHQL query builder as source of
 * data.
 *
 * Unlike offset pagination, this adapter does not use an ever-growing OFFSET.
 * It appends a WHERE condition on a unique, indexed cursor column so that each
 * page is an O(1) index seek regardless of depth.
 *
 * Limitations:
 * - No total count: `getTotalItems()` always returns 0.
 * - No random access: `getLast()` always returns 0. Pages must be traversed
 *   in order by following the cursor value returned in `getNext()`.
 * - The cursor column must be unique and indexed (e.g. a primary key).
 * - Items are returned as an array of associative arrays (via
 *   `Resultset::toArray()`), not as model objects.
 * - `cursorColumn` must match the PHQL-accessible column name exactly
 *   (e.g. `"inv_id"`).
 *
 * ```php
 * use Phalcon\Paginator\Adapter\QueryBuilderCursor;
 *
 * $builder = $this->modelsManager->createBuilder()
 *                 ->columns("inv_id, inv_title")
 *                 ->from(Invoices::class)
 *                 ->orderBy("inv_id");
 *
 * $paginator = new QueryBuilderCursor(
 *     [
 *         "builder"      => $builder,
 *         "limit"        => 20,
 *         "cursorColumn" => "inv_id",
 *         "cursor"       => null,  // first page; pass $page->getNext() for subsequent pages
 *     ]
 * );
 *
 * $page = $paginator->paginate();
 * // $page->getItems()   - array of rows for this page
 * // $page->getNext()    - cursor value to pass for the next page (0 means no more pages)
 * // $page->getCurrent() - cursor value used for this page (0 on first page)
 * ```
 */
ZEPHIR_INIT_CLASS(Phalcon_Paginator_Adapter_QueryBuilderCursor)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Paginator\\Adapter, QueryBuilderCursor, phalcon, paginator_adapter_querybuildercursor, phalcon_paginator_adapter_abstractadapter_ce, phalcon_paginator_adapter_querybuildercursor_method_entry, 0);

	/**
	 * Paginator's data
	 *
	 * @var Builder
	 */
	zend_declare_property_null(phalcon_paginator_adapter_querybuildercursor_ce, SL("builder"), ZEND_ACC_PROTECTED);
	/**
	 * The cursor value for the current page (null = first page)
	 *
	 * @var mixed
	 */
	zend_declare_property_null(phalcon_paginator_adapter_querybuildercursor_ce, SL("cursor"), ZEND_ACC_PROTECTED);
	/**
	 * The column used as the cursor (must be unique and indexed)
	 *
	 * @var string
	 */
	zend_declare_property_null(phalcon_paginator_adapter_querybuildercursor_ce, SL("cursorColumn"), ZEND_ACC_PROTECTED);
	return SUCCESS;
}

/**
 * Phalcon\Paginator\Adapter\QueryBuilderCursor
 *
 * @param array config = [
 *     'limit'        => 10,
 *     'builder'      => null,
 *     'cursorColumn' => 'id',
 *     'cursor'       => null
 * ]
 */
PHP_METHOD(Phalcon_Paginator_Adapter_QueryBuilderCursor, __construct)
{
	zend_bool _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *config_param = NULL, builder, cursorColumn, cursor, _0$$5, _2$$7;
	zval config;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&config);
	ZVAL_UNDEF(&builder);
	ZVAL_UNDEF(&cursorColumn);
	ZVAL_UNDEF(&cursor);
	ZVAL_UNDEF(&_0$$5);
	ZVAL_UNDEF(&_2$$7);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(config, config_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &config_param);
	zephir_get_arrval(&config, config_param);
	if (UNEXPECTED(!(zephir_array_isset_value_string(&config, SL("limit"))))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_paginator_exceptions_missingrequiredparameter_ce, "limit", "phalcon/Paginator/Adapter/QueryBuilderCursor.zep", 101);
		return;
	}
	zephir_memory_observe(&builder);
	if (UNEXPECTED(!(zephir_array_isset_string_fetch(&builder, &config, SL("builder"), 0)))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_paginator_exceptions_missingrequiredparameter_ce, "builder", "phalcon/Paginator/Adapter/QueryBuilderCursor.zep", 105);
		return;
	}
	if (UNEXPECTED(!((zephir_instance_of_ev(&builder, phalcon_mvc_model_query_builder_ce))))) {
		ZEPHIR_INIT_VAR(&_0$$5);
		object_init_ex(&_0$$5, phalcon_paginator_exceptions_invalidbuilderinstance_ce);
		ZEPHIR_CALL_METHOD(NULL, &_0$$5, "__construct", NULL, 0);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$5, "phalcon/Paginator/Adapter/QueryBuilderCursor.zep", 109);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_memory_observe(&cursorColumn);
	if (UNEXPECTED(!(zephir_array_isset_string_fetch(&cursorColumn, &config, SL("cursorColumn"), 0)))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_paginator_exceptions_missingrequiredparameter_ce, "cursorColumn", "phalcon/Paginator/Adapter/QueryBuilderCursor.zep", 113);
		return;
	}
	_1 = Z_TYPE_P(&cursorColumn) != IS_STRING;
	if (!(_1)) {
		_1 = ZEPHIR_IS_EMPTY(&cursorColumn);
	}
	if (UNEXPECTED(_1)) {
		ZEPHIR_INIT_VAR(&_2$$7);
		object_init_ex(&_2$$7, phalcon_paginator_exceptions_invalidcursorcolumn_ce);
		ZEPHIR_CALL_METHOD(NULL, &_2$$7, "__construct", NULL, 0);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_2$$7, "phalcon/Paginator/Adapter/QueryBuilderCursor.zep", 117);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("cursorColumn"), &cursorColumn);
	zephir_memory_observe(&cursor);
	if (zephir_array_isset_string_fetch(&cursor, &config, SL("cursor"), 0)) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("cursor"), &cursor);
	}
	ZEPHIR_CALL_PARENT(NULL, phalcon_paginator_adapter_querybuildercursor_ce, getThis(), "__construct", NULL, 0, &config);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setquerybuilder", NULL, 0, &builder);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Get the cursor value for the current page (null on first page)
 */
PHP_METHOD(Phalcon_Paginator_Adapter_QueryBuilderCursor, getCursor)
{

	RETURN_MEMBER(getThis(), "cursor");
}

/**
 * Get the cursor column name
 */
PHP_METHOD(Phalcon_Paginator_Adapter_QueryBuilderCursor, getCursorColumn)
{

	RETURN_MEMBER_TYPED(getThis(), "cursorColumn", IS_STRING);
}

/**
 * Get the current page number
 *
 * Returns the cursor value used for this page cast to int, or 0 for the
 * first page. Use getCursor() to retrieve the raw cursor value.
 */
PHP_METHOD(Phalcon_Paginator_Adapter_QueryBuilderCursor, getCurrentPage)
{
	zval _0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property(&_0, this_ptr, ZEND_STRL("cursor"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_0) == IS_NULL) {
		RETURN_MM_LONG(0);
	}
	zephir_memory_observe(&_1);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("cursor"), PH_NOISY_CC);
	RETURN_MM_LONG(zephir_get_intval(&_1));
}

/**
 * Get query builder object
 */
PHP_METHOD(Phalcon_Paginator_Adapter_QueryBuilderCursor, getQueryBuilder)
{

	RETURN_MEMBER(getThis(), "builder");
}

/**
 * Returns a slice of the resultset to show in the pagination
 *
 * Fetches `limit + 1` rows from the builder. If the extra row is present
 * a next page exists; it is discarded and the cursor value of the last
 * included row is stored in the `next` repository property.
 */
PHP_METHOD(Phalcon_Paginator_Adapter_QueryBuilderCursor, paginate)
{
	zval _9, _5$$5;
	zval builder, query, result, items, lastItem, currentCursor, _0, _1, _2, _6, _10, _11, _3$$5, _4$$5, _7$$6, _8$$6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, nextCursor = 0, currentPage = 0, limit = 0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&builder);
	ZVAL_UNDEF(&query);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&items);
	ZVAL_UNDEF(&lastItem);
	ZVAL_UNDEF(&currentCursor);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_5$$5);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property(&_0, this_ptr, ZEND_STRL("builder"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	if (zephir_clone(&_1, &_0) == FAILURE) {
		RETURN_MM();
	}
	ZEPHIR_CPY_WRT(&builder, &_1);
	zephir_memory_observe(&_2);
	zephir_read_property(&_2, this_ptr, ZEND_STRL("limitRows"), PH_NOISY_CC);
	limit = zephir_get_intval(&_2);
	zephir_memory_observe(&currentCursor);
	zephir_read_property(&currentCursor, this_ptr, ZEND_STRL("cursor"), PH_NOISY_CC);
	if (Z_TYPE_P(&currentCursor) == IS_NULL) {
		currentPage = 0;
	} else {
		currentPage = zephir_get_intval(&currentCursor);
	}
	if (Z_TYPE_P(&currentCursor) != IS_NULL) {
		zephir_read_property(&_3$$5, this_ptr, ZEND_STRL("cursorColumn"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_4$$5);
		ZEPHIR_CONCAT_SVS(&_4$$5, "[", &_3$$5, "] > :cursor:");
		ZEPHIR_INIT_VAR(&_5$$5);
		zephir_create_array(&_5$$5, 1, 0);
		zephir_array_update_string(&_5$$5, SL("cursor"), &currentCursor, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD(NULL, &builder, "andwhere", NULL, 0, &_4$$5, &_5$$5);
		zephir_check_call_status();
	}
	ZVAL_LONG(&_6, (limit + 1));
	ZEPHIR_CALL_METHOD(NULL, &builder, "limit", NULL, 0, &_6);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&query, &builder, "getquery", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&result, &query, "execute", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&items, &result, "toarray", NULL, 0);
	zephir_check_call_status();
	if (zephir_fast_count_int(&items) > limit) {
		ZEPHIR_MAKE_REF(&items);
		ZEPHIR_CALL_FUNCTION(NULL, "array_pop", NULL, 0, &items);
		ZEPHIR_UNREF(&items);
		zephir_check_call_status();
		zephir_memory_observe(&lastItem);
		zephir_array_fetch_long(&lastItem, &items, (zephir_fast_count_int(&items) - 1), PH_NOISY, "phalcon/Paginator/Adapter/QueryBuilderCursor.zep", 220);
		zephir_memory_observe(&_7$$6);
		zephir_memory_observe(&_8$$6);
		zephir_read_property(&_8$$6, this_ptr, ZEND_STRL("cursorColumn"), PH_NOISY_CC);
		zephir_array_fetch(&_7$$6, &lastItem, &_8$$6, PH_NOISY, "phalcon/Paginator/Adapter/QueryBuilderCursor.zep", 221);
		nextCursor = zephir_get_intval(&_7$$6);
	} else {
		nextCursor = 0;
	}
	ZEPHIR_INIT_VAR(&_9);
	zephir_create_array(&_9, 8, 0);
	zephir_array_update_string(&_9, SL("items"), &items, PH_COPY | PH_SEPARATE);
	add_assoc_long_ex(&_9, SL("total_items"), 0);
	zephir_memory_observe(&_10);
	zephir_read_property(&_10, this_ptr, ZEND_STRL("limitRows"), PH_NOISY_CC);
	zephir_array_update_string(&_9, SL("limit"), &_10, PH_COPY | PH_SEPARATE);
	add_assoc_long_ex(&_9, SL("first"), 1);
	add_assoc_long_ex(&_9, SL("previous"), 0);
	ZEPHIR_INIT_VAR(&_11);
	ZVAL_LONG(&_11, currentPage);
	zephir_array_update_string(&_9, SL("current"), &_11, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_11);
	ZVAL_LONG(&_11, nextCursor);
	zephir_array_update_string(&_9, SL("next"), &_11, PH_COPY | PH_SEPARATE);
	add_assoc_long_ex(&_9, SL("last"), 0);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getrepository", NULL, 0, &_9);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Set the cursor value for the next paginate() call
 *
 * Pass the value returned by Repository::getNext() to advance to the
 * next page, or null to restart from the first page.
 */
PHP_METHOD(Phalcon_Paginator_Adapter_QueryBuilderCursor, setCursor)
{
	zval *cursor, cursor_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&cursor_sub);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(cursor)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &cursor);
	zephir_update_property_zval(this_ptr, ZEND_STRL("cursor"), cursor);
	RETURN_THISW();
}

/**
 * Set query builder object
 */
PHP_METHOD(Phalcon_Paginator_Adapter_QueryBuilderCursor, setQueryBuilder)
{
	zval *builder, builder_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&builder_sub);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(builder, phalcon_mvc_model_query_builder_ce)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &builder);
	zephir_update_property_zval(this_ptr, ZEND_STRL("builder"), builder);
	RETURN_THISW();
}

