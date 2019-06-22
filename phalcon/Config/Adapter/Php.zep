
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

/**
 * Phalcon\Config\Adapter\Php
 *
 * Reads php files and converts them to Phalcon\Config objects.
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
 * $config = new \Phalcon\Config\Adapter\Php("path/config.php");
 *
 * echo $config->phalcon->controllersDir;
 * echo $config->database->username;
 *```
 */
class Php extends Config
{
    /**
     * Phalcon\Config\Adapter\Php constructor
     */
    public function __construct(string! filePath) -> void
    {
        parent::__construct(
            require filePath
        );
    }
}
