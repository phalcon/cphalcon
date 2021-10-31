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
 * Class CheckTokenCest
 *
 * @package Phalcon\Tests\Unit\Encryption\Security
 */
class CheckTokenCest
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
     * Tests Phalcon\Security :: checkToken() and destroyToken()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function securityCheckToken(UnitTester $I)
    {
        $I->wantToTest('Security - checkToken()');
        $I->skipTest('TODO: Enable when Request is done');
        $store = $_POST ?? [];

        /** @var Manager $session */
        $session = $this->container->getShared('session');

        $session->start();

        $security = new Security();
        $security->setDI($this->container);

        // Random token and token key check
        $tokenKey = $security->getTokenKey();
        $token    = $security->getToken();

        $_POST = [
            $tokenKey => $token,
        ];

        $actual = $security->checkToken(null, null, false);
        $I->assertTrue($actual);

        $actual = $security->checkToken();
        $I->assertTrue($actual);

        $actual = $security->checkToken();
        $I->assertFalse($actual);


        // Destroy token check
        $tokenKey = $security->getTokenKey();
        $token    = $security->getToken();

        $security->destroyToken();

        $_POST = [
            $tokenKey => $token,
        ];

        $actual = $security->checkToken();
        $I->assertFalse($actual);

        // Custom token key check
        $token = $security->getToken();

        $_POST = [
            'custom_key' => $token,
        ];

        $actual = $security->checkToken(null, null, false);
        $I->assertFalse($actual);

        $actual = $security->checkToken('other_custom_key', null, false);
        $I->assertFalse($actual);

        $actual = $security->checkToken('custom_key');
        $I->assertTrue($actual);

        // Custom token value check
        $token = $security->getToken();

        $_POST = [];

        $actual = $security->checkToken(null, null, false);
        $I->assertFalse($actual);

        $actual = $security->checkToken('some_random_key', 'some_random_value', false);
        $I->assertFalse($actual);

        $actual = $security->checkToken('custom_key', $token);
        $I->assertTrue($actual);

        $session->destroy();

        $_POST = $store;
    }
}
