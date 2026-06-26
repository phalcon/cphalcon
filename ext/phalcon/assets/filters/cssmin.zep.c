
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
 * Filter intended to minify CSS content (remove comments, newlines, and line
 * feeds, and drop the last semicolon of the last property).
 *
 * > NOTE: This functionality is not currently available; `filter()` returns
 * > the content unchanged.
 * {: .alert .alert-info }
 *
 * @deprecated Use Phalcon\Assets\Filters\None, or a custom
 *             Phalcon\Assets\FilterInterface wrapping a real CSS minifier.
 */
ZEPHIR_INIT_CLASS(Phalcon_Assets_Filters_Cssmin)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Assets\\Filters, Cssmin, phalcon, assets_filters_cssmin, phalcon_assets_filters_cssmin_method_entry, 0);

	zend_class_implements(phalcon_assets_filters_cssmin_ce, 1, phalcon_assets_filterinterface_ce);
	return SUCCESS;
}

/**
 * Filters the content using CSSMIN
 */
PHP_METHOD(Phalcon_Assets_Filters_Cssmin, filter)
{
	zval content_zv;
	zend_string *content = NULL;

	ZVAL_UNDEF(&content_zv);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(content)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&content_zv, content);
	RETURN_STR(zend_string_copy(content));
}

