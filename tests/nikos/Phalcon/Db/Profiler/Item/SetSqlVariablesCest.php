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

namespace Phalcon\Test\Unit\Db\Profiler\Item;

use UnitTester;

/**
 * Class SetSqlVariablesCest
 */
class SetSqlVariablesCest
{
    /**
     * Tests Phalcon\Db\Profiler\Item :: setSqlVariables()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function dbProfilerItemSetSqlVariables(UnitTester $I)
    {
        $I->wantToTest('Db\Profiler\Item - setSqlVariables()');
        $I->skipTest('Need implementation');
    }
}
