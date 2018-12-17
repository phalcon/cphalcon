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
 * Class GetNameCest
 */
class GetNameCest
{
    /**
     * Tests Phalcon\Acl\Operation :: getName()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function aclOperationGetName(UnitTester $I)
    {
        $I->wantToTest('Acl\Operation - getName()');
        $operation = new Operation('Administrators');

        $expected = 'Administrators';
        $actual   = $operation->getName();
        $I->assertEquals($expected, $actual);
    }
}
