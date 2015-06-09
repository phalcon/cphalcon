
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
	 */
	public function __construct(array! options)
	{
		var data, file;

		if !isset options["content"] {
			throw new Exception("Parameter 'content' is required");
		}

		let options = array_merge([
			"delimiter": ";",
			"length": 0,
			"enclosure": "\""
		], options);

		let file = fopen(options["content"], "rb");

		if typeof file !== "resource" {
			throw new Exception("Error opening translation file '" . options["content"] . "'");
		}

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
