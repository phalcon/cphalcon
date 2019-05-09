
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\CacheFactory
 *
 * Creates a new Cache class
 */
ZEPHIR_INIT_CLASS(Phalcon_Cache_CacheFactory) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Cache, CacheFactory, phalcon, cache_cachefactory, phalcon_cache_cachefactory_method_entry, 0);

	/**
	 * @var <AdapterFactory>
	 */
	zend_declare_property_null(phalcon_cache_cachefactory_ce, SL("adapterFactory"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Constructor
 */
PHP_METHOD(Phalcon_Cache_CacheFactory, __construct) {

	zval *factory, factory_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&factory_sub);

	zephir_fetch_params(0, 1, 0, &factory);



	zephir_update_property_zval(this_ptr, SL("adapterFactory"), factory);

}

/**
 * Constructor.
 *
 * @param AdapterInterface  adapter The cache adapter
 */
PHP_METHOD(Phalcon_Cache_CacheFactory, newInstance) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval options;
	zval *name_param = NULL, *options_param = NULL, adapter, _0;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&adapter);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&options);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &name_param, &options_param);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}
	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&options, options_param);
	}


	zephir_read_property(&_0, this_ptr, SL("adapterFactory"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&adapter, &_0, "newinstance", NULL, 0, &name, &options);
	zephir_check_call_status();
	object_init_ex(return_value, phalcon_cache_cache_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 134, &adapter);
	zephir_check_call_status();
	RETURN_MM();

}

