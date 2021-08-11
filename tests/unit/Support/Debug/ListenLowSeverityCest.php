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

namespace Phalcon\Test\Unit\Support\Debug;

use UnitTester;

class ListenLowSeverityCest
{
    /**
     * Tests Phalcon\Debug :: listenLowSeverity()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function supportDebugListenLowSeverity(UnitTester $I)
    {
        $I->wantToTest('Debug - listenLowSeverity()');

        $I->skipTest('Need implementation');
    }
}
