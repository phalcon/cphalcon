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

namespace Phalcon\Test\Cli\Cli\Router;

use CliTester;

class SetDefaultsCest
{
    /**
     * Tests Phalcon\Cli\Router :: setDefaults()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function cliRouterSetDefaults(CliTester $I)
    {
        $I->wantToTest('Cli\Router - setDefaults()');
        $I->skipTest('Need implementation');
    }
}
