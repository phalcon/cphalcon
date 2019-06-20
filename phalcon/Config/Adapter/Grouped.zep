
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Config\Adapter;

use Phalcon\Config\Config;
use Phalcon\Config\Exception;
use Phalcon\Factory\Exception as FactoryException;
use Phalcon\Config\ConfigFactory;

/**
 * Phalcon\Config\Adapter\Grouped
 *
 * Reads multiple files (or arrays) and merges them all together.
 *
 * @see Phalcon\Config\Factory::load To load Config Adapter class using 'adapter' option.
 *
 * <code>
 * use Phalcon\Config\Adapter\Grouped;
 *
 * $config = new Grouped(
 *     [
 *         "path/to/config.php",
 *         "path/to/config.dist.php",
 *     ]
 * );
 * </code>
 *
 * <code>
 * use Phalcon\Config\Adapter\Grouped;
 *
 * $config = new Grouped(
 *     [
 *         "path/to/config.json",
 *         "path/to/config.dist.json",
 *     ],
 *     "json"
 * );
 * </code>
 *
 * <code>
 * use Phalcon\Config\Adapter\Grouped;
 *
 * $config = new Grouped(
 *     [
 *         [
 *             "filePath" => "path/to/config.php",
 *             "adapter"  => "php",
 *         ],
 *         [
 *             "filePath" => "path/to/config.json",
 *             "adapter"  => "json",
 *         ],
 *         [
 *             "adapter"  => "array",
 *             "config"   => [
 *                 "property" => "value",
 *             ],
 *         ],
 *     ],
 * );
 * </code>
 */
class Grouped extends Config
{
    /**
     * Phalcon\Config\Adapter\Grouped constructor
     *
     * Grouped constructor.
     *
     * @param array  $arrayConfig
     * @param string $defaultAdapter
     *
     * @throws Exception
     * @throws FactoryException
     */
    public function __construct(array! arrayConfig, string! defaultAdapter = "php")
    {
        var configArray, configInstance, configName;

        parent::__construct([]);

        for configName in arrayConfig {
            let configInstance = configName;

            // Set to default adapter if passed as string
            if typeof configName === "string" {
                if ("" === defaultAdapter) {
                    this->merge(
                        (new ConfigFactory())->load(configName)
                    );

                    continue;
                }

                let configInstance = [
                    "filePath" : configName,
                    "adapter"  : defaultAdapter
                ];
            } elseif !isset configInstance["adapter"] {
                let configInstance["adapter"] = defaultAdapter;
            }

            if "array" === configInstance["adapter"] {
                if !isset configInstance["config"] {
                    throw new Exception(
                        "To use 'array' adapter you have to specify " .
                        "the 'config' as an array."
                    );
                }

                let configArray    = configInstance["config"],
                    configInstance = new Config(configArray);
            } else {
                let configInstance = (new ConfigFactory())->load(configInstance);
            }

            this->merge(configInstance);
        }
    }
}
