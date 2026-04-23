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

use Phalcon\Support\Helper\Str\Includes;
use Phalcon\Tests\AbstractUnitTestCase;

final class IncludesTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testSupportHelperStrIncludes(): void
    {
        $object = new Includes();
        $source = 'Mary had a little lamb';
        $actual = $object($source, 'lamb');
        $this->assertTrue($actual);

        $actual = $object($source, 'unknown');
        $this->assertFalse($actual);

        $actual = $object($source, 'Mary');
        $this->assertTrue($actual);
    }
}
