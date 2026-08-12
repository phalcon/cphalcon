
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *
 * Implementation of this component has been inspired by the queue-interop and
 * enqueue projects.
 *
 * @link    https://github.com/queue-interop/queue-interop
 * @license https://github.com/queue-interop/queue-interop/blob/master/LICENSE
 *
 * @link    https://github.com/php-enqueue/enqueue-dev
 * @license https://github.com/php-enqueue/enqueue-dev/blob/master/LICENSE
 */

namespace Phalcon\Contracts\Queue;

/**
 * Central registry of the array shapes used across the Queue namespace.
 * @phpstan-type queue_message_headers array<string, mixed>
 * @phpstan-type queue_message_properties array<string, mixed>
 * @phpstan-type queue_message_envelope array{
 *     body: string,
 *     properties: queue_message_properties,
 *     headers: queue_message_headers,
 * }
 * @phpstan-type queue_connection_options array<string, mixed>
 * @phpstan-type queue_beanstalk_options array{
 *     host?: string,
 *     port?: int,
 *     persistent?: bool,
 *     ttr?: int,
 *     pollInterval?: int,
 * }
 * @phpstan-type queue_redis_options array{
 *     host?: string,
 *     port?: int,
 *     timeout?: int,
 *     persistent?: bool,
 *     persistentId?: string,
 *     auth?: string|array{0: string, 1: string},
 *     index?: int,
 *     prefix?: string,
 *     pollInterval?: int,
 * }
 * @phpstan-type queue_stream_options array{
 *     storageDir?: string,
 *     pollInterval?: int,
 * }
 * @phpstan-type queue_subscriptions array<string, array{0: Consumer, 1: callable}>
 * @phpstan-type queue_beanstalk_status list<string>
 * @phpstan-type queue_beanstalk_job array{0: string, 1: false|string}
 */
interface QueueTypes
{
}
