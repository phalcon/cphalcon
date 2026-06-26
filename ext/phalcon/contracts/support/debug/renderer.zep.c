
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Canonical contract for Phalcon\Support\Debug renderers. Turns an
 * ExceptionReport into output.
 */
ZEPHIR_INIT_CLASS(Phalcon_Contracts_Support_Debug_Renderer)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Contracts\\Support\\Debug, Renderer, phalcon, contracts_support_debug_renderer, phalcon_contracts_support_debug_renderer_method_entry);

	zend_class_implements(phalcon_contracts_support_debug_renderer_ce, 1, phalcon_contracts_support_debug_templateaware_ce);
	return SUCCESS;
}

/**
 * Returns the CSS sources block for the given base URI.
 *
 * @param string $uri
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Support_Debug_Renderer, getCssSources);
/**
 * Returns the JavaScript sources block for the given base URI.
 *
 * @param string $uri
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Support_Debug_Renderer, getJsSources);
/**
 * Returns the framework version block.
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Support_Debug_Renderer, getVersion);
/**
 * Renders the report.
 *
 * @param ExceptionReport $report
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Support_Debug_Renderer, render);
