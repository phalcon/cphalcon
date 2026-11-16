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
use Phalcon\Tests\Support\Traits\ErrorHandlerTrait;
use stdClass;

final class CustomTest extends AbstractUnitTestCase
{
    use ErrorHandlerTrait;

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
     * A sanitizer with no __invoke() gives a warning and null, the same as
     * cphalcon.
     *
     * @issue  https://github.com/phalcon/phalcon/issues/808
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-15
     */
    public function testFilterFilterCustomNotCallableCall(): void
    {
        $filter = new Filter(['custom' => stdClass::class]);

        [$actual, $messages] = $this->collectErrors(
            static fn () => $filter->custom('5')
        );

        $this->assertNull($actual);
        $this->assertSame(['class stdClass does not have a method "__invoke"'], $messages);
    }

    /**
     * @issue  https://github.com/phalcon/phalcon/issues/808
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-15
     */
    public function testFilterFilterCustomNotCallableSanitize(): void
    {
        $filter = new Filter(['custom' => stdClass::class]);

        [$actual, $messages] = $this->collectErrors(
            static fn () => $filter->sanitize('5', 'custom')
        );

        $this->assertNull($actual);
        $this->assertSame(['no array or string given'], $messages);
    }

    /**
     * Each element of an array value gives a warning and null.
     *
     * @issue  https://github.com/phalcon/phalcon/issues/808
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-15
     */
    public function testFilterFilterCustomNotCallableSanitizeArray(): void
    {
        $filter = new Filter(['custom' => stdClass::class]);

        [$actual, $messages] = $this->collectErrors(
            static fn () => $filter->sanitize(['5', '6'], 'custom')
        );

        $this->assertSame([null, null], $actual);
        $this->assertSame(['no array or string given', 'no array or string given'], $messages);
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
