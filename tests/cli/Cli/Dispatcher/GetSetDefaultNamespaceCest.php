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
use Phalcon\Cli\Dispatcher;

class GetSetDefaultNamespaceCest
{
    /**
     * Tests Phalcon\Cli\Dispatcher :: getDefaultNamespace() / setDefaultNamespace()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function cliDispatcherGetSetDefaultNamespace(CliTester $I)
    {
        $I->wantToTest('Cli\Dispatcher - getDefaultNamespace() / setDefaultNamespace()');
        $dispatcher = new Dispatcher();

        $I->assertEquals('', $dispatcher->getDefaultNamespace());

        $namespace = "Phalcon\Rules";
        $dispatcher->setDefaultNamespace($namespace);

        $I->assertEquals($namespace, $dispatcher->getDefaultNamespace());
    }
}
