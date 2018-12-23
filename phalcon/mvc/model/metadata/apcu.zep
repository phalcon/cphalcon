
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Mvc\Model\MetaData;

use Phalcon\Mvc\Model\MetaData;
use Phalcon\Mvc\Model\Exception;

/**
 * Phalcon\Mvc\Model\MetaData\Apcu
 *
 * Stores model meta-data in the APCu cache. Data will erased if the web server is restarted
 *
 * By default meta-data is stored for 48 hours (172800 seconds)
 *
 * You can query the meta-data by printing apcu_fetch('$PMM$') or apcu_fetch('$PMM$my-app-id')
 *
 *<code>
 * $metaData = new \Phalcon\Mvc\Model\Metadata\Apcu(
 *     [
 *         "prefix"   => "my-app-id",
 *         "lifetime" => 86400,
 *     ]
 * );
 *</code>
 */
class Apcu extends MetaData
{

	protected _prefix = "";

	protected _ttl = 172800;

	protected _metaData = [];

	/**
	 * Phalcon\Mvc\Model\MetaData\Apcu constructor
	 *
	 * @param array options
	 */
	public function __construct(options = null)
	{
		var prefix, ttl;

		if typeof options == "array" {
			if fetch prefix, options["prefix"] {
				let this->_prefix = prefix;
			}
			if fetch ttl, options["lifetime"] {
				let this->_ttl = ttl;
			}
		}
	}

	/**
	 * Reads meta-data from APCu
	 */
	public function read(string! key) -> array | null
	{
		var data;

		let data = apcu_fetch("$PMM$" . this->_prefix . key);
		if typeof data == "array" {
			return data;
		}
		return null;
	}

	/**
	 * Writes the meta-data to APCu
	 */
	public function write(string! key, array data) -> void
	{
		apcu_store("$PMM$" . this->_prefix . key, data, this->_ttl);
	}
}
