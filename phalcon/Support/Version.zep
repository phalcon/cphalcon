
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Support;

/**
 * This class allows to get the installed version of the framework
 */
class Version
{
    /**
     * The constant referencing the major version. Returns 0
     *
     * ```php
     * echo (new Phalcon\Support\Version())
     *          ->getPart(Phalcon\Support\Version::VERSION_MAJOR);
     * ```
     */
    const VERSION_MAJOR = 0;

    /**
     * The constant referencing the major version. Returns 1
     *
     * ```php
     * echo (new Phalcon\Support\Version())
     *          ->getPart(Phalcon\Support\Version::VERSION_MEDIUM);
     * ```
     */
    const VERSION_MEDIUM = 1;

    /**
     * The constant referencing the major version. Returns 2
     *
     * ```php
     * echo (new Phalcon\Support\Version())
     *          ->getPart(Phalcon\Support\Version::VERSION_MINOR);
     * ```
     */
    const VERSION_MINOR = 2;

    /**
     * The constant referencing the major version. Returns 3
     *
     * ```php
     * echo (new Phalcon\Support\Version())
     *          ->getPart(Phalcon\Support\Version::VERSION_SPECIAL);
     * ```
     */
    const VERSION_SPECIAL = 3;

    /**
     * The constant referencing the major version. Returns 4
     *
     * ```php
     * echo (new Phalcon\Support\Version())
     *          ->getPart(Phalcon\Support\Version::VERSION_SPECIAL_NUMBER);
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
    protected function getVersion() -> array
    {
        return [5, 6, 1, 4, 0];
    }

    /**
     * Translates a number to a special release.
     */
    protected final function getSpecial(int special) -> string
    {
        var suffix;

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
            default:
                let suffix = "";
                break;
        }

        return suffix;
    }

    /**
     * Returns the active version (string)
     *
     * ```php
     * echo (new Phalcon\Version())->get();
     * ```
     */
    public function get() -> string
    {
        var version, major, medium, minor, special, specialNumber, suffix;
        string result;

        let version = this->getVersion();

        let major         = version[self::VERSION_MAJOR],
            medium        = version[self::VERSION_MEDIUM],
            minor         = version[self::VERSION_MINOR],
            special       = version[self::VERSION_SPECIAL],
            specialNumber = version[self::VERSION_SPECIAL_NUMBER];

        let result  = major . "." . medium . "." . minor;
        let suffix  = this->getSpecial(special);

        if suffix != "" {
            /**
             * A pre-release version should be denoted by appending alpha/beta or RC and
             * a patch version.
             * examples 5.0.0alpha2, 5.0.0beta1, 5.0.0RC3
             */
            let result .= suffix;

            if specialNumber != 0 {
                let result .= specialNumber;
            }
        }

        return result;
    }

    /**
     * Returns the numeric active version
     *
     * ```php
     * echo (new Phalcon\Version())->getId();
     * ```
     */
    public function getId() -> string
    {
        var version, major, medium, minor, special, specialNumber;

        let version = this->getVersion();

        let major         = version[self::VERSION_MAJOR],
            medium        = version[self::VERSION_MEDIUM],
            minor         = version[self::VERSION_MINOR],
            special       = version[self::VERSION_SPECIAL],
            specialNumber = version[self::VERSION_SPECIAL_NUMBER];

        return major
            . sprintf("%02s", medium)
            . sprintf("%02s", minor)
            . special
            . specialNumber;
    }

    /**
     * Returns a specific part of the version. If the wrong parameter is passed
     * it will return the full version
     *
     * ```php
     * echo (new Phalcon\Version())->getPart(Phalcon\Version::VERSION_MAJOR);
     * ```
     */
    public function getPart(int part) -> string
    {
        var version;

        let version = this->getVersion();

        switch part {
            case self::VERSION_MAJOR:
            case self::VERSION_MEDIUM:
            case self::VERSION_MINOR:
            case self::VERSION_SPECIAL_NUMBER:
                return (string) version[part];

            case self::VERSION_SPECIAL:
                return this->getSpecial(version[self::VERSION_SPECIAL]);
        }

        return this->get();
    }
}
