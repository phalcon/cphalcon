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

use Phalcon\Flash\Exception;
use Phalcon\Flash\FlashInterface;
use Phalcon\Flash\Session;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Support\Traits\DiTrait;

final class ConstructTest extends AbstractUnitTestCase
{
    use DiTrait;

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testFlashSessionConstruct(): void
    {
        $flash = new Session();
        $this->assertInstanceOf(FlashInterface::class, $flash);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testFlashSessionConstructNoSessionService(): void
    {
        $this->setNewFactoryDefault();
        $this->setDiService('sessionStream');

        $this->expectException(Exception::class);
        $this->expectExceptionMessage(
            'A dependency injection container is required to ' .
            "access the 'session' service"
        );

        $flash = new Session();
        $flash->getMessages();
    }
}
