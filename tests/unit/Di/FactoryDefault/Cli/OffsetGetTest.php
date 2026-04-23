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

final class OffsetGetTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testDiFactorydefaultCliOffsetGet(): void
    {
        $di = new Di();

        $di->set('escaper', Escaper::class);
        $this->assertInstanceOf(Escaper::class, $di->offsetGet('escaper'));

        $this->expectException(Exception::class);
        $this->expectExceptionMessage(
            "Service 'non-exists' is not registered in the container"
        );

        $di->offsetGet('non-exists');
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testDiFactorydefaultCliOffsetGetArray(): void
    {
        $di = new Di();

        $di->set('escaper', Escaper::class);
        $this->assertInstanceOf(Escaper::class, $di['escaper']);

        $this->expectException(Exception::class);
        $this->expectExceptionMessage(
            "Service 'non-exists' is not registered in the container"
        );

        $di['non-exists'];
    }
}
