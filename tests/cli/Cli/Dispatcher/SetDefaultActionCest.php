<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Test\Cli\Cli\Dispatcher;

use CliTester;

class SetDefaultActionCest
{
    /**
     * Tests Phalcon\Cli\Dispatcher :: setDefaultAction()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function cliDispatcherSetDefaultAction(CliTester $I)
    {
        $I->wantToTest('Cli\Dispatcher - setDefaultAction()');
        $I->skipTest('Need implementation');
    }
}
