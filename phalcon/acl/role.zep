
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2013 Phalcon Team (http://www.phalconphp.com)       |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file docs/LICENSE.txt.                        |
 |                                                                        |
 | If you did not receive a copy of the license and are unable to         |
 | obtain it through the world-wide-web, please send an email             |
 | to license@phalconphp.com so we can send you a copy immediately.       |
 +------------------------------------------------------------------------+
 | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
 |          Eduar Carvajal <eduar@phalconphp.com>                         |
 +------------------------------------------------------------------------+
 */

namespace Phalcon\Acl;

/**
 * Phalcon\Acl\Role
 *
 * This class defines role entity and its description
 */
class Role
{
	/**
	 * Role name
	 * @var string
	 */
	protected _name;

	/**
	 * Role description
	 * @var string
	 */
	protected _description;

	/**
	 * Phalcon\Acl\Role constructor
	 *
	 * @param string name
	 * @param string description
	 */
	public function __construct(name, description=null)
	{
		if name == "*" {
			throw new Phalcon\Acl\Exception("Role name cannot be '*'");
		}
		let this->_name = name;

		if description {
			let this->_description = description;
		}
	}

	/**
	 * Returns the role name
	 *
	 * @return string
	 */
	public function getName()
	{
		return this->_name;
	}

	/**
	 * Returns role description
	 *
	 * @return string
	 */
	public function getDescription()
	{
		return this->_description;
	}

	/**
	 * Magic method __toString
	 *
	 * @return string
	 */
	public function __toString()
	{
		return this->_name;
	}

}
