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

namespace Phalcon\Tests\Unit\Support\Helper\Str;

use Phalcon\Support\Helper\Str\IsUpper;
use Phalcon\Tests\AbstractUnitTestCase;

final class IsUpperTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testSupportHelperStrIsUpper(): void
    {
        $object = new IsUpper();
        $actual = $object('PHALCON FRAMEWORK');
        $this->assertTrue($actual);

        $actual = $object('Phalcon Framework');
        $this->assertFalse($actual);
    }
}
