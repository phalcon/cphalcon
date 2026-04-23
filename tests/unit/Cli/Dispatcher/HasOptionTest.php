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
 * Class HasOptionTest extends AbstractUnitTestCase
 */
final class HasOptionTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testCliDispatcherHasOption(): void
    {
        $dispatcher = new Dispatcher();
        $optionName = "Phalcon";

        $actual = $dispatcher->hasOption($optionName);
        $this->assertFalse($actual);

        $dispatcher->setOptions([$optionName => "value"]);

        $actual = $dispatcher->hasOption($optionName);
        $this->assertTrue($actual);

        // Options should be case-sensitive
        $actual = $dispatcher->hasOption(strtolower($optionName));
        $this->assertFalse($actual);
    }
}
