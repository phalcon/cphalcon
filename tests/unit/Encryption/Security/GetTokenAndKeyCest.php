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
use Phalcon\Tests\Fixtures\Http\RequestFixture;
use Phalcon\Tests\Fixtures\Traits\DiTrait;
use UnitTester;

class GetTokenAndKeyCest
{
    use DiTrait;

    /**
     * executed before each test
     */
    public function _before(UnitTester $I)
    {
        $I->checkExtensionIsLoaded('openssl');

        $this->setNewFactoryDefault();
        $this->setDiService('sessionStream');
    }

    /**
     * Tests Security::getToken() and Security::getTokenKey() for generating
     * only one token per request
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function securityGetToken(UnitTester $I)
    {
        $I->wantToTest('Security - getToken()');

        /** @var Manager $session */
        $session = $this->container->getShared('session');

        $session->start();

        $security = new Security();
        $security->setDI($this->container);

        // Random token and token key check
        $tokenKey = $security->getTokenKey();
        $token    = $security->getToken();

        $I->assertEquals($tokenKey, $security->getTokenKey());
        $I->assertEquals($token, $security->getToken());
        $I->assertEquals($token, $security->getSessionToken());

        $security->destroyToken();

        $I->assertNotEquals($tokenKey, $security->getTokenKey());
        $I->assertNotEquals($token, $security->getToken());
        $I->assertNotEquals($token, $security->getSessionToken());

        $security->destroyToken();

        $session->destroy();
    }
}
