
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Traits\Php;

trait IniTrait
{
    /**
     * Gets the value of a configuration option
     *
     * @param string $input
     * @param string $defaultValue
     *
     * @return string
     *
     * @link https://php.net/manual/en/function.ini-get.php
     * @link https://php.net/manual/en/ini.list.php
     */
    protected static function phpIniGet(
        string input,
        string defaultValue = ""
    ) -> string {
        var value;

        let value = ini_get(input);
        if (value === false) {
            return defaultValue;
        }

        return value;
    }

    /**
     * Query a php.ini value and return it back as boolean
     *
     * @param string $input
     * @param bool   $defaultValue
     *
     * @return bool
     *
     * @link https://php.net/manual/en/function.ini-get.php
     * @link https://php.net/manual/en/ini.list.php
     */
    protected static function phpIniGetBool(
        string input,
        bool defaultValue = false
    ) -> bool {
        var value;
        bool result = false;

        let value = ini_get(input);
        if (value === false) {
            return defaultValue;
        }

        switch strtolower(value) {
            case "true":
            case "on":
            case "yes":
            case "y":
            case "1":
                let result = true;
        };

        return result;
    }

    /**
     * Query a php.ini value and return it back as integer
     *
     * @param string $input
     * @param int    $defaultValue
     *
     * @return int
     *
     * @link https://php.net/manual/en/function.ini-get.php
     * @link https://php.net/manual/en/ini.list.php
     */
    protected static function phpIniGetInt(string input, int defaultValue = 0) -> int
    {
        var value;

        let value = ini_get(input);
        if (value === false) {
            return defaultValue;
        }

        return (int) value;
    }

    /**
     * Parse a configuration file
     *
     * @param string $filename
     * @param bool   $processSections
     * @param int    $scannerMode
     *
     * @return array|false
     *
     * @link https://php.net/manual/en/function.parse-ini-file.php
     */
    protected static function phpParseIniFile(
        string filename,
        bool processSections = false,
        int scannerMode = 0
    ) -> array | false {
        return parse_ini_file(filename, processSections, scannerMode);
    }
}
