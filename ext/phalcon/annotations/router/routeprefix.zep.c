
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


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Sets the prefix of every route of a controller. It is the attribute form of
 * `@RoutePrefix`.
 */
ZEPHIR_INIT_CLASS(Phalcon_Annotations_Router_RoutePrefix)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Annotations\\Router, RoutePrefix, phalcon, annotations_router_routeprefix, phalcon_annotations_router_routeprefix_method_entry, 0);

	{
		zend_attribute *_za = zephir_add_class_attribute(phalcon_annotations_router_routeprefix_ce, SL("Attribute"), 1);
		zval _zc0;
		ZVAL_LONG(&_zc0, 1);
		zephir_attribute_set_arg(_za, 0, NULL, 0, &_zc0);
	}

	/**
	 * @var string
	 */
	zend_declare_property_null(phalcon_annotations_router_routeprefix_ce, SL("prefix"), ZEND_ACC_PUBLIC);
	return SUCCESS;
}

PHP_METHOD(Phalcon_Annotations_Router_RoutePrefix, __construct)
{
	zval prefix_zv;
	zend_string *prefix = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&prefix_zv);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("prefix", 6, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(prefix)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&prefix_zv, prefix);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 419, &prefix_zv);
}

