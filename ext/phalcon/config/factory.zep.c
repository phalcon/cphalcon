
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
#include "kernel/string.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/array.h"
#include "kernel/object.h"
#include "kernel/concat.h"


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

	zend_class_entry *_14$$8, *_10$$11, *_12$$13;
	zend_bool _2;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *namespace_param = NULL, *config = NULL, *adapter = NULL, *className = NULL, *mode = NULL, *callbacks = NULL, *filePath = NULL, *extension = NULL, *oldConfig = NULL, _0$$3 = zval_used_for_init, *_1$$3 = NULL, *_3$$5 = NULL, *_4$$8, _5$$8, *_6$$8, *_13$$8 = NULL, *_7$$9 = NULL, *_8$$9, *_9$$11 = NULL, *_11$$13 = NULL;
	zval *namespace = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &namespace_param, &config);

	zephir_get_strval(namespace, namespace_param);
	ZEPHIR_SEPARATE_PARAM(config);


	if (Z_TYPE_P(config) == IS_STRING) {
		ZEPHIR_CPY_WRT(oldConfig, config);
		ZEPHIR_SINIT_VAR(_0$$3);
		ZVAL_STRING(&_0$$3, ".", 0);
		ZEPHIR_CALL_FUNCTION(&_1$$3, "strrchr", NULL, 151, config, &_0$$3);
		zephir_check_call_status();
		ZEPHIR_SINIT_NVAR(_0$$3);
		ZVAL_LONG(&_0$$3, 1);
		ZEPHIR_INIT_VAR(extension);
		zephir_substr(extension, _1$$3, 1 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
		if (ZEPHIR_IS_EMPTY(extension)) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_factory_exception_ce, "You need to provide extension in file path", "phalcon/config/factory.zep", 59);
			return;
		}
		ZEPHIR_INIT_NVAR(config);
		zephir_create_array(config, 2, 0 TSRMLS_CC);
		zephir_array_update_string(&config, SL("adapter"), &extension, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&config, SL("filePath"), &oldConfig, PH_COPY | PH_SEPARATE);
	}
	_2 = Z_TYPE_P(config) == IS_OBJECT;
	if (_2) {
		_2 = zephir_instance_of_ev(config, phalcon_config_ce TSRMLS_CC);
	}
	if (_2) {
		ZEPHIR_CALL_METHOD(&_3$$5, config, "toarray", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(config, _3$$5);
	}
	if (Z_TYPE_P(config) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_factory_exception_ce, "Config must be array or Phalcon\\Config object", "phalcon/config/factory.zep", 73);
		return;
	}
	ZEPHIR_OBS_VAR(filePath);
	if (!(zephir_array_isset_string_fetch(&filePath, config, SS("filePath"), 0 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_factory_exception_ce, "You must provide 'filePath' option in factory config parameter.", "phalcon/config/factory.zep", 77);
		return;
	}
	ZEPHIR_OBS_VAR(adapter);
	if (zephir_array_isset_string_fetch(&adapter, config, SS("adapter"), 0 TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(_4$$8);
		zephir_camelize(_4$$8, adapter, NULL  );
		ZEPHIR_INIT_VAR(className);
		ZEPHIR_CONCAT_VSV(className, namespace, "\\", _4$$8);
		ZEPHIR_SINIT_VAR(_5$$8);
		ZVAL_STRING(&_5$$8, ".", 0);
		ZEPHIR_INIT_VAR(_6$$8);
		zephir_fast_strpos(_6$$8, filePath, &_5$$8, 0 );
		if (!(zephir_is_true(_6$$8))) {
			ZEPHIR_CALL_FUNCTION(&_7$$9, "lcfirst", NULL, 71, adapter);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(_8$$9);
			ZEPHIR_CONCAT_VSV(_8$$9, filePath, ".", _7$$9);
			ZEPHIR_CPY_WRT(filePath, _8$$9);
		}
		if (ZEPHIR_IS_STRING(className, "Phalcon\\Config\\Adapter\\Ini")) {
			ZEPHIR_OBS_VAR(mode);
			if (zephir_array_isset_string_fetch(&mode, config, SS("mode"), 0 TSRMLS_CC)) {
				zephir_fetch_safe_class(_9$$11, className);
					_10$$11 = zend_fetch_class(Z_STRVAL_P(_9$$11), Z_STRLEN_P(_9$$11), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
				object_init_ex(return_value, _10$$11);
				if (zephir_has_constructor(return_value TSRMLS_CC)) {
					ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, filePath, mode);
					zephir_check_call_status();
				}
				RETURN_MM();
			}
		} else if (ZEPHIR_IS_STRING(className, "Phalcon\\Config\\Adapter\\Yaml")) {
			ZEPHIR_OBS_VAR(callbacks);
			if (zephir_array_isset_string_fetch(&callbacks, config, SS("callbacks"), 0 TSRMLS_CC)) {
				zephir_fetch_safe_class(_11$$13, className);
					_12$$13 = zend_fetch_class(Z_STRVAL_P(_11$$13), Z_STRLEN_P(_11$$13), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
				object_init_ex(return_value, _12$$13);
				if (zephir_has_constructor(return_value TSRMLS_CC)) {
					ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, filePath, callbacks);
					zephir_check_call_status();
				}
				RETURN_MM();
			}
		}
		zephir_fetch_safe_class(_13$$8, className);
			_14$$8 = zend_fetch_class(Z_STRVAL_P(_13$$8), Z_STRLEN_P(_13$$8), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
		object_init_ex(return_value, _14$$8);
		if (zephir_has_constructor(return_value TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, filePath);
			zephir_check_call_status();
		}
		RETURN_MM();
	}
	ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_factory_exception_ce, "You must provide 'adapter' option in factory config parameter.", "phalcon/config/factory.zep", 99);
	return;

}

