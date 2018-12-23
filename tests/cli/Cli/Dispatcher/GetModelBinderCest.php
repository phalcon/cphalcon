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
 * Class GetModelBinderCest
 */
class GetModelBinderCest
{
    /**
     * Tests Phalcon\Cli\Dispatcher :: getModelBinder()
     *
     * @param CliTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function cliDispatcherGetModelBinder(CliTester $I)
    {
        $I->wantToTest('Cli\Dispatcher - getModelBinder()');
        $I->skipTest('Need implementation');
    }
}
