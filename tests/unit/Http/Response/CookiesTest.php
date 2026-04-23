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

namespace Phalcon\Tests\Unit\Http\Response;

use Phalcon\Di\Di;
use Phalcon\Http\Cookie\CookieInterface;
use Phalcon\Http\Response;
use Phalcon\Http\Response\Cookies;
use Phalcon\Session\Adapter\Stream as SessionFiles;
use Phalcon\Session\Manager as SessionManager;
use Phalcon\Tests\Unit\Http\Helper\AbstractHttpBase;

final class CookiesTest extends AbstractHttpBase
{
    /**
     * @issue  https://github.com/phalcon/cphalcon/issues/12978
     * @author Phalcon Team <team@phalcon.io>
     * @since  2017-09-02
     */
    public function testShouldWorkWithoutInitializeInternalCookiesProperty(): void
    {
        $this->assertTrue(
            (new Cookies())->send()
        );
    }

    /**
     * @author limx <715557344@qq.com>
     */
    public function testGetCookies(): void
    {
        $cookies = new Cookies();

        Di::reset();

        $di = new Di();

        $di->set(
            'response',
            function () {
                return new Response();
            }
        );

        $di->set(
            'session',
            function () {
                $manager = new SessionManager();
                $adapter = new SessionFiles();

                $manager->setAdapter($adapter);

                return $manager;
            }
        );

        $cookies->setDI($di);

        $cookies->set('x-token', '1bf0bc92ed7dcc80d337a5755f879878');
        $cookies->set('x-user-id', 1);

        $cookieArray = $cookies->getCookies();

        $this->assertIsArray($cookieArray);

        $this->assertInstanceOf(
            CookieInterface::class,
            $cookieArray['x-token']
        );

        $this->assertInstanceOf(
            CookieInterface::class,
            $cookieArray['x-user-id']
        );

        $this->assertEquals(
            '1bf0bc92ed7dcc80d337a5755f879878',
            $cookieArray['x-token']
        );

        $expected = 1;
        $actual   = $cookieArray['x-user-id']->getValue();
        $this->assertSame($expected, $actual);
    }
}
