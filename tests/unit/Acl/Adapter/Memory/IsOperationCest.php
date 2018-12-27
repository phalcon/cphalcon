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

use Phalcon\Acl\Adapter\Memory;
use Phalcon\Acl\Operation;
use UnitTester;

/**
 * Class IsOperationCest
 */
class IsOperationCest
{
    /**
     * Tests Phalcon\Acl\Adapter\Memory :: isOperation()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function aclAdapterMemoryIsOperation(UnitTester $I)
    {
        $I->wantToTest('Acl\Adapter\Memory - isOperation()');
        $acl          = new Memory();
        $aclOperation = new Operation('Administrators', 'Super User access');

        $acl->addOperation($aclOperation);

        $actual = $acl->isOperation('Administrators');
        $I->assertTrue($actual);
    }

    /**
     * Tests Phalcon\Acl\Adapter\Memory :: isOperation() - unknown
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function aclAdapterMemoryIsOperationUnknown(UnitTester $I)
    {
        $I->wantToTest('Acl\Adapter\Memory - isOperation() - unknown');
        $acl          = new Memory();
        $aclOperation = new Operation('Administrators', 'Super User access');

        $acl->addOperation($aclOperation);

        $actual = $acl->isOperation('unknown');
        $I->assertFalse($actual);
    }
}
