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

namespace Phalcon\Tests\Cli\Cli\Dispatcher;

use CliTester;
use Phalcon\Cli\Dispatcher;

/**
 * Class GetSetNamespaceNameCest
 */
class GetSetNamespaceNameCest
{
    /**
     * Tests Phalcon\Cli\Dispatcher - getNamespaceName() / setNamespaceName()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function cliDispatcherGetSetNamespaceName(CliTester $I)
    {
        $I->wantToTest('Cli\Dispatcher - getNamespaceName() / setNamespaceName()');

        $dispatcher = new Dispatcher();
        $I->assertNull($dispatcher->getNamespaceName());

        $namespace = "Phalcon";
        $dispatcher->setNamespaceName($namespace);
        $I->assertEquals($namespace, $dispatcher->getNamespaceName());
    }
}
