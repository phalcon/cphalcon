
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
use Phalcon\Config\Exceptions\CannotLoadConfigFile;
use Phalcon\Support\Helper\Json\Decode;

/**
 * Reads JSON files and converts them to Phalcon\Config\Config objects.
 *
 * Given the following configuration file:
 *
 *```json
 * {"phalcon":{"baseuri":"\/phalcon\/"},"models":{"metadata":"memory"}}
 *```
 *
 * You can read it as follows:
 *
 *```php
 * use Phalcon\Config\Adapter\Json;
 *
 * $config = new Json("path/config.json");
 *
 * echo $config->phalcon->baseuri;
 * echo $config->models->metadata;
 *```
 */
class Json extends Config
{
    /**
     * Phalcon\Config\Adapter\Json constructor
     *
     * @throws CannotLoadConfigFile
     */
    public function __construct( string filePath)
    {
        var content;

        let content = file_get_contents(filePath);

        if unlikely content === false {
            throw new CannotLoadConfigFile(basename(filePath));
        }

        parent::__construct(
            (new Decode())->__invoke(content, true)
        );
    }
}
