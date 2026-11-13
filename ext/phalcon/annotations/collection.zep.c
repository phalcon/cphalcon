
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
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/string.h"
#include "kernel/exception.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
/**
 * Represents a collection of annotations. This class allows to traverse a group
 * of annotations easily
 *
 *```php
 * // Traverse annotations
 * foreach ($classAnnotations as $annotation) {
 *     echo "Name=", $annotation->getName(), PHP_EOL;
 * }
 *
 * // Check if the annotations has a specific
 * var_dump($classAnnotations->has("Cacheable"));
 *
 * // Get an specific annotation in the collection
 * $annotation = $classAnnotations->get("Cacheable");
 *```
 *
 * The class cannot carry an `@implements Iterator<int, Annotation>` tag.
 * `current()` returns `false` past the end of the collection, while Psalm's
 * `Iterator` stub requires `TValue|null` there. Narrowing the iteration would
 * mean changing that return to null, which is a v7 signature change.
 *
 * @phpstan-import-type annotations_list from AnnotationsTypes
 * @phpstan-import-type annotations_node_list from AnnotationsTypes
 */
ZEPHIR_INIT_CLASS(Phalcon_Annotations_Collection)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Annotations, Collection, phalcon, annotations_collection, phalcon_annotations_collection_method_entry, 0);

	/**
	 * @var array
	 *
	 * @phpstan-var annotations_list
	 */
	zend_declare_property_null(phalcon_annotations_collection_ce, SL("annotations"), ZEND_ACC_PROTECTED);
	/**
	 * @var int
	 */
	zend_declare_property_long(phalcon_annotations_collection_ce, SL("position"), 0, ZEND_ACC_PROTECTED);
	zend_class_implements(phalcon_annotations_collection_ce, 1, zend_ce_iterator);
	zend_class_implements(phalcon_annotations_collection_ce, 1, zend_ce_countable);
	return SUCCESS;
}

/**
 * Phalcon\Annotations\Collection constructor
 *
 * @phpstan-param annotations_node_list $reflectionData
 */
PHP_METHOD(Phalcon_Annotations_Collection, __construct)
{
	zend_bool _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *reflectionData_param = NULL, annotations, annotationData, *_0, _2, _1$$3, _4$$4;
	zval reflectionData;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&reflectionData);
	ZVAL_UNDEF(&annotations);
	ZVAL_UNDEF(&annotationData);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_4$$4);
	ZEND_TLS zephir_method_cache _zephir_call_cache[6];
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("annotations", 11, 1);
	}

	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(reflectionData, reflectionData_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 1, &reflectionData_param);
	if (!reflectionData_param) {
		ZEPHIR_INIT_VAR(&reflectionData);
		array_init(&reflectionData);
	} else {
		zephir_get_arrval(&reflectionData, reflectionData_param);
	}
	ZEPHIR_INIT_VAR(&annotations);
	array_init(&annotations);
	zephir_is_iterable(&reflectionData, 0, "phalcon/Annotations/Collection.zep", 72);
	if (Z_TYPE_P(&reflectionData) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&reflectionData), _0)
		{
			ZEPHIR_INIT_NVAR(&annotationData);
			ZVAL_COPY(&annotationData, _0);
			ZEPHIR_INIT_NVAR(&_1$$3);
			object_init_ex(&_1$$3, phalcon_annotations_annotation_ce);
			ZEPHIR_CALL_METHOD_CACHED(NULL, &_1$$3, "__construct", &_zephir_call_cache[0], &annotationData);
			zephir_check_call_status();
			zephir_array_append(&annotations, &_1$$3, PH_SEPARATE, "phalcon/Annotations/Collection.zep", 69);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD_CACHED(NULL, &reflectionData, "rewind", &_zephir_call_cache[1]);
		zephir_check_call_status();
		_3 = 1;
		while (1) {
			if (_3) {
				_3 = 0;
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, &reflectionData, "next", &_zephir_call_cache[2]);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD_CACHED(&_2, &reflectionData, "valid", &_zephir_call_cache[3]);
			zephir_check_call_status();
			if (!zend_is_true(&_2)) {
				break;
			}
			ZEPHIR_CALL_METHOD_CACHED(&annotationData, &reflectionData, "current", &_zephir_call_cache[4]);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_4$$4);
				object_init_ex(&_4$$4, phalcon_annotations_annotation_ce);
				ZEPHIR_CALL_METHOD_CACHED(NULL, &_4$$4, "__construct", &_zephir_call_cache[5], &annotationData);
				zephir_check_call_status();
				zephir_array_append(&annotations, &_4$$4, PH_SEPARATE, "phalcon/Annotations/Collection.zep", 69);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
		}
	}
	ZEPHIR_INIT_NVAR(&annotationData);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 408, &annotations);
	ZEPHIR_MM_RESTORE();
}

/**
 * Returns the number of annotations in the collection
 */
PHP_METHOD(Phalcon_Annotations_Collection, count)
{
	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("annotations", 11, 1);
	}
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 408, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		return;
	}
	RETURN_LONG(zephir_fast_count_int(&_0));
}

/**
 * Returns the current annotation in the iterator
 *
 * @phpstan-return Annotation|false
 */
PHP_METHOD(Phalcon_Annotations_Collection, current)
{
	zend_bool _2;
	zval annotation, _0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&annotation);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("annotations", 11, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("position", 8, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_memory_observe(&annotation);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 408, PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_1, 409, PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	_2 = zephir_array_isset_fetch(&annotation, &_0, &_1, 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (!(_2)) {
		RETURN_MM_BOOL(0);
	}
	RETURN_CCTOR(&annotation);
}

/**
 * Returns the first annotation that match a name
 */
PHP_METHOD(Phalcon_Annotations_Collection, get)
{
	zend_bool _7, _5$$3, _9$$5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval name_zv, annotation, annotations, _0, *_1, _2, *_3, _6, _10, _4$$3, _8$$5;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&annotation);
	ZVAL_UNDEF(&annotations);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_8$$5);
	ZEND_TLS zephir_method_cache _zephir_call_cache[7];
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("annotations", 11, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 408, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CPY_WRT(&annotations, &_0);
	if (Z_TYPE_P(&annotations) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_2);
		zephir_string_to_char_array(&_2, &annotations);
		_1 = &_2;
	} else {
		_1 = &annotations;
	}
	zephir_is_iterable(_1, 0, "phalcon/Annotations/Collection.zep", 114);
	if (Z_TYPE_P(_1) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_1), _3)
		{
			ZEPHIR_INIT_NVAR(&annotation);
			ZVAL_COPY(&annotation, _3);
			ZEPHIR_CALL_METHOD_CACHED(&_4$$3, &annotation, "getName", &_zephir_call_cache[0]);
			zephir_check_call_status();
			_5$$3 = ZEPHIR_IS_EQUAL(&name_zv, &_4$$3);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (_5$$3) {
				RETURN_CCTOR(&annotation);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD_CACHED(NULL, _1, "rewind", &_zephir_call_cache[1]);
		zephir_check_call_status();
		_7 = 1;
		while (1) {
			if (_7) {
				_7 = 0;
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, _1, "next", &_zephir_call_cache[2]);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD_CACHED(&_6, _1, "valid", &_zephir_call_cache[3]);
			zephir_check_call_status();
			if (!zend_is_true(&_6)) {
				break;
			}
			ZEPHIR_CALL_METHOD_CACHED(&annotation, _1, "current", &_zephir_call_cache[4]);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD_CACHED(&_8$$5, &annotation, "getName", &_zephir_call_cache[5]);
				zephir_check_call_status();
				_9$$5 = ZEPHIR_IS_EQUAL(&name_zv, &_8$$5);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (_9$$5) {
					RETURN_CCTOR(&annotation);
				}
		}
	}
	ZEPHIR_INIT_NVAR(&annotation);
	ZEPHIR_INIT_VAR(&_10);
	object_init_ex(&_10, phalcon_annotations_exceptions_annotationnotfound_ce);
	ZEPHIR_CALL_METHOD_CACHED(NULL, &_10, "__construct", &_zephir_call_cache[6], &name_zv);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_10, "phalcon/Annotations/Collection.zep", 114);
	ZEPHIR_MM_RESTORE();
	return;
}

/**
 * Returns all the annotations that match a name
 *
 * @phpstan-return annotations_list
 */
PHP_METHOD(Phalcon_Annotations_Collection, getAll)
{
	zend_bool _7, _5$$3, _9$$5;
	zval found;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval name_zv, annotations, annotation, _0, *_1, _2, *_3, _6, _4$$3, _8$$5;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&annotations);
	ZVAL_UNDEF(&annotation);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&found);
	ZEND_TLS zephir_method_cache _zephir_call_cache[6];
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("annotations", 11, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	ZEPHIR_INIT_VAR(&found);
	array_init(&found);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 408, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CPY_WRT(&annotations, &_0);
	if (Z_TYPE_P(&annotations) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_2);
		zephir_string_to_char_array(&_2, &annotations);
		_1 = &_2;
	} else {
		_1 = &annotations;
	}
	zephir_is_iterable(_1, 0, "phalcon/Annotations/Collection.zep", 136);
	if (Z_TYPE_P(_1) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_1), _3)
		{
			ZEPHIR_INIT_NVAR(&annotation);
			ZVAL_COPY(&annotation, _3);
			ZEPHIR_CALL_METHOD_CACHED(&_4$$3, &annotation, "getName", &_zephir_call_cache[0]);
			zephir_check_call_status();
			_5$$3 = ZEPHIR_IS_EQUAL(&name_zv, &_4$$3);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (_5$$3) {
				zephir_array_append(&found, &annotation, PH_SEPARATE, "phalcon/Annotations/Collection.zep", 132);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD_CACHED(NULL, _1, "rewind", &_zephir_call_cache[1]);
		zephir_check_call_status();
		_7 = 1;
		while (1) {
			if (_7) {
				_7 = 0;
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, _1, "next", &_zephir_call_cache[2]);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD_CACHED(&_6, _1, "valid", &_zephir_call_cache[3]);
			zephir_check_call_status();
			if (!zend_is_true(&_6)) {
				break;
			}
			ZEPHIR_CALL_METHOD_CACHED(&annotation, _1, "current", &_zephir_call_cache[4]);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD_CACHED(&_8$$5, &annotation, "getName", &_zephir_call_cache[5]);
				zephir_check_call_status();
				_9$$5 = ZEPHIR_IS_EQUAL(&name_zv, &_8$$5);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (_9$$5) {
					zephir_array_append(&found, &annotation, PH_SEPARATE, "phalcon/Annotations/Collection.zep", 132);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
		}
	}
	ZEPHIR_INIT_NVAR(&annotation);
	RETURN_CTOR(&found);
}

/**
 * Returns the internal annotations as an array
 *
 * @phpstan-return annotations_list
 */
PHP_METHOD(Phalcon_Annotations_Collection, getAnnotations)
{

	RETURN_MEMBER_TYPED(getThis(), "annotations", IS_ARRAY);
}

/**
 * Check if an annotation exists in a collection
 */
PHP_METHOD(Phalcon_Annotations_Collection, has)
{
	zend_bool _7, _5$$3, _9$$5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval name_zv, annotations, annotation, _0, *_1, _2, *_3, _6, _4$$3, _8$$5;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&annotations);
	ZVAL_UNDEF(&annotation);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_8$$5);
	ZEND_TLS zephir_method_cache _zephir_call_cache[6];
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("annotations", 11, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 408, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CPY_WRT(&annotations, &_0);
	if (Z_TYPE_P(&annotations) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_2);
		zephir_string_to_char_array(&_2, &annotations);
		_1 = &_2;
	} else {
		_1 = &annotations;
	}
	zephir_is_iterable(_1, 0, "phalcon/Annotations/Collection.zep", 164);
	if (Z_TYPE_P(_1) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_1), _3)
		{
			ZEPHIR_INIT_NVAR(&annotation);
			ZVAL_COPY(&annotation, _3);
			ZEPHIR_CALL_METHOD_CACHED(&_4$$3, &annotation, "getName", &_zephir_call_cache[0]);
			zephir_check_call_status();
			_5$$3 = ZEPHIR_IS_EQUAL(&name_zv, &_4$$3);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (_5$$3) {
				RETURN_MM_BOOL(1);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD_CACHED(NULL, _1, "rewind", &_zephir_call_cache[1]);
		zephir_check_call_status();
		_7 = 1;
		while (1) {
			if (_7) {
				_7 = 0;
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, _1, "next", &_zephir_call_cache[2]);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD_CACHED(&_6, _1, "valid", &_zephir_call_cache[3]);
			zephir_check_call_status();
			if (!zend_is_true(&_6)) {
				break;
			}
			ZEPHIR_CALL_METHOD_CACHED(&annotation, _1, "current", &_zephir_call_cache[4]);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD_CACHED(&_8$$5, &annotation, "getName", &_zephir_call_cache[5]);
				zephir_check_call_status();
				_9$$5 = ZEPHIR_IS_EQUAL(&name_zv, &_8$$5);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (_9$$5) {
					RETURN_MM_BOOL(1);
				}
		}
	}
	ZEPHIR_INIT_NVAR(&annotation);
	RETURN_MM_BOOL(0);
}

/**
 * Returns the current position/key in the iterator
 */
PHP_METHOD(Phalcon_Annotations_Collection, key)
{

	RETURN_MEMBER_TYPED(getThis(), "position", IS_LONG);
}

/**
 * Moves the internal iteration pointer to the next position
 */
PHP_METHOD(Phalcon_Annotations_Collection, next)
{
	zval *this_ptr = getThis();
	RETURN_ON_FAILURE(zephir_property_incr(this_ptr, SL("position")));
}

/**
 * Rewinds the internal iterator
 */
PHP_METHOD(Phalcon_Annotations_Collection, rewind)
{
	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("position", 8, 1);
	}
	ZVAL_UNDEF(&_0);
	ZVAL_LONG(&_0, 0);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 409, &_0);
}

/**
 * Check if the current annotation in the iterator is valid
 */
PHP_METHOD(Phalcon_Annotations_Collection, valid)
{
	zend_bool _2;
	zval _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("annotations", 11, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("position", 8, 1);
	}
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 408, PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		return;
	}
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_1, 409, PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		return;
	}
	_2 = zephir_array_isset_value(&_0, &_1);
	if (UNEXPECTED(EG(exception))) {
		return;
	}
	RETURN_BOOL(_2);
}

