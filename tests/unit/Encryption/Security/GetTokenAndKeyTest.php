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

final class GetTokenAndKeyTest extends AbstractUnitTestCase
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
    public function testEncryptionSecurityGetToken(): void
    {
        /** @var Manager $session */
        $session = $this->container->getShared('session');

        $session->start();

        $security = new Security();
        $security->setDI($this->container);

        // Random token and token key check
        $tokenKey = $security->getTokenKey();
        $token    = $security->getToken();

        $this->assertSame($tokenKey, $security->getTokenKey());
        $this->assertSame($token, $security->getToken());
        $this->assertSame($token, $security->getSessionToken());

        $security->destroyToken();

        $this->assertNotEquals($tokenKey, $security->getTokenKey());
        $this->assertNotEquals($token, $security->getToken());
        $this->assertNotEquals($token, $security->getSessionToken());

        $security->destroyToken();

        $session->destroy();
    }
}
