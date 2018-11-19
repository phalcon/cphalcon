
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
 * $config = new \Phalcon\Config\Adapter\Ini("path/config.ini");
 *
 * echo $config->phalcon->controllersDir;
 * echo $config->database->username;
 *</code>
 *
 * PHP constants may also be parsed in the ini file, so if you define a constant
 * as an ini value before calling the constructor, the constant's value will be
 * integrated into the results. To use it this way you must specify the optional
 * second parameter as INI_SCANNER_NORMAL when calling the constructor:
 *
 * <code>
 * $config = new \Phalcon\Config\Adapter\Ini(
 *     "path/config-with-constants.ini",
 *     INI_SCANNER_NORMAL
 * );
 * </code>
 */
class Ini extends Config
{

	/**
	 * Phalcon\Config\Adapter\Ini constructor
	 */
	public function __construct(string! filePath, mode = null)
	{
		var iniConfig;

		// Default to INI_SCANNER_RAW if not specified
		if null === mode {
			let mode = INI_SCANNER_RAW;
		}

		let iniConfig = parse_ini_file(filePath, true, mode);
		if iniConfig === false {
			throw new Exception("Configuration file " . basename(filePath) . " can't be loaded");
		}

		var config, section, sections, directives, path, lastValue;

		let config = [];

		for section, directives in iniConfig {
			if typeof directives == "array" {
				let sections = [];
				for path, lastValue in directives {
					let sections[] = this->_parseIniString((string)path, lastValue);
				}
				if count(sections) {
					let config[section] = call_user_func_array("array_replace_recursive", sections);
				}
			} else {
				let config[section] = this->_cast(directives);
			}
		}

		parent::__construct(config);
	}

	/**
	 * Build multidimensional array from string
	 *
	 * <code>
	 * $this->_parseIniString("path.hello.world", "value for last key");
	 *
	 * // result
	 * [
	 *      "path" => [
	 *          "hello" => [
	 *              "world" => "value for last key",
	 *          ],
	 *      ],
	 * ];
	 * </code>
	 */
	protected function _parseIniString(string! path, var value) -> array
	{
		var pos, key;
		let value = this->_cast(value);
		let pos = strpos(path, ".");

		if pos === false {
			return [path: value];
		}

		let key = substr(path, 0, pos);
		let path = substr(path, pos + 1);

		return [key: this->_parseIniString(path, value)];
	}
	/**
	 * We have to cast values manually because parse_ini_file() has a poor implementation.
	 *
	 * @param mixed ini The array casted by `parse_ini_file`
	 */
	protected function _cast(var ini) -> bool | null | double | int | string
	{
		var key, val;
		if typeof ini == "array" {
			for key, val in ini{
				let ini[key] = this->_cast(val);
			}
		}
		if typeof ini == "string" {
			// Decode true
			if ini === "true" || ini === "yes" || strtolower(ini) === "on"{
				return true;
			}

			// Decode false
			if ini === "false" || ini === "no" || strtolower(ini) === "off"{
				return false;
			}

			// Decode null
			if ini === "null" {
				return null;
			}

			// Decode float/int
			if is_numeric(ini) {
				if preg_match("/[.]+/", ini) {
					return (double) ini;
				} else {
					return (int) ini;
				}
			}
		}
		return ini;
	}
}
