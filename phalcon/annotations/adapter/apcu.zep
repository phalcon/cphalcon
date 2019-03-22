
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Annotations\Adapter;

use Phalcon\Annotations\Adapter;
use Phalcon\Annotations\Reflection;

/**
 * Phalcon\Annotations\Adapter\Apcu
 *
 * Stores the parsed annotations in APCu. This adapter is suitable for production
 *
 *<code>
 * use Phalcon\Annotations\Adapter\Apcu;
 *
 * $annotations = new Apcu();
 *</code>
 */
class Apcu extends Adapter
{

    protected prefix = "";

    protected ttl = 172800;

    /**
     * Phalcon\Annotations\Adapter\Apcu constructor
     *
     * @param array options
     */
    public function __construct(options = null)
    {
        var prefix, ttl;

        if typeof options == "array" {
            if fetch prefix, options["prefix"] {
                let this->prefix = prefix;
            }
            if fetch ttl, options["lifetime"] {
                let this->ttl = ttl;
            }
        }
    }

    /**
     * Reads parsed annotations from APCu
     */
    public function read(string! key) -> <Reflection> | bool
    {
        return apcu_fetch(strtolower("_PHAN" . this->prefix . key));
    }

    /**
     * Writes parsed annotations to APCu
     */
    public function write(string! key, <Reflection> data)
    {
        return apcu_store(strtolower("_PHAN" . this->prefix . key), data, this->ttl);
    }
}
