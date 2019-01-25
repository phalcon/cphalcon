<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Fixtures\Filter\Sanitize;

use function func_get_args;
use Phalcon\Filter\SanitizerInterface;

/**
 * Class IPv4
 */
class IPv4 implements SanitizerInterface
{
    /**
     * Sanitizes IP addresses
     *
     * @return mixed
     */
    public function __invoke()
    {
        $arguments = func_get_args();
        $value     = $arguments[0] ?? '';

        return filter_var($value, FILTER_VALIDATE_IP, FILTER_FLAG_IPV4);
    }
}
