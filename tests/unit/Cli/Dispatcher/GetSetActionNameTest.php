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
 * Class GetActionNameTest extends AbstractUnitTestCase
 */
final class GetSetActionNameTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testCliDispatcherGetActionName(): void
    {
        $dispatcher = new Dispatcher();
        $dispatcher->setActionName('hello');

        $expected = 'hello';
        $actual   = $dispatcher->getActionName();
        $this->assertSame($expected, $actual);
    }
}
