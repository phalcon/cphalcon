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

namespace Phalcon\Test\Unit\Security;

use UnitTester;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Security;

/**
 * Class GetTokenCest
 */
class GetTokenAndKeyCest
{
    use DiTrait;

    private $shouldStopSession = false;

    /**
     * executed before each test
     */
    public function _before(UnitTester $I)
    {
        $I->checkExtensionIsLoaded('openssl');

        $this->setNewFactoryDefault();
        $this->setDiSessionFiles();

        $_SESSION = [];
        global $_SESSION;
    }

    public function _after(UnitTester $I)
    {
        if (true === $this->shouldStopSession) {
            @\session_destroy();
        }
    }

    private function startSession(): void
    {
        if (PHP_SESSION_ACTIVE !== \session_status()) {
            @\session_start();
        }

        if (!isset($_SESSION)) {
            $_SESSION = [];
        }

        $this->shouldStopSession = true;
    }

    /**
     * Tests Security::getToken and Security::getTokenKey for generating only
     * one token per request
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function securityGetToken(UnitTester $I)
    {
        $I->wantToTest('Security - getToken()');

        $this->startSession();

        $container = $this->getDi();
        $security  = new Security();
        $security->setDI($container);

        $tokenKey = $security->getTokenKey();
        $token    = $security->getToken();

        $expected = $tokenKey;
        $actual   = $security->getTokenKey();
        $I->assertEquals($expected, $actual);

        $expected = $token;
        $actual   = $security->getToken();
        $I->assertEquals($expected, $actual);

        $expected = $token;
        $actual   = $security->getSessionToken();
        $I->assertEquals($expected, $actual);

        $security->destroyToken();

        $expected = $tokenKey;
        $actual   = $security->getTokenKey();
        $I->assertNotEquals($expected, $actual);

        $expected = $token;
        $actual   = $security->getToken();
        $I->assertNotEquals($expected, $actual);

        $expected = $token;
        $actual   = $security->getSessionToken();
        $I->assertNotEquals($expected, $actual);

        $security->destroyToken();
    }
}
