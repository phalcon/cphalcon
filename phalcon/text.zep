
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
	 * <code>
	 *    echo Phalcon\Text::camelize('coco_bongo'); //CocoBongo
	 * </code>
	 */
	public static function camelize(string! str) -> string
	{
		return str->camelize();
	}

	/**
	 * Uncamelize strings which are camelized
	 *
	 * <code>
	 *    echo Phalcon\Text::camelize('CocoBongo'); //coco_bongo
	 * </code>
	 */
	public static function uncamelize(string! str) -> string
	{
		return str->uncamelize();
	}

	/**
	 * Adds a number to a string or increment that number if it already is defined
	 *
	 * <code>
	 *    echo Phalcon\Text::increment("a"); // "a_1"
	 *    echo Phalcon\Text::increment("a_1"); // "a_2"
	 * </code>
	 */
	public static function increment(string str, var separator = null) -> string
	{
		var parts, number;

		if separator === null {
			let separator = "_";
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
	 * <code>
	 *    echo Phalcon\Text::random(Phalcon\Text::RANDOM_ALNUM); //"aloiwkqz"
	 * </code>
	 */
	public static function random(int type = 0, long length = 8) -> string
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
	 * <code>
	 *    echo Phalcon\Text::startsWith("Hello", "He"); // true
	 *    echo Phalcon\Text::startsWith("Hello", "he", false); // false
	 *    echo Phalcon\Text::startsWith("Hello", "he"); // true
	 * </code>
	 */
	public static function startsWith(string str, string start, boolean ignoreCase = true) -> boolean
	{
		return starts_with(str, start, ignoreCase);
	}

	/**
	 * Check if a string ends with a given string
	 *
	 * <code>
	 *    echo Phalcon\Text::endsWith("Hello", "llo"); // true
	 *    echo Phalcon\Text::endsWith("Hello", "LLO", false); // false
	 *    echo Phalcon\Text::endsWith("Hello", "LLO"); // true
	 * </code>
	 */
	public static function endsWith(string str, string end, boolean ignoreCase = true) -> boolean
	{
		return ends_with(str, end, ignoreCase);
	}

	/**
	 * Lowercases a string, this function makes use of the mbstring extension if available
	 *
	 * <code>
	 *    echo Phalcon\Text::lower("HELLO"); // hello
	 * </code>
	 */
	public static function lower(string! str, string! encoding = "UTF-8") -> string
	{
		/**
		 * 'lower' checks for the mbstring extension to make a correct lowercase transformation
		 */
		if function_exists("mb_strtolower") {
			return mb_strtolower(str, encoding);
		}
		return strtolower(str);
	}

	/**
	 * Uppercases a string, this function makes use of the mbstring extension if available
	 *
	 * <code>
	 *    echo Phalcon\Text::upper("hello"); // HELLO
	 * </code>
	 */
	public static function upper(string! str, string! encoding = "UTF-8") -> string
	{
		/**
		 * 'upper' checks for the mbstring extension to make a correct lowercase transformation
		 */
		if function_exists("mb_strtoupper") {
			return mb_strtoupper(str, encoding);
		}
		return strtoupper(str);
	}

	/**
	 * Reduces multiple slashes in a string to single slashes
	 *
	 * <code>
	 *    echo Phalcon\Text::reduceSlashes("foo//bar/baz"); // foo/bar/baz
	 *    echo Phalcon\Text::reduceSlashes("http://foo.bar///baz/buz"); // http://foo.bar/baz/buz
	 * </code>
	 */
	public static function reduceSlashes(string str) -> string
	{
		return preg_replace("#(?<!:)//+#", "/", str);
	}

	/**
	 * Concatenates strings using the separator only once without duplication in places concatenation
	 *
	 * <code>
	 *    $str = Phalcon\Text::concat("/", "/tmp/", "/folder_1/", "/folder_2", "folder_3/");
	 *    echo $str; // /tmp/folder_1/folder_2/folder_3/
	 * </code>
	 *
	 * @param string separator
	 * @param string a
	 * @param string b
	 * @param string ...N
	 */
	//public static function concat(string! separator, string! a, string! b) -> string
	public static function concat() -> string
	{
		/**
		 * TODO:
		 * Remove after solve https://github.com/phalcon/zephir/issues/938,
		 * and also replace line 214 to 213
		 */
		var separator, a, b;
		let separator = func_get_arg(0),
			a = func_get_arg(1),
			b = func_get_arg(2);
		//END

		var c;

		if func_num_args() > 3 {
			for c in array_slice(func_get_args(), 3) {
				let b = rtrim(b, separator) . separator . ltrim(c, separator);
			}
		}

		return rtrim(a, separator) . separator . ltrim(b, separator);
	}
}
