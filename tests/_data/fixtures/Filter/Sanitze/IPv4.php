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

/**
 * Class IPv4
 */
class IPv4
{
    /**
     * Sanitizes IP addresses
     *
     * @param string $value
     *
     * @return mixed
     */
    public function __invoke(string $value)
    {
        return filter_var($value, FILTER_VALIDATE_IP, FILTER_FLAG_IPV4);
    }
}
