
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
 | Author: Ivan Zubok <chi_no@ukr.net>                                    |
 +------------------------------------------------------------------------+
 */

namespace Phalcon\Translate\Adapter;

use Phalcon\Translate\Exception;
use Phalcon\Translate\Adapter;

/**
 * Phalcon\Translate\Adapter\Csv
 *
 * Allows to define translation lists using CSV file
 */
class Csv extends Adapter implements \ArrayAccess
{

	protected _translate = [];

	/**
	 * Phalcon\Translate\Adapter\Csv constructor
	 */
	public function __construct(array! options)
	{
		parent::__construct(options);

		if !isset options["content"] {
			throw new Exception("Parameter 'content' is required");
		}

		this->_load(options["content"], 0, ";", "\"");
	}

	/**
	* Load translates from file
	*
	* @param string file
	* @param int length
	* @param string delimiter
	* @param string enclosure
	*/
	private function _load(file, length, delimiter, enclosure) -> void
	{
		var data, fileHandler;

		let fileHandler = fopen(file, "rb");

		if typeof fileHandler !== "resource" {
			throw new Exception("Error opening translation file '" . file . "'");
		}

		loop {

			let data = fgetcsv(fileHandler, length, delimiter, enclosure);
			if data === false {
				break;
			}

			if substr(data[0], 0, 1) === "#" || !isset data[1] {
				continue;
			}

			let this->_translate[data[0]] = data[1];
		}

		fclose(fileHandler);
	}

	/**
	 * Returns the translation related to the given key
	 */
	public function query(string! index, placeholders = null) -> string
	{
		var translation;

		if !fetch translation, this->_translate[index] {
			let translation = index;
		}

		return this->replacePlaceholders(translation, placeholders);
	}

	/**
	 * Check whether is defined a translation key in the internal array
	 */
	public function exists(string! index) -> boolean
	{
		return isset this->_translate[index];
	}
}
