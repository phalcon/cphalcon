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

final class CheckTokenTest extends AbstractUnitTestCase
{
    use DiTrait;

    /**
     * executed before each test
     */
    public function setUp(): void
    {
        $this->checkExtensionIsLoaded('openssl');

        $this->setNewFactoryDefault();
        $this->setDiService('sessionStream');
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testEncryptionSecurityCheckToken(): void
    {
        $tokenSessionId      = '$PHALCON/CSRF/KEY$';
        $tokenValueSessionId = '$PHALCON/CSRF$';
        /** @var Manager $session */
        $session = $this->container->getShared('session');
        $session->start();

        /**
         * Just in case
         */
        if (true === $session->has($tokenSessionId)) {
            $session->remove($tokenSessionId);
        }
        if (true === $session->has($tokenValueSessionId)) {
            $session->remove($tokenValueSessionId);
        }

        $security = new Security();

        /**
         * No session - checkToken returns empty
         */
        $actual = $security->checkToken();
        $this->assertFalse($actual);

        $actual = $security->getTokenKey();
        $this->assertNull($actual);

        /**
         * Enable the Session
         */
        $security->setDI($this->container);

        // Random token and token key check
        $token = $security->getToken();

        $actual = $session->has($tokenValueSessionId);
        $this->assertTrue($actual);

        $expected = $token;
        $actual   = $session->get($tokenValueSessionId);
        $this->assertSame($expected, $actual);

        $session->destroy();
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testEncryptionSecurityCheckTokenWithRequest(): void
    {
        $this->markTestSkipped("TODO: Enable when Request is ready");

        $store = $_POST ?? [];
        $_POST = [];

        /** @var Manager $session */
        $session = $this->container->getShared('session');
        $session->start();

        $security = new Security();

        /**
         * No session - checkToken returns empty
         */
        $actual = $security->checkToken();
        $this->assertFalse($actual);

        $actual = $security->getTokenKey();
        $this->assertNull($actual);

        $actual = $security->getToken();
        $this->assertNull($actual);

        /**
         * Enable the Session
         */
        $security->setDI($this->container);

        // Random token and token key check
        $tokenKey = $security->getTokenKey();
        $token    = $security->getToken();

        $actual = $session->has('$PHALCON/CSRF/KEY$');
        $this->assertTrue($actual);

        $session->destroy();

        $_POST = [
            $tokenKey => $token,
        ];

        $actual = $security->checkToken(null, null, false);
        $this->assertTrue($actual);

        $actual = $security->checkToken();
        $this->assertTrue($actual);

        $actual = $security->checkToken();
        $this->assertFalse($actual);

        // Destroy token check
        $tokenKey = $security->getTokenKey();
        $token    = $security->getToken();

        $security->destroyToken();

        $_POST = [
            $tokenKey => $token,
        ];

        $actual = $security->checkToken();
        $this->assertFalse($actual);

        // Custom token key check
        $token = $security->getToken();

        $_POST = [
            'custom_key' => $token,
        ];

        $actual = $security->checkToken(null, null, false);
        $this->assertFalse($actual);

        $actual = $security->checkToken('other_custom_key', null, false);
        $this->assertFalse($actual);

        $actual = $security->checkToken('custom_key');
        $this->assertTrue($actual);

        // Custom token value check
        $token = $security->getToken();

        $_POST = [];

        $actual = $security->checkToken(null, null, false);
        $this->assertFalse($actual);

        $actual = $security->checkToken('some_random_key', 'some_random_value', false);
        $this->assertFalse($actual);

        $actual = $security->checkToken('custom_key', $token);
        $this->assertTrue($actual);

        $session->destroy();

        $_POST = $store;
    }
}
