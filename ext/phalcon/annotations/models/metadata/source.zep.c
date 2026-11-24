
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
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
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
 * Names the table of a model when the annotations service uses AttributesReader.
 * An explicit setSource() takes precedence. The model manager applies its
 * table prefix to the source.
 * The attribute applies only to the class declaring it; it is not inherited.
 * PHPDoc @Source annotations do not change the model's table.
 * A Source attribute must specify a non-empty string table name.
 *
 * ```php
 * use Phalcon\Annotations\Models\MetaData\Source;
 * use Phalcon\Mvc\Model;
 *
 * #[Source(table: "customers")]
 * class Customers extends Model
 * {
 * }
 * ```
 */
ZEPHIR_INIT_CLASS(Phalcon_Annotations_Models_MetaData_Source)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Annotations\\Models\\MetaData, Source, phalcon, annotations_models_metadata_source, phalcon_annotations_models_metadata_source_method_entry, 0);

	{
		zend_attribute *_za = zephir_add_class_attribute(phalcon_annotations_models_metadata_source_ce, SL("Attribute"), 1);
		zval _zc0;
		ZVAL_LONG(&_zc0, ZEND_ATTRIBUTE_TARGET_CLASS);
		zephir_attribute_set_arg(_za, 0, NULL, 0, &_zc0);
	}

	/**
	 * @var string
	 */
	zend_declare_property_null(phalcon_annotations_models_metadata_source_ce, SL("table"), ZEND_ACC_PUBLIC);
	return SUCCESS;
}

PHP_METHOD(Phalcon_Annotations_Models_MetaData_Source, __construct)
{
	zval table_zv;
	zend_string *table = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&table_zv);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("table", 5, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(table)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&table_zv, table);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 418, &table_zv);
	if (UNEXPECTED(EG(exception))) {
		return;
	}
}

/**
 * Returns the table from a Source annotation, or null when none is present.
 * Named arguments take precedence over positional arguments.
 *
 * @throws InvalidSourceTable
 */
PHP_METHOD(Phalcon_Annotations_Models_MetaData_Source, getTable)
{
	zend_bool _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *annotations, annotations_sub, sourceAnnotation, table, _0, _1, _2$$4, _4$$5;

	ZVAL_UNDEF(&annotations_sub);
	ZVAL_UNDEF(&sourceAnnotation);
	ZVAL_UNDEF(&table);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_4$$5);
	ZEND_TLS zephir_method_cache _zephir_call_cache[5];
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(annotations, phalcon_annotations_collection_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &annotations);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "Source");
	ZEPHIR_CALL_METHOD_CACHED(&_0, annotations, "has", &_zephir_call_cache[0], &_1);
	zephir_check_call_status();
	if (!(zephir_is_true(&_0))) {
		RETURN_MM_NULL();
	}
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Source");
	ZEPHIR_CALL_METHOD_CACHED(&sourceAnnotation, annotations, "get", &_zephir_call_cache[1], &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "table");
	ZEPHIR_CALL_METHOD_CACHED(&table, &sourceAnnotation, "getNamedArgument", &_zephir_call_cache[2], &_1);
	zephir_check_call_status();
	if (Z_TYPE_P(&table) == IS_NULL) {
		ZVAL_LONG(&_2$$4, 0);
		ZEPHIR_CALL_METHOD_CACHED(&table, &sourceAnnotation, "getArgument", &_zephir_call_cache[3], &_2$$4);
		zephir_check_call_status();
	}
	_3 = Z_TYPE_P(&table) != IS_STRING;
	if (!(_3)) {
		ZEPHIR_INIT_NVAR(&_1);
		zephir_fast_trim(&_1, &table, NULL , ZEPHIR_TRIM_BOTH);
		_3 = ZEPHIR_IS_STRING_IDENTICAL(&_1, "");
	}
	if (_3) {
		ZEPHIR_INIT_VAR(&_4$$5);
		object_init_ex(&_4$$5, phalcon_annotations_exceptions_invalidsourcetable_ce);
		zephir_constructor_start(&_4$$5);
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_4$$5, "__construct", &_zephir_call_cache[4], &table);
		zephir_check_call_status();
		zephir_constructor_finish(&_4$$5);
		zephir_throw_exception_debug(&_4$$5, "phalcon/Annotations/Models/MetaData/Source.zep", 72);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_CCTOR(&table);
}

/**
 * Returns the model's table when the adapter uses AttributesReader.
 * Other readers do not opt in and are not asked to parse the class.
 * A value that is not an annotations adapter does not opt in.
 *
 * @throws InvalidSourceTable
 */
PHP_METHOD(Phalcon_Annotations_Models_MetaData_Source, getTableFromAdapter)
{
	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_string *className = NULL;
	zval *adapter, adapter_sub, className_zv, annotations, _1, _2;

	ZVAL_UNDEF(&adapter_sub);
	ZVAL_UNDEF(&className_zv);
	ZVAL_UNDEF(&annotations);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_TLS zephir_method_cache _zephir_call_cache[4];
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(adapter)
		Z_PARAM_STR(className)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	adapter = ZEND_CALL_ARG(execute_data, 1);
	zephir_memory_observe(&className_zv);
	ZVAL_STR_COPY(&className_zv, className);
	_0 = Z_TYPE_P(adapter) != IS_OBJECT;
	if (!(_0)) {
		_0 = !((zephir_instance_of_ev(adapter, phalcon_annotations_adapter_adapterinterface_ce)));
	}
	if (_0) {
		RETURN_MM_NULL();
	}
	ZEPHIR_CALL_METHOD_CACHED(&_1, adapter, "getReader", &_zephir_call_cache[0]);
	zephir_check_call_status();
	if (!(zephir_instance_of_ev(&_1, phalcon_annotations_attributesreader_ce))) {
		RETURN_MM_NULL();
	}
	ZEPHIR_CALL_METHOD_CACHED(&_2, adapter, "get", &_zephir_call_cache[1], &className_zv);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(&annotations, &_2, "getClassAnnotations", &_zephir_call_cache[2]);
	zephir_check_call_status();
	if (Z_TYPE_P(&annotations) == IS_NULL) {
		RETURN_MM_NULL();
	}
	ZEPHIR_RETURN_CALL_SELF_CACHED("getTable", &_zephir_call_cache[3], &annotations);
	zephir_check_call_status();
	RETURN_MM();
}

