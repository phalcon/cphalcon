
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Contracts\Queue;

/**
 * Marker contract for a consumer that supports a visibility timeout
 * (for example Beanstalk TTR or an SQS visibility timeout). Callers detect
 * support with `instanceof`. It carries no behavior and commits to no class
 * shape.
 */
interface VisibilityAware
{
}
