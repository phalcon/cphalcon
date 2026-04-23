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

namespace Phalcon\Tests\Unit\Application;

use Phalcon\Di\FactoryDefault;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Unit\Application\Fake\FakeApplication;

final class GetSetDITest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testApplicationGetSetDiConstruct(): void
    {
        $container   = new FactoryDefault();
        $application = new FakeApplication($container);

        $expected = $container;
        $actual   = $application->getDI();
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testApplicationGetSetDi(): void
    {
        $container   = new FactoryDefault();
        $application = new FakeApplication();

        $application->setDI($container);

        $expected = $container;
        $actual   = $application->getDI();
        $this->assertSame($expected, $actual);
    }
}
