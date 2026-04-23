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

use Phalcon\Di\FactoryDefault\Cli as Di;
use Phalcon\Events\Manager;
use Phalcon\Events\ManagerInterface;
use Phalcon\Tests\AbstractUnitTestCase;

final class GetInternalEventsManagerTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testDiFactorydefaultCliGetInternalEventsManager(): void
    {
        $di = new Di();

        $actual = $di->getInternalEventsManager();
        $this->assertNull($actual);

        $di->setInternalEventsManager(new Manager());

        $class  = ManagerInterface::class;
        $actual = $di->getInternalEventsManager();
        $this->assertInstanceOf($class, $actual);
    }
}
