
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
 * Phalcon\Assets\Inline
 *
 * Represents an inline asset
 *
 *<code>
 * $inline = new \Phalcon\Assets\Inline("js", "alert('hello world');");
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Assets_Inline) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Assets, Inline, phalcon, assets_inline, phalcon_assets_inline_method_entry, 0);

	/**
	 * @var string
	 */
	zend_declare_property_null(phalcon_assets_inline_ce, SL("_type"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_assets_inline_ce, SL("_content"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var bool
	 */
	zend_declare_property_null(phalcon_assets_inline_ce, SL("_filter"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_assets_inline_ce, SL("_attributes"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_assets_inline_ce TSRMLS_CC, 1, phalcon_assets_resourceinterface_ce);
	return SUCCESS;

}

/**
 */
PHP_METHOD(Phalcon_Assets_Inline, getType) {

	

	RETURN_MEMBER(getThis(), "_type");

}

PHP_METHOD(Phalcon_Assets_Inline, getContent) {

	

	RETURN_MEMBER(getThis(), "_content");

}

/**
 */
PHP_METHOD(Phalcon_Assets_Inline, getFilter) {

	

	RETURN_MEMBER(getThis(), "_filter");

}

/**
 * Phalcon\Assets\Inline constructor
 *
 * @param string type
 * @param string content
 * @param boolean filter
 * @param array attributes
 */
PHP_METHOD(Phalcon_Assets_Inline, __construct) {

	zend_bool filter;
	zval *type_param = NULL, *content_param = NULL, *filter_param = NULL, *attributes = NULL;
	zval *type = NULL, *content = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 2, &type_param, &content_param, &filter_param, &attributes);

	zephir_get_strval(type, type_param);
	zephir_get_strval(content, content_param);
	if (!filter_param) {
		filter = 1;
	} else {
		filter = zephir_get_boolval(filter_param);
	}
	if (!attributes) {
		attributes = ZEPHIR_GLOBAL(global_null);
	}


	zephir_update_property_this(getThis(), SL("_type"), type TSRMLS_CC);
	zephir_update_property_this(getThis(), SL("_content"), content TSRMLS_CC);
	if (filter) {
		zephir_update_property_this(getThis(), SL("_filter"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	} else {
		zephir_update_property_this(getThis(), SL("_filter"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	}
	if (Z_TYPE_P(attributes) == IS_ARRAY) {
		zephir_update_property_this(getThis(), SL("_attributes"), attributes TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets the inline's type
 */
PHP_METHOD(Phalcon_Assets_Inline, setType) {

	zval *type_param = NULL;
	zval *type = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &type_param);

	zephir_get_strval(type, type_param);


	zephir_update_property_this(getThis(), SL("_type"), type TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Sets if the resource must be filtered or not
 */
PHP_METHOD(Phalcon_Assets_Inline, setFilter) {

	zval *filter_param = NULL;
	zend_bool filter;

	zephir_fetch_params(0, 1, 0, &filter_param);

	filter = zephir_get_boolval(filter_param);


	if (filter) {
		zephir_update_property_this(getThis(), SL("_filter"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	} else {
		zephir_update_property_this(getThis(), SL("_filter"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	}
	RETURN_THISW();

}

/**
 * Sets extra HTML attributes
 */
PHP_METHOD(Phalcon_Assets_Inline, setAttributes) {

	zval *attributes_param = NULL;
	zval *attributes = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &attributes_param);

	zephir_get_arrval(attributes, attributes_param);


	zephir_update_property_this(getThis(), SL("_attributes"), attributes TSRMLS_CC);
	RETURN_THIS();

}

/**
 * returns extra HTML attributes
 */
PHP_METHOD(Phalcon_Assets_Inline, getAttributes) {

	

	RETURN_MEMBER(getThis(), "_attributes");

}

/**
 * Gets the resource's key.
 */
PHP_METHOD(Phalcon_Assets_Inline, getResourceKey) {

	zval *key = NULL, *_0 = NULL, *_1 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "gettype", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getcontent", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(key);
	ZEPHIR_CONCAT_VSV(key, _0, ":", _1);
	zephir_md5(return_value, key);
	RETURN_MM();

}

