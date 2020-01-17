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

namespace Phalcon\Test\Unit\Http\Cookie;

use Phalcon\Http\Cookie;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use UnitTester;

class ConstructCest
{
    use DiTrait;

    /**
     * Tests Phalcon\Http\Cookie :: __construct()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function httpCookieConstruct(UnitTester $I)
    {
        $I->wantToTest('Http\Cookie - __construct()');

        $this->setNewFactoryDefault();
        $this->setDiSessionFiles();

        $cookie = new Cookie('test');
        $I->assertInstanceOf(Cookie\CookieInterface::class, $cookie);
        $I->assertInstanceOf(Cookie::class, $cookie);
    }

    public function secureCorrectConstruct(UnitTester $I)
    {
        $I->wantToTest('Http\Cookie - __construct() sets correct secure value');

        $this->setNewFactoryDefault();
        $this->setDiSessionFiles();
        $time = time() + 3600;
        $cookie = new Cookie('test-name', 'test-value', $time, '/', false);
        $I->assertInstanceOf(Cookie\CookieInterface::class, $cookie);
        $I->assertInstanceOf(Cookie::class, $cookie);
        $I->assertEquals(false, $cookie->getSecure());
        $cookie = new Cookie('test-name', 'test-value', $time, '/', true);
        $I->assertInstanceOf(Cookie\CookieInterface::class, $cookie);
        $I->assertInstanceOf(Cookie::class, $cookie);
        $I->assertEquals(true, $cookie->getSecure());
    }

    public function httpOnlyCorrectConstruct(UnitTester $I)
    {
        $I->wantToTest('Http\Cookie - __construct() sets correct httpOnly value');

        $this->setNewFactoryDefault();
        $this->setDiSessionFiles();
        $time = time() + 3600;
        $cookie = new Cookie('test-name', 'test-value', $time, '/', false, 'phalcon.test', true);
        $I->assertInstanceOf(Cookie\CookieInterface::class, $cookie);
        $I->assertInstanceOf(Cookie::class, $cookie);
        $I->assertEquals(true, $cookie->getHttpOnly());
        $cookie = new Cookie('test-name', 'test-value', $time, '/', true, 'phalcon.test', false);
        $I->assertInstanceOf(Cookie\CookieInterface::class, $cookie);
        $I->assertInstanceOf(Cookie::class, $cookie);
        $I->assertEquals(false, $cookie->getHttpOnly());
    }
}
