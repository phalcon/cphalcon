
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
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"


/**
 * Phalcon\Assets\Resource\Css
 *
 * Represents CSS resources
 */
ZEPHIR_INIT_CLASS(Phalcon_Assets_Resource_Css) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Assets\\Resource, Css, phalcon, assets_resource_css, phalcon_assets_resource_ce, phalcon_assets_resource_css_method_entry, 0);

	return SUCCESS;

}

/**
 * Phalcon\Assets\Resource\Css
 *
 * @param string path
 * @param boolean local
 * @param boolean filter
 * @param array attributes
 */
PHP_METHOD(Phalcon_Assets_Resource_Css, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zend_bool local, filter;
	zval *path_param = NULL, *local_param = NULL, *filter_param = NULL, *attributes = NULL, *_1;
	zval *path = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &path_param, &local_param, &filter_param, &attributes);

	if (unlikely(Z_TYPE_P(path_param) != IS_STRING && Z_TYPE_P(path_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'path' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(path_param) == IS_STRING)) {
		zephir_get_strval(path, path_param);
	} else {
		ZEPHIR_INIT_VAR(path);
		ZVAL_EMPTY_STRING(path);
	}
	if (!local_param) {
		local = 1;
	} else {
		local = zephir_get_boolval(local_param);
	}
	if (!filter_param) {
		filter = 1;
	} else {
		filter = zephir_get_boolval(filter_param);
	}
	if (!attributes) {
		attributes = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "css", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_PARENT(NULL, phalcon_assets_resource_css_ce, this_ptr, "__construct", &_0, 31, _1, path, (local ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false)), (filter ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false)), attributes);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

