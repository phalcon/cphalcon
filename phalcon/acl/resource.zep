
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

use Phalcon\Acl\Exception;

/**
 * Phalcon\Acl\Resource
 *
 * This class defines resource entity and its description
 */
class $Resource
{

	/**
	 * Resource name
	 * @var string
	 */
	protected _name { get, __toString };

	/**
	 * Resource description
	 * @var string
	 */
	protected _description { get };

	/**
	 * Phalcon\Acl\Resource constructor
	 */
	public function __construct(string! name, string description = null)
	{
		if name == "*" {
			throw new Exception("Resource name cannot be '*'");
		}

		let this->_name = name;
		if description {
			let this->_description = description;
		}
	}
}
