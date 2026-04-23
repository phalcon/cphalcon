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

use Phalcon\Support\Helper\Str\StartsWith;
use Phalcon\Tests\AbstractUnitTestCase;

final class StartsWithTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testSupportHelperStrStartsWith(): void
    {
        $object = new StartsWith();

        $actual = $object('Hello', 'H');
        $this->assertTrue($actual);

        $actual = $object('Hello', 'He');
        $this->assertTrue($actual);

        $actual = $object('Hello', 'Hello');
        $this->assertTrue($actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testSupportHelperStrStartsWithCaseInsensitive(): void
    {
        $object = new StartsWith();

        $actual = $object('Hello', 'h');
        $this->assertTrue($actual);

        $actual = $object('Hello', 'he');
        $this->assertTrue($actual);

        $actual = $object('Hello', 'hello');
        $this->assertTrue($actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testSupportHelperStrStartsWithCaseSensitive(): void
    {
        $object = new StartsWith();

        $actual = $object('Hello', 'hello', true);
        $this->assertTrue($actual);

        $actual = $object('Hello', 'hello', false);
        $this->assertFalse($actual);

        $actual = $object('Hello', 'h', false);
        $this->assertFalse($actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testSupportHelperStrStartsWithEmpty(): void
    {
        $object = new StartsWith();

        $actual = $object('', '');
        $this->assertFalse($actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testSupportHelperStrStartsWithEmptySearchString(): void
    {
        $object = new StartsWith();

        $actual = $object('', 'hello');
        $this->assertFalse($actual);
    }
}
