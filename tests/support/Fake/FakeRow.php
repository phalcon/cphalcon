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

namespace Phalcon\Tests\Support\Fake;

/**
 * Row object that exposes readAttribute(), the way the resultset helpers
 * expect a model to do.
 */
final class FakeRow
{
    /**
     * @var array<string, mixed>
     */
    private array $attributes;

    /**
     * @param array<string, mixed> $attributes
     */
    public function __construct(array $attributes = [])
    {
        $this->attributes = $attributes;
    }

    public function readAttribute(string $name): mixed
    {
        return $this->attributes[$name] ?? null;
    }
}
