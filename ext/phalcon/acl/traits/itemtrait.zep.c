
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
 * Shared name/description state for ACL Role and Component entities.
 */
ZEPHIR_INIT_CLASS(Phalcon_Acl_Traits_ItemTrait)
{
	ZEPHIR_REGISTER_TRAIT(Phalcon\\Acl\\Traits, ItemTrait, phalcon, acl_traits_itemtrait, phalcon_acl_traits_itemtrait_method_entry);

	/**
	 * Element description
	 *
	 * @var string | null
	 */
	zend_declare_property_null(phalcon_acl_traits_itemtrait_ce, SL("description"), ZEND_ACC_PROTECTED);
	/**
	 * Element name
	 *
	 * @var string
	 */
	zend_declare_property_null(phalcon_acl_traits_itemtrait_ce, SL("name"), ZEND_ACC_PROTECTED);
	return SUCCESS;
}

PHP_METHOD(Phalcon_Acl_Traits_ItemTrait, __toString)
{

	RETURN_MEMBER_TYPED(getThis(), "name", IS_STRING);
}

PHP_METHOD(Phalcon_Acl_Traits_ItemTrait, getDescription)
{

	RETURN_MEMBER(getThis(), "description");
}

PHP_METHOD(Phalcon_Acl_Traits_ItemTrait, getName)
{

	RETURN_MEMBER_TYPED(getThis(), "name", IS_STRING);
}

