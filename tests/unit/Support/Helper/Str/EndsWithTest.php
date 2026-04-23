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

use Phalcon\Support\Helper\Str\EndsWith;
use Phalcon\Tests\AbstractUnitTestCase;

final class EndsWithTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testSupportHelperStrEndsWith(): void
    {
        $object = new EndsWith();
        $actual = $object('Hello', 'o');
        $this->assertTrue($actual);

        $actual = $object('Hello', 'lo');
        $this->assertTrue($actual);

        $actual = $object('Hello', 'Hello');
        $this->assertTrue($actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testSupportHelperStrEndsWithCaseInsensitive(): void
    {
        $object = new EndsWith();
        $actual = $object('Hello', 'O');
        $this->assertTrue($actual);

        $actual = $object('Hello', 'LO');
        $this->assertTrue($actual);

        $actual = $object('Hello', 'hello');
        $this->assertTrue($actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testSupportHelperStrEndsWithCaseSensitive(): void
    {
        $object = new EndsWith();
        $actual = $object('Hello', 'hello', true);
        $this->assertTrue($actual);

        $actual = $object('Hello', 'hello', false);
        $this->assertFalse($actual);

        $actual = $object('Hello', 'O', false);
        $this->assertFalse($actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testSupportHelperStrEndsWithEmpty(): void
    {
        $object = new EndsWith();
        $actual = $object('', '');
        $this->assertFalse($actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testSupportHelperStrEndsWithEmptySearchString(): void
    {
        $object = new EndsWith();
        $actual = $object('', 'hello');
        $this->assertFalse($actual);
    }
}
