
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
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/memory.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Shared source/target path, uri and locality state for asset objects
 * (`Asset`, `Collection`).
 */
ZEPHIR_INIT_CLASS(Phalcon_Assets_Traits_SourceTargetTrait)
{
	ZEPHIR_REGISTER_TRAIT(Phalcon\\Assets\\Traits, SourceTargetTrait, phalcon, assets_traits_sourcetargettrait, phalcon_assets_traits_sourcetargettrait_method_entry);

	{
		zval _zc0;
		ZVAL_BOOL(&_zc0, 1);
		zephir_declare_typed_property(phalcon_assets_traits_sourcetargettrait_ce, SL("isLocal"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_BOOL, NULL, 0);
	}

	{
		zval _zc0;
		ZVAL_STRINGL(&_zc0, "", sizeof("") - 1);
		zephir_declare_typed_property(phalcon_assets_traits_sourcetargettrait_ce, SL("sourcePath"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_STRING, NULL, 0);
	}

	{
		zval _zc0;
		ZVAL_STRINGL(&_zc0, "", sizeof("") - 1);
		zephir_declare_typed_property(phalcon_assets_traits_sourcetargettrait_ce, SL("targetPath"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_STRING, NULL, 0);
	}

	{
		zval _zc0;
		ZVAL_STRINGL(&_zc0, "", sizeof("") - 1);
		zephir_declare_typed_property(phalcon_assets_traits_sourcetargettrait_ce, SL("targetUri"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_STRING, NULL, 0);
	}

	return SUCCESS;
}

PHP_METHOD(Phalcon_Assets_Traits_SourceTargetTrait, getSourcePath)
{

	RETURN_MEMBER_TYPED(getThis(), "sourcePath", IS_STRING);
}

PHP_METHOD(Phalcon_Assets_Traits_SourceTargetTrait, getTargetPath)
{

	RETURN_MEMBER_TYPED(getThis(), "targetPath", IS_STRING);
}

PHP_METHOD(Phalcon_Assets_Traits_SourceTargetTrait, getTargetUri)
{

	RETURN_MEMBER_TYPED(getThis(), "targetUri", IS_STRING);
}

/**
 * Checks if the asset is local or not
 */
PHP_METHOD(Phalcon_Assets_Traits_SourceTargetTrait, isLocal)
{

	RETURN_MEMBER(getThis(), "isLocal");
}

/**
 * Sets if the asset is local or external
 */
PHP_METHOD(Phalcon_Assets_Traits_SourceTargetTrait, setIsLocal)
{
	zval *flag_param = NULL, __$true, __$false;
	zend_bool flag;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("isLocal", 7, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(flag)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &flag_param);
	if (flag) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 421, &__$true);
	} else {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 421, &__$false);
	}
	RETURN_THISW();
}

/**
 * Sets the asset's source path
 */
PHP_METHOD(Phalcon_Assets_Traits_SourceTargetTrait, setSourcePath)
{
	zval sourcePath_zv;
	zend_string *sourcePath = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sourcePath_zv);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("sourcePath", 10, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(sourcePath)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&sourcePath_zv, sourcePath);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 422, &sourcePath_zv);
	RETURN_THISW();
}

/**
 * Sets the asset's target path
 */
PHP_METHOD(Phalcon_Assets_Traits_SourceTargetTrait, setTargetPath)
{
	zval targetPath_zv;
	zend_string *targetPath = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&targetPath_zv);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("targetPath", 10, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(targetPath)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&targetPath_zv, targetPath);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 423, &targetPath_zv);
	RETURN_THISW();
}

/**
 * Sets a target uri for the generated HTML
 */
PHP_METHOD(Phalcon_Assets_Traits_SourceTargetTrait, setTargetUri)
{
	zval targetUri_zv;
	zend_string *targetUri = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&targetUri_zv);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("targetUri", 9, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(targetUri)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&targetUri_zv, targetUri);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 424, &targetUri_zv);
	RETURN_THISW();
}

