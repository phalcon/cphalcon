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

namespace Phalcon\Test\Unit\Acl\Operation;

use Phalcon\Acl\Operation;
use UnitTester;

/**
 * Class ToStringCest
 */
class ToStringCest
{
    /**
     * Tests Phalcon\Acl\Operation :: __toString()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function aclOperationToString(UnitTester $I)
    {
        $I->wantToTest('Acl\Operation - __toString()');
        $operation = new Operation('Administrator');

        $expected = 'Administrator';
        $actual   = $operation->__toString();
        $I->assertEquals($expected, $actual);

        $expected = 'Administrator';
        $actual   = (string) $operation;
        $I->assertEquals($expected, $actual);
    }
}
