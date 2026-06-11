
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
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/file.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Supplies form element definitions from a JSON string or file.
 *
 * When $source looks like an existing, readable file path it is read from
 * disk first; otherwise the value is treated as a raw JSON string.
 */
ZEPHIR_INIT_CLASS(Phalcon_Forms_Loader_JsonLoader)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Forms\\Loader, JsonLoader, phalcon, forms_loader_jsonloader, phalcon_forms_loader_jsonloader_method_entry, 0);

	/**
	 * @var string
	 */
	zend_declare_property_null(phalcon_forms_loader_jsonloader_ce, SL("source"), ZEND_ACC_PROTECTED);
	zend_class_implements(phalcon_forms_loader_jsonloader_ce, 1, phalcon_contracts_forms_schema_ce);
	return SUCCESS;
}

/**
 * @param string $source JSON string or path to a JSON file
 */
PHP_METHOD(Phalcon_Forms_Loader_JsonLoader, __construct)
{
	zval source_zv;
	zend_string *source = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&source_zv);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(source)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&source_zv, source);
	zephir_update_property_zval(this_ptr, ZEND_STRL("source"), &source_zv);
}

/**
 * @phpstan-return array<int, array<string, mixed>>
 * @throws Exception
 */
PHP_METHOD(Phalcon_Forms_Loader_JsonLoader, load)
{
	zval _4$$3;
	zend_bool _1, _12;
	zval ex, definitions, json, loader, _0, _2, _9, _13, _3$$3, _5$$4, _6$$4, _7$$4, _8$$4, _10$$5, _11$$5, _14$$6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&ex);
	ZVAL_UNDEF(&definitions);
	ZVAL_UNDEF(&json);
	ZVAL_UNDEF(&loader);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_14$$6);
	ZVAL_UNDEF(&_4$$3);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_memory_observe(&json);
	zephir_read_property(&json, this_ptr, ZEND_STRL("source"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&_0, "is_file", NULL, 353, &json);
	zephir_check_call_status();
	_1 = zephir_is_true(&_0);
	if (_1) {
		ZEPHIR_CALL_FUNCTION(&_2, "is_readable", NULL, 0, &json);
		zephir_check_call_status();
		_1 = zephir_is_true(&_2);
	}
	if (_1) {
		ZEPHIR_CALL_METHOD(&_3$$3, this_ptr, "phpfilegetcontents", NULL, 0, &json);
		zephir_check_call_status();
		zephir_cast_to_string(&_4$$3, &_3$$3);
		ZEPHIR_CPY_WRT(&json, &_4$$3);
	}

	/* try_start_1: */

		ZEPHIR_INIT_VAR(&_5$$4);
		object_init_ex(&_5$$4, phalcon_support_helper_json_decode_ce);
		if (zephir_has_constructor(&_5$$4)) {
			ZEPHIR_CALL_METHOD(NULL, &_5$$4, "__construct", NULL, 0);
			zephir_check_call_status_or_jump(try_end_1);
		}

		ZVAL_BOOL(&_6$$4, 1);
		ZVAL_LONG(&_7$$4, 512);
		ZVAL_LONG(&_8$$4, 4194304);
		ZEPHIR_CALL_METHOD(&definitions, &_5$$4, "__invoke", NULL, 305, &json, &_6$$4, &_7$$4, &_8$$4);
		zephir_check_call_status_or_jump(try_end_1);

	try_end_1:

	if (EG(exception)) {
		ZEPHIR_INIT_VAR(&_9);
		ZVAL_OBJ(&_9, EG(exception));
		Z_ADDREF_P(&_9);
		if (zephir_is_instance_of(&_9, SL("InvalidArgumentException"))) {
			zend_clear_exception();
			ZEPHIR_CPY_WRT(&ex, &_9);
			ZEPHIR_INIT_VAR(&_10$$5);
			object_init_ex(&_10$$5, phalcon_forms_exceptions_invalidjsonschema_ce);
			ZEPHIR_CALL_METHOD(&_11$$5, &ex, "getmessage", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &_10$$5, "__construct", NULL, 0, &_11$$5);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_10$$5, "phalcon/Forms/Loader/JsonLoader.zep", 58);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	_12 = Z_TYPE_P(&definitions) != IS_ARRAY;
	if (!(_12)) {
		ZEPHIR_CALL_FUNCTION(&_13, "array_is_list", NULL, 0, &definitions);
		zephir_check_call_status();
		_12 = !zephir_is_true(&_13);
	}
	if (_12) {
		ZEPHIR_INIT_VAR(&_14$$6);
		object_init_ex(&_14$$6, phalcon_forms_exceptions_jsonschemanotarray_ce);
		ZEPHIR_CALL_METHOD(NULL, &_14$$6, "__construct", NULL, 0);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_14$$6, "phalcon/Forms/Loader/JsonLoader.zep", 62);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&loader);
	object_init_ex(&loader, phalcon_forms_loader_arrayloader_ce);
	ZEPHIR_CALL_METHOD(NULL, &loader, "__construct", NULL, 0, &definitions);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&loader, "load", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Phalcon_Forms_Loader_JsonLoader, phpFileGetContents)
{
	zval filename_zv;
	zend_string *filename = NULL;

	ZVAL_UNDEF(&filename_zv);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(filename)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&filename_zv, filename);
	zephir_file_get_contents(return_value, &filename_zv);
	return;
}

