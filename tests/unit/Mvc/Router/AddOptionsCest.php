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
 * Class AddOptionsCest
 *
 * @package Phalcon\Test\Unit\Mvc\Router
 */
class AddOptionsCest
{
    /**
     * Tests Phalcon\Mvc\Router :: addOptions()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function mvcRouterAddOptions(UnitTester $I)
    {
        $I->wantToTest("Mvc\Router - addOptions()");
        $I->skipTest("Need implementation");
    }
}
