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

namespace Phalcon\Tests\Unit\Security;

use Phalcon\Security;
use Phalcon\Tests\Fixtures\Traits\DiTrait;
use UnitTester;

use function session_destroy;
use function session_start;
use function session_status;

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
        $this->setDiService('sessionStream');

        $_SESSION = [];
        global $_SESSION;
    }

    public function _after(UnitTester $I)
    {
        if (true === $this->shouldStopSession) {
            @session_destroy();
        }
    }

    /**
     * Tests Security::getToken() and Security::getTokenKey() for generating
     * only one token per request
     *
     * @author Phalcon Team <team@phalcon.io>
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


        $I->assertEquals(
            $tokenKey,
            $security->getTokenKey()
        );

        $I->assertEquals(
            $token,
            $security->getToken()
        );

        $I->assertEquals(
            $token,
            $security->getSessionToken()
        );


        $security->destroyToken();

        $I->assertNotEquals(
            $tokenKey,
            $security->getTokenKey()
        );

        $I->assertNotEquals(
            $token,
            $security->getToken()
        );

        $I->assertNotEquals(
            $token,
            $security->getSessionToken()
        );


        $security->destroyToken();
    }

    private function startSession(): void
    {
        if (PHP_SESSION_ACTIVE !== session_status()) {
            @session_start();
        }

        if (!isset($_SESSION)) {
            $_SESSION = [];
        }

        $this->shouldStopSession = true;
    }
}
