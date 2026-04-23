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

namespace Phalcon\Tests\Unit\Flash\Session;

use Phalcon\Flash\Session;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Support\Traits\DiTrait;

use function uniqid;

final class GetMessagesTest extends AbstractUnitTestCase
{
    use DiTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDiService('sessionStream');
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testFlashSessionGetMessages(): void
    {
        $session = $this->container->getShared('session');
        $session->start();

        $flash = new Session();
        $flash->setDI($this->container);

        $message1 = uniqid('m-');
        $message2 = uniqid('m-');
        $flash->success($message1);
        $flash->error($message2);

        $expected = [
            'success' => [$message1],
            'error'   => [$message2],
        ];
        $actual   = $flash->getMessages();
        $this->assertSame($expected, $actual);

        $message1 = uniqid('m-');
        $message2 = uniqid('m-');
        $message3 = uniqid('m-');
        $flash->success($message1);
        $flash->error($message2);
        $flash->warning($message3);

        $expected = [$message1];
        $actual   = $flash->getMessages('success', false);
        $this->assertSame($expected, $actual);

        $expected = [$message2];
        $actual   = $flash->getMessages('error', false);
        $this->assertSame($expected, $actual);

        $expected = [$message3];
        $actual   = $flash->getMessages('warning', true);
        $this->assertSame($expected, $actual);

        $expected = [
            'success' => [$message1],
            'error'   => [$message2],
        ];
        $actual   = $flash->getMessages();
        $this->assertSame($expected, $actual);

        $session->destroy();
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2024-01-01
     */
    public function testFlashSessionGetMessagesNonExistentTypeReturnsEmpty(): void
    {
        $session = $this->container->getShared('session');
        $session->start();

        $flash = new Session();
        $flash->setDI($this->container);
        $flash->success('some message');

        // Request a type that has no messages
        $actual = $flash->getMessages('error');
        $this->assertSame([], $actual);

        $session->destroy();
    }
}
