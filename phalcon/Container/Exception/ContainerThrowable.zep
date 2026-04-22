
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Container\Exception;

use Phalcon\Container\Interop\Ioc\IocThrowable;
use Phalcon\Container\Interop\Resolver\ResolverThrowable;
use Phalcon\Container\Interop\Service\Throwable as ServiceThrowable;

interface ContainerThrowable extends IocThrowable, ResolverThrowable, ServiceThrowable
{
}
