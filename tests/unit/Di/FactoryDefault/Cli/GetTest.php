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
use Phalcon\Di\Service;
use Phalcon\Html\Escaper;
use Phalcon\Tests\AbstractUnitTestCase;

final class GetTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testDiFactorydefaultCliGet(): void
    {
        // setup
        $di = new Di();

        // set a service and get it to check
        $actual = $di->set('escaper', Escaper::class);

        $this->assertInstanceOf(Service::class, $actual);
        $this->assertFalse($actual->isShared());

        // get escaper service
        $actual   = $di->get('escaper');
        $expected = new Escaper();

        $this->assertInstanceOf(Escaper::class, $actual);
        $this->assertEquals($expected, $actual);

        // non exists service
        $this->expectException(Exception::class);
        $this->expectExceptionMessage(
            "Service 'non-exists' is not registered in the container"
        );

        $di->get('non-exists');
    }
}
