
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
 * Loads Config Adapter class using 'adapter' option, if no extension is provided it will be added to filePath
 *
 *<code>
 * use Phalcon\Config\Factory;
 *
 * $options = [
 *     "filePath" => "path/config",
 *     "adapter"  => "php",
 * ];
 * $config = Factory::load($options);
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Config_Factory) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Config, Factory, phalcon, config_factory, phalcon_factory_ce, phalcon_config_factory_method_entry, 0);

	return SUCCESS;

}

/**
 * @param \Phalcon\Config|array config
 */
PHP_METHOD(Phalcon_Config_Factory, load) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *config, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &config);



	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "Phalcon\\Config\\Adapter", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_SELF("loadclass", NULL, 0, _0, config);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Phalcon_Config_Factory, loadClass) {

	zend_class_entry *_12$$6, *_8$$9, *_10$$11;
	zend_bool _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *namespace_param = NULL, *config = NULL, *adapter = NULL, *className = NULL, *mode = NULL, *callbacks = NULL, *filePath = NULL, *_1$$3 = NULL, *_2$$6, _3$$6, *_4$$6, *_11$$6 = NULL, *_5$$7 = NULL, *_6$$7, *_7$$9 = NULL, *_9$$11 = NULL;
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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_factory_exception_ce, "Config must be array or Phalcon\\Config object", "phalcon/config/factory.zep", 59);
		return;
	}
	ZEPHIR_OBS_VAR(filePath);
	if (!(zephir_array_isset_string_fetch(&filePath, config, SS("filePath"), 0 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_factory_exception_ce, "You must provide 'filePath' option in factory config parameter.", "phalcon/config/factory.zep", 63);
		return;
	}
	ZEPHIR_OBS_VAR(adapter);
	if (zephir_array_isset_string_fetch(&adapter, config, SS("adapter"), 0 TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(_2$$6);
		zephir_camelize(_2$$6, adapter, NULL  );
		ZEPHIR_INIT_VAR(className);
		ZEPHIR_CONCAT_VSV(className, namespace, "\\", _2$$6);
		ZEPHIR_SINIT_VAR(_3$$6);
		ZVAL_STRING(&_3$$6, ".", 0);
		ZEPHIR_INIT_VAR(_4$$6);
		zephir_fast_strpos(_4$$6, filePath, &_3$$6, 0 );
		if (!(zephir_is_true(_4$$6))) {
			ZEPHIR_CALL_FUNCTION(&_5$$7, "lcfirst", NULL, 69, adapter);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(_6$$7);
			ZEPHIR_CONCAT_VSV(_6$$7, filePath, ".", _5$$7);
			ZEPHIR_CPY_WRT(filePath, _6$$7);
		}
		if (ZEPHIR_IS_STRING(className, "Phalcon\\Config\\Adapter\\Ini")) {
			ZEPHIR_OBS_VAR(mode);
			if (zephir_array_isset_string_fetch(&mode, config, SS("mode"), 0 TSRMLS_CC)) {
				zephir_fetch_safe_class(_7$$9, className);
					_8$$9 = zend_fetch_class(Z_STRVAL_P(_7$$9), Z_STRLEN_P(_7$$9), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
				object_init_ex(return_value, _8$$9);
				if (zephir_has_constructor(return_value TSRMLS_CC)) {
					ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, filePath, mode);
					zephir_check_call_status();
				}
				RETURN_MM();
			}
		} else if (ZEPHIR_IS_STRING(className, "Phalcon\\Config\\Adapter\\Yaml")) {
			ZEPHIR_OBS_VAR(callbacks);
			if (zephir_array_isset_string_fetch(&callbacks, config, SS("callbacks"), 0 TSRMLS_CC)) {
				zephir_fetch_safe_class(_9$$11, className);
					_10$$11 = zend_fetch_class(Z_STRVAL_P(_9$$11), Z_STRLEN_P(_9$$11), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
				object_init_ex(return_value, _10$$11);
				if (zephir_has_constructor(return_value TSRMLS_CC)) {
					ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, filePath, callbacks);
					zephir_check_call_status();
				}
				RETURN_MM();
			}
		}
		zephir_fetch_safe_class(_11$$6, className);
			_12$$6 = zend_fetch_class(Z_STRVAL_P(_11$$6), Z_STRLEN_P(_11$$6), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
		object_init_ex(return_value, _12$$6);
		if (zephir_has_constructor(return_value TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, filePath);
			zephir_check_call_status();
		}
		RETURN_MM();
	}
	ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_factory_exception_ce, "You must provide 'adapter' option in factory config parameter.", "phalcon/config/factory.zep", 85);
	return;

}

