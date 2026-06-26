
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
 * Canonical contract for components that render through named, overridable
 * template strings.
 */
ZEPHIR_INIT_CLASS(Phalcon_Contracts_Support_Debug_TemplateAware)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Contracts\\Support\\Debug, TemplateAware, phalcon, contracts_support_debug_templateaware, phalcon_contracts_support_debug_templateaware_method_entry);

	return SUCCESS;
}

/**
 * Returns the template for the given name (override if set, default
 * otherwise).
 *
 * @param string $name
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Support_Debug_TemplateAware, getTemplate);
/**
 * Overrides the template for the given name.
 *
 * @param string $name
 * @param string $template
 *
 * @return static
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Support_Debug_TemplateAware, setTemplate);
