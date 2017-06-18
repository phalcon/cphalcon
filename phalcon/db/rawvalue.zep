
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2017 Phalcon Team (https://phalconphp.com)          |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file LICENSE.txt.                             |
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
 * This class allows to insert/update raw data without quoting or formatting.
 *
 * The next example shows how to use the MySQL now() function as a field value.
 *
 *<code>
 * $subscriber = new Subscribers();
 *
 * $subscriber->email     = "andres@phalconphp.com";
 * $subscriber->createdAt = new \Phalcon\Db\RawValue("now()");
 *
 * $subscriber->save();
 *</code>
 */
class RawValue
{

	/**
	 * Raw value without quoting or formatting
	 *
	 * @var string
	 */
	protected _value { get, __toString };

	/**
	 * Phalcon\Db\RawValue constructor
	 */
	public function __construct(var value)
	{
		if typeof value == "string" && value == "" {
			let this->_value = "''";
			return;
		}

		if value === null {
			let this->_value = "NULL";
			return;
		}

		let this->_value = (string) value;
	}
}
