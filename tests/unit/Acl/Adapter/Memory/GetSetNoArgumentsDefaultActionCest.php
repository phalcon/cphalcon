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
use Phalcon\Acl\Enum;
use UnitTester;

/**
 * Class GetSetNoArgumentsDefaultActionCest
 *
 * @package Phalcon\Tests\Unit\Acl\Adapter\Memory
 */
class GetSetNoArgumentsDefaultActionCest
{
    /**
     * Tests Phalcon\Acl\Adapter\Memory ::
     * getNoArgumentsDefaultAction()/setNoArgumentsDefaultAction()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function aclAdapterMemoryGetSetNoArgumentsDefaultAction(UnitTester $I)
    {
        $I->wantToTest(
            'Acl\Adapter\Memory - getNoArgumentsDefaultAction()/setNoArgumentsDefaultAction()'
        );

        $acl = new Memory();
        $acl->setNoArgumentsDefaultAction(Enum::ALLOW);

        $expected = Enum::ALLOW;
        $actual   = $acl->getNoArgumentsDefaultAction();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Acl\Adapter\Memory ::
     * getNoArgumentsDefaultAction()/setNoArgumentsDefaultAction() - default
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function aclAdapterMemoryGetSetNoArgumentsDefaultActionDefault(UnitTester $I)
    {
        $I->wantToTest(
            'Acl\Adapter\Memory - getNoArgumentsDefaultAction()/setNoArgumentsDefaultAction() - default'
        );

        $acl = new Memory();

        $expected = Enum::DENY;
        $actual   = $acl->getNoArgumentsDefaultAction();
        $I->assertEquals($expected, $actual);
    }
}
