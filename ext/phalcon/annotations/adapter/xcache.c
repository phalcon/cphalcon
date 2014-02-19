
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
#include "kernel/string.h"
#include "kernel/concat.h"
#include "kernel/fcall.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/object.h"


/*
+------------------------------------------------------------------------+
| Phalcon Framework                                                      |
+------------------------------------------------------------------------+
| Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
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
/**
 * Phalcon\Annotations\Adapter\Xcache
 *
 * Stores the parsed annotations to XCache. This adapter is suitable for production
 *
 *<code>
 * $annotations = new \Phalcon\Annotations\Adapter\Xcache();
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Annotations_Adapter_Xcache) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Annotations\\Adapter, Xcache, phalcon, annotations_adapter_xcache, phalcon_annotations_adapter_xcache_method_entry, 0);

	return SUCCESS;

}

/**
 * Reads parsed annotations from XCache
 *
 * @param string key
 * @return Phalcon\Annotations\Reflection
 */
PHP_METHOD(Phalcon_Annotations_Adapter_Xcache, read) {

	zval *key_param = NULL, *serialized, *data, *_0;
	zval *key = NULL, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	if (Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (Z_TYPE_P(key_param) == IS_STRING) {
		key = key_param;
	} else {
		ZEPHIR_INIT_VAR(key);
		ZVAL_EMPTY_STRING(key);
	}


	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_CONCAT_SV(_1, "_PHAN", key);
	zephir_fast_strtolower(_0, _1);
	ZEPHIR_INIT_VAR(serialized);
	zephir_call_func_p1(serialized, "xcache_get", _0);
	if ((Z_TYPE_P(serialized) == IS_STRING)) {
		ZEPHIR_INIT_VAR(data);
		zephir_call_func_p1(data, "unserialize", serialized);
		if ((Z_TYPE_P(data) == IS_OBJECT)) {
			RETURN_CCTOR(data);
		}
	}
	RETURN_MM_BOOL(0);

}

/**
 * Writes parsed annotations to XCache
 *
 * @param string key
 * @param Phalcon\Annotations\Reflection $data
 */
PHP_METHOD(Phalcon_Annotations_Adapter_Xcache, write) {

	zval *key_param = NULL, *data, *_0, *_2;
	zval *key = NULL, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key_param, &data);

	if (Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (Z_TYPE_P(key_param) == IS_STRING) {
		key = key_param;
	} else {
		ZEPHIR_INIT_VAR(key);
		ZVAL_EMPTY_STRING(key);
	}


	if (!(zephir_instance_of_ev(data, phalcon_annotations_reflection_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_STR(spl_ce_InvalidArgumentException, "Parameter 'data' must be an instance of 'Phalcon\\Annotations\\Reflection'");
		return;
	}
	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_CONCAT_SV(_1, "_PHAN", key);
	zephir_fast_strtolower(_0, _1);
	ZEPHIR_INIT_VAR(_2);
	zephir_call_func_p1(_2, "serialize", data);
	zephir_call_func_p2_noret("xcache_set", _0, _2);
	ZEPHIR_MM_RESTORE();

}

