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

namespace Phalcon\Tests\Unit\Flash\Direct;

use Phalcon\Di\Di;
use Phalcon\Flash\Direct;
use Phalcon\Flash\Exception;
use Phalcon\Html\Escaper;
use Phalcon\Tests\AbstractUnitTestCase;

use function spl_object_hash;

final class GetSetEscaperServiceTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testFlashDirectGetEscaperServiceException(): void
    {
        $this->expectException(Exception::class);
        $this->expectExceptionMessage(
            'A dependency injection container is required to access the ' .
            '\'escaper\' service'
        );

        $flash = new Direct();
        $flash->getEscaperService();
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testFlashDirectGetSetEscaperService(): void
    {
        $escaper = new Escaper();
        $flash   = new Direct($escaper);

        $actual = $flash->getEscaperService();
        $this->assertSame(spl_object_hash($escaper), spl_object_hash($actual));

        $newEscaper = new Escaper();
        $actual     = $flash->setEscaperService($newEscaper);
        $this->assertInstanceOf(Direct::class, $actual);

        $actual = $flash->getEscaperService();
        $this->assertSame(spl_object_hash($newEscaper), spl_object_hash($actual));
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testFlashDirectGetSetEscaperServiceContainer(): void
    {
        $container = new Di();
        $escaper   = new Escaper();
        $container->setShared('escaper', $escaper);
        $flash = new Direct();
        $flash->setDI($container);

        $actual = $flash->getEscaperService();
        $this->assertSame(spl_object_hash($escaper), spl_object_hash($actual));
    }
}
