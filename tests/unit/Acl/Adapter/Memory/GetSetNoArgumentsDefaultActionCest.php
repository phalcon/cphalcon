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

namespace Phalcon\Test\Unit\Acl\Adapter\Memory;

use Phalcon\Acl;
use Phalcon\Acl\Adapter\Memory;
use UnitTester;

/**
 * Class GetNoArgumentsDefaultActionCest
 */
class GetSetNoArgumentsDefaultActionCest
{
    /**
     * Tests Phalcon\Acl\Adapter\Memory :: getNoArgumentsDefaultAction()/setNoArgumentsDefaultAction()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function aclAdapterMemoryGetSetNoArgumentsDefaultAction(UnitTester $I)
    {
        $I->wantToTest('Acl\Adapter\Memory - getNoArgumentsDefaultAction()/setNoArgumentsDefaultAction()');
        $acl = new Memory();

        $acl->setNoArgumentsDefaultAction(Acl::ALLOW);

        $expected = Acl::ALLOW;
        $actual   = $acl->getNoArgumentsDefaultAction();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Acl\Adapter\Memory :: getNoArgumentsDefaultAction()/setNoArgumentsDefaultAction() - default
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function aclAdapterMemoryGetSetNoArgumentsDefaultActionDefault(UnitTester $I)
    {
        $I->wantToTest('Acl\Adapter\Memory - getNoArgumentsDefaultAction()/setNoArgumentsDefaultAction() - default');
        $acl = new Memory();

        $expected = Acl::DENY;
        $actual   = $acl->getNoArgumentsDefaultAction();
        $I->assertEquals($expected, $actual);
    }
}
