
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
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/object.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Represents JavaScript assets
 */
ZEPHIR_INIT_CLASS(Phalcon_Assets_Asset_Js)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Assets\\Asset, Js, phalcon, assets_asset_js, phalcon_assets_asset_ce, phalcon_assets_asset_js_method_entry, 0);

	return SUCCESS;
}

/**
 * Phalcon\Assets\Asset\Js constructor
 */
PHP_METHOD(Phalcon_Assets_Asset_Js, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval attributes;
	zend_bool local, filter, autoVersion;
	zval *path_param = NULL, *local_param = NULL, *filter_param = NULL, *attributes_param = NULL, *version_param = NULL, *autoVersion_param = NULL, _0, _1, _2, _3;
	zval path, version;

	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&version);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&attributes);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 6)
		Z_PARAM_STR(path)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(local)
		Z_PARAM_BOOL(filter)
		Z_PARAM_ARRAY(attributes)
		Z_PARAM_STR_OR_NULL(version)
		Z_PARAM_BOOL(autoVersion)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 5, &path_param, &local_param, &filter_param, &attributes_param, &version_param, &autoVersion_param);
	if (UNEXPECTED(Z_TYPE_P(path_param) != IS_STRING && Z_TYPE_P(path_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'path' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(path_param) == IS_STRING)) {
		zephir_get_strval(&path, path_param);
	} else {
		ZEPHIR_INIT_VAR(&path);
	}
	if (!local_param) {
		local = 1;
	} else {
		}
	if (!filter_param) {
		filter = 1;
	} else {
		}
	if (!attributes_param) {
		ZEPHIR_INIT_VAR(&attributes);
		array_init(&attributes);
	} else {
		zephir_get_arrval(&attributes, attributes_param);
	}
	if (!version_param) {
		ZEPHIR_INIT_VAR(&version);
	} else {
		zephir_get_strval(&version, version_param);
	}
	if (!autoVersion_param) {
		autoVersion = 0;
	} else {
		}
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "js");
	if (local) {
		ZVAL_BOOL(&_1, 1);
	} else {
		ZVAL_BOOL(&_1, 0);
	}
	if (filter) {
		ZVAL_BOOL(&_2, 1);
	} else {
		ZVAL_BOOL(&_2, 0);
	}
	if (autoVersion) {
		ZVAL_BOOL(&_3, 1);
	} else {
		ZVAL_BOOL(&_3, 0);
	}
	ZEPHIR_CALL_PARENT(NULL, phalcon_assets_asset_js_ce, getThis(), "__construct", NULL, 0, &_0, &path, &_1, &_2, &attributes, &version, &_3);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

