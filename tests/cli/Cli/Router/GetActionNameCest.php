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

class GetActionNameCest
{
    /**
     * Tests Phalcon\Cli\Router :: getActionName()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function cliRouterGetActionName(CliTester $I)
    {
        $I->wantToTest('Cli\Router - getActionName()');
        $I->skipTest('Need implementation');
    }
}
