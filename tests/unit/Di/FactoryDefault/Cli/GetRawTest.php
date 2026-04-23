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

namespace Phalcon\Tests\Unit\Di\FactoryDefault\Cli;

use Phalcon\Di\Exception;
use Phalcon\Di\FactoryDefault\Cli as Di;
use Phalcon\Html\Escaper;
use Phalcon\Tests\AbstractUnitTestCase;

final class GetRawTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testDiFactorydefaultCliGetRaw(): void
    {
        $di = new Di();

        // existing service
        $di->set('escaper', Escaper::class);

        $expected = Escaper::class;
        $actual   = $di->getRaw('escaper');
        $this->assertSame($expected, $actual);

        // nonexistent service
        $this->expectException(Exception::class);
        $this->expectExceptionMessage(
            "Service 'nonexistent-service' is not registered in the "
            . "container"
        );

        $di->getRaw('nonexistent-service');
    }
}
