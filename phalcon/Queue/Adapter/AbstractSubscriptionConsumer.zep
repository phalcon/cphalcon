
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Queue\Adapter;

use Phalcon\Contracts\Queue\SubscriptionConsumer as SubscriptionConsumerInterface;
use Phalcon\Queue\Adapter\Traits\SubscriptionConsumerTrait;

/**
 * Shared subscription-consumer base.
 *
 * @todo Remove in v7. Kept only for backwards compatibility; compose
 * Phalcon\Queue\Adapter\Traits\SubscriptionConsumerTrait directly instead of
 * extending this.
 */
abstract class AbstractSubscriptionConsumer implements SubscriptionConsumerInterface
{
    use SubscriptionConsumerTrait;
}
