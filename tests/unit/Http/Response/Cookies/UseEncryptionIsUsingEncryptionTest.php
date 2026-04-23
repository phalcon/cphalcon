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
use Phalcon\Tests\Unit\Http\Fake\CookieTrait;
use Phalcon\Tests\Unit\Http\Helper\AbstractHttpBase;

final class UseEncryptionIsUsingEncryptionTest extends AbstractHttpBase
{
    use CookieTrait;

    /**
     * executed before each test
     */
    public function setUp(): void
    {
        parent::setUp();
        $this->setDiService('sessionStream');
    }

    /**
     * @author Jeremy PASTOURET <https://github.com/jenovateurs>
     * @since  2020-01-06
     */
    public function testHttpResponseCookiesUseEncryptionIsUsingEncryption(): void
    {
        $this->setDiService('crypt');

        $cookies = new Cookies(false);
        $cookies->setDI($this->container);

        $actual = $cookies->isUsingEncryption();
        $this->assertFalse($actual);

        $cookies->useEncryption(true);

        $actual = $cookies->isUsingEncryption();
        $this->assertTrue($actual);
    }
}
