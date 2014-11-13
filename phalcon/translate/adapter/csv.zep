
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file docs/LICENSE.txt.                        |
 |                                                                        |
 | If you did not receive a copy of the license and are unable to         |
 | obtain it through the world-wide-web, please send an email             |
 | to license@phalconphp.com so we can send you a copy immediately.       |
 +------------------------------------------------------------------------+
 | Author: Ivan Zubok <chi_no@ukr.net>                             |
 +------------------------------------------------------------------------+
 */

namespace Phalcon\Translate\Adapter;

use Phalcon\Translate\Exception;
use Phalcon\Translate\AdapterInterface;
use Phalcon\Translate\Adapter;

/**
 * Phalcon\Translate\Adapter\Csv
 *
 * Allows to define translation lists using CSV file
 */
class Csv extends Adapter implements AdapterInterface, \ArrayAccess
{

	protected _translate = [];

	/**
	 * Phalcon\Translate\Adapter\Csv constructor
	 *
	 * @param array options
	 */
	public function __construct(array! options)
	{
		if !isset options["content"] {
			throw new Exception("Parameter 'content' is required");
		}

		let options = array_merge([
			"delimiter": ";",
			"length": 0,
			"enclosure": "\""
		], options);

		var file;
		let file = fopen(options["content"], "rb");

		if typeof file !== "resource" {
			throw new Exception("Error opening translation file '" . options["content"] . "'");
		}

		var data;

		loop {
			let data = fgetcsv(file, options["length"], options["delimiter"], options["enclosure"]);
			if data === false {
				break;
			}

			if substr(data[0], 0, 1) === "#" || !isset data[1] {
				continue;
			}

			let this->_translate[data[0]] = data[1];
		}

		fclose(file);
	}

	/**
	 * Returns the translation related to the given key
	 *
	 * @param string  index
	 * @param array   placeholders
	 * @return string
	 */
	public function query(string! index, placeholders = null) -> string
	{
		var translation, key, value;

		if fetch translation, this->_translate[index] {
			if typeof placeholders === "array" {
				if count(placeholders) {
					for key, value in placeholders {
						let translation = str_replace("%" . key . "%", value, translation);
					}
				}
			}
			return translation;
		}
		return index;
	}

	/**
	 * Check whether is defined a translation key in the internal array
	 *
	 * @param    string index
	 * @return   bool
	 */
	public function exists(string! index) -> boolean
	{
		return isset this->_translate[index];
	}
}
