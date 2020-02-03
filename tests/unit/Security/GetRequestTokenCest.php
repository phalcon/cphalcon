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

namespace Phalcon\Test\Unit\Security;

use Phalcon\Security;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use UnitTester;

use function session_destroy;
use function session_start;
use function session_status;

class GetRequestTokenCest
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
        ;

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
     * Tests Phalcon\Security :: getRequestToken() and getSessionToken()
     * without session initialization
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-09-02
     */
    public function securityGetTokensWithoutSessionInitialization(UnitTester $I)
    {
        $I->wantToTest('Security - getRequestToken() and getSessionToken() without session initialization');

        $this->startSession();

        $container = $this->getDI();
        $security  = new Security();
        $security->setDI($container);

        $I->assertNull($security->getSessionToken());
        $I->assertNull($security->getRequestToken());
    }

    /**
     * Tests Phalcon\Security :: getRequestToken() and getSessionToken()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function securityGetRequestTokenAndGetSessionToken(UnitTester $I)
    {
        $I->wantToTest('Security - getRequestToken() and getSessionToken()');

        $this->startSession();

        $container = $this->getDI();

        // Initialize session.
        $security = new Security();
        $security->setDI($container);

        $security->getTokenKey();
        $security->getToken();

        // Reinitialize object like if it's a new request.
        $security = new Security();

        $security->setDI($container);

        $requestToken = $security->getRequestToken();
        $sessionToken = $security->getSessionToken();
        $tokenKey     = $security->getTokenKey();
        $token        = $security->getToken();

        $I->assertEquals($sessionToken, $requestToken);

        $I->assertNotEquals($token, $sessionToken);

        $I->assertEquals(
            $requestToken,
            $security->getRequestToken()
        );

        $I->assertNotEquals(
            $token,
            $security->getRequestToken()
        );


        $_POST = [
            $tokenKey => $requestToken,
        ];

        $I->assertTrue(
            $security->checkToken(null, null, false)
        );


        $_POST = [
            $tokenKey => $token,
        ];

        $I->assertFalse(
            $security->checkToken(null, null, false)
        );

        $I->assertFalse(
            $security->checkToken()
        );


        $security->destroyToken();

        $I->assertNotEquals(
            $requestToken,
            $security->getRequestToken()
        );
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
