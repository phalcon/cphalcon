
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Mvc\Model\Exceptions;

use Phalcon\Mvc\Model\Exception;

class InvalidResultsetCacheService extends Exception
{
    public function __construct()
    {
        parent::__construct(
            "Cache service must be an object implementing Phalcon\\Cache\\CacheInterface or Psr\\SimpleCache\\CacheInterface"
        );
    }
}
