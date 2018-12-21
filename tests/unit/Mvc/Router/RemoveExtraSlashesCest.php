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
 * Class RemoveExtraSlashesCest
 *
 * @package Phalcon\Test\Unit\Mvc\Router
 */
class RemoveExtraSlashesCest
{
    /**
     * Tests Phalcon\Mvc\Router :: removeExtraSlashes()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function mvcRouterRemoveExtraSlashes(UnitTester $I)
    {
        $I->wantToTest("Mvc\Router - removeExtraSlashes()");
        $I->skipTest("Need implementation");
    }
}
