<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Filter\Sanitize;

use Phalcon\Filter\Sanitize\Ip;
use Phalcon\Tests\AbstractUnitTestCase;

final class IpTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-01-19
     */
    public function testFilterSanitizeIpPlain(): void
    {
        $sanitizer = new Ip();

        $this->assertSame('192.168.1.1', $sanitizer('192.168.1.1'));
        $this->assertSame('10.0.0.1', $sanitizer('  10.0.0.1  '));
        $this->assertSame('2001:db8::1', $sanitizer('2001:db8::1'));
        $this->assertFalse($sanitizer('not-an-ip'));
        $this->assertFalse($sanitizer('999.999.999.999'));
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-01-19
     */
    public function testFilterSanitizeIpCidr(): void
    {
        $sanitizer = new Ip();

        // Valid IPv4 CIDR
        $this->assertSame('192.168.1.0/24', $sanitizer('192.168.1.0/24'));
        $this->assertSame('10.0.0.0/8', $sanitizer('10.0.0.0/8'));
        $this->assertSame('0.0.0.0/0', $sanitizer('0.0.0.0/0'));

        // Valid IPv6 CIDR
        $this->assertSame('2001:db8::/32', $sanitizer('2001:db8::/32'));
        $this->assertSame('::1/128', $sanitizer('::1/128'));

        // Invalid: bad IP part
        $this->assertFalse($sanitizer('not-an-ip/24'));

        // Invalid: non-digit mask
        $this->assertFalse($sanitizer('192.168.1.0/abc'));

        // Invalid: IPv4 mask exceeds 32
        $this->assertFalse($sanitizer('192.168.1.0/33'));

        // Invalid: IPv6 mask exceeds 128
        $this->assertFalse($sanitizer('2001:db8::/129'));
    }
}
