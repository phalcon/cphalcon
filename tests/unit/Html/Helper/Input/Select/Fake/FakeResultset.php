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

namespace Phalcon\Tests\Unit\Html\Helper\Input\Select\Fake;

use ArrayIterator;
use Closure;
use Phalcon\Mvc\Model\ResultsetInterface;
use Phalcon\Mvc\ModelInterface;

final class FakeResultset extends ArrayIterator implements ResultsetInterface
{
    public function delete(Closure | null $conditionCallback = null): bool
    {
        return false;
    }

    public function filter($filter): array
    {
        return [];
    }

    public function getCache(): mixed
    {
        return null;
    }

    public function getFirst(): mixed
    {
        return null;
    }

    public function getHydrateMode(): int
    {
        return 0;
    }

    public function getLast(): ModelInterface | null
    {
        return null;
    }

    public function getMessages(): array
    {
        return [];
    }

    public function getType(): int
    {
        return 0;
    }

    public function isFresh(): bool
    {
        return false;
    }

    public function setHydrateMode(int $hydrateMode): ResultsetInterface
    {
        return $this;
    }

    public function setIsFresh(bool $isFresh): ResultsetInterface
    {
        return $this;
    }

    public function toArray(): array
    {
        return iterator_to_array($this);
    }

    public function update(mixed $data, Closure | null $conditionCallback = null): bool
    {
        return false;
    }
}
