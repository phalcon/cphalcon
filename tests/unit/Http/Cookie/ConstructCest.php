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

namespace Phalcon\Tests\Unit\Http\Cookie;

use Phalcon\Http\Cookie;
use Phalcon\Http\Cookie\CookieInterface;
use Phalcon\Tests\Unit\Http\Helper\HttpBase;
use UnitTester;

use function uniqid;

class ConstructCest extends HttpBase
{
    /**
     * Tests Phalcon\Http\Cookie :: __construct()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function httpCookieConstruct(UnitTester $I)
    {
        $I->wantToTest('Http\Cookie - __construct()');

        $this->setDiService('sessionStream');

        $name   = uniqid('nam-');
        $cookie = new Cookie($name);

        $I->assertInstanceOf(CookieInterface::class, $cookie);
        $I->assertInstanceOf(Cookie::class, $cookie);
    }
}
