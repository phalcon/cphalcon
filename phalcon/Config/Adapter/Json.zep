
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
use Phalcon\Contracts\Config\ConfigTypes;
use Phalcon\Support\Helper\Json\Decode;
use Phalcon\Traits\Php\FileTrait;

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
 *
 * @phpstan-import-type config_data from ConfigTypes
 */
class Json extends Config
{
    use FileTrait;

    /**
     * Json constructor.
     *
     * @throws CannotLoadConfigFile
     */
    public function __construct( string filePath)
    {
        var content, data;

        let content = this->phpFileGetContents(filePath);

        if unlikely content === false {
            throw new CannotLoadConfigFile(basename(filePath));
        }

        let data = (new Decode())->__invoke(content, true);

        parent::__construct(data);
    }
}
