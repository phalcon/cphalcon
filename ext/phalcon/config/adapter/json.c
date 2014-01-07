
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
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"


/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2013 Phalcon Team (http://www.phalconphp.com)       |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file docs/LICENSE.txt.                        |
 |                                                                        |
 | If you did not receive a copy of the license and are unable to         |
 | obtain it through the world-wide-web, please send an email             |
 | to license@phalconphp.com so we can send you a copy immediately.       |
 +------------------------------------------------------------------------+
 | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
 |          Eduar Carvajal <eduar@phalconphp.com>                         |
 +------------------------------------------------------------------------+
 */
ZEPHIR_INIT_CLASS(Phalcon_Config_Adapter_Json) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Config\\Adapter, Json, phalcon, config_adapter_json, phalcon_config_ce, phalcon_config_adapter_json_method_entry, 0);


	return SUCCESS;

}

/**
 * Phalcon\Config\Adapter\Json constructor
 *
 * @param string filePath
 */
PHP_METHOD(Phalcon_Config_Adapter_Json, __construct) {

	zval *filePath_param = NULL, *config, *_0;
	zval *filePath = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &filePath_param);

		if (Z_TYPE_P(filePath_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'filePath' must be a string") TSRMLS_CC);
				RETURN_MM_NULL();
		}

		filePath = filePath_param;



	ZEPHIR_INIT_VAR(_0);
	zephir_call_func_p1(_0, "file_get_contents", filePath);
	ZEPHIR_INIT_VAR(config);
	zephir_call_func_p2(config, "json_decode", _0, ZEPHIR_GLOBAL(global_true));
	zephir_call_parent_p1_noret(this_ptr, phalcon_config_adapter_json_ce, "__construct", config);
	ZEPHIR_MM_RESTORE();

}

