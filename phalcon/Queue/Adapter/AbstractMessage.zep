
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Queue\Adapter;

use Phalcon\Contracts\Queue\Message as MessageInterface;
use Phalcon\Queue\Adapter\Traits\MessageTrait;

/**
 * Shared base for the concrete adapter messages.
 *
 * @todo Remove in v7. Kept only for backwards compatibility; compose
 * Phalcon\Queue\Adapter\Traits\MessageTrait directly instead of extending this.
 */
abstract class AbstractMessage implements MessageInterface
{
    use MessageTrait;
}
