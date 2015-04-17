
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2015 Phalcon Team (http://www.phalconphp.com)       |
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
 * Phalcon\Acl\RoleInterface
 *
 * Interface for Phalcon\Acl\Role
 */
interface RoleInterface
{

	/**
	 * Phalcon\Acl\Role constructor
	 */
	public function __construct(string! name, string description = null);

	/**
	 * Returns the role name
	 */
	public function getName() -> string;

	/**
	 * Returns role description
	 */
	public function getDescription() -> string;

	/**
	 * Magic method __toString
	 */
	public function __toString() -> string;

}
