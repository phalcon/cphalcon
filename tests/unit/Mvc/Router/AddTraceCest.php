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

namespace Phalcon\Test\Unit\Mvc\Router;

use UnitTester;

/**
 * Class AddTraceCest
 *
 * @package Phalcon\Test\Unit\Mvc\Router
 */
class AddTraceCest
{
    /**
     * Tests Phalcon\Mvc\Router :: addTrace()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function mvcRouterAddTrace(UnitTester $I)
    {
        $I->wantToTest("Mvc\Router - addTrace()");
        $I->skipTest("Need implementation");
    }
}
