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

namespace Phalcon\Tests\Unit\Http\Response\Cookies;

use Phalcon\Http\Response\Cookies;
use Phalcon\Http\Response\Exceptions\ResponseServiceUnavailable;
use Phalcon\Tests\AbstractUnitTestCase;

final class ExceptionsTest extends AbstractUnitTestCase
{
    /**
     * Tests that Cookies::get() throws a descriptive exception when no DI
     * container has been set, rather than a fatal error.
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/16650
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-30
     */
    public function testHttpResponseCookiesGetThrowsExceptionWhenContainerIsNull(): void
    {
        $this->expectException(ResponseServiceUnavailable::class);
        $this->expectExceptionMessage(
            "A dependency injection container is required to access the 'response' service"
        );

        $cookies = new Cookies(false);
        $cookies->get('test-cookie');
    }
}
