
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
use Phalcon\Config\Exceptions\CannotLoadConfigFile;
use Phalcon\Config\Exceptions\MissingYamlExtension;
use Phalcon\Traits\Php\InfoTrait;
use Phalcon\Traits\Php\YamlTrait;

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
    use InfoTrait;
    use YamlTrait;

    /**
     * Phalcon\Config\Adapter\Yaml constructor
     */
    public function __construct(string filePath,  array callbacks = null)
    {
        var yamlConfig;

        if unlikely !this->phpExtensionLoaded("yaml") {
            throw new MissingYamlExtension();
        }

        if empty(callbacks) {
            let yamlConfig = this->phpYamlParseFile(filePath);
        } else {
            let yamlConfig = this->phpYamlParseFile(filePath, 0, callbacks);
        }

        if unlikely yamlConfig === null {
            let yamlConfig = [];
        }

        if unlikely yamlConfig === false {
            throw new CannotLoadConfigFile(basename(filePath));
        }

        parent::__construct(yamlConfig);
    }
}
