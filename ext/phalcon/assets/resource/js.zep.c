
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


/**
 * Phalcon\Assets\Resource\Js
 *
 * Represents Javascript resources
 */
ZEPHIR_INIT_CLASS(Phalcon_Assets_Resource_Js) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Assets\\Resource, Js, phalcon, assets_resource_js, phalcon_assets_resource_ce, phalcon_assets_resource_js_method_entry, 0);

	return SUCCESS;

}

/**
 * Phalcon\Assets\Resource\Js
 *
 * @param string path
 * @param boolean local
 * @param boolean filter
 * @param array attributes
 */
PHP_METHOD(Phalcon_Assets_Resource_Js, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *path, path_sub, *local = NULL, local_sub, *filter = NULL, filter_sub, *attributes = NULL, attributes_sub, __$true, __$null, _1;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&path_sub);
	ZVAL_UNDEF(&local_sub);
	ZVAL_UNDEF(&filter_sub);
	ZVAL_UNDEF(&attributes_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &path, &local, &filter, &attributes);

	if (!local) {
		local = &local_sub;
		local = &__$true;
	}
	if (!filter) {
		filter = &filter_sub;
		filter = &__$true;
	}
	if (!attributes) {
		attributes = &attributes_sub;
		attributes = &__$null;
	}


	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "js");
	ZEPHIR_CALL_PARENT(NULL, phalcon_assets_resource_js_ce, this_ptr, "__construct", &_0, 108, &_1, path, local, filter, attributes);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

