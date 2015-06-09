
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
 |          Nikolaos Dimopoulos <nikos@niden.net>                         |
 +------------------------------------------------------------------------+
*/

namespace Phalcon;

/**
 * Phalcon\Version
 *
 * This class allows to get the installed version of the framework
 */
class Version
{

	/**
	 * The constant referencing the major version. Returns 0
	 * <code>
	 * echo Phalcon\Version::getPart(Phalcon\Version::VERSION_MAJOR);
	 * </code>
	 */
	const VERSION_MAJOR = 0;

	/**
	 * The constant referencing the major version. Returns 1
	 * <code>
	 * echo Phalcon\Version::getPart(Phalcon\Version::VERSION_MEDIUM);
	 * </code>
	 */
	const VERSION_MEDIUM = 1;

	/**
	 * The constant referencing the major version. Returns 2
	 * <code>
	 * echo Phalcon\Version::getPart(Phalcon\Version::VERSION_MINOR);
	 * </code>
	 */
	const VERSION_MINOR = 2;

	/**
	 * The constant referencing the major version. Returns 3
	 * <code>
	 * echo Phalcon\Version::getPart(Phalcon\Version::VERSION_SPECIAL);
	 * </code>
	 */
	const VERSION_SPECIAL = 3;

	/**
	 * The constant referencing the major version. Returns 4
	 * <code>
	 * echo Phalcon\Version::getPart(Phalcon\Version::VERSION_SPECIAL_NUMBER);
	 * </code>
	 */
	const VERSION_SPECIAL_NUMBER = 4;

	/**
	 * Area where the version number is set. The format is as follows:
	 * ABBCCDE
	 *
	 * A - Major version
	 * B - Med version (two digits)
	 * C - Min version (two digits)
	 * D - Special release: 1 = Alpha, 2 = Beta, 3 = RC, 4 = Stable
	 * E - Special release version i.e. RC1, Beta2 etc.
	 */
	protected static function _getVersion() -> array
	{
		return [2, 0, 3, 4, 0];
	}

	/**
	 * Translates a number to a special release
	 *
	 * If Special release = 1 this function will return ALPHA
	 */
	protected final static function _getSpecial(int special) -> string
	{
		var suffix = "";

		switch special {
			case 1:
				let suffix = "ALPHA";
				break;
			case 2:
				let suffix = "BETA";
				break;
			case 3:
				let suffix = "RC";
				break;
		}

		return suffix;
	}

	/**
	 * Returns the active version (string)
	 *
	 * <code>
	 * echo Phalcon\Version::get();
	 * </code>
	 */
	public static function get() -> string
	{
		var version, major, medium, minor,
			special, specialNumber, result, suffix;

		let version       = self::_getVersion();

		let major         = version[self::VERSION_MAJOR],
			medium        = version[self::VERSION_MEDIUM],
			minor         = version[self::VERSION_MINOR],
			special       = version[self::VERSION_SPECIAL],
			specialNumber = version[self::VERSION_SPECIAL_NUMBER];

		let result  = major . "." . medium . "." . minor . " ";
		let suffix  = self::_getSpecial(special);

		if suffix != "" {
			let result .= suffix . " " . specialNumber;
		}

		return trim(result);
	}

	/**
	 * Returns the numeric active version
	 *
	 * <code>
	 * echo Phalcon\Version::getId();
	 * </code>
	 */
	public static function getId() -> string
	{
		var version, major, medium, minor,
			special, specialNumber;

		let version       = self::_getVersion();

		let major         = version[self::VERSION_MAJOR],
			medium        = version[self::VERSION_MEDIUM],
			minor         = version[self::VERSION_MINOR],
			special       = version[self::VERSION_SPECIAL],
			specialNumber = version[self::VERSION_SPECIAL_NUMBER];

		return major . sprintf("%02s", medium) . sprintf("%02s", minor) . special . specialNumber;
	}

	/**
	 * Returns a specific part of the version. If the wrong parameter is passed
	 * it will return the full version
	 *
	 * <code>
	 * echo Phalcon\Version::getPart(Phalcon\Version::VERSION_MAJOR);
	 * </code>
	 */
	public static function getPart(int part) -> string
	{
		var version, result;

		let version = self::_getVersion();

		switch part {

			case self::VERSION_MAJOR:
			case self::VERSION_MEDIUM:
			case self::VERSION_MINOR:
			case self::VERSION_SPECIAL_NUMBER:
				let result = version[part];
				break;

			case self::VERSION_SPECIAL:
				let result = self::_getSpecial(version[self::VERSION_SPECIAL]);
				break;

			default:
				let result = self::get();
				break;
		}

		return result;
	}
}
