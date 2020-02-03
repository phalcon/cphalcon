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

class CheckTokenCest
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
        $this->setDiService('sessionStream');;

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
     * Tests Phalcon\Security :: checkToken() and destroyToken()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function securityCheckToken(UnitTester $I)
    {
        $I->wantToTest('Security - checkToken()');

        $this->startSession();

        $container = $this->getDi();

        $security = new Security();

        $security->setDI($container);


        // Random token and token key check
        $tokenKey = $security->getTokenKey();
        $token    = $security->getToken();

        $_POST = [
            $tokenKey => $token,
        ];

        $I->assertTrue(
            $security->checkToken(null, null, false)
        );

        $I->assertTrue(
            $security->checkToken()
        );

        $I->assertFalse(
            $security->checkToken()
        );


        // Destroy token check
        $tokenKey = $security->getTokenKey();
        $token    = $security->getToken();

        $security->destroyToken();

        $_POST = [
            $tokenKey => $token,
        ];

        $I->assertFalse(
            $security->checkToken()
        );


        // Custom token key check
        $token = $security->getToken();

        $_POST = [
            'custom_key' => $token,
        ];

        $I->assertFalse(
            $security->checkToken(null, null, false)
        );

        $I->assertFalse(
            $security->checkToken('other_custom_key', null, false)
        );

        $I->assertTrue(
            $security->checkToken('custom_key')
        );


        // Custom token value check
        $token = $security->getToken();

        $_POST = [];

        $I->assertFalse(
            $security->checkToken(null, null, false)
        );

        $I->assertFalse(
            $security->checkToken('some_random_key', 'some_random_value', false)
        );

        $I->assertTrue(
            $security->checkToken('custom_key', $token)
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
