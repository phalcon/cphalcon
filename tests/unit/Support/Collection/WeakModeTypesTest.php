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

namespace Phalcon\Tests\Unit\Support\Collection;

use Closure;
use Phalcon\Support\Collection;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use PHPUnit\Framework\Attributes\DataProvider;

/**
 * The collection calls the callbacks with the PHP weak type rules, the same
 * as cphalcon. The test file declares strict_types=1, so the mode of the
 * caller has no effect.
 */
final class WeakModeTypesTest extends AbstractUnitTestCase
{
    /**
     * Each row runs one method of the collection with a callback that takes
     * an int, and returns the result.
     *
     * @return array<string, array{0: Closure, 1: mixed}>
     */
    public static function getCallbacks(): array
    {
        return [
            'each'   => [
                function (Collection $collection): mixed {
                    $seen = null;
                    $collection->each(
                        function (int $value) use (&$seen): void {
                            $seen = $value;
                        }
                    );

                    return $seen;
                },
                5,
            ],
            'filter' => [
                function (Collection $collection): mixed {
                    return $collection
                        ->filter(
                            function (int $value): bool {
                                return $value === 5;
                            }
                        )
                        ->toArray()
                    ;
                },
                ['a' => '5'],
            ],
            'map'    => [
                function (Collection $collection): mixed {
                    return $collection
                        ->map(
                            function (int $value): int {
                                return $value * 2;
                            }
                        )
                        ->toArray()
                    ;
                },
                ['a' => 10],
            ],
            'reduce' => [
                function (Collection $collection): mixed {
                    return $collection->reduce(
                        function (int $carry, int $value): int {
                            return $carry + $value;
                        },
                        0
                    );
                },
                5,
            ],
        ];
    }

    /**
     * @issue  https://github.com/phalcon/phalcon/issues/805
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-14
     */
    #[DataProvider('getCallbacks')]
    public function testSupportCollectionWeakModeCallbacks(
        Closure $run,
        mixed $expected
    ): void {
        $collection = new Collection(['a' => '5']);

        $this->assertSame($expected, $run($collection));
    }
}
