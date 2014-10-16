
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/array.h"


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
 * Phalcon\Registry
 *
 * A registry is a container for storing objects and values in the application space.
 * By storing the value in a registry, the same object is always available throughout
 * your application.
 *
 *<code>
 * 	$registry = new \Phalcon\Registry();
 *
 * 	// Set value
 * 	$registry->something = 'something';
 * 	// or
 * 	$registry['something'] = 'something';
 *
 * 	// Get value
 * 	$value = $registry->something;
 * 	// or
 * 	$value = $registry['something'];
 *
 * 	// Check if the key exists
 * 	$exists = isset($registry->something);
 * 	// or
 * 	$exists = isset($registry['something']);
 *
 * 	// Unset
 * 	unset($registry->something);
 * 	// or
 * 	unset($registry['something']);
 *</code>
 *
 * In addition to ArrayAccess, Phalcon\Registry also implements Countable
 * (count($registry) will return the number of elements in the registry),
 * Serializable and Iterator (you can iterate over the registry
 * using a foreach loop) interfaces. For PHP 5.4 and higher, JsonSerializable
 * interface is implemented.
 *
 * Phalcon\Registry is very fast (it is typically faster than any userspace
 * implementation of the registry); however, this comes at a price:
 * Phalcon\Registry is a final class and cannot be inherited from.
 *
 * Though Phalcon\Registry exposes methods like __get(), offsetGet(), count() etc,
 * it is not recommended to invoke them manually (these methods exist mainly to
 * match the interfaces the registry implements): $registry->__get('property')
 * is several times slower than $registry->property.
 *
 * Internally all the magic methods (and interfaces except JsonSerializable)
 * are implemented using object handlers or similar techniques: this allows
 * to bypass relatively slow method calls.
 */
ZEPHIR_INIT_CLASS(Phalcon_Registry) {

	ZEPHIR_REGISTER_CLASS(Phalcon, Registry, phalcon, registry, phalcon_registry_method_entry, 0);

	zend_declare_property_null(phalcon_registry_ce, SL("_data"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_class_implements(phalcon_registry_ce TSRMLS_CC, 1, zend_ce_arrayaccess);
	return SUCCESS;

}

PHP_METHOD(Phalcon_Registry, __construct) {

	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_property_this(this_ptr, SL("_data"), _0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Registry, offsetExists) {

	zval *offset, *_0;

	zephir_fetch_params(0, 1, 0, &offset);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_data"), PH_NOISY_CC);
	RETURN_BOOL(zephir_array_isset(_0, offset));

}

PHP_METHOD(Phalcon_Registry, offsetGet) {

	zval *offset, *_0, *_1;

	zephir_fetch_params(0, 1, 0, &offset);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_data"), PH_NOISY_CC);
	zephir_array_fetch(&_1, _0, offset, PH_NOISY | PH_READONLY, "phalcon/registry.zep", 89 TSRMLS_CC);
	RETURN_CTORW(_1);

}

PHP_METHOD(Phalcon_Registry, offsetSet) {

	zval *offset, *value;

	zephir_fetch_params(0, 2, 0, &offset, &value);



	zephir_update_property_array(this_ptr, SL("_data"), offset, value TSRMLS_CC);

}

PHP_METHOD(Phalcon_Registry, offsetUnset) {

	zval *offset, *_0;

	zephir_fetch_params(0, 1, 0, &offset);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_data"), PH_NOISY_CC);
	zephir_array_unset(&_0, offset, PH_SEPARATE);

}

