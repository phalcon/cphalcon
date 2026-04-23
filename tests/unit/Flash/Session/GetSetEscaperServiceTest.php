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
use Phalcon\Flash\Session;
use Phalcon\Html\Escaper;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Support\Traits\DiTrait;

use function spl_object_hash;

final class GetSetEscaperServiceTest extends AbstractUnitTestCase
{
    use DiTrait;

    public function setUp(): void
    {
        $this->newDi();
        $this->setDiService('sessionStream');
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testFlashSessionGetEscaperServiceException(): void
    {
        $this->expectException(Exception::class);
        $this->expectExceptionMessage(
            "A dependency injection container is required to " .
            "access the 'escaper' service"
        );

        $flash = new Session();
        $flash->getEscaperService();
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testFlashSessionGetSetEscaperService(): void
    {
        $session = $this->container->getShared('session');
        $session->start();

        $escaper = new Escaper();
        $flash   = new Session($escaper);

        $actual = $flash->getEscaperService();
        $this->assertSame(spl_object_hash($escaper), spl_object_hash($actual));

        $newEscaper = new Escaper();
        $actual     = $flash->setEscaperService($newEscaper);
        $this->assertInstanceOf(Session::class, $actual);

        $actual = $flash->getEscaperService();
        $this->assertSame(spl_object_hash($newEscaper), spl_object_hash($actual));

        $session->destroy();
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testFlashSessionGetSetEscaperServiceContainer(): void
    {
        $escaper = new Escaper();
        $this->container->setShared('escaper', $escaper);

        $flash = new Session();
        $flash->setDI($this->container);

        $actual = $flash->getEscaperService();
        $this->assertSame(spl_object_hash($escaper), spl_object_hash($actual));
    }
}
