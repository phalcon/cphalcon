
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

/**
 * Reads php files and converts them to Phalcon\Config\Config objects.
 *
 * Given the next configuration file:
 *
 *```php
 * <?php
 *
 * return [
 *     "database" => [
 *         "adapter"  => "Mysql",
 *         "host"     => "localhost",
 *         "username" => "scott",
 *         "password" => "cheetah",
 *         "dbname"   => "test_db",
 *     ],
 *     "phalcon" => [
 *         "controllersDir" => "../app/controllers/",
 *         "modelsDir"      => "../app/models/",
 *         "viewsDir"       => "../app/views/",
 *     ],
 * ];
 *```
 *
 * You can read it as follows:
 *
 *```php
 * use Phalcon\Config\Adapter\Php;
 *
 * $config = new Php("path/config.php");
 *
 * echo $config->phalcon->controllersDir;
 * echo $config->database->username;
 *```
 *
 * @phpstan-import-type config_data from ConfigTypes
 */
class Php extends Config
{
    /**
     * Php constructor.
     *
     * @throws CannotLoadConfigFile
     */
    public function __construct( string filePath)
    {
        var data;

        if unlikely true !== is_file(filePath) {
            throw new CannotLoadConfigFile(basename(filePath));
        }

        let data = require filePath;

        parent::__construct(data);
    }
}
