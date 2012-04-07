
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2012 Phalcon Team (http://www.phalconphp.com)       |
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

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/require.h"
#include "kernel/object.h"
#include "kernel/debug.h"
#include "kernel/assert.h"
#include "kernel/array.h"
#include "kernel/memory.h"

#include "zend_operators.h"
#include "zend_exceptions.h"
#include "zend_interfaces.h"

/**
 * Phalcon_Cache
 *
 * Phalcon_Cache could be use to caches output fragments for improve performance
 *
 *
 * $frontendOptions = array(
 *	'lifetime' => 172800
 *);
 *
 *$backendOptions = array(
 *	'cacheDir' => '../app/cache/'
 *);
 *
 *$cache = Phalcon_Cache::factory('File', $frontendOptions, $backendOptions);
 *
 *$content = $cache->start('my-cache');
 *if($content===null){
 *  $cache->save();
 *} else {
 *	echo $content;
 *}
 */

/**
 * Factories diferent caches backends from its adapters
 *
 * @paramstring $adapter
 * @paramarray $frontendOptions
 * @paramarray $backendOptions
 * @static
 */
PHP_METHOD(Phalcon_Cache, factory){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL;
	zval *a0 = NULL, *a1 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;
	zval *i0 = NULL, *i1 = NULL;
	zval *p1[] = { NULL }, *p2[] = { NULL, NULL };
	zend_class_entry *ce0;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|zz", &v0, &v1, &v2) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	if (!v1) {
		PHALCON_INIT_VAR(a0);
		array_init(a0);
	PHALCON_CPY_WRT(v1, a0);
	}
	if (!v2) {
		PHALCON_INIT_VAR(a1);
		array_init(a1);
	PHALCON_CPY_WRT(v2, a1);
	}
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CONCAT_LEFT(r0, "Phalcon_Cache_Adapter_", v0);
	PHALCON_CPY_WRT(v3, r0);
	PHALCON_ALLOC_ZVAL_MM(r1);
	Z_ADDREF_P(v3);
	PHALCON_CALL_FUNC_PARAMS_1(r1, "class_exists", v3, 0x000);
	Z_DELREF_P(v3);
	if (!zend_is_true(r1)) {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_cache_exception_class_entry);
		PHALCON_ALLOC_ZVAL_MM(r2);
		PHALCON_CONCAT_BOTH(r2,  "Adapter \"", v0, "' doesn't exist");
		Z_ADDREF_P(r2);
		p1[0] = r2;
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p1, PHALCON_CALL_CHECK);
		Z_DELREF_P(p1[0]);
		zend_throw_exception_object(i0 TSRMLS_CC);
		Z_ADDREF_P(i0);
		PHALCON_MM_RESTORE();
		return;
	}
	ce0 = zend_fetch_class(Z_STRVAL_P(v3), Z_STRLEN_P(v3), ZEND_FETCH_CLASS_DEFAULT TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(i1);
	object_init_ex(i1, ce0);
	Z_ADDREF_P(v1);
	p2[0] = v1;
	Z_ADDREF_P(v2);
	p2[1] = v2;
	PHALCON_CALL_METHOD_PARAMS_NORETURN(i1, "__construct", 2, p2, PHALCON_CALL_CHECK);
	Z_DELREF_P(p2[0]);
	Z_DELREF_P(p2[1]);
	PHALCON_RETURN_CTOR(i1);
}

