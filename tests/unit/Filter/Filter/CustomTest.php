<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Filter\Filter;

use Phalcon\Filter\Filter;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use Phalcon\Tests\Support\Filter\Sanitize\IPv4;
use stdClass;
use TypeError;

final class CustomTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testFilterFilterCustomHas(): void
    {
        $actual = (new Filter(['ipv4' => IPv4::class]))->has('ipv4');
        $this->assertTrue($actual);
    }

    /**
     * A sanitizer with no __invoke() throws the TypeError of
     * call_user_func_array().
     *
     * @issue  https://github.com/phalcon/phalcon/issues/808
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-15
     */
    public function testFilterFilterCustomNotCallableCall(): void
    {
        $filter = new Filter(['custom' => stdClass::class]);

        $this->expectException(TypeError::class);
        $this->expectExceptionMessage(
            'call_user_func_array(): Argument #1 ($callback) must be a valid callback, '
            . 'class stdClass does not have a method "__invoke"'
        );

        $filter->custom('5');
    }

    /**
     * @issue  https://github.com/phalcon/phalcon/issues/808
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-15
     */
    public function testFilterFilterCustomNotCallableSanitize(): void
    {
        $filter = new Filter(['custom' => stdClass::class]);

        $this->expectException(TypeError::class);
        $this->expectExceptionMessage(
            'call_user_func_array(): Argument #1 ($callback) must be a valid callback, '
            . 'no array or string given'
        );

        $filter->sanitize('5', 'custom');
    }

    /**
     * An array value throws the TypeError at its first element.
     *
     * @issue  https://github.com/phalcon/phalcon/issues/808
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-15
     */
    public function testFilterFilterCustomNotCallableSanitizeArray(): void
    {
        $filter = new Filter(['custom' => stdClass::class]);

        $this->expectException(TypeError::class);
        $this->expectExceptionMessage(
            'call_user_func_array(): Argument #1 ($callback) must be a valid callback, '
            . 'no array or string given'
        );

        $filter->sanitize(['5', '6'], 'custom');
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testFilterFilterCustomSanitizer(): void
    {
        /** @var IPv4 $sanitizer */
        $sanitizer = (new Filter(['ipv4' => IPv4::class]))->get('ipv4');

        $this->assertInstanceOf(IPv4::class, $sanitizer);
        $expected = '127.0.0.1';
        $actual   = $sanitizer('127.0.0.1');
        $this->assertSame($expected, $actual);
        $this->assertFalse($sanitizer('127.0.0'));
    }
}
