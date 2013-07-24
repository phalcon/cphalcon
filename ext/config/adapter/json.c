
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
  |          Vladimir Kolesnikov <vladimir@extrememember.com>              |
  +------------------------------------------------------------------------+
*/

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_phalcon.h"
#include "phalcon.h"

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/file.h"
#include "kernel/string.h"

#include "config/adapter/json.h"

/**
 * Phalcon\Config\Adapter\Json
 *
 * Reads JSON files and converts them to Phalcon\Config objects.
 *
 * Given the following configuration file:
 *
 *<code>
 *{"phalcon":{"baseuri":"\/phalcon\/"},"models":{"metadata":"memory"}}
 *</code>
 *
 * You can read it as follows:
 *
 *<code>
 *	$config = new Phalcon\Config\Adapter\Json("path/config.json");
 *	echo $config->phalcon->baseuri;
 *	echo $config->models->metadata;
 *</code>
 *
 */


/**
 * Phalcon\Config\Adapter\Json initializer
 */
PHALCON_INIT_CLASS(Phalcon_Config_Adapter_Json){

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Config\\Adapter, Json, config_adapter_json, "phalcon\\config", phalcon_config_adapter_json_method_entry, 0);

	return SUCCESS;
}

/**
 * Phalcon\Config\Adapter\Json constructor
 *
 * @param string $filePath
 */
PHP_METHOD(Phalcon_Config_Adapter_Json, __construct){

	zval *file_path, *contents, *array;

	phalcon_fetch_params(0, 1, 0, &file_path);

	ALLOC_INIT_ZVAL(contents);
	ALLOC_INIT_ZVAL(array);
	phalcon_file_get_contents(contents, file_path TSRMLS_CC);

	if (Z_TYPE_P(contents) == IS_STRING) {
		phalcon_json_decode(array, contents, 1 TSRMLS_CC);
	}

	zval_ptr_dtor(&contents);

	if (Z_TYPE_P(array) != IS_ARRAY) {
		zval_dtor(array);
		array_init_size(array, 0);
	}

	phalcon_config_construct_internal(getThis(), array TSRMLS_CC);
	zval_ptr_dtor(&array);
}
