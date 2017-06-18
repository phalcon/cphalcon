
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
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/exception.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/string.h"
#include "kernel/operators.h"


/**
 * Loads Logger Adapter class using 'adapter' option
 *
 *<code>
 * use Phalcon\Logger\Factory;
 *
 * $options = [
 *     "name"    => "log.txt",
 *     "adapter" => "file",
 * ];
 * $logger = Factory::load($options);
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Logger_Factory) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Logger, Factory, phalcon, logger_factory, phalcon_factory_ce, phalcon_logger_factory_method_entry, 0);

	return SUCCESS;

}

/**
 * @param \Phalcon\Config|array config
 */
PHP_METHOD(Phalcon_Logger_Factory, load) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *config, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &config);



	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "Phalcon\\Logger\\Adapter", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_SELF("loadclass", NULL, 0, _0, config);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Phalcon_Logger_Factory, loadClass) {

	zend_class_entry *_6$$5, *_4$$6;
	zend_bool _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *namespace_param = NULL, *config = NULL, *adapter = NULL, *className = NULL, *name = NULL, *_1$$3 = NULL, *_2$$5, *_5$$5 = NULL, *_3$$6 = NULL;
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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_factory_exception_ce, "Config must be array or Phalcon\\Config object", "phalcon/logger/factory.zep", 59);
		return;
	}
	ZEPHIR_OBS_VAR(adapter);
	if (zephir_array_isset_string_fetch(&adapter, config, SS("adapter"), 0 TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(_2$$5);
		zephir_camelize(_2$$5, adapter, NULL  );
		ZEPHIR_INIT_VAR(className);
		ZEPHIR_CONCAT_VSV(className, namespace, "\\", _2$$5);
		if (!ZEPHIR_IS_STRING(className, "Phalcon\\Logger\\Adapter\\Firephp")) {
			zephir_array_unset_string(&config, SS("adapter"), PH_SEPARATE);
			ZEPHIR_OBS_VAR(name);
			if (!(zephir_array_isset_string_fetch(&name, config, SS("name"), 0 TSRMLS_CC))) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_factory_exception_ce, "You must provide 'name' option in factory config parameter.", "phalcon/logger/factory.zep", 68);
				return;
			}
			zephir_array_unset_string(&config, SS("name"), PH_SEPARATE);
			zephir_fetch_safe_class(_3$$6, className);
				_4$$6 = zend_fetch_class(Z_STRVAL_P(_3$$6), Z_STRLEN_P(_3$$6), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
			object_init_ex(return_value, _4$$6);
			if (zephir_has_constructor(return_value TSRMLS_CC)) {
				ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, name, config);
				zephir_check_call_status();
			}
			RETURN_MM();
		}
		zephir_fetch_safe_class(_5$$5, className);
			_6$$5 = zend_fetch_class(Z_STRVAL_P(_5$$5), Z_STRLEN_P(_5$$5), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
		object_init_ex(return_value, _6$$5);
		if (zephir_has_constructor(return_value TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0);
			zephir_check_call_status();
		}
		RETURN_MM();
	}
	ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_factory_exception_ce, "You must provide 'adapter' option in factory config parameter.", "phalcon/logger/factory.zep", 78);
	return;

}

