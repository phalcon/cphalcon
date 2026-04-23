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

namespace Phalcon\Tests\Unit\Cli\Dispatcher;

use Phalcon\Cli\Dispatcher;
use Phalcon\Di\FactoryDefault\Cli as DiFactoryDefault;
use Phalcon\Mvc\Model\Binder;
use Phalcon\Tests\AbstractUnitTestCase;

/**
 * Class GetBoundModelsTest extends AbstractUnitTestCase
 */
final class GetBoundModelsTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testCliDispatcherGetBoundModels(): void
    {
        $dispatcher = new Dispatcher();
        $dispatcher->setDI(new DiFactoryDefault());

        //No binder set should return empty array
        $expected = [];
        $actual   = $dispatcher->getBoundModels();
        $this->assertSame($expected, $actual);

        $modelBinder = new Binder();
        $dispatcher->setModelBinder($modelBinder);

        $expected = 0;
        $actual   = count($dispatcher->getBoundModels());
        $this->assertSame($expected, $actual);
    }
}
