
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Config\Adapter;

use InvalidArgumentException; // @todo this will also be removed when traits are available
use Phalcon\Config\Config;

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
     */
    public function __construct(string! filePath)
    {
        parent::__construct(
            this->decode(
                file_get_contents(filePath),
                true
            )
        );
    }

    /**
     * @todo This will be removed when traits are introduced
     */
    private function decode(
        string! data,
        bool associative = false,
        int depth = 512,
        int options = 0
    ) -> var
    {
        var decoded;

        let decoded = json_decode(data, associative, depth, options);

        if unlikely JSON_ERROR_NONE !== json_last_error() {
            throw new InvalidArgumentException(
                "json_decode error: " . json_last_error_msg()
            );
        }

        return decoded;
    }
}
