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
use Phalcon\Tests\AbstractUnitTestCase;

/**
 * Class GetSetModuleNameTest extends AbstractUnitTestCase
 */
final class GetSetModuleNameTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testCliDispatcherGetModuleName(): void
    {
        $dispatcher = new Dispatcher();

        $expected = '';
        $actual   = $dispatcher->getModuleName();
        $this->assertSame($expected, $actual);

        $moduleName = "Phalcon";
        $dispatcher->setModuleName($moduleName);

        $expected = $moduleName;
        $actual   = $dispatcher->getModuleName();
        $this->assertSame($expected, $actual);
    }
}
