
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
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/concat.h"
#include "kernel/fcall.h"
#include "kernel/string.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Represents an inline asset
 *
 *```php
 * $inline = new \Phalcon\Assets\Inline("js", "alert('hello world');");
 *```
 */
ZEPHIR_INIT_CLASS(Phalcon_Assets_Inline) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Assets, Inline, phalcon, assets_inline, phalcon_assets_inline_method_entry, 0);

	/**
	 * @var array | null
	 */
	zend_declare_property_null(phalcon_assets_inline_ce, SL("attributes"), ZEND_ACC_PROTECTED);

	/**
	 * @var string
	 */
	zend_declare_property_null(phalcon_assets_inline_ce, SL("content"), ZEND_ACC_PROTECTED);

	/**
	 * @var bool
	 */
	zend_declare_property_null(phalcon_assets_inline_ce, SL("filter"), ZEND_ACC_PROTECTED);

	/**
	 * @var string
	 */
	zend_declare_property_null(phalcon_assets_inline_ce, SL("type"), ZEND_ACC_PROTECTED);

	zend_class_implements(phalcon_assets_inline_ce, 1, phalcon_assets_assetinterface_ce);
	return SUCCESS;

}

/**
 */
PHP_METHOD(Phalcon_Assets_Inline, getAttributes) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "attributes");

}

/**
 */
PHP_METHOD(Phalcon_Assets_Inline, getContent) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "content");

}

/**
 */
PHP_METHOD(Phalcon_Assets_Inline, getFilter) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "filter");

}

/**
 */
PHP_METHOD(Phalcon_Assets_Inline, getType) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "type");

}

/**
 * Phalcon\Assets\Inline constructor
 */
PHP_METHOD(Phalcon_Assets_Inline, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval attributes;
	zend_bool filter;
	zval *type_param = NULL, *content_param = NULL, *filter_param = NULL, *attributes_param = NULL, __$true, __$false;
	zval type, content;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&content);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&attributes);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 2, &type_param, &content_param, &filter_param, &attributes_param);

	zephir_get_strval(&type, type_param);
	zephir_get_strval(&content, content_param);
	if (!filter_param) {
		filter = 1;
	} else {
		filter = zephir_get_boolval(filter_param);
	}
	if (!attributes_param) {
		ZEPHIR_INIT_VAR(&attributes);
		array_init(&attributes);
	} else {
		zephir_get_arrval(&attributes, attributes_param);
	}


	zephir_update_property_zval(this_ptr, ZEND_STRL("type"), &type);
	zephir_update_property_zval(this_ptr, ZEND_STRL("content"), &content);
	if (filter) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("filter"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("filter"), &__$false);
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("attributes"), &attributes);
	ZEPHIR_MM_RESTORE();

}

/**
 * Gets the asset's key.
 */
PHP_METHOD(Phalcon_Assets_Inline, getAssetKey) {

	zval key, _0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "gettype", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getcontent", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&key);
	ZEPHIR_CONCAT_VSV(&key, &_0, ":", &_1);
	zephir_md5(return_value, &key);
	RETURN_MM();

}

/**
 * Sets extra HTML attributes
 */
PHP_METHOD(Phalcon_Assets_Inline, setAttributes) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *attributes_param = NULL;
	zval attributes;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&attributes);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &attributes_param);

	zephir_get_arrval(&attributes, attributes_param);


	zephir_update_property_zval(this_ptr, ZEND_STRL("attributes"), &attributes);
	RETURN_THIS();

}

/**
 * Sets if the asset must be filtered or not
 */
PHP_METHOD(Phalcon_Assets_Inline, setFilter) {

	zval *filter_param = NULL, __$true, __$false;
	zend_bool filter;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);

	zephir_fetch_params_without_memory_grow(1, 0, &filter_param);

	filter = zephir_get_boolval(filter_param);


	if (filter) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("filter"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("filter"), &__$false);
	}
	RETURN_THISW();

}

/**
 * Sets the inline's type
 */
PHP_METHOD(Phalcon_Assets_Inline, setType) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *type_param = NULL;
	zval type;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&type);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &type_param);

	zephir_get_strval(&type, type_param);


	zephir_update_property_zval(this_ptr, ZEND_STRL("type"), &type);
	RETURN_THIS();

}

