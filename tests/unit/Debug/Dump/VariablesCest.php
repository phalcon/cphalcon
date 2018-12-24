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

namespace Phalcon\Test\Unit\Debug\Dump;

use UnitTester;

/**
 * Class VariablesCest
 */
class VariablesCest
{
    /**
     * Tests Phalcon\Debug\Dump :: variables()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function debugDumpVariables(UnitTester $I)
    {
        $I->wantToTest('Debug\Dump - variables()');
        $I->skipTest('Need implementation');
    }
}
