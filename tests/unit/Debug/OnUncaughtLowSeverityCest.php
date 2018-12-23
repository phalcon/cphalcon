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

namespace Phalcon\Test\Unit\Debug;

use UnitTester;

/**
 * Class OnUncaughtLowSeverityCest
 */
class OnUncaughtLowSeverityCest
{
    /**
     * Tests Phalcon\Debug :: onUncaughtLowSeverity()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function debugOnUncaughtLowSeverity(UnitTester $I)
    {
        $I->wantToTest('Debug - onUncaughtLowSeverity()');
        $I->skipTest('Need implementation');
    }
}
