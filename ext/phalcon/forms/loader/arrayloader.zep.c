
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
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/exception.h"
#include "kernel/concat.h"
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
 * Supplies form element definitions from a PHP array.
 */
ZEPHIR_INIT_CLASS(Phalcon_Forms_Loader_ArrayLoader)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Forms\\Loader, ArrayLoader, phalcon, forms_loader_arrayloader, phalcon_forms_loader_arrayloader_method_entry, 0);

	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_forms_loader_arrayloader_ce, SL("definitions"), ZEND_ACC_PROTECTED);
	zend_class_implements(phalcon_forms_loader_arrayloader_ce, 1, phalcon_contracts_forms_schema_ce);
	return SUCCESS;
}

/**
 * @param array $definitions
 */
PHP_METHOD(Phalcon_Forms_Loader_ArrayLoader, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *definitions_param = NULL;
	zval definitions;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&definitions);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(definitions, definitions_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &definitions_param);
	zephir_get_arrval(&definitions, definitions_param);
	zephir_update_property_zval(this_ptr, ZEND_STRL("definitions"), &definitions);
	ZEPHIR_MM_RESTORE();
}

/**
 * @return array
 * @throws Exception
 */
PHP_METHOD(Phalcon_Forms_Loader_ArrayLoader, load)
{
	zend_string *_4;
	zend_ulong _3;
	zval definition, index, _0, *_1, _2, _5$$3, _7$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_6 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&definition);
	ZVAL_UNDEF(&index);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_7$$4);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property(&_0, this_ptr, ZEND_STRL("definitions"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_0, 0, "phalcon/Forms/Loader/ArrayLoader.zep", 46);
	if (Z_TYPE_P(&_0) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_0), _3, _4, _1)
		{
			ZEPHIR_INIT_NVAR(&index);
			if (_4 != NULL) { 
				ZVAL_STR_COPY(&index, _4);
			} else {
				ZVAL_LONG(&index, _3);
			}
			ZEPHIR_INIT_NVAR(&definition);
			ZVAL_COPY(&definition, _1);
			ZVAL_LONG(&_5$$3, zephir_get_intval(&index));
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "validatedefinition", &_6, 0, &definition, &_5$$3);
			zephir_check_call_status();
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_0, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_2, &_0, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_2)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&index, &_0, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&definition, &_0, "current", NULL, 0);
			zephir_check_call_status();
				ZVAL_LONG(&_7$$4, zephir_get_intval(&index));
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "validatedefinition", &_6, 0, &definition, &_7$$4);
				zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &_0, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&definition);
	ZEPHIR_INIT_NVAR(&index);
	RETURN_MM_MEMBER_TYPED(getThis(), "definitions", IS_ARRAY);
}

/**
 * @param mixed $definition
 * @param int   $index
 *
 * @throws Exception
 */
PHP_METHOD(Phalcon_Forms_Loader_ArrayLoader, validateDefinition)
{
	zend_bool _3, _8;
	zval _2$$3, _7$$4, _12$$5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long index, ZEPHIR_LAST_CALL_STATUS;
	zval *definition, definition_sub, *index_param = NULL, _0$$3, _1$$3, _4, _9, _5$$4, _6$$4, _10$$5, _11$$5;

	ZVAL_UNDEF(&definition_sub);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_12$$5);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(definition)
		Z_PARAM_LONG(index)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &definition, &index_param);
	if (Z_TYPE_P(definition) != IS_ARRAY) {
		ZEPHIR_INIT_VAR(&_0$$3);
		object_init_ex(&_0$$3, phalcon_forms_exception_ce);
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_LONG(&_1$$3, index);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZEPHIR_CONCAT_SVS(&_2$$3, "Form schema definition at index ", &_1$$3, " must be an array");
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 49, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$3, "phalcon/Forms/Loader/ArrayLoader.zep", 60);
		ZEPHIR_MM_RESTORE();
		return;
	}
	_3 = !(zephir_array_isset_string(definition, SL("type")));
	if (!(_3)) {
		zephir_array_fetch_string(&_4, definition, SL("type"), PH_NOISY | PH_READONLY, "phalcon/Forms/Loader/ArrayLoader.zep", 63);
		_3 = ZEPHIR_IS_EMPTY(&_4);
	}
	if (_3) {
		ZEPHIR_INIT_VAR(&_5$$4);
		object_init_ex(&_5$$4, phalcon_forms_exception_ce);
		ZEPHIR_INIT_VAR(&_6$$4);
		ZVAL_LONG(&_6$$4, index);
		ZEPHIR_INIT_VAR(&_7$$4);
		ZEPHIR_CONCAT_SVS(&_7$$4, "Form schema definition at index ", &_6$$4, " is missing required key \"type\"");
		ZEPHIR_CALL_METHOD(NULL, &_5$$4, "__construct", NULL, 49, &_7$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_5$$4, "phalcon/Forms/Loader/ArrayLoader.zep", 66);
		ZEPHIR_MM_RESTORE();
		return;
	}
	_8 = !(zephir_array_isset_string(definition, SL("name")));
	if (!(_8)) {
		zephir_array_fetch_string(&_9, definition, SL("name"), PH_NOISY | PH_READONLY, "phalcon/Forms/Loader/ArrayLoader.zep", 69);
		_8 = ZEPHIR_IS_EMPTY(&_9);
	}
	if (_8) {
		ZEPHIR_INIT_VAR(&_10$$5);
		object_init_ex(&_10$$5, phalcon_forms_exception_ce);
		ZEPHIR_INIT_VAR(&_11$$5);
		ZVAL_LONG(&_11$$5, index);
		ZEPHIR_INIT_VAR(&_12$$5);
		ZEPHIR_CONCAT_SVS(&_12$$5, "Form schema definition at index ", &_11$$5, " is missing required key \"name\"");
		ZEPHIR_CALL_METHOD(NULL, &_10$$5, "__construct", NULL, 49, &_12$$5);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_10$$5, "phalcon/Forms/Loader/ArrayLoader.zep", 72);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_MM_RESTORE();
}

