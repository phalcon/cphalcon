
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
	zval *path, *local = NULL, *filter = NULL, *attributes = NULL, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &path, &local, &filter, &attributes);

	if (!local) {
		local = ZEPHIR_GLOBAL(global_true);
	}
	if (!filter) {
		filter = ZEPHIR_GLOBAL(global_true);
	}
	if (!attributes) {
		attributes = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "js", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_PARENT(NULL, phalcon_assets_resource_js_ce, this_ptr, "__construct", &_0, 31, _1, path, local, filter, attributes);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

