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

namespace Phalcon\Test\Unit\Di;

use Phalcon\Di;
use Phalcon\Events\Manager;
use Phalcon\Events\ManagerInterface;
use UnitTester;

class GetInternalEventsManagerCest
{
    /**
     * Unit Tests Phalcon\Di :: getInternalEventsManager()
     *
     * @param  UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-06-13
     */
    public function diGetInternalEventsManager(UnitTester $I)
    {
        $I->wantToTest('Di - getInternalEventsManager()');

        $di = new Di();

        $I->assertNull(
            $di->getInternalEventsManager()
        );

        $di->setInternalEventsManager(new Manager());

        $I->assertInstanceOf(
            ManagerInterface::class,
            $di->getInternalEventsManager()
        );
    }
}
