
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Config\Adapter;

use Phalcon\Config\Config;
use Phalcon\Config\Exception;
use Phalcon\Support\Traits\PhpFileTrait;

/**
 * Reads ini files and converts them to Phalcon\Config\Config objects.
 *
 * Given the next configuration file:
 *
 *```ini
 * [database]
 * adapter = Mysql
 * host = localhost
 * username = scott
 * password = cheetah
 * dbname = test_db
 *
 * [phalcon]
 * controllersDir = "../app/controllers/"
 * modelsDir = "../app/models/"
 * viewsDir = "../app/views/"
 * ```
 *
 * You can read it as follows:
 *
 *```php
 * use Phalcon\Config\Adapter\Ini;
 *
 * $config = new Ini("path/config.ini");
 *
 * echo $config->phalcon->controllersDir;
 * echo $config->database->username;
 *```
 *
 * PHP constants may also be parsed in the ini file, so if you define a constant
 * as an ini value before calling the constructor, the constant's value will be
 * integrated into the results. To use it this way you must specify the optional
 * second parameter as `INI_SCANNER_NORMAL` when calling the constructor:
 *
 * ```php
 * $config = new \Phalcon\Config\Adapter\Ini(
 *     "path/config-with-constants.ini",
 *     INI_SCANNER_NORMAL
 * );
 * ```
 */
class Ini extends Config
{
    /**
     * Ini constructor.
     *
     * @param string $filePath
     * @param int    $mode
     *
     * @throws Exception
     */
    public function __construct(string filePath, int mode = 1)
    {
        var directives, iniConfig, lastValue, path, section, sections;
        array config;

        let iniConfig = parse_ini_file(filePath, true, mode);

        if unlikely iniConfig === false {
            throw new Exception(
                "Configuration file " . basename(filePath) . " cannot be loaded"
            );
        }

        let config = [];

        for section, directives in iniConfig {
            if typeof directives === "array" {
                let sections = [];

                for path, lastValue in directives {
                    let sections[] = this->parseIniString(
                        (string) path,
                        lastValue
                    );
                }

                if count(sections) {
                    let config[section] = call_user_func_array(
                        "array_replace_recursive",
                        sections
                    );
                }

                continue;
            }

            let config[section] = this->cast(directives);
        }

        parent::__construct(config);
    }

    /**
     * We have to cast values manually because parse_ini_file() has a poor
     * implementation.
     *
     * @param mixed $ini
     *
     * @return array|float|int|mixed|string|null
     */
    protected function cast(var ini) -> bool | null | double | int | string
    {
        var lowerIni;
        array castMap;

        if typeof ini === "array" {
            return this->castArray(ini);
        }

        let ini      = (string) ini,
            lowerIni = strtolower(ini);

        // Decode null/boolean
        if "null" === lowerIni {
            return null;
        }

        // Decode boolean
        let castMap = [
            "on"    : true,
            "true"  : true,
            "yes"   : true,
            "off"   : false,
            "no"    : false,
            "false" : false
        ];

        if true === isset(castMap[lowerIni]) {
            return castMap[lowerIni];
        }

        // Decode float/int
        if typeof ini === "string" && is_numeric(ini) {
            if preg_match("/[.]+/", ini) {
                return (double) ini;
            }

            return (int) ini;
        }

        return ini;
    }

    /**
     * @param array $ini
     *
     * @return array
     */
    protected function castArray(array ini) -> array
    {
        var key, value;

        for key, value in ini {
            let ini[key] = this->cast(value);
        }

        return ini;
    }

    /**
     * Build multidimensional array from string
     *
     * @param string $path
     * @param mixed  $value
     *
     * @return array
     */
    protected function parseIniString(string path, var value) -> array
    {
        var castValue, key, position, result;

        let castValue = this->cast(value),
            position  = strpos(path, ".");

        if false === position {
            return [
                path : castValue
            ];
        }

        let key    = substr(path, 0, position),
            path   = substr(path, position + 1),
            result = this->parseIniString(path, castValue);

        return [
            key : result
        ];
    }
}
