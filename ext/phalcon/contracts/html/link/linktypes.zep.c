
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
 * Central registry of the array shapes used across the Html\Link namespace.
 *
 * PSR-13 states that a link attribute value is "a PHP primitive or an array of
 * PHP strings", so `link_attributes` keeps the array member that the plain
 * Html attribute shape drops.
 *
 * @phpstan-type link_attribute_value array<array-key, string>|string|bool|int|float|null
 * @phpstan-type link_attributes array<string, link_attribute_value>
 * @phpstan-type link_rels list<string>
 * @phpstan-type link_collection array<array-key, LinkInterface>
 * @phpstan-type link_list list<LinkInterface>
 */
ZEPHIR_INIT_CLASS(Phalcon_Contracts_Html_Link_LinkTypes)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Contracts\\Html\\Link, LinkTypes, phalcon, contracts_html_link_linktypes, NULL);

	return SUCCESS;
}

