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
 * Class GetActiveOperationCest
 */
class GetActiveOperationCest
{
    /**
     * Tests Phalcon\Acl\Adapter\Memory :: getActiveOperation() - default
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function aclAdapterMemoryGetActiveOperationDefault(UnitTester $I)
    {
        $I->wantToTest('Acl\Adapter\Memory - getActiveOperation() - default');
        $acl    = new Memory();
        $actual = $acl->getActiveOperation();
        $I->assertNull($actual);
    }

    /**
     * Tests Phalcon\Acl\Adapter\Memory :: getActiveOperation() - default
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function aclAdapterMemoryGetActiveOperation(UnitTester $I)
    {
        $I->wantToTest('Acl\Adapter\Memory - getActiveOperation()');
        $acl = new Memory();
        $acl->setDefaultAction(Acl::DENY);

        $acl->addOperation('Guests');
        $acl->addSubject('Login', ['help', 'index']);

        $acl->allow('Guests', 'Login', '*');
        $actual = $acl->isAllowed('Guests', 'Login', 'index');
        $I->assertTrue($actual);

        $expected = 'Guests';
        $actual   = $acl->getActiveOperation();
        $I->assertEquals($expected, $actual);
    }
}
