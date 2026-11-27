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

namespace Phalcon\Tests\Unit\Events\Manager;

use Error;
use Phalcon\Events\EventInterface;
use Phalcon\Events\Manager;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use PHPUnit\Framework\Attributes\DataProvider;
use stdClass;

use function get_class;
use function restore_error_handler;
use function set_error_handler;

/**
 * The events manager calls the listeners with the PHP weak type rules, the
 * same as cphalcon. The test file declares strict_types=1, so the mode of the
 * caller has no effect.
 */
final class WeakModeTypesTest extends AbstractUnitTestCase
{
    /**
     * A listener method that the manager cannot call
     *
     * @return array<string, array{0: mixed, 1: string}>
     */
    public static function getBadListenerMethods(): array
    {
        return [
            'missing method' => [
                [new stdClass(), 'missing'],
                'Call to undefined method stdClass::missing()',
            ],
            'private method' => [
                new class () {
                    private function b(): void
                    {
                    }
                },
                'Call to private method',
            ],
        ];
    }

    /**
     * Each listener kind, alone (the fast path) and with one more listener
     * (the loop).
     *
     * @return array<string, array{0: string, 1: bool}>
     */
    public static function getListenerKinds(): array
    {
        $rows = [];
        foreach (['closure', 'array', 'object', 'invokable'] as $kind) {
            $rows[$kind . ', alone']      = [$kind, false];
            $rows[$kind . ', in a queue'] = [$kind, true];
        }

        return $rows;
    }

    /**
     * A listener method that the manager cannot call gives the Error of a
     * direct call, the same as cphalcon. It is not a TypeError.
     *
     * @issue  https://github.com/phalcon/phalcon/issues/805
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-14
     */
    #[DataProvider('getBadListenerMethods')]
    public function testEventsManagerWeakModeBadListenerMethod(
        mixed $listener,
        string $message
    ): void {
        $manager = new Manager();
        $manager->attach('a', $listener);

        $actual = null;
        try {
            $manager->fire('a:b', new stdClass(), '5');
        } catch (Error $ex) {
            $actual = $ex;
        }

        $this->assertInstanceOf(Error::class, $actual);
        $this->assertSame(Error::class, get_class($actual));
        $this->assertStringContainsString($message, $actual->getMessage());
    }

    /**
     * A listener with a by-reference parameter gets a warning and a copy of
     * the data, the same as cphalcon. The next listener gets the data that
     * fire() received.
     *
     * @issue  https://github.com/phalcon/phalcon/issues/805
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-14
     */
    public function testEventsManagerWeakModeByReferenceData(): void
    {
        $seen     = null;
        $warnings = [];
        $manager  = new Manager();
        $manager->attach(
            'a',
            function ($event, $source, &$data): void {
                $data = 'changed';
            }
        );
        $manager->attach(
            'a',
            function ($event, $source, $data) use (&$seen): void {
                $seen = $data;
            }
        );

        set_error_handler(
            function (int $number, string $message) use (&$warnings): bool {
                $warnings[] = $message;

                return true;
            }
        );

        try {
            $manager->fire('a:b', new stdClass(), 'original');
        } finally {
            restore_error_handler();
        }

        $this->assertCount(1, $warnings);
        $this->assertStringContainsString(
            'must be passed by reference',
            $warnings[0]
        );
        $this->assertSame('original', $seen);
    }

    /**
     * @issue  https://github.com/phalcon/phalcon/issues/805
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-14
     */
    #[DataProvider('getListenerKinds')]
    public function testEventsManagerWeakModeData(
        string $kind,
        bool $inQueue
    ): void {
        $recorder       = new stdClass();
        $recorder->data = null;

        $manager = new Manager();
        $manager->attach('a', $this->getListener($kind, $recorder));

        if ($inQueue) {
            $manager->attach(
                'a',
                function (): void {
                }
            );
        }

        $manager->fire('a:b', new stdClass(), '5');

        $this->assertSame(5, $recorder->data);
    }

    /**
     * Returns a listener that stores the data in the recorder. The data
     * parameter is an int.
     */
    private function getListener(string $kind, stdClass $recorder): mixed
    {
        $object = new class ($recorder) {
            public function __construct(private stdClass $recorder)
            {
            }

            public function b(
                EventInterface $event,
                mixed $source,
                int $data
            ): void {
                $this->recorder->data = $data;
            }
        };

        $invokable = new class ($recorder) {
            public function __construct(private stdClass $recorder)
            {
            }

            public function __invoke(
                EventInterface $event,
                mixed $source,
                int $data
            ): void {
                $this->recorder->data = $data;
            }
        };

        return match ($kind) {
            'closure'   => function (
                EventInterface $event,
                mixed $source,
                int $data
            ) use ($recorder): void {
                $recorder->data = $data;
            },
            'array'     => [$object, 'b'],
            'object'    => $object,
            'invokable' => $invokable,
        };
    }
}
