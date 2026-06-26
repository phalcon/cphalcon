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

namespace Phalcon\Tests\Unit\Support\Debug\Dump;

use Phalcon\Support\Debug\Dump;
use Phalcon\Tests\AbstractUnitTestCase;

final class GetSetDetailedTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testSupportDebugDumpGetSetDetailed(): void
    {
        $dump = new Dump([], false);

        $actual = $dump->getDetailed();
        $this->assertFalse($actual);

        $dump->setDetailed(true);
        $actual = $dump->getDetailed();
        $this->assertTrue($actual);
    }
}
