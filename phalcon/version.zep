
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

	const ALPHA = 1;
	const BETA = 2;
	const RC = 3;
	const STABLE = 4;

	const MAJOR = 0;
	const MEDIUM = 1;
	const MINOR = 2;
	const SPECIAL = 3;
	const SPECIAL_NUMBER = 4;

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
	protected static function _getVersion()
	{
		return [2, 0, 0, self::BETA, 1];
	}

	/**
	 * Returns the active version (string)
	 *
	 * <code>
	 * echo Phalcon\Version::get();
	 * </code>
	 *
	 * @return string
	 */
	public static function get() -> string
	{
		var version, major, medium, minor,
			special, specialNumber, result, suffix;

		let version       = self::_getVersion();

		let major         = version[self::MAJOR],
			medium        = version[self::MEDIUM],
			minor         = version[self::MINOR],
			special       = version[self::SPECIAL],
			specialNumber = version[self::SPECIAL_NUMBER];

		let result = major . "." . medium . "." . minor . " ";
		switch special {
			case 1:
				let suffix = "ALPHA " . specialNumber;
				break;
			case 2:
				let suffix = "BETA " . specialNumber;
				break;
			case 3:
				let suffix = "RC " . specialNumber;
				break;
			default:
				let suffix = "";
				break;
		}

		let result .= suffix;
		return trim(result);
	}

	/**
	 * Returns the numeric active version
	 *
	 * <code>
	 * echo Phalcon\Version::getId();
	 * </code>
	 *
	 * @return string
	 */
	public static function getId() -> string
	{
		var version, major, medium, minor,
			special, specialNumber;

		let version       = self::_getVersion();

		let major         = version[self::MAJOR],
			medium        = version[self::MEDIUM],
			minor         = version[self::MINOR],
			special       = version[self::SPECIAL],
			specialNumber = version[self::SPECIAL_NUMBER];

		return major . sprintf("%02s", medium) . sprintf("%02s", minor) . special . specialNumber;
	}

}
