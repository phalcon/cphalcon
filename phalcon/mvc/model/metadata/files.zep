
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

namespace Phalcon\Mvc\Model\MetaData;

use Phalcon\Mvc\Model\MetaData;
use Phalcon\Mvc\Model\Exception;

/**
 * Phalcon\Mvc\Model\MetaData\Files
 *
 * Stores model meta-data in PHP files.
 *
 *<code>
 * $metaData = new \Phalcon\Mvc\Model\MetaData\Files(
 *     [
 *         "metaDataDir" => "app/cache/metadata/",
 *     ]
 * );
 *</code>
 */
class Files extends MetaData
{

	protected _metaDataDir = "./";

	protected _metaData = [];

	/**
	 * Phalcon\Mvc\Model\MetaData\Files constructor
	 *
	 * @param array options
	 */
	public function __construct(options = null)
	{
		var metaDataDir;
		if typeof options == "array" {
			if fetch metaDataDir, options["metaDataDir"] {
				let this->_metaDataDir = metaDataDir;
			}
		}
	}

	/**
	 * Reads meta-data from files
	 *
	 * @param string key
	 * @return mixed
	 */
	public function read(string! key)
	{
		var path;
		let path = this->_metaDataDir . prepare_virtual_path(key, "_") . ".php";
		if file_exists(path) {
			return require path;
		}
		return null;
	}

	/**
	 * Writes the meta-data to files
	 *
	 * @param string key
	 * @param array data
	 */
	public function write(string! key, var data) -> void
	{
		var path;

		let path = this->_metaDataDir . prepare_virtual_path(key, "_") . ".php";
		if file_put_contents(path, "<?php return " . var_export(data, true) . "; ") === false {
			throw new Exception("Meta-Data directory cannot be written");
		}
	}
}
