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

final class GetSetOptionsTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testCliDispatcherGetOptions(): void
    {
        $dispatcher = new Dispatcher();
        $expected = [];
        $actual   = $dispatcher->getOptions();
        $this->assertSame($expected, $actual);

        $options = ["Phalcon", "Rocks"];
        $dispatcher->setOptions($options);

        $expected = $options;
        $actual   = $dispatcher->getOptions();
        $this->assertSame($expected, $actual);
    }
}
