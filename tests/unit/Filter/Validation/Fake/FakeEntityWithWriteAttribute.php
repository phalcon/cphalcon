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

namespace Phalcon\Tests\Unit\Filter\Validation\Fake;

/**
 * Fake entity with writeAttribute() for testing Validation::bind() writeAttribute path
 */
final class FakeEntityWithWriteAttribute
{
    /**
     * @var array<string, mixed>
     */
    private array $attributes = [];

    /**
     * @return mixed
     */
    public function readAttribute(string $name): mixed
    {
        return $this->attributes[$name] ?? null;
    }

    public function writeAttribute(string $name, mixed $value): void
    {
        $this->attributes[$name] = $value;
    }
}
