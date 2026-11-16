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

namespace Phalcon\Tests\Unit\Container;

use Phalcon\Container\Resolver\Resolver;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use Phalcon\Tests\Support\WeakTypes\IntTarget;
use stdClass;

/**
 * The resolver calls the callable with the PHP weak type rules, the same as
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
    public function testContainerResolverWeakModeResolveCall(): void
    {
        $actual = (new Resolver())->resolveCall(
            new stdClass(),
            [IntTarget::class, 'double'],
            ['5']
        );

        $this->assertSame(10, $actual);
    }
}
