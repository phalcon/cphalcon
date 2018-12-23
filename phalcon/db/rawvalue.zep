
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
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
