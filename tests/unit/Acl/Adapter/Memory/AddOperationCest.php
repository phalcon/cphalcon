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
 * Class AddOperationCest
 */
class AddOperationCest
{
    /**
     * Tests Phalcon\Acl\Adapter\Memory :: addOperation() - string
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function aclAdapterMemoryAddOperationString(UnitTester $I)
    {
        $I->wantToTest('Acl\Adapter\Memory - addOperation() - string');
        $acl       = new Memory();
        $operation = new Operation('Administrators', 'Super User access');

        $actual = $acl->addOperation('Administrators');
        $I->assertTrue($actual);
    }

    /**
     * Tests Phalcon\Acl\Adapter\Memory :: addOperation() - object
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function aclAdapterMemoryAddOperationObject(UnitTester $I)
    {
        $I->wantToTest('Acl\Adapter\Memory - addOperation() - object');
        $acl       = new Memory();
        $operation = new Operation('Administrators', 'Super User access');

        $actual = $acl->addOperation($operation);
        $I->assertTrue($actual);
    }

    /**
     * Tests Phalcon\Acl\Adapter\Memory :: addOperation() - twice string
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function aclAdapterMemoryAddOperationTwiceString(UnitTester $I)
    {
        $I->wantToTest('Acl\Adapter\Memory - addOperation() - twice string');
        $acl       = new Memory();
        $operation = new Operation('Administrators', 'Super User access');

        $actual = $acl->addOperation('Administrators');
        $I->assertTrue($actual);
        $actual = $acl->addOperation('Administrators');
        $I->assertFalse($actual);
    }

    /**
     * Tests Phalcon\Acl\Adapter\Memory :: addOperation() - twice object
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function aclAdapterMemoryAddOperationTwiceObject(UnitTester $I)
    {
        $I->wantToTest('Acl\Adapter\Memory - addOperation() - twice object');
        $acl       = new Memory();
        $operation = new Operation('Administrators', 'Super User access');

        $actual = $acl->addOperation($operation);
        $I->assertTrue($actual);
        $actual = $acl->addOperation($operation);
        $I->assertFalse($actual);
    }

    /**
     * Tests Phalcon\Acl\Adapter\Memory :: addOperation() - numeric key
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function aclAdapterMemoryAddOperationNumericKey(UnitTester $I)
    {
        $I->wantToTest('Acl\Adapter\Memory - addOperation() - numeric key');
        $acl       = new Memory();
        $operation = new Operation('11', 'Super User access');

        $actual = $acl->addOperation('11');
        $I->assertTrue($actual);
        $actual = $acl->isOperation('11');
        $I->assertTrue($actual);
    }
}
