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
use Phalcon\Di\FactoryDefault\Cli as DiFactoryDefault;
use Phalcon\Mvc\Model\Binder;

/**
 * Class GetBoundModelsCest
 */
class GetBoundModelsCest
{
    /**
     * Tests Phalcon\Cli\Dispatcher :: getBoundModels()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function cliDispatcherGetBoundModels(CliTester $I)
    {
        $I->wantToTest('Cli\Dispatcher - getBoundModels()');
        $dispatcher = new Dispatcher();
        $dispatcher->setDI(
            new DiFactoryDefault()
        );

        //No binder set should return empty array
        $I->assertEquals([], $dispatcher->getBoundModels());

        $modelBinder = new Binder();
        $dispatcher->setModelBinder($modelBinder);
        $I->assertCount(0, $dispatcher->getBoundModels());
    }
}
