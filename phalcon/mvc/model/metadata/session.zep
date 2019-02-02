
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
 * Phalcon\Mvc\Model\MetaData\Session
 *
 * Stores model meta-data in session. Data will erased when the session finishes.
 * Meta-data are permanent while the session is active.
 *
 * You can query the meta-data by printing $_SESSION['$PMM$']
 *
 *<code>
 * $metaData = new \Phalcon\Mvc\Model\Metadata\Session(
 *     [
 *        "prefix" => "my-app-id",
 *     ]
 * );
 *</code>
 */
class Session extends MetaData
{

	protected _prefix = "";

	/**
	 * Phalcon\Mvc\Model\MetaData\Session constructor
	 *
	 * @param array options
	 */
	public function __construct(options = null)
	{
		var prefix;

		if fetch prefix, options["prefix"] {
			let this->_prefix = prefix;
		}
	}

	/**
	 * Reads meta-data from $_SESSION
	 */
	public function read(string! key) -> array | null
	{
		var metaData, status;

		let status = session_status();
		if status !== PHP_SESSION_ACTIVE {
			// To use $_SESSION variable we need to start session first
			return null;
		}

		if fetch metaData, _SESSION["$PMM$" . this->_prefix][key] {
			return metaData;
		}

		return null;
	}

	/**
	 * Writes the meta-data to $_SESSION
	 */
	public function write(string! key, array data) -> void
	{
		var status;

		let status = session_status();
		if status !== PHP_SESSION_ACTIVE {
			// To use $_SESSION variable we need to start session first
			return;
		}

		let _SESSION["$PMM$" . this->_prefix][key] = data;
	}
}
