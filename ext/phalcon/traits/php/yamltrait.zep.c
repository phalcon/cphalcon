
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
#include "kernel/memory.h"
#include "kernel/fcall.h"
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
 * YAML based wrapper methods
 */
ZEPHIR_INIT_CLASS(Phalcon_Traits_Php_YamlTrait)
{
	ZEPHIR_REGISTER_TRAIT(Phalcon\\Traits\\Php, YamlTrait, phalcon, traits_php_yamltrait, phalcon_traits_php_yamltrait_method_entry);

	return SUCCESS;
}

/**
 * Parse a YAML stream from a file
 *
 * @param string $filename
 * @param int    $pos
 * @param array  $callbacks
 *
 * @return mixed
 *
 * @link https://php.net/manual/en/function.yaml-parse-file.php
 */
PHP_METHOD(Phalcon_Traits_Php_YamlTrait, phpYamlParseFile)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval callbacks;
	zend_long pos, ZEPHIR_LAST_CALL_STATUS;
	zval filename_zv, *pos_param = NULL, *callbacks_param = NULL, ndocs, _0;
	zend_string *filename = NULL;

	ZVAL_UNDEF(&filename_zv);
	ZVAL_UNDEF(&ndocs);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&callbacks);
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_STR(filename)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(pos)
		ZEPHIR_Z_PARAM_ARRAY(callbacks, callbacks_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		pos_param = ZEND_CALL_ARG(execute_data, 2);
	}
	if (ZEND_NUM_ARGS() > 2) {
		callbacks_param = ZEND_CALL_ARG(execute_data, 3);
	}
	zephir_memory_observe(&filename_zv);
	ZVAL_STR_COPY(&filename_zv, filename);
	if (!pos_param) {
		pos = 0;
	} else {
		}
	if (!callbacks_param) {
		ZEPHIR_INIT_VAR(&callbacks);
		array_init(&callbacks);
	} else {
		zephir_get_arrval(&callbacks, callbacks_param);
	}
	ZEPHIR_INIT_VAR(&ndocs);
	ZVAL_NULL(&ndocs);
	ZVAL_LONG(&_0, pos);
	ZEPHIR_MAKE_REF(&ndocs);
	ZEPHIR_RETURN_CALL_FUNCTION("yaml_parse_file", NULL, 420, &filename_zv, &_0, &ndocs, &callbacks);
	ZEPHIR_UNREF(&ndocs);
	zephir_check_call_status();
	RETURN_MM();
}

