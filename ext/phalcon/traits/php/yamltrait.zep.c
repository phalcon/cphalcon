
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
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *filename, filename_sub, *pos = NULL, pos_sub, *callbacks = NULL, callbacks_sub, ndocs;

	ZVAL_UNDEF(&filename_sub);
	ZVAL_UNDEF(&pos_sub);
	ZVAL_UNDEF(&callbacks_sub);
	ZVAL_UNDEF(&ndocs);
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_ZVAL(filename)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL(pos)
		Z_PARAM_ZVAL(callbacks)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 2, &filename, &pos, &callbacks);
	if (!pos) {
		pos = &pos_sub;
		ZEPHIR_INIT_VAR(pos);
		ZVAL_LONG(pos, 0);
	}
	if (!callbacks) {
		callbacks = &callbacks_sub;
		ZEPHIR_INIT_VAR(callbacks);
		array_init(callbacks);
	}
	ZEPHIR_INIT_VAR(&ndocs);
	ZVAL_NULL(&ndocs);
	ZEPHIR_MAKE_REF(&ndocs);
	ZEPHIR_RETURN_CALL_FUNCTION("yaml_parse_file", NULL, 399, filename, pos, &ndocs, callbacks);
	ZEPHIR_UNREF(&ndocs);
	zephir_check_call_status();
	RETURN_MM();
}

