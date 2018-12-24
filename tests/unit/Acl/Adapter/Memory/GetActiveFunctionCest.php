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

use UnitTester;

/**
 * Class GetActiveFunctionCest
 */
class GetActiveFunctionCest
{
    /**
     * Tests Phalcon\Acl\Adapter\Memory :: getActiveFunction()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function aclAdapterMemoryGetActiveFunction(UnitTester $I)
    {
        $I->wantToTest('Acl\Adapter\Memory - getActiveFunction()');
        $I->skipTest('Need implementation');
    }
}
