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

namespace Phalcon\Test\Unit\Flash\Session;

use UnitTester;

/**
 * Class SuccessCest
 */
class SuccessCest
{
    /**
     * Tests Phalcon\Flash\Session :: success()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function flashSessionSuccess(UnitTester $I)
    {
        $I->wantToTest('Flash\Session - success()');
        $I->skipTest('Need implementation');
    }
}
