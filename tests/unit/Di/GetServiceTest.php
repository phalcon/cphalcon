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

use Phalcon\Di\Di;
use Phalcon\Di\Exception;
use Phalcon\Di\Service;
use Phalcon\Html\Escaper;
use Phalcon\Tests\AbstractUnitTestCase;

final class GetServiceTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-09-09
     */
    public function testDiGetService(): void
    {
        // setup
        $container = new Di();

        // set a service and get it to check
        $class  = Service::class;
        $actual = $container->set('escaper', Escaper::class);
        $this->assertInstanceOf($class, $actual);

        // get escaper service
        $escaper = $container->getService('escaper');
        $this->assertInstanceOf(Service::class, $escaper);

        $actual = $escaper->isShared();
        $this->assertFalse($actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-09-09
     */
    public function testDiGetServiceException(): void
    {
        // setup
        $container = new Di();

        // non exists service
        $this->expectException(Exception::class);
        $this->expectExceptionMessage(
            "Service 'non-exists' is not registered in the " .
            "container"
        );

        $container->getService('non-exists');
    }
}
