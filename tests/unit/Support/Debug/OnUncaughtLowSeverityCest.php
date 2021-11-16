<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Support\Debug;

use UnitTester;

/**
 * Class OnUncaughtLowSeverityCest
 *
 * @package Phalcon\Tests\Unit\Support\Debug
 */
class OnUncaughtLowSeverityCest
{
    /**
     * Tests Phalcon\Debug :: onUncaughtLowSeverity()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function supportDebugOnUncaughtLowSeverity(UnitTester $I)
    {
        $I->wantToTest('Debug - onUncaughtLowSeverity()');

        $I->skipTest('Need implementation');
    }
}
