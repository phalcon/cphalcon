
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/exception.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/string.h"
#include "kernel/array.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Turns the `eager` find parameter into a tree.
 *
 * Elements are either a bare path string or `path => options`. A path implies
 * every one of its prefixes and prefixes are merged, so ["customer",
 * "customer.country"] and ["customer.country"] produce the same two-node tree.
 * The number of queries an eager load costs follows the number of nodes in
 * this tree, not the number of elements supplied.
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Eager_PathTree)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Mvc\\Model\\Eager, PathTree, phalcon, mvc_model_eager_pathtree, phalcon_mvc_model_eager_pathtree_method_entry, 0);

	/**
	 * Longest path accepted. Depth alone is not what makes an eager load
	 * expensive, but an unbounded path is never intentional.
	 */
	zephir_declare_class_constant_long(phalcon_mvc_model_eager_pathtree_ce, SL("MAX_DEPTH"), 5);

	return SUCCESS;
}

/**
 * @param array $spec the `eager` find parameter
 */
PHP_METHOD(Phalcon_Mvc_Model_Eager_PathTree, parse)
{
	zval _5$$6, _17$$12;
	zend_bool _14;
	zend_string *_2;
	zend_ulong _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_6 = NULL, *_8 = NULL, *_11 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *spec_param = NULL, key, options, path, segments, value, *_0, _13, _3$$6, _4$$6, _7$$7, _9$$8, _10$$3, _12$$3, _15$$12, _16$$12, _18$$13, _19$$14, _20$$9, _21$$9;
	zval spec, tree;

	ZVAL_UNDEF(&spec);
	ZVAL_UNDEF(&tree);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&segments);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_3$$6);
	ZVAL_UNDEF(&_4$$6);
	ZVAL_UNDEF(&_7$$7);
	ZVAL_UNDEF(&_9$$8);
	ZVAL_UNDEF(&_10$$3);
	ZVAL_UNDEF(&_12$$3);
	ZVAL_UNDEF(&_15$$12);
	ZVAL_UNDEF(&_16$$12);
	ZVAL_UNDEF(&_18$$13);
	ZVAL_UNDEF(&_19$$14);
	ZVAL_UNDEF(&_20$$9);
	ZVAL_UNDEF(&_21$$9);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_17$$12);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(spec, spec_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &spec_param);
	zephir_get_arrval(&spec, spec_param);
	ZEPHIR_INIT_VAR(&tree);
	array_init(&tree);
	zephir_is_iterable(&spec, 0, "phalcon/Mvc/Model/Eager/PathTree.zep", 73);
	if (Z_TYPE_P(&spec) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&spec), _1, _2, _0)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_2 != NULL) { 
				ZVAL_STR_COPY(&key, _2);
			} else {
				ZVAL_LONG(&key, _1);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _0);
			if (Z_TYPE_P(&key) == IS_STRING) {
				ZEPHIR_CPY_WRT(&path, &key);
				ZEPHIR_CPY_WRT(&options, &value);
			} else {
				ZEPHIR_CPY_WRT(&path, &value);
				ZEPHIR_INIT_NVAR(&options);
				array_init(&options);
			}
			if (UNEXPECTED(Z_TYPE_P(&path) != IS_STRING)) {
				ZEPHIR_INIT_NVAR(&_3$$6);
				object_init_ex(&_3$$6, phalcon_mvc_model_exceptions_invalideagerpath_ce);
				ZEPHIR_INIT_NVAR(&_4$$6);
				if (Z_TYPE_P(&path) == IS_OBJECT) {
					ZEPHIR_INIT_NVAR(&_4$$6);
					zephir_get_class(&_4$$6, &path, 0);
				} else {
					zephir_cast_to_string(&_5$$6, &path);
					ZEPHIR_CPY_WRT(&_4$$6, &_5$$6);
				}
				ZEPHIR_CALL_METHOD(NULL, &_3$$6, "__construct", &_6, 0, &_4$$6);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_3$$6, "phalcon/Mvc/Model/Eager/PathTree.zep", 55);
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (UNEXPECTED(Z_TYPE_P(&options) != IS_ARRAY)) {
				ZEPHIR_INIT_NVAR(&_7$$7);
				object_init_ex(&_7$$7, phalcon_mvc_model_exceptions_invalideagerpath_ce);
				ZEPHIR_CALL_METHOD(NULL, &_7$$7, "__construct", &_6, 0, &path);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_7$$7, "phalcon/Mvc/Model/Eager/PathTree.zep", 59);
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_CALL_SELF(NULL, "assertoptions", &_8, 0, &options);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&segments);
			zephir_fast_explode_str(&segments, SL("."), &path, LONG_MAX);
			if (UNEXPECTED(zephir_fast_count_int(&segments) > 5)) {
				ZEPHIR_INIT_NVAR(&_9$$8);
				object_init_ex(&_9$$8, phalcon_mvc_model_exceptions_invalideagerpath_ce);
				ZEPHIR_CALL_METHOD(NULL, &_9$$8, "__construct", &_6, 0, &path);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_9$$8, "phalcon/Mvc/Model/Eager/PathTree.zep", 67);
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZVAL_LONG(&_12$$3, 0);
			ZEPHIR_CALL_SELF(&_10$$3, "insert", &_11, 0, &tree, &path, &segments, &_12$$3, &options);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&tree, &_10$$3);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &spec, "rewind", NULL, 0);
		zephir_check_call_status();
		_14 = 1;
		while (1) {
			if (_14) {
				_14 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &spec, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_13, &spec, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_13)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, &spec, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, &spec, "current", NULL, 0);
			zephir_check_call_status();
				if (Z_TYPE_P(&key) == IS_STRING) {
					ZEPHIR_CPY_WRT(&path, &key);
					ZEPHIR_CPY_WRT(&options, &value);
				} else {
					ZEPHIR_CPY_WRT(&path, &value);
					ZEPHIR_INIT_NVAR(&options);
					array_init(&options);
				}
				if (UNEXPECTED(Z_TYPE_P(&path) != IS_STRING)) {
					ZEPHIR_INIT_NVAR(&_15$$12);
					object_init_ex(&_15$$12, phalcon_mvc_model_exceptions_invalideagerpath_ce);
					ZEPHIR_INIT_NVAR(&_16$$12);
					if (Z_TYPE_P(&path) == IS_OBJECT) {
						ZEPHIR_INIT_NVAR(&_16$$12);
						zephir_get_class(&_16$$12, &path, 0);
					} else {
						zephir_cast_to_string(&_17$$12, &path);
						ZEPHIR_CPY_WRT(&_16$$12, &_17$$12);
					}
					ZEPHIR_CALL_METHOD(NULL, &_15$$12, "__construct", &_6, 0, &_16$$12);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_15$$12, "phalcon/Mvc/Model/Eager/PathTree.zep", 55);
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (UNEXPECTED(Z_TYPE_P(&options) != IS_ARRAY)) {
					ZEPHIR_INIT_NVAR(&_18$$13);
					object_init_ex(&_18$$13, phalcon_mvc_model_exceptions_invalideagerpath_ce);
					ZEPHIR_CALL_METHOD(NULL, &_18$$13, "__construct", &_6, 0, &path);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_18$$13, "phalcon/Mvc/Model/Eager/PathTree.zep", 59);
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_CALL_SELF(NULL, "assertoptions", &_8, 0, &options);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&segments);
				zephir_fast_explode_str(&segments, SL("."), &path, LONG_MAX);
				if (UNEXPECTED(zephir_fast_count_int(&segments) > 5)) {
					ZEPHIR_INIT_NVAR(&_19$$14);
					object_init_ex(&_19$$14, phalcon_mvc_model_exceptions_invalideagerpath_ce);
					ZEPHIR_CALL_METHOD(NULL, &_19$$14, "__construct", &_6, 0, &path);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_19$$14, "phalcon/Mvc/Model/Eager/PathTree.zep", 67);
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZVAL_LONG(&_21$$9, 0);
				ZEPHIR_CALL_SELF(&_20$$9, "insert", &_11, 0, &tree, &path, &segments, &_21$$9, &options);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(&tree, &_20$$9);
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	RETURN_CTOR(&tree);
}

/**
 * A per-parent limit requires ROW_NUMBER() OVER (PARTITION BY ...), which
 * PHQL has no syntax for. Applying `limit` to the batch query instead
 * would return N children in total rather than N per parent, which is
 * silently wrong.
 */
PHP_METHOD(Phalcon_Mvc_Model_Eager_PathTree, assertOptions)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *options_param = NULL;
	zval options;

	ZVAL_UNDEF(&options);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(options, options_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &options_param);
	zephir_get_arrval(&options, options_param);
	if (UNEXPECTED(zephir_array_isset_value_string(&options, SL("limit")))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exceptions_unsupportedeageroption_ce, "limit", "phalcon/Mvc/Model/Eager/PathTree.zep", 85);
		return;
	}
	if (UNEXPECTED(zephir_array_isset_value_string(&options, SL("offset")))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exceptions_unsupportedeageroption_ce, "offset", "phalcon/Mvc/Model/Eager/PathTree.zep", 89);
		return;
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * @param array  $tree     accumulated tree
 * @param string $path     the original path, for error messages
 * @param array  $segments exploded path
 * @param int    $index    segment currently being inserted
 * @param array  $options  attach to the last segment only
 */
PHP_METHOD(Phalcon_Mvc_Model_Eager_PathTree, insert)
{
	zend_bool isLast = 0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_7 = NULL;
	zend_long index, ZEPHIR_LAST_CALL_STATUS;
	zend_string *path = NULL;
	zval *tree_param = NULL, path_zv, *segments_param = NULL, *index_param = NULL, *options_param = NULL, node, segment, _0, _1$$3, _2$$4, _3$$4, _4$$5, _5$$5, _6$$6, _8$$6, _9$$6;
	zval tree, segments, options;

	ZVAL_UNDEF(&tree);
	ZVAL_UNDEF(&segments);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&path_zv);
	ZVAL_UNDEF(&node);
	ZVAL_UNDEF(&segment);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_9$$6);
	ZEND_PARSE_PARAMETERS_START(5, 5)
		ZEPHIR_Z_PARAM_ARRAY(tree, tree_param)
		Z_PARAM_STR(path)
		ZEPHIR_Z_PARAM_ARRAY(segments, segments_param)
		Z_PARAM_LONG(index)
		ZEPHIR_Z_PARAM_ARRAY(options, options_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	tree_param = ZEND_CALL_ARG(execute_data, 1);
	segments_param = ZEND_CALL_ARG(execute_data, 3);
	index_param = ZEND_CALL_ARG(execute_data, 4);
	options_param = ZEND_CALL_ARG(execute_data, 5);
	zephir_get_arrval(&tree, tree_param);
	zephir_memory_observe(&path_zv);
	ZVAL_STR_COPY(&path_zv, path);
	zephir_get_arrval(&segments, segments_param);
	zephir_get_arrval(&options, options_param);
	zephir_array_fetch_long(&_0, &segments, index, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Eager/PathTree.zep", 110);
	ZEPHIR_INIT_VAR(&segment);
	zephir_fast_trim(&segment, &_0, NULL , ZEPHIR_TRIM_BOTH);
	if (UNEXPECTED(ZEPHIR_IS_STRING_IDENTICAL(&segment, ""))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_mvc_model_exceptions_invalideagerpath_ce);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 0, &path_zv);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Mvc/Model/Eager/PathTree.zep", 113);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_memory_observe(&node);
	if (!(zephir_array_isset_fetch(&node, &tree, &segment, 0))) {
		ZEPHIR_INIT_VAR(&_2$$4);
		zephir_create_array(&_2$$4, 2, 0);
		ZEPHIR_INIT_VAR(&_3$$4);
		array_init(&_3$$4);
		zephir_array_update_string(&_2$$4, SL("options"), &_3$$4, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(&_3$$4);
		array_init(&_3$$4);
		zephir_array_update_string(&_2$$4, SL("children"), &_3$$4, PH_COPY | PH_SEPARATE);
		ZEPHIR_CPY_WRT(&node, &_2$$4);
	}
	isLast = (index + 1) >= zephir_fast_count_int(&segments);
	if (isLast) {
		ZEPHIR_INIT_VAR(&_4$$5);
		zephir_array_fetch_string(&_5$$5, &node, SL("options"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Eager/PathTree.zep", 126);
		zephir_fast_array_merge(&_4$$5, &_5$$5, &options);
		zephir_array_update_string(&node, SL("options"), &_4$$5, PH_COPY | PH_SEPARATE);
	} else {
		zephir_array_fetch_string(&_8$$6, &node, SL("children"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Eager/PathTree.zep", 129);
		ZVAL_LONG(&_9$$6, (index + 1));
		ZEPHIR_CALL_SELF(&_6$$6, "insert", &_7, 0, &_8$$6, &path_zv, &segments, &_9$$6, &options);
		zephir_check_call_status();
		zephir_array_update_string(&node, SL("children"), &_6$$6, PH_COPY | PH_SEPARATE);
	}
	zephir_array_update_zval(&tree, &segment, &node, PH_COPY | PH_SEPARATE);
	RETURN_CTOR(&tree);
}

