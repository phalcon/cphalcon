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

namespace Phalcon\Test\Unit\Dispatcher;

use UnitTester;

/**
 * Class GetHandlerClassCest
 */
class GetHandlerClassCest
{
    /**
     * Tests Phalcon\Dispatcher :: getHandlerClass()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function dispatcherGetHandlerClass(UnitTester $I)
    {
        $I->wantToTest('Dispatcher - getHandlerClass()');
        $I->skipTest('Need implementation');
    }
}
