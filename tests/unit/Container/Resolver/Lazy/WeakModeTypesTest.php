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

namespace Phalcon\Tests\Unit\Container\Resolver\Lazy;

use Phalcon\Container\Container;
use Phalcon\Container\Resolver\Lazy\FunctionCall;
use Phalcon\Container\Resolver\Lazy\GetCall;
use Phalcon\Container\Resolver\Lazy\Lazy;
use Phalcon\Container\Resolver\Lazy\NewCall;
use Phalcon\Container\Resolver\Lazy\StaticCall;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use Phalcon\Tests\Support\WeakTypes\IntTarget;
use PHPUnit\Framework\Attributes\DataProvider;

/**
 * The lazy calls call the user code with the PHP weak type rules, the same as
 * cphalcon. The test file declares strict_types=1, so the mode of the caller
 * has no effect.
 */
final class WeakModeTypesTest extends AbstractUnitTestCase
{
    /**
     * Each lazy call calls IntTarget::double() with '5'.
     *
     * @return array<string, array{0: Lazy}>
     */
    public static function getLazyCalls(): array
    {
        return [
            'FunctionCall' => [
                new FunctionCall(IntTarget::class . '::double', ['5']),
            ],
            'GetCall'      => [
                new GetCall(IntTarget::class, 'double', ['5']),
            ],
            'NewCall'      => [
                new NewCall(IntTarget::class, 'double', ['5']),
            ],
            'StaticCall'   => [
                new StaticCall(IntTarget::class, 'double', ['5']),
            ],
        ];
    }

    /**
     * @issue  https://github.com/phalcon/phalcon/issues/805
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-14
     */
    #[DataProvider('getLazyCalls')]
    public function testContainerResolverLazyWeakMode(Lazy $lazy): void
    {
        $this->assertSame(10, $lazy->resolve(new Container()));
    }
}
