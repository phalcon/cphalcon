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

namespace Phalcon\Tests\Unit\Filter\Filter;

use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use Phalcon\Tests\Support\Filter\CallableFilter;

final class SanitizeCallableTest extends AbstractUnitTestCase
{
    /**
     * @issue  https://github.com/phalcon/cphalcon/issues/17610
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-09-28
     */
    public function testFilterFilterSanitizeCallableArrayValues(): void
    {
        $filter = new CallableFilter();

        $expected = ['ok:admin', 'ok:user'];
        $actual   = $filter->sanitize(['admin', 'user'], 'prefix');
        $this->assertSame($expected, $actual);
    }

    /**
     * @issue  https://github.com/phalcon/cphalcon/issues/17610
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-09-28
     */
    public function testFilterFilterSanitizeCallableMultiple(): void
    {
        $filter = new CallableFilter();

        $expected = 'ok:admin:done';
        $actual   = $filter->sanitize('admin', ['prefix', 'suffix']);
        $this->assertSame($expected, $actual);
    }

    /**
     * @issue  https://github.com/phalcon/cphalcon/issues/17610
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-09-28
     */
    public function testFilterFilterSanitizeCallableObjectMethod(): void
    {
        $filter = new CallableFilter();

        $expected = 'ok:admin';
        $actual   = $filter->sanitize('admin', 'prefix');
        $this->assertSame($expected, $actual);
    }

    /**
     * @issue  https://github.com/phalcon/cphalcon/issues/17610
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-09-28
     */
    public function testFilterFilterSanitizeCallableParameters(): void
    {
        $filter = new CallableFilter();

        $expected = '[admin]';
        $actual   = $filter->sanitize('admin', ['wrap' => ['[', ']']]);
        $this->assertSame($expected, $actual);
    }

    /**
     * @issue  https://github.com/phalcon/cphalcon/issues/17610
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-09-28
     */
    public function testFilterFilterSanitizeCallableStaticMethod(): void
    {
        $filter = new CallableFilter();

        $expected = 'admin:done';
        $actual   = $filter->sanitize('admin', 'suffix');
        $this->assertSame($expected, $actual);
    }
}
