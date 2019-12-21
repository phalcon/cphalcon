
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon;

/**
 * This class allows to get the installed version of the framework
 */
class Version
{
    /**
     * The constant referencing the major version. Returns 0
     *
     * ```php
     * echo Phalcon\Version::getPart(
     *     Phalcon\Version::VERSION_MAJOR
     * );
     * ```
     */
    const VERSION_MAJOR = 0;

    /**
     * The constant referencing the major version. Returns 1
     *
     * ```php
     * echo Phalcon\Version::getPart(
     *     Phalcon\Version::VERSION_MEDIUM
     * );
     * ```
     */
    const VERSION_MEDIUM = 1;

    /**
     * The constant referencing the major version. Returns 2
     *
     * ```php
     * echo Phalcon\Version::getPart(
     *     Phalcon\Version::VERSION_MINOR
     * );
     * ```
     */
    const VERSION_MINOR = 2;

    /**
     * The constant referencing the major version. Returns 3
     *
     * ```php
     * echo Phalcon\Version::getPart(
     *     Phalcon\Version::VERSION_SPECIAL
     * );
     * ```
     */
    const VERSION_SPECIAL = 3;

    /**
     * The constant referencing the major version. Returns 4
     *
     * ```php
     * echo Phalcon\Version::getPart(
     *     Phalcon\Version::VERSION_SPECIAL_NUMBER
     * );
     * ```
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
        return [4, 0, 0, 4, 0];
    }

    /**
     * Translates a number to a special release.
     */
    protected final static function _getSpecial(int special) -> string
    {
        string suffix = "";

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
     * ```php
     * echo Phalcon\Version::get();
     * ```
     */
    public static function get() -> string
    {
        var version, major, medium, minor, special, specialNumber, suffix;
        string result;

        let version = static::_getVersion();

        let major         = version[self::VERSION_MAJOR],
            medium        = version[self::VERSION_MEDIUM],
            minor         = version[self::VERSION_MINOR],
            special       = version[self::VERSION_SPECIAL],
            specialNumber = version[self::VERSION_SPECIAL_NUMBER];

        let result  = major . "." . medium . "." . minor;
        let suffix  = static::_getSpecial(special);

        if suffix != "" {
            /**
             * A pre-release version should be denoted by appending a hyphen and
             * a series of dot separated identifiers immediately following the
             * patch version.
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
     * ```php
     * echo Phalcon\Version::getId();
     * ```
     */
    public static function getId() -> string
    {
        var version, major, medium, minor, special, specialNumber;

        let version = static::_getVersion();

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
     * ```php
     * echo Phalcon\Version::getPart(
     *     Phalcon\Version::VERSION_MAJOR
     * );
     * ```
     */
    public static function getPart(int part) -> string
    {
        var version;

        let version = static::_getVersion();

        switch part {
            case self::VERSION_MAJOR:
            case self::VERSION_MEDIUM:
            case self::VERSION_MINOR:
            case self::VERSION_SPECIAL_NUMBER:
                return version[part];

            case self::VERSION_SPECIAL:
                return static::_getSpecial(
                    version[self::VERSION_SPECIAL]
                );
        }

        return static::get();
    }
}
