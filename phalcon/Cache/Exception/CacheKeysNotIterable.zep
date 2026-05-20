
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Cache\Exception;

class CacheKeysNotIterable extends InvalidArgumentException
{
    public function __construct()
    {
        parent::__construct(
            "The keys need to be an array or instance of Traversable"
        );
    }
}
