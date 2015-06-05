
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
 |          Ivan Zubok <chi_no@ukr.net>                                   |
 +------------------------------------------------------------------------+
 */

namespace Phalcon\Config\Adapter;

use Phalcon\Config;
use Phalcon\Config\Exception;

/**
 * Phalcon\Config\Adapter\Ini
 *
 * Reads ini files and converts them to Phalcon\Config objects.
 *
 * Given the next configuration file:
 *
 *<code>
 * [database]
 * adapter = Mysql
 * host = localhost
 * username = scott
 * password = cheetah
 * dbname = test_db
 *
 * [phalcon]
 * controllersDir = "../app/controllers/"
 * modelsDir = "../app/models/"
 * viewsDir = "../app/views/"
 * </code>
 *
 * You can read it as follows:
 *
 *<code>
 * $config = new Phalcon\Config\Adapter\Ini("path/config.ini");
 * echo $config->phalcon->controllersDir;
 * echo $config->database->username;
 *</code>
 */
class Ini extends Config
{

	/**
	 * Phalcon\Config\Adapter\Ini constructor
	 */
	public function __construct(string! filePath)
	{
		var iniConfig;

		let iniConfig = parse_ini_file(filePath, true);
		if iniConfig === false {
			throw new Exception("Configuration file " . basename(filePath) . " can't be loaded");
		}

		var config, section, sections, directives, path, lastValue;

		let config = [];

		for section, directives in iniConfig {
			let sections = [];
			for path, lastValue in directives {
				let sections[] = this->_parseIniString(path, lastValue);
			}
			if count(sections) {
				let config[section] = call_user_func_array("array_merge_recursive", sections);
			}
		}

		parent::__construct(config);
	}

	/**
	 * Build multidimensional array from string
	 *
	 * <code>
	 * $this->_parseIniString('path.hello.world', 'value for last key');
	 *
	 * // result
	 * [
	 *      'path' => [
	 *          'hello' => [
	 *              'world' => 'value for last key',
	 *          ],
	 *      ],
	 * ];
	 * </code>	 
	 */
	protected function _parseIniString(string! path, var value) -> array
	{
		var pos, key;
		let pos = strpos(path, ".");

		if pos === false {
			return [path: value];
		}

		let key = substr(path, 0, pos);
		let path = substr(path, pos + 1);

		return [key: this->_parseIniString(path, value)];
	}
}
