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

namespace Phalcon\Tests\Unit\Auth\Fake;

/**
 * A model-like stand-in that does NOT implement
 * Phalcon\Contracts\Auth\AuthUser. Used to assert the adapters' hydration
 * guard: the array adapters via `new {model}()`, the Model adapter via
 * findFirst().
 */
final class FakeNotAuthUserModel
{
    /**
     * Static fixture rows used by findFirst() to simulate Model lookups.
     *
     * @var array<int, array<string, mixed>>
     */
    public static array $rows = [];

    /**
     * @param array<string, mixed> $row
     */
    public function assign(array $row): void
    {
    }

    /**
     * Mimics Phalcon\Mvc\Model::findFirst with the array form used by the
     * Model adapter: ['conditions' => '...', 'bind' => [...]].
     *
     * @param array{conditions?: string, bind?: array<string, mixed>}|string $parameters
     */
    public static function findFirst(array | string $parameters = []): static | null
    {
        if (is_string($parameters)) {
            return null;
        }

        $bind = $parameters['bind'] ?? [];

        if (!is_array($bind)) {
            return null;
        }

        foreach (self::$rows as $row) {
            $matches = true;

            foreach ($bind as $key => $value) {
                if (!isset($row[$key]) || $row[$key] !== $value) {
                    $matches = false;
                    break;
                }
            }

            if ($matches) {
                return new static();
            }
        }

        return null;
    }
}
