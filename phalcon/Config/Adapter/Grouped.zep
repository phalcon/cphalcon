
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
use Phalcon\Config\ConfigFactory;
use Phalcon\Config\ConfigInterface;
use Phalcon\Config\Exception;
use Phalcon\Config\Exceptions\GroupedAdapterRequiresArray;
use Phalcon\Factory\Exception as FactoryException;

/**
 * Reads multiple files (or arrays) and merges them all together.
 *
 * See `Phalcon\Config\ConfigFactory::load` To load Config Adapter class using 'adapter' option.
 *
 * ```php
 * use Phalcon\Config\Adapter\Grouped;
 *
 * $config = new Grouped(
 *     [
 *         "path/to/config.php",
 *         "path/to/config.dist.php",
 *     ]
 * );
 * ```
 *
 * ```php
 * use Phalcon\Config\Adapter\Grouped;
 *
 * $config = new Grouped(
 *     [
 *         "path/to/config.json",
 *         "path/to/config.dist.json",
 *     ],
 *     "json"
 * );
 * ```
 *
 * ```php
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
 * ```
 */
class Grouped extends Config
{
    /**
     * Phalcon\Config\Adapter\Grouped constructor
     *
     * @param array              $arrayConfig
     * @param string             $defaultAdapter
     * @param ConfigFactory|null $factory        Factory used to load file
     *                                           based fragments; a default
     *                                           one is created when not
     *                                           provided
     */
    public function __construct(
        array! arrayConfig,
        string! defaultAdapter = "php",
        <ConfigFactory> factory = null
    ) {
        var configArray, configFactory, configInstance, configName;

        parent::__construct([]);

        let configFactory = factory;

        if null === configFactory {
            let configFactory = new ConfigFactory();
        }

        for configName in arrayConfig {
            let configInstance = configName;

            // Set to default adapter if passed as string
            if typeof configName === "object" && configName instanceof ConfigInterface {
                this->merge(configInstance);
                continue;
            } elseif typeof configName === "string" {
                if "" === defaultAdapter {
                    this->merge(
                        configFactory->load(configName)
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
                    throw new GroupedAdapterRequiresArray();
                }

                let configArray    = configInstance["config"],
                    configInstance = new Config(configArray, this->insensitive);
            } else {
                let configInstance = configFactory->load(configInstance);
            }

            this->merge(configInstance);
        }
    }
}
