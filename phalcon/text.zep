
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
 | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
 |          Eduar Carvajal <eduar@phalconphp.com>                         |
 +------------------------------------------------------------------------+
 */

namespace Phalcon;

/**
 * Phalcon\Text
 *
 * Provides utilities to work with texts
 */
abstract class Text
{

	const RANDOM_ALNUM = 0;

	const RANDOM_ALPHA = 1;

	const RANDOM_HEXDEC = 2;

	const RANDOM_NUMERIC = 3;

	const RANDOM_NOZERO = 4;

	/**
	 * Converts strings to camelize style
	 *
	 *<code>
	 *      echo Phalcon\Text::camelize('coco_bongo'); //CocoBongo
	 *</code>
	 *
	 * @param string str
	 * @return string
	 */
	static public function camelize(string str) -> string
	{
		return str->camelize();
	}

	/**
	 * Uncamelize strings which are camelized
	 *
	 *<code>
	 *      echo Phalcon\Text::camelize('CocoBongo'); //coco_bongo
	 *</code>
	 *
	 * @param string str
	 * @return string
	 */
	static public function uncamelize(string str) -> string
	{
		return str->uncamelize();
	}

	/**
	 * Adds a number to a string or increment that number if it already is defined
	 *
	 *<code>
	 *	echo Phalcon\Text::increment("a"); // "a_1"
	 *	echo Phalcon\Text::increment("a_1"); // "a_2"
	 *</code>
	 *
	 * @param string $str
	 * @param string $separator
	 * @return string
	 */
	static public function increment(string str, var separator=null)
	{
		var parts, number;

		if separator === null {
			let separator = '_';
		}

		let parts = explode(separator, str);

		if fetch number, parts[1] {
			let number++;
		} else {
			let number = 1;
		}

		return parts[0] . separator. number;
	}

	/**
	 * Generates a random string based on the given type. Type is one of the RANDOM_* constants
	 *
	 *<code>
	 *	echo Phalcon\Text::random(Phalcon\Text::RANDOM_ALNUM); //"aloiwkqz"
	 *</code>
	 *
	 * @param int type
	 * @param int length
	 * @return string
	 */
	static public function random(int type=0, long length=8) -> string
	{
		var pool, str = "";
		int end;

		switch type {
			case Text::RANDOM_ALPHA:
				let pool = array_merge(range("a", "z"), range("A", "Z"));
				break;
			case Text::RANDOM_HEXDEC:
				let pool = array_merge(range(0, 9), range("a", "f"));
				break;
			case Text::RANDOM_NUMERIC:
				let pool = range(0, 9);
				break;
			case Text::RANDOM_NOZERO:
				let pool = range(1, 9);
				break;
			default:
				// Default type \Phalcon\Text::RANDOM_ALNUM
				let pool = array_merge(range(0, 9), range("a", "z"), range("A", "Z"));
				break;
		}

		let end = count(pool) - 1;

		while strlen(str) < length {
			let str .= pool[mt_rand(0, end)];
		}

		return str;
	}

	/**
	 * Check if a string starts with a given string
	 *
	 *<code>
	 *	echo Phalcon\Text::startsWith("Hello", "He"); // true
	 *	echo Phalcon\Text::startsWith("Hello", "he"); // false
	 *	echo Phalcon\Text::startsWith("Hello", "he", false); // true
	 *</code>
	 *
	 * @param string str
	 * @param string start
	 * @param boolean ignoreCase
	 * @return boolean
	 */
	static public function startsWith(str, start, ignoreCase = true) -> boolean
	{
		return starts_with(str, start, ignoreCase);
	}

	/**
	 * Check if a string ends with a given string
	 *
	 *<code>
	 *	echo Phalcon\Text::endsWith("Hello", "llo"); // true
	 *	echo Phalcon\Text::endsWith("Hello", "LLO"); // false
	 *	echo Phalcon\Text::endsWith("Hello", "LLO", false); // true
	 *</code>
	 *
	 * @param string str
	 * @param string end
	 * @param boolean ignoreCase
	 * @return boolean
	 */
	static public function endsWith(string str, string end, boolean ignoreCase=true) -> boolean
	{
		return ends_with(str, end, ignoreCase);
	}

	/**
	 * Lowercases a string, this function makes use of the mbstring extension if available
	 *
	 * @param string $str
	 * @return string
	 */
	static public function lower(string str) -> string
	{
		/**
		 * 'lower' checks for the mbstring extension to make a correct lowercase transformation
		 */
		if function_exists("mb_strtolower") {
			return mb_strtolower($str);
		}
		return strtolower($str);
	}

	/**
	 * Uppercases a string, this function makes use of the mbstring extension if available
	 *
	 * @param string str
	 * @return string
	 */
	static public function upper(string str) -> string
	{
		/**
		 * 'upper' checks for the mbstring extension to make a correct lowercase transformation
		 */
		if function_exists("mb_strtoupper") {
			return mb_strtoupper($str);
		}
		return strtoupper(str);
	}

}