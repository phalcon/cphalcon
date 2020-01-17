
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Annotations\Adapter;

use Phalcon\Annotations\Reflection;

/**
 * Stores the parsed annotations in APCu. This adapter is suitable for production
 *
 *```php
 * use Phalcon\Annotations\Adapter\Apcu;
 *
 * $annotations = new Apcu();
 *```
 */
class Apcu extends AbstractAdapter
{
    /**
     * @var string
     */
    protected prefix = "";

    /**
     * @var int
     */
    protected ttl = 172800;

    /**
     * @param array options = [
     *     'prefix' => 'phalcon'
     *     'lifetime' => 3600
     * ]
     *
     * Phalcon\Annotations\Adapter\Apcu constructor
     */
    public function __construct(array options = [])
    {
        var prefix, ttl;

        if fetch prefix, options["prefix"] {
            let this->prefix = prefix;
        }

        if fetch ttl, options["lifetime"] {
            let this->ttl = ttl;
        }
    }

    /**
     * Reads parsed annotations from APCu
     */
    public function read(string! key) -> <Reflection> | bool
    {
        return apcu_fetch(
            mb_strtolower(
                "_PHAN" . this->prefix . key
            )
        );
    }

    /**
     * Writes parsed annotations to APCu
     */
    public function write(string! key, <Reflection> data) -> bool
    {
        return apcu_store(
            mb_strtolower(
                "_PHAN" . this->prefix . key
            ),
            data,
            this->ttl
        );
    }
}
