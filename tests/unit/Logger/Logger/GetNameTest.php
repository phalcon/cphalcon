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

namespace Phalcon\Tests\Unit\Logger\Logger;

use Phalcon\Logger\Logger;
use Phalcon\Tests\AbstractUnitTestCase;

final class GetNameTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testLoggerGetName(): void
    {
        $logger = new Logger('my-name');

        $expected = 'my-name';
        $actual   = $logger->getName();
        $this->assertSame($expected, $actual);
    }
}
