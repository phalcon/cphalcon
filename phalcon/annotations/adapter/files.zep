
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

namespace Phalcon\Annotations\Adapter;

use Phalcon\Annotations\Adapter;
use Phalcon\Annotations\AdapterInterface;
use Phalcon\Annotations\Reflection;
use Phalcon\Annotations\Exception;

/**
 * Phalcon\Annotations\Adapter\Files
 *
 * Stores the parsed annotations in diles. This adapter is suitable for production
 *
 *<code>
 * $annotations = new \Phalcon\Annotations\Adapter\Files(array(
 *    'annotationsDir' => 'app/cache/annotations/'
 * ));
 *</code>
 */
class Files extends Adapter implements AdapterInterface
{
	protected _annotationsDir = "./";

	/**
	 * Phalcon\Annotations\Adapter\Files constructor
	 *
	 * @param array options
	 */
	public function __construct(options = null)
	{
		var annotationsDir;
		if typeof options == "array" {
			if fetch annotationsDir, options["annotationsDir"] {
				let this->_annotationsDir = annotationsDir;
			}
		}
	}

	/**
	 * Reads parsed annotations from files
	 *
	 * @param string key
	 * @return Phalcon\Annotations\Reflection
	 */
	public function read(string key) -> <Reflection> | boolean | int
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
