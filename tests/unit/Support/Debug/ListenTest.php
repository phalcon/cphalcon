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

namespace Phalcon\Tests\Unit\Support\Debug;

use Phalcon\Support\Debug;
use Phalcon\Tests\AbstractUnitTestCase;

final class ListenTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-11
     */
    public function testSupportDebugListenExceptionsOnly(): void
    {
        $debug  = new Debug();
        $result = $debug->listen();

        $this->assertInstanceOf(Debug::class, $result);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-11
     */
    public function testSupportDebugListenLowSeverityBranch(): void
    {
        $debug  = new Debug();
        $result = $debug->listen(false, true);

        $this->assertInstanceOf(Debug::class, $result);
    }
}
