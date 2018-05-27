
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
#include "kernel/object.h"
#include "kernel/exception.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/string.h"
#include "kernel/operators.h"


/**
 * Loads Backend Cache Adapter class using 'adapter' option, if frontend will be provided as array it will call Frontend Cache Factory
 *
 *<code>
 * use Phalcon\Cache\Backend\Factory;
 * use Phalcon\Cache\Frontend\Data;
 *
 * $options = [
 *     "prefix"   => "app-data",
 *     "frontend" => new Data(),
 *     "adapter"  => "apc",
 * ];
 * $backendCache = Factory::load($options);
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Cache_Backend_Factory) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Cache\\Backend, Factory, phalcon, cache_backend_factory, phalcon_factory_ce, phalcon_cache_backend_factory_method_entry, 0);

	return SUCCESS;

}

/**
 * @param \Phalcon\Config|array config
 */
PHP_METHOD(Phalcon_Cache_Backend_Factory, load) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *config, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &config);



	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "Phalcon\\Cache\\Backend", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_SELF("loadclass", NULL, 0, _0, config);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Phalcon_Cache_Backend_Factory, loadClass) {

	zend_class_entry *_7$$6;
	zend_bool _0, _2$$6;
	zephir_fcall_cache_entry *_4 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *namespace_param = NULL, *config = NULL, *adapter = NULL, *className = NULL, *frontend = NULL, *_1$$3 = NULL, *_5$$6, *_6$$6 = NULL, *_3$$7 = NULL;
	zval *namespace = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &namespace_param, &config);

	zephir_get_strval(namespace, namespace_param);
	ZEPHIR_SEPARATE_PARAM(config);


	_0 = Z_TYPE_P(config) == IS_OBJECT;
	if (_0) {
		_0 = zephir_instance_of_ev(config, phalcon_config_ce TSRMLS_CC);
	}
	if (_0) {
		ZEPHIR_CALL_METHOD(&_1$$3, config, "toarray", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(config, _1$$3);
	}
	if (Z_TYPE_P(config) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_factory_exception_ce, "Config must be array or Phalcon\\Config object", "phalcon/cache/backend/factory.zep", 62);
		return;
	}
	ZEPHIR_OBS_VAR(frontend);
	if (!(zephir_array_isset_string_fetch(&frontend, config, SS("frontend"), 0 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_factory_exception_ce, "You must provide 'frontend' option in factory config parameter.", "phalcon/cache/backend/factory.zep", 66);
		return;
	}
	ZEPHIR_OBS_VAR(adapter);
	if (zephir_array_isset_string_fetch(&adapter, config, SS("adapter"), 0 TSRMLS_CC)) {
		zephir_array_unset_string(&config, SS("adapter"), PH_SEPARATE);
		zephir_array_unset_string(&config, SS("frontend"), PH_SEPARATE);
		_2$$6 = Z_TYPE_P(frontend) == IS_ARRAY;
		if (!(_2$$6)) {
			_2$$6 = zephir_instance_of_ev(frontend, phalcon_config_ce TSRMLS_CC);
		}
		if (_2$$6) {
			ZEPHIR_CALL_CE_STATIC(&_3$$7, phalcon_cache_frontend_factory_ce, "load", &_4, 123, frontend);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(frontend, _3$$7);
		}
		ZEPHIR_INIT_VAR(_5$$6);
		zephir_camelize(_5$$6, adapter, NULL  );
		ZEPHIR_INIT_VAR(className);
		ZEPHIR_CONCAT_VSV(className, namespace, "\\", _5$$6);
		zephir_fetch_safe_class(_6$$6, className);
			_7$$6 = zend_fetch_class(Z_STRVAL_P(_6$$6), Z_STRLEN_P(_6$$6), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
		object_init_ex(return_value, _7$$6);
		if (zephir_has_constructor(return_value TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, frontend, config);
			zephir_check_call_status();
		}
		RETURN_MM();
	}
	ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_factory_exception_ce, "You must provide 'adapter' option in factory config parameter.", "phalcon/cache/backend/factory.zep", 80);
	return;

}

