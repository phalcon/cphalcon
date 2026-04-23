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

final class DebugVarTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-02-04
     */
    public function testSupportDebugDebugVar(): void
    {
        $debug = new Debug();
        $result = $debug->debugVar('test variable');

        $this->assertInstanceOf(Debug::class, $result);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-11
     */
    public function testSupportDebugDebugVarAndClearVars(): void
    {
        $debug = new Debug();
        $debug->debugVar('first variable');
        $debug->debugVar('second variable');

        $result = $debug->clearVars();
        $this->assertInstanceOf(Debug::class, $result);
    }
}
