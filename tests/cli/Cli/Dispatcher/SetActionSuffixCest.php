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

/**
 * Class SetActionSuffixCest
 */
class SetActionSuffixCest
{
    /**
     * Tests Phalcon\Cli\Dispatcher :: setActionSuffix()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function cliDispatcherSetActionSuffix(CliTester $I)
    {
        $I->wantToTest('Cli\Dispatcher - setActionSuffix()');
        $I->skipTest('Need implementation');
    }
}
