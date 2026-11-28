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
use Phalcon\Tests\Support\WeakTypes\IntTarget;

/**
 * The filter calls the sanitizers with the PHP weak type rules, the same as
 * cphalcon. The test file declares strict_types=1, so the mode of the caller
 * has no effect.
 */
final class WeakModeTypesTest extends AbstractUnitTestCase
{
    /**
     * @issue  https://github.com/phalcon/phalcon/issues/805
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-14
     */
    public function testFilterFilterWeakModeCall(): void
    {
        $filter = new Filter();
        $filter->set('double', IntTarget::class);

        $actual = $filter->double('5');

        $this->assertSame(10, $actual);
    }

    /**
     * @issue  https://github.com/phalcon/phalcon/issues/805
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-14
     */
    public function testFilterFilterWeakModeSanitize(): void
    {
        $filter = new Filter();
        $filter->set('double', [IntTarget::class, 'double']);

        $actual = $filter->sanitize('5', 'double');

        $this->assertSame(10, $actual);
    }
}
