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

namespace Phalcon\Test\Unit\Mvc\Dispatcher;

use UnitTester;

/**
 * Class GetModuleNameCest
 */
class GetModuleNameCest
{
    /**
     * Tests Phalcon\Mvc\Dispatcher :: getModuleName()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function mvcDispatcherGetModuleName(UnitTester $I)
    {
        $I->wantToTest('Mvc\Dispatcher - getModuleName()');
        $I->skipTest('Need implementation');
    }
}
