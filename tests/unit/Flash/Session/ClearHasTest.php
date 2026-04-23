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

final class ClearHasTest extends AbstractUnitTestCase
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
    public function testFlashSessionClearHas(): void
    {
        $session = $this->container->getShared('session');
        $session->start();

        $flash = new Session();
        $flash->setDI($this->container);

        $message1 = uniqid('m-');
        $message2 = uniqid('m-');
        $flash->success($message1);
        $flash->error($message2);

        $actual = $flash->has();
        $this->assertTrue($actual);

        $actual = $flash->has('success');
        $this->assertTrue($actual);

        $actual = $flash->has('error');
        $this->assertTrue($actual);

        $actual = $flash->has('warning');
        $this->assertFalse($actual);

        $actual = $flash->has('notice');
        $this->assertFalse($actual);

        $expected = [$message1];
        $actual   = $flash->getMessages('success', false);
        $this->assertSame($expected, $actual);

        $expected = [$message2];
        $actual   = $flash->getMessages('error', false);
        $this->assertSame($expected, $actual);

        $flash->clear();

        $actual = $flash->getMessages();
        $this->assertEmpty($actual);

        $session->destroy();
    }
}
