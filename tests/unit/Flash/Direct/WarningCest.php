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

namespace Phalcon\Test\Unit\Flash\Direct;

use UnitTester;

class WarningCest
{
    /**
     * Tests Phalcon\Flash\Direct :: warning()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function flashDirectWarning(UnitTester $I)
    {
        $I->wantToTest('Flash\Direct - warning()');

        $I->skipTest('Need implementation');
    }
}
