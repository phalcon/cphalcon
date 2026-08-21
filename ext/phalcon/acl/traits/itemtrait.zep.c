
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
 * This class defines role/component names and their descriptions
 */
ZEPHIR_INIT_CLASS(Phalcon_Acl_Traits_ItemTrait)
{
	ZEPHIR_REGISTER_TRAIT(Phalcon\\Acl\\Traits, ItemTrait, phalcon, acl_traits_itemtrait, phalcon_acl_traits_itemtrait_method_entry);

	/**
	 * Role/Component description
	 */
	{
		zval _zc0;
		ZVAL_NULL(&_zc0);
		zephir_declare_typed_property(phalcon_acl_traits_itemtrait_ce, SL("description"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_STRING|MAY_BE_NULL, NULL, 0);
	}

	/**
	 * Role/Component name
	 */
	{
		zval _zc0;
		ZVAL_UNDEF(&_zc0);
		zephir_declare_typed_property(phalcon_acl_traits_itemtrait_ce, SL("name"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_STRING, NULL, 0);
	}

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

