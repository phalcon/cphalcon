
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

/**
 * Reads YAML files and converts them to Phalcon\Config\Config objects.
 *
 * Given the following configuration file:
 *
 *```yaml
 * phalcon:
 *   baseuri:        /phalcon/
 *   controllersDir: !approot  /app/controllers/
 * models:
 *   metadata: memory
 *```
 *
 * You can read it as follows:
 *
 *```php
 * define(
 *     "APPROOT",
 *     dirname(__DIR__)
 * );
 *
 * use Phalcon\Config\Adapter\Yaml;
 *
 * $config = new Yaml(
 *     "path/config.yaml",
 *     [
 *         "!approot" => function($value) {
 *             return APPROOT . $value;
 *         },
 *     ]
 * );
 *
 * echo $config->phalcon->controllersDir;
 * echo $config->phalcon->baseuri;
 * echo $config->models->metadata;
 *```
 */
class Yaml extends Config
{
    /**
     * Phalcon\Config\Adapter\Yaml constructor
     */
    public function __construct(string! filePath, array! callbacks = null)
    {
        var yamlConfig;
        int ndocs = 0;

        if unlikely !extension_loaded("yaml") {
            throw new Exception("Yaml extension not loaded");
        }

        if empty(callbacks) {
            let yamlConfig = yaml_parse_file(filePath);
        } else {
            let yamlConfig = yaml_parse_file(filePath, 0, ndocs, callbacks);
        }

        if unlikely yamlConfig === false {
            throw new Exception(
                "Configuration file " . basename(filePath) . " can't be loaded"
            );
        }

        parent::__construct(yamlConfig);
    }
}
