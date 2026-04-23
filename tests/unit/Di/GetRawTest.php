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

namespace Phalcon\Tests\Unit\Di;

use Exception;
use Phalcon\Di\Di;
use Phalcon\Html\Escaper;
use Phalcon\Tests\AbstractUnitTestCase;

final class GetRawTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-09-09
     */
    public function testDiGetRaw(): void
    {
        $container = new Di();

        // existing service
        $container->set('escaper', Escaper::class);

        $expected = Escaper::class;
        $actual   = $container->getRaw('escaper');

        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-09-09
     */
    public function testDiGetRawException(): void
    {
        $container = new Di();

        // nonexistent service
        $this->expectException(Exception::class);
        $this->expectExceptionMessage(
            "Service 'nonexistent-service' is not registered in the container"
        );

        $container->getRaw('nonexistent-service');
    }
}
