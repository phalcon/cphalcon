
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
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/operators.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Shared HTML-attributes state for asset objects (`Asset`, `Inline`,
 * `Collection`).
 *
 * @todo set attributes to have a default array when introduced in zephir
 * @todo v7 - share setAttributes here too (blocked: Collection is not an AssetInterface, so the return type diverges)
 */
ZEPHIR_INIT_CLASS(Phalcon_Assets_Traits_AttributesTrait)
{
	ZEPHIR_REGISTER_TRAIT(Phalcon\\Assets\\Traits, AttributesTrait, phalcon, assets_traits_attributestrait, phalcon_assets_traits_attributestrait_method_entry);

	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_assets_traits_attributestrait_ce, SL("attributes"), ZEND_ACC_PROTECTED);
	return SUCCESS;
}

/**
 * Gets extra HTML attributes.
 *
 * @return array
 */
PHP_METHOD(Phalcon_Assets_Traits_AttributesTrait, getAttributes)
{
	zval _1;
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("attributes", 10, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_memory_observe(&_0);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 419, PH_NOISY_CC);
	zephir_get_arrval(&_1, &_0);
	RETURN_CTOR(&_1);
}

