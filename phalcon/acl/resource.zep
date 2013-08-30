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
 * Phalcon\Acl\Resource
 *
 * This class defines resource entity and its description
 *
 */
class Resource
{

  /**
  * Resource's name
  * @var string
  */
  protected _name;

  /**
  * Resource's description
  * @var string
  */
  protected _description;

  /**
  * Phalcon\Acl\Resource constructor
  *
  * @param string $name
  * @param string $description
  */
  public function __construct(name, description)
  {
	if name == "*" {
	  throw new Phalcon\Acl\Exception("Resource name cannot be '*'");
	}

	let this->_name = name;
	if description != null {
	  let this->_description = description;
	}
  }

  /**
   * Returns the resource name
   *
   * @return string
   */
  public function getName()
  {
	return this->_name;
  }

  /**
   * Returns resource description
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

