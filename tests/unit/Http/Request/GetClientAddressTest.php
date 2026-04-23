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

namespace Phalcon\Tests\Unit\Http\Request;

use Phalcon\Di\FactoryDefault;
use Phalcon\Http\Request;
use Phalcon\Tests\Support\Page\Http;
use Phalcon\Tests\Unit\Http\Fake\FakeRequest;
use Phalcon\Tests\Unit\Http\Helper\AbstractHttpBase;

final class GetClientAddressTest extends AbstractHttpBase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-03-17
     */
    public function testHttpRequestGetClientAddress(): void
    {
        $_SERVER['REMOTE_ADDR'] = Http::TEST_IP_THREE;

        $request = new Request();

        $expected = Http::TEST_IP_THREE;
        $actual   = $request->getClientAddress();
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-03-17
     */
    public function testHttpRequestGetClientAddressIncorrect(): void
    {
        $_SERVER['REMOTE_ADDR'] = [Http::TEST_IP_THREE];

        $request = new Request();

        $actual = $request->getClientAddress();
        $this->assertFalse($actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-03-17
     */
    public function testHttpRequestGetClientAddressIpv6(): void
    {
        $_SERVER['REMOTE_ADDR'] = Http::TEST_IP_IPV6;

        $request = new Request();

        $expected = Http::TEST_IP_IPV6;
        $actual   = $request->getClientAddress();
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2025-07-11
     */
    public function testHttpRequestGetClientAddressTrustForwardedHeader(): void
    {
        $container = new FactoryDefault();

        // skip private IP and return the first non-private and non-reserved IP
        $_SERVER['REMOTE_ADDR']          = '25.25.25.25';
        $_SERVER['HTTP_X_FORWARDED_FOR'] = '10.4.6.1,25.25.25.25';

        $request = new Request();
        $request->setDI($container);

        $expected = '25.25.25.25';
        $actual   = $request->getClientAddress(true);
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2025-07-11
     */
    public function testHttpRequestSetTrustedProxies(): void
    {
        $container = new FactoryDefault();

        $request = new FakeRequest();
        $request->setDI($container);
        $request->setTrustedProxies([
            '25.25.25.0/24'
        ]);

        $expected = ['25.25.25.0/24'];
        $actual   = $request->getTrustedProxies();
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2025-07-11
     */
    public function testHttpRequestGetClientAddressTrustForwardedHeaderWithValidTrustedProxy(): void
    {
        $container = new FactoryDefault();

        $_SERVER['REMOTE_ADDR']          = '25.25.25.1';
        $_SERVER['HTTP_X_FORWARDED_FOR'] = '8.8.8.8,25.25.25.1';

        $request = new Request();
        $request->setDI($container);
        $request->setTrustedProxies([
            '25.25.25.0/24'
        ]);

        $expected = '8.8.8.8';
        $actual   = $request->getClientAddress(true);
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2025-07-11
     */
    public function testHttpRequestGetClientAddressTrustForwardedHeaderWithInvalidTrustedProxy(): void
    {
        $container = new FactoryDefault();

        $_SERVER['REMOTE_ADDR']          = '1.1.1.1';
        $_SERVER['HTTP_X_FORWARDED_FOR'] = '8.8.8.8,1.1.1.1';

        $request = new Request();
        $request->setDI($container);
        $request->setTrustedProxies([
            '25.25.25.0/24'
        ]);

        $expected = '1.1.1.1';
        $actual   = $request->getClientAddress(true);
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2025-07-11
     */
    public function testHttpRequestGetClientAddressTrustForwardedHeaderWithNonPublicProxyIps(): void
    {
        $container = new FactoryDefault();

        $_SERVER['REMOTE_ADDR']          = '192.168.0.10';
        $_SERVER['HTTP_X_FORWARDED_FOR'] = '10.4.5.3,192.168.0.10';

        $request = new Request();
        $request->setDI($container);
        $request->setTrustedProxies([
            '192.168.0.10'
        ]);

        $expected = '192.168.0.10';
        $actual   = $request->getClientAddress(true);
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-03-17
     */
    public function testHttpRequestGetClientAddressTrustForwardedHeaderClientIp(): void
    {
        $container = new FactoryDefault();
        $_SERVER['REMOTE_ADDR'] = Http::TEST_IP_THREE;
        $_SERVER['HTTP_CLIENT_IP'] = Http::TEST_IP_TWO;

        $request = new Request();
        $request->setDI($container);
        $request->setTrustedProxyHeader('HTTP_CLIENT_IP');

        $expected = Http::TEST_IP_TWO;
        $actual   = $request->getClientAddress(true);
        $this->assertSame($expected, $actual);
    }
}
