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

namespace Phalcon\Test\Unit\Di\Service;

use UnitTester;

class IsResolvedCest
{
    /**
     * Unit Tests Phalcon\Di\Service :: isResolved()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-06-13
     */
    public function diServiceIsResolved(UnitTester $I)
    {
        $I->wantToTest('Di\Service - isResolved()');

        $I->skipTest('Need implementation');
    }
}
