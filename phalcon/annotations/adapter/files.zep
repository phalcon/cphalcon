
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Annotations\Adapter;

use Phalcon\Annotations\Adapter;
use Phalcon\Annotations\Reflection;
use Phalcon\Annotations\Exception;

/**
 * Phalcon\Annotations\Adapter\Files
 *
 * Stores the parsed annotations in files. This adapter is suitable for production
 *
 *<code>
 * use Phalcon\Annotations\Adapter\Files;
 *
 * $annotations = new Files(
 *     [
 *         "annotationsDir" => "app/cache/annotations/",
 *     ]
 * );
 *</code>
 */
class Files extends Adapter
{
	protected _annotationsDir = "./";

	/**
	 * Phalcon\Annotations\Adapter\Files constructor
	 */
	public function __construct(array options = [])
	{
		var annotationsDir;

		if fetch annotationsDir, options["annotationsDir"] {
			let this->_annotationsDir = annotationsDir;
		}
	}

	/**
	 * Reads parsed annotations from files
	 */
	public function read(string key) -> <Reflection> | bool | int
	{
		var path;

		/**
		 * Paths must be normalized before be used as keys
		 */
		let path = this->_annotationsDir . prepare_virtual_path(key, "_") . ".php";

		if file_exists(path) {
			return require path;
		}

		return false;
	}

	/**
	 * Writes parsed annotations to files
	 */
	public function write(string! key, <Reflection> data)
	{
		var path;

		/**
		 * Paths must be normalized before be used as keys
		 */
		let path = this->_annotationsDir . prepare_virtual_path(key, "_") . ".php";

		if (file_put_contents(path, "<?php return " . var_export(data, true) . "; ") === false) {
	  		throw new Exception("Annotations directory cannot be written");
		}
	}
}
