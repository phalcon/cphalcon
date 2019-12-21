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

namespace Phalcon\Test\Unit\Dispatcher;

use UnitTester;

class GetDICest
{
    /**
     * Tests Phalcon\Dispatcher :: getDI()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function dispatcherGetDI(UnitTester $I)
    {
        $I->wantToTest('Dispatcher - getDI()');

        $I->skipTest('Need implementation');
    }
}
