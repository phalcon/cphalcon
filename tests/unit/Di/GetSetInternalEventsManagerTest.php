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
use Phalcon\Events\Manager;
use Phalcon\Events\ManagerInterface;
use Phalcon\Html\Escaper;
use Phalcon\Tests\AbstractUnitTestCase;

final class GetSetInternalEventsManagerTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2024-01-01
     */
    public function testDiEventsManagerFiringOnGet(): void
    {
        $container     = new Di();
        $eventsManager = new Manager();

        // The afterServiceResolve listener must forward the resolved instance so
        // that Di::get() returns it unchanged.
        $eventsManager->attach(
            'di:afterServiceResolve',
            function ($event, $source, $data) {
                return $data['instance'];
            }
        );

        $container->setInternalEventsManager($eventsManager);
        $container->set('escaper', Escaper::class);

        $instance = $container->get('escaper');

        $class = Escaper::class;
        $this->assertInstanceOf($class, $instance);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-09-09
     */
    public function testDiGetSetInternalEventsManager(): void
    {
        $container = new Di();

        $actual = $container->getInternalEventsManager();
        $this->assertNull($actual);

        $container->setInternalEventsManager(new Manager());

        $class  = ManagerInterface::class;
        $actual = $container->getInternalEventsManager();
        $this->assertInstanceOf($class, $actual);
    }
}
