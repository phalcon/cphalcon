<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Di;

use Phalcon\Di;
use Phalcon\Events\Manager;
use Phalcon\Events\ManagerInterface;
use UnitTester;

class SetInternalEventsManagerCest
{
    /**
     * Unit Tests Phalcon\Di :: setInternalEventsManager()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-06-13
     */
    public function diSetInternalEventsManager(UnitTester $I)
    {
        $I->wantToTest('Di - setInternalEventsManager()');

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
