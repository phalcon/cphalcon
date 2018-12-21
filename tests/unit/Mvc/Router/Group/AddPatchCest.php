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

namespace Phalcon\Test\Unit\Mvc\Router\Group;

use UnitTester;

/**
 * Class AddPatchCest
 *
 * @package Phalcon\Test\Unit\Mvc\Router\Group
 */
class AddPatchCest
{
    /**
     * Tests Phalcon\Mvc\Router\Group :: addPatch()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function mvcRouterGroupAddPatch(UnitTester $I)
    {
        $I->wantToTest("Mvc\Router\Group - addPatch()");
        $I->skipTest("Need implementation");
    }
}
