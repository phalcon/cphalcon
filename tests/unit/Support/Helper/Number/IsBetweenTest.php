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

namespace Phalcon\Tests\Unit\Support\Helper\Number;

use Phalcon\Support\Helper\Number\IsBetween;
use Phalcon\Tests\AbstractUnitTestCase;

final class IsBetweenTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testSupportHelperNumberBetween(): void
    {
        $object = new IsBetween();
        $actual = $object(5, 1, 10);
        $this->assertTrue($actual);

        $actual = $object(1, 1, 10);
        $this->assertTrue($actual);

        $actual = $object(10, 1, 10);
        $this->assertTrue($actual);

        $actual = $object(1, 5, 10);
        $this->assertFalse($actual);
    }
}
