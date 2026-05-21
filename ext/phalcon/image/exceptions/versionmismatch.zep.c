
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
#include "kernel/concat.h"
#include "kernel/memory.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(Phalcon_Image_Exceptions_VersionMismatch)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Image\\Exceptions, VersionMismatch, phalcon, image_exceptions_versionmismatch, phalcon_image_exception_ce, phalcon_image_exceptions_versionmismatch_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Phalcon_Image_Exceptions_VersionMismatch, __construct)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval version_zv;
	zend_string *version = NULL;

	ZVAL_UNDEF(&version_zv);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(version)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&version_zv);
	ZVAL_STR_COPY(&version_zv, version);
	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_CONCAT_SV(&_0, "Phalcon\\Image\\Adapter\\GD requires GD version '2.0.1' or greater, you have ", &version_zv);
	ZEPHIR_CALL_PARENT(NULL, phalcon_image_exceptions_versionmismatch_ce, getThis(), "__construct", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

