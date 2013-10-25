
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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_phalcon.h"
#include "phalcon.h"

#include "Zend/zend_operators.h"
#include "Zend/zend_exceptions.h"
#include "Zend/zend_interfaces.h"

#include "kernel/main.h"
#include "kernel/memory.h"

#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/exception.h"
#include "kernel/hash.h"
#include "kernel/string.h"
#include "kernel/array.h"

/**
 * Phalcon\Config\Adapter\Php
 *
 * Reads php files and converts them to Phalcon\Config objects.
 *
 * Given the next configuration file:
 *
 *<code>
 *[database]
 *adapter = Mysql
 *host = localhost
 *username = scott
 *password = cheetah
 *dbname = test_db
 *
 *[phalcon]
 *controllersDir = "../app/controllers/"
 *modelsDir = "../app/models/"
 *viewsDir = "../app/views/"
 *</code>
 *
 * You can read it as follows:
 *
 *<code>
 *	$config = new Phalcon\Config\Adapter\Php("path/config.php");
 *	echo $config->phalcon->controllersDir;
 *	echo $config->database->username;
 *</code>
 *
 */

static inline void phalcon_config_adapter_php_update_zval_directive(zval **arr, zval *section, zval *directive, zval **value, int flags TSRMLS_DC) {
	zval *temp1 = NULL, *temp2 = NULL, *index = NULL;
	int i, n;

	n = zend_hash_num_elements(Z_ARRVAL_P(directive));

	if (Z_TYPE_PP(arr) == IS_ARRAY) {
		phalcon_array_fetch(&temp1, *arr, section, PH_SILENT);
		if (Z_REFCOUNT_P(temp1) > 1) {
			phalcon_array_update_zval(arr, section, &temp1, PH_COPY | PH_CTOR);
		}
		if (Z_TYPE_P(temp1) != IS_ARRAY) {
			convert_to_array(temp1);
			phalcon_array_update_zval(arr, section, &temp1, PH_COPY);
		}

		for (i = 0; i < n - 1; i++) {
			phalcon_array_fetch_long(&index, directive, i, PH_NOISY);

			phalcon_array_fetch(&temp2, temp1, index, PH_SILENT);
			if (Z_REFCOUNT_P(temp2) > 1) {
				phalcon_array_update_zval(&temp1, index, &temp2, PH_COPY | PH_CTOR);
			}
			if (Z_TYPE_P(temp2) != IS_ARRAY) {
				convert_to_array(temp2);
				phalcon_array_update_zval(&temp1, index, &temp2, PH_COPY);
			}
			zval_ptr_dtor(&index);

			if (temp1 != NULL) {
				zval_ptr_dtor(&temp1);
			}
			temp1 = temp2;
			temp2 = NULL;
		}

		phalcon_array_fetch_long(&index, directive, n - 1, PH_NOISY);
		phalcon_array_update_zval(&temp1, index, value, PH_COPY);

		zval_ptr_dtor(&index);

		if (temp1 != NULL) {
			zval_ptr_dtor(&temp1);
		}
	}
}

/**
 * Phalcon\Config\Adapter\Php phptializer
 */
PHALCON_INIT_CLASS(Phalcon_Config_Adapter_Php){

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Config\\Adapter, Php, config_adapter_php, phalcon_config_ce, phalcon_config_adapter_php_method_entry, 0);

	return SUCCESS;
}

/**
 * Phalcon\Config\Adapter\Php constructor
 *
 * @param string $filePath
 */
PHP_METHOD(Phalcon_Config_Adapter_Php, __construct){

	zval *file_path, *config, *exception_message;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &file_path);

	PHALCON_INIT_VAR(config);
	if (phalcon_require_ret(config, file_path TSRMLS_CC) == FAILURE) {			
		PHALCON_INIT_VAR(exception_message);
		PHALCON_CONCAT_SVS(exception_message, "Configuration file ", file_path, " can't be loaded");
		PHALCON_THROW_EXCEPTION_ZVAL(phalcon_config_exception_ce, exception_message);
		return;
	}
	
	/** 
	 * Calls the Phalcon\Config constructor
	 */
	phalcon_call_parent_p1_noret(this_ptr, phalcon_config_adapter_php_ce, "__construct", config);
	
	PHALCON_MM_RESTORE();
}

