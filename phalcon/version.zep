
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
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
	 *
	 * <code>
	 * echo Phalcon\Version::getPart(
	 *     Phalcon\Version::VERSION_MAJOR
	 * );
	 * </code>
	 */
	const VERSION_MAJOR = 0;

	/**
	 * The constant referencing the major version. Returns 1
	 *
	 * <code>
	 * echo Phalcon\Version::getPart(
	 *     Phalcon\Version::VERSION_MEDIUM
	 * );
	 * </code>
	 */
	const VERSION_MEDIUM = 1;

	/**
	 * The constant referencing the major version. Returns 2
	 *
	 * <code>
	 * echo Phalcon\Version::getPart(
	 *     Phalcon\Version::VERSION_MINOR
	 * );
	 * </code>
	 */
	const VERSION_MINOR = 2;

	/**
	 * The constant referencing the major version. Returns 3
	 *
	 * <code>
	 * echo Phalcon\Version::getPart(
	 *     Phalcon\Version::VERSION_SPECIAL
	 * );
	 * </code>
	 */
	const VERSION_SPECIAL = 3;

	/**
	 * The constant referencing the major version. Returns 4
	 *
	 * <code>
	 * echo Phalcon\Version::getPart(
	 *     Phalcon\Version::VERSION_SPECIAL_NUMBER
	 * );
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
	 * D - Special release: 1 = alpha, 2 = beta, 3 = RC, 4 = stable
	 * E - Special release version i.e. RC1, Beta2 etc.
	 */
	protected static function _getVersion() -> array
	{
		return [4, 0, 0, 1, 3];
	}

	/**
	 * Translates a number to a special release.
	 */
	protected final static function _getSpecial(int special) -> string
	{
		var suffix = "";

		switch special {
			case 1:
				let suffix = "alpha";
				break;
			case 2:
				let suffix = "beta";
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

		let version       = static::_getVersion();

		let major         = version[self::VERSION_MAJOR],
			medium        = version[self::VERSION_MEDIUM],
			minor         = version[self::VERSION_MINOR],
			special       = version[self::VERSION_SPECIAL],
			specialNumber = version[self::VERSION_SPECIAL_NUMBER];

		let result  = major . "." . medium . "." . minor;
		let suffix  = static::_getSpecial(special);

		if suffix != "" {
			/**
			 * A pre-release version should be denoted by appending a hyphen and a series
			 * of dot separated identifiers immediately following the patch version.
			 */
			let result .= "-". suffix;
			if specialNumber != 0 {
				let result .= "." . specialNumber;
			}
		}

		return result;
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

		let version       = static::_getVersion();

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
	 * echo Phalcon\Version::getPart(
	 *     Phalcon\Version::VERSION_MAJOR
	 * );
	 * </code>
	 */
	public static function getPart(int part) -> string
	{
		var version, result;

		let version = static::_getVersion();

		switch part {
			case self::VERSION_MAJOR:
			case self::VERSION_MEDIUM:
			case self::VERSION_MINOR:
			case self::VERSION_SPECIAL_NUMBER:
				let result = version[part];
				break;

			case self::VERSION_SPECIAL:
				let result = static::_getSpecial(version[self::VERSION_SPECIAL]);
				break;

			default:
				let result = static::get();
				break;
		}

		return result;
	}
}
