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

namespace Phalcon\Test\Cli\Cli\Dispatcher;

use CliTester;

/**
 * Class SetReturnedValueCest
 */
class SetReturnedValueCest
{
    /**
     * Tests Phalcon\Cli\Dispatcher :: setReturnedValue()
     *
     * @param CliTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function cliDispatcherSetReturnedValue(CliTester $I)
    {
        $I->wantToTest('Cli\Dispatcher - setReturnedValue()');
        $I->skipTest('Need implementation');
    }
}
