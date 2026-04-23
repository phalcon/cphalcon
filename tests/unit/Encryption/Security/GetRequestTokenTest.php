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
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Support\Traits\DiTrait;

final class GetRequestTokenTest extends AbstractUnitTestCase
{
    use DiTrait;

    /**
     * @var array
     */
    protected array $store = [];

    /**
     * executed before each test
     */
    public function setUp(): void
    {
        $this->checkExtensionIsLoaded('openssl');

        $this->store = $_SESSION ?? [];

        $this->setNewFactoryDefault();
        $this->setDiService('sessionStream');
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testEncryptionSecurityGetRequestTokenAndGetSessionToken(): void
    {
        $this->markTestSkipped('TODO: Enable when Request is done');

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

        $this->assertSame($sessionToken, $requestToken);
        $this->assertNotEquals($token, $sessionToken);
        $this->assertSame($requestToken, $security->getRequestToken());
        $this->assertNotEquals($token, $security->getRequestToken());

        $_POST = [
            $tokenKey => $requestToken,
        ];

        $actual = $security->checkToken(null, null, false);
        $this->assertTrue($actual);


        $_POST = [
            $tokenKey => $token,
        ];

        $actual = $security->checkToken(null, null, false);
        $this->assertFalse($actual);

        $actual = $security->checkToken();
        $this->assertFalse($actual);


        $security->destroyToken();

        $this->assertNotEquals($requestToken, $security->getRequestToken());

        $session->destroy();

        $_POST = $store;
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testEncryptionSecurityGetTokensWithoutSessionInitialization(): void
    {
        /** @var Manager $session */
        $session = $this->container->getShared('session');

        $session->start();

        $security = new Security();
        $security->setDI($this->container);

        $this->assertNull($security->getSessionToken());
        $this->assertNull($security->getRequestToken());

        $session->destroy();
    }
}
