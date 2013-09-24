
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

namespace Phalcon\Db;

/**
 * Phalcon\Db\RawValue
 *
 * This class allows to insert/update raw data without quoting or formating.
 *
 *The next example shows how to use the MySQL now() function as a field value.
 *
 *<code>
 *	$subscriber = new Subscribers();
 *	$subscriber->email = 'andres@phalconphp.com';
 *	$subscriber->created_at = new Phalcon\Db\RawValue('now()');
 *	$subscriber->save();
 *</code>
 */
class RawValue
{

	protected _value;

	/**
	 * Phalcon\Db\RawValue constructor
	 *
	 * @param string value
	 */
	public function __construct(value)
	{
		let this->_value = value;
	}

	/**
	 * Returns internal raw value without quoting or formating
	 *
	 * @return string
	 */
	public function getValue()
	{
		return this->_value;
	}

	/**
	 * Magic method __toString returns raw value without quoting or formating
	 */
	public function __toString()
	{
		return this->_value;
	}

}
