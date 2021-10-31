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

namespace Phalcon\Tests\Unit\Encryption\Security;

use Phalcon\Encryption\Security;
use Phalcon\Session\Manager;
use Phalcon\Tests\Fixtures\Traits\DiTrait;
use UnitTester;

/**
 * Class GetRequestTokenCest
 *
 * @package Phalcon\Tests\Unit\Encryption\Security
 */
class GetRequestTokenCest
{
    use DiTrait;

    /**
     * executed before each test
     */
    public function _before(UnitTester $I)
    {
        $I->checkExtensionIsLoaded('openssl');

        $this->store = $_SESSION ?? [];

        $this->setNewFactoryDefault();
        $this->setDiService('sessionStream');
    }

    /**
     * Tests Phalcon\Security :: getRequestToken() and getSessionToken()
     * without session initialization
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function securityGetTokensWithoutSessionInitialization(UnitTester $I)
    {
        $I->wantToTest('Security - getRequestToken() and getSessionToken() without session initialization');

        /** @var Manager $session */
        $session = $this->container->getShared('session');

        $session->start();

        $security = new Security();
        $security->setDI($this->container);

        $I->assertNull($security->getSessionToken());
        $I->assertNull($security->getRequestToken());

        $session->destroy();
    }

    /**
     * Tests Phalcon\Security :: getRequestToken() and getSessionToken()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function securityGetRequestTokenAndGetSessionToken(UnitTester $I)
    {
        $I->wantToTest('Security - getRequestToken() and getSessionToken()');
        $I->skipTest('TODO: Enable when Request is done');

        $store = $_POST ?? [];

        /** @var Manager $session */
        $session = $this->container->getShared('session');

        $session->start();

        $security = new Security();
        $security->setDI($this->container);

        $security->getTokenKey();
        $security->getToken();

        // Reinitialize object like if it's a new request.
        $security = new Security();
        $security->setDI($this->container);

        $requestToken = $security->getRequestToken();
        $sessionToken = $security->getSessionToken();
        $tokenKey     = $security->getTokenKey();
        $token        = $security->getToken();

        $I->assertEquals($sessionToken, $requestToken);
        $I->assertNotEquals($token, $sessionToken);
        $I->assertEquals($requestToken, $security->getRequestToken());
        $I->assertNotEquals($token, $security->getRequestToken());

        $_POST = [
            $tokenKey => $requestToken,
        ];

        $actual = $security->checkToken(null, null, false);
        $I->assertTrue($actual);


        $_POST = [
            $tokenKey => $token,
        ];

        $actual = $security->checkToken(null, null, false);
        $I->assertFalse($actual);

        $actual = $security->checkToken();
        $I->assertFalse($actual);


        $security->destroyToken();

        $I->assertNotEquals($requestToken, $security->getRequestToken());

        $session->destroy();

        $_POST = $store;
    }
}
