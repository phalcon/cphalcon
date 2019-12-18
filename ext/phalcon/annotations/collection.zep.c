
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
#include "ext/spl/spl_iterators.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
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
 */
ZEPHIR_INIT_CLASS(Phalcon_Annotations_Collection) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Annotations, Collection, phalcon, annotations_collection, phalcon_annotations_collection_method_entry, 0);

	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_annotations_collection_ce, SL("annotations"), ZEND_ACC_PROTECTED);

	/**
	 * @var int
	 */
	zend_declare_property_long(phalcon_annotations_collection_ce, SL("position"), 0, ZEND_ACC_PROTECTED);

	zend_class_implements(phalcon_annotations_collection_ce, 1, zend_ce_iterator);
	zend_class_implements(phalcon_annotations_collection_ce, 1, spl_ce_Countable);
	return SUCCESS;

}

/**
 * Phalcon\Annotations\Collection constructor
 */
PHP_METHOD(Phalcon_Annotations_Collection, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_3 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *reflectionData_param = NULL, annotations, annotationData, *_0, _1, _2$$3, _4$$4;
	zval reflectionData;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&reflectionData);
	ZVAL_UNDEF(&annotations);
	ZVAL_UNDEF(&annotationData);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_4$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &reflectionData_param);

	if (!reflectionData_param) {
		ZEPHIR_INIT_VAR(&reflectionData);
		array_init(&reflectionData);
	} else {
		zephir_get_arrval(&reflectionData, reflectionData_param);
	}


	ZEPHIR_INIT_VAR(&annotations);
	array_init(&annotations);
	zephir_is_iterable(&reflectionData, 0, "phalcon/Annotations/Collection.zep", 58);
	if (Z_TYPE_P(&reflectionData) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&reflectionData), _0)
		{
			ZEPHIR_INIT_NVAR(&annotationData);
			ZVAL_COPY(&annotationData, _0);
			ZEPHIR_INIT_NVAR(&_2$$3);
			object_init_ex(&_2$$3, phalcon_annotations_annotation_ce);
			ZEPHIR_CALL_METHOD(NULL, &_2$$3, "__construct", &_3, 147, &annotationData);
			zephir_check_call_status();
			zephir_array_append(&annotations, &_2$$3, PH_SEPARATE, "phalcon/Annotations/Collection.zep", 55);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &reflectionData, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1, &reflectionData, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&annotationData, &reflectionData, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_4$$4);
				object_init_ex(&_4$$4, phalcon_annotations_annotation_ce);
				ZEPHIR_CALL_METHOD(NULL, &_4$$4, "__construct", &_3, 147, &annotationData);
				zephir_check_call_status();
				zephir_array_append(&annotations, &_4$$4, PH_SEPARATE, "phalcon/Annotations/Collection.zep", 55);
			ZEPHIR_CALL_METHOD(NULL, &reflectionData, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&annotationData);
	zephir_update_property_zval(this_ptr, SL("annotations"), &annotations);
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns the number of annotations in the collection
 */
PHP_METHOD(Phalcon_Annotations_Collection, count) {

	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	zephir_read_property(&_0, this_ptr, SL("annotations"), PH_NOISY_CC | PH_READONLY);
	RETURN_LONG(zephir_fast_count_int(&_0));

}

/**
 * Returns the current annotation in the iterator
 */
PHP_METHOD(Phalcon_Annotations_Collection, current) {

	zval annotation, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&annotation);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);


	zephir_read_property(&_0, this_ptr, SL("annotations"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_1, this_ptr, SL("position"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset_fetch(&annotation, &_0, &_1, 1))) {
		RETURN_BOOL(0);
	}
	RETURN_CTORW(&annotation);

}

/**
 * Returns the first annotation that match a name
 */
PHP_METHOD(Phalcon_Annotations_Collection, get) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, annotation, annotations, _0, *_1, _2, _5, _3$$3, _4$$5;
	zval name, _6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&annotation);
	ZVAL_UNDEF(&annotations);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(&name, name_param);


	zephir_read_property(&_0, this_ptr, SL("annotations"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&annotations, &_0);
	zephir_is_iterable(&annotations, 0, "phalcon/Annotations/Collection.zep", 98);
	if (Z_TYPE_P(&annotations) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&annotations), _1)
		{
			ZEPHIR_INIT_NVAR(&annotation);
			ZVAL_COPY(&annotation, _1);
			ZEPHIR_CALL_METHOD(&_3$$3, &annotation, "getname", NULL, 0);
			zephir_check_call_status();
			if (ZEPHIR_IS_EQUAL(&name, &_3$$3)) {
				RETURN_CCTOR(&annotation);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &annotations, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_2, &annotations, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_2)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&annotation, &annotations, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_4$$5, &annotation, "getname", NULL, 0);
				zephir_check_call_status();
				if (ZEPHIR_IS_EQUAL(&name, &_4$$5)) {
					RETURN_CCTOR(&annotation);
				}
			ZEPHIR_CALL_METHOD(NULL, &annotations, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&annotation);
	ZEPHIR_INIT_VAR(&_5);
	object_init_ex(&_5, phalcon_annotations_exception_ce);
	ZEPHIR_INIT_VAR(&_6);
	ZEPHIR_CONCAT_SVS(&_6, "Collection doesn't have an annotation called '", &name, "'");
	ZEPHIR_CALL_METHOD(NULL, &_5, "__construct", NULL, 6, &_6);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_5, "phalcon/Annotations/Collection.zep", 100);
	ZEPHIR_MM_RESTORE();
	return;

}

/**
 * Returns all the annotations that match a name
 */
PHP_METHOD(Phalcon_Annotations_Collection, getAll) {

	zval found;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, annotations, annotation, _0, *_1, _2, _3$$3, _4$$5;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&annotations);
	ZVAL_UNDEF(&annotation);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&found);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(&name, name_param);


	ZEPHIR_INIT_VAR(&found);
	array_init(&found);
	zephir_read_property(&_0, this_ptr, SL("annotations"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&annotations, &_0);
	zephir_is_iterable(&annotations, 0, "phalcon/Annotations/Collection.zep", 120);
	if (Z_TYPE_P(&annotations) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&annotations), _1)
		{
			ZEPHIR_INIT_NVAR(&annotation);
			ZVAL_COPY(&annotation, _1);
			ZEPHIR_CALL_METHOD(&_3$$3, &annotation, "getname", NULL, 0);
			zephir_check_call_status();
			if (ZEPHIR_IS_EQUAL(&name, &_3$$3)) {
				zephir_array_append(&found, &annotation, PH_SEPARATE, "phalcon/Annotations/Collection.zep", 116);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &annotations, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_2, &annotations, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_2)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&annotation, &annotations, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_4$$5, &annotation, "getname", NULL, 0);
				zephir_check_call_status();
				if (ZEPHIR_IS_EQUAL(&name, &_4$$5)) {
					zephir_array_append(&found, &annotation, PH_SEPARATE, "phalcon/Annotations/Collection.zep", 116);
				}
			ZEPHIR_CALL_METHOD(NULL, &annotations, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&annotation);
	RETURN_CTOR(&found);

}

/**
 * Returns the internal annotations as an array
 */
PHP_METHOD(Phalcon_Annotations_Collection, getAnnotations) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "annotations");

}

/**
 * Check if an annotation exists in a collection
 */
PHP_METHOD(Phalcon_Annotations_Collection, has) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, annotations, annotation, _0, *_1, _2, _3$$3, _4$$5;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&annotations);
	ZVAL_UNDEF(&annotation);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(&name, name_param);


	zephir_read_property(&_0, this_ptr, SL("annotations"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&annotations, &_0);
	zephir_is_iterable(&annotations, 0, "phalcon/Annotations/Collection.zep", 146);
	if (Z_TYPE_P(&annotations) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&annotations), _1)
		{
			ZEPHIR_INIT_NVAR(&annotation);
			ZVAL_COPY(&annotation, _1);
			ZEPHIR_CALL_METHOD(&_3$$3, &annotation, "getname", NULL, 0);
			zephir_check_call_status();
			if (ZEPHIR_IS_EQUAL(&name, &_3$$3)) {
				RETURN_MM_BOOL(1);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &annotations, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_2, &annotations, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_2)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&annotation, &annotations, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_4$$5, &annotation, "getname", NULL, 0);
				zephir_check_call_status();
				if (ZEPHIR_IS_EQUAL(&name, &_4$$5)) {
					RETURN_MM_BOOL(1);
				}
			ZEPHIR_CALL_METHOD(NULL, &annotations, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&annotation);
	RETURN_MM_BOOL(0);

}

/**
 * Returns the current position/key in the iterator
 */
PHP_METHOD(Phalcon_Annotations_Collection, key) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "position");

}

/**
 * Moves the internal iteration pointer to the next position
 */
PHP_METHOD(Phalcon_Annotations_Collection, next) {

	zval *this_ptr = getThis();


	RETURN_ON_FAILURE(zephir_property_incr(this_ptr, SL("position")));

}

/**
 * Rewinds the internal iterator
 */
PHP_METHOD(Phalcon_Annotations_Collection, rewind) {

	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, 0);
	zephir_update_property_zval(this_ptr, SL("position"), &_0);

}

/**
 * Check if the current annotation in the iterator is valid
 */
PHP_METHOD(Phalcon_Annotations_Collection, valid) {

	zval _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);


	zephir_read_property(&_0, this_ptr, SL("annotations"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_1, this_ptr, SL("position"), PH_NOISY_CC | PH_READONLY);
	RETURN_BOOL(zephir_array_isset(&_0, &_1));

}

