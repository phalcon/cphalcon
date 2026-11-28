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

namespace Phalcon\Tests\Unit\ADR\Router;

use Phalcon\ADR\Router\AttributeFilter;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use Phalcon\Tests\Support\WeakTypes\IntTarget;

/**
 * The attribute filter calls the converters with the PHP weak type rules, the
 * same as cphalcon. The test file declares strict_types=1, so the mode of the
 * caller has no effect.
 */
final class WeakModeTypesTest extends AbstractUnitTestCase
{
    /**
     * The rule casts the segment to a string. The converter takes an int.
     *
     * @issue  https://github.com/phalcon/phalcon/issues/805
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-14
     */
    public function testAdrRouterWeakModeAttributeFilterConvert(): void
    {
        $actual = (new AttributeFilter())->filter(IntTarget::class, ['5']);

        $this->assertSame(['id' => 10], $actual);
    }
}
