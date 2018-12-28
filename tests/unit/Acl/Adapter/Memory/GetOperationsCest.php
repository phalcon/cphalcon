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
 * Class GetOperationsCest
 */
class GetOperationsCest
{
    /**
     * Tests Phalcon\Acl\Adapter\Memory :: getOperations()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function aclAdapterMemoryGetOperations(UnitTester $I)
    {
        $I->wantToTest('Acl\Adapter\Memory - getOperations()');
        $acl = new Memory();

        $operation1 = new Operation('Admin');
        $operation2 = new Operation('Guest');

        $acl->addOperation($operation1);
        $acl->addOperation($operation2);

        $expected = [$operation1, $operation2];
        $actual   = $acl->getOperations();
        $I->assertEquals($expected, $actual);
    }
}
