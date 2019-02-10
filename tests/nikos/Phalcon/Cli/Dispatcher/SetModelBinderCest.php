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

namespace Phalcon\Test\Unit\Cli\Dispatcher;

use UnitTester;

/**
 * Class SetModelBinderCest
 */
class SetModelBinderCest
{
    /**
     * Tests Phalcon\Cli\Dispatcher :: setModelBinder()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function cliDispatcherSetModelBinder(UnitTester $I)
    {
        $I->wantToTest('Cli\Dispatcher - setModelBinder()');
        $I->skipTest('Need implementation');
    }
}
