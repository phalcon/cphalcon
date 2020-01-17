
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Config\Adapter;

use Phalcon\Config;
use Phalcon\Config\Exception;

/**
 * Reads ini files and converts them to Phalcon\Config objects.
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
     */
    public function __construct(string! filePath, var mode = null)
    {
        var directives, iniConfig, lastValue, path, section, sections;
        array config;

        // Default to INI_SCANNER_RAW if not specified
        if likely null === mode {
            let mode = INI_SCANNER_RAW;
        }

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
            } else {
                let config[section] = this->cast(directives);
            }
        }

        parent::__construct(config);
    }

    /**
     * We have to cast values manually because parse_ini_file() has a poor
     * implementation.
     */
    protected function cast(var ini) -> bool | null | double | int | string
    {
        var key, lowerIni, value;

        if typeof ini === "array" {
            for key, value in ini {
                let ini[key] = this->cast(value);
            }

            return ini;
        }

        // Decode true
        let ini      = (string) ini,
            lowerIni = mb_strtolower(ini);

        switch (lowerIni) {
            case "true":
            case "yes":
            case "on":
                return true;
            case "false":
            case "no":
            case "off":
                return false;
            case "null":
                return null;
        }

        // Decode float/int
        if typeof ini === "string" && is_numeric(ini) {
            if preg_match("/[.]+/", ini) {
                return (double) ini;
            } else {
                return (int) ini;
            }
        }

        return ini;
    }

    /**
     * Build multidimensional array from string
     */
    protected function parseIniString(string! path, var value) -> array
    {
        var key, position;

        let value    = this->cast(value),
            position = mb_strpos(path, ".");

        if false === position {
            return [
                path : value
            ];
        }

        let key  = mb_substr(path, 0, position),
            path = mb_substr(path, position + 1);

        return [
            key : this->parseIniString(path, value)
        ];
    }
}
