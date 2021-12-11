<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the
 * LICENSE.txt file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Di;

use Phalcon\Di\Di;
use Phalcon\Events\Manager;
use Phalcon\Events\ManagerInterface;
use UnitTester;

/**
 * Class GetSetInternalEventsManagerCest
 *
 * @package Phalcon\Tests\Unit\Di
 */
class GetSetInternalEventsManagerCest
{
    /**
     * Unit Tests Phalcon\Di :: getInternalEventsManager()/setInternalEventsManager()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-09-09
     */
    public function diGetSetInternalEventsManager(UnitTester $I)
    {
        $I->wantToTest('Di - getInternalEventsManager()/setInternalEventsManager()');

        $container = new Di();

        $actual = $container->getInternalEventsManager();
        $I->assertNull($actual);

        $container->setInternalEventsManager(new Manager());

        $class  = ManagerInterface::class;
        $actual = $container->getInternalEventsManager();
        $I->assertInstanceOf($class, $actual);
    }
}
