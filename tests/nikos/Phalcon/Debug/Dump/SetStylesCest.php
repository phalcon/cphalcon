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
 * Class SetStylesCest
 */
class SetStylesCest
{
    /**
     * Tests Phalcon\Debug\Dump :: setStyles()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function debugDumpSetStyles(UnitTester $I)
    {
        $I->wantToTest('Debug\Dump - setStyles()');
        $I->skipTest('Need implementation');
    }
}
