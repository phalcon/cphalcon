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

class GetActionSuffixCest
{
    /**
     * Tests Phalcon\Mvc\Dispatcher :: getActionSuffix()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-07
     */
    public function mvcDispatcherGetActionSuffix(UnitTester $I)
    {
        $I->wantToTest('Mvc\Dispatcher - getActionSuffix()');

        $I->skipTest('Need implementation');
    }
}
