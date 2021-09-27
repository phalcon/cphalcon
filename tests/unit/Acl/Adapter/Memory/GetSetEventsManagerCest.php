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

namespace Phalcon\Tests\Unit\Acl\Adapter\Memory;

use Phalcon\Acl\Adapter\Memory;
use Phalcon\Events\Manager;
use UnitTester;

/**
 * Class GetSetEventsManagerCest
 *
 * @package Phalcon\Tests\Unit\Acl\Adapter\Memory
 */
class GetSetEventsManagerCest
{
    /**
     * Tests Phalcon\Acl\Adapter\Memory :: getEventsManager()/setEventsManager()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function aclAdapterMemoryGetSetEventsManager(UnitTester $I)
    {
        $I->wantToTest('Acl\Adapter\Memory - getEventsManager()/setEventsManager()');

        $acl     = new Memory();
        $manager = new Manager();

        $acl->setEventsManager($manager);

        $actual = $acl->getEventsManager();
        $I->assertInstanceOf(Manager::class, $actual);
        $I->assertEquals($manager, $actual);
    }
}
