<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *
 * Implementation of this file has been influenced by sinbadxiii/cphalcon-auth
 * @link    https://github.com/sinbadxiii/cphalcon-auth
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Auth\Fake;

use Phalcon\Session\ManagerInterface;
use SessionHandlerInterface;

final class FakeSessionManager implements ManagerInterface
{
    /**
     * @var array<string, mixed>
     */
    private array $data = [];

    public function __get(string $key): mixed
    {
        return $this->data[$key] ?? null;
    }

    public function __isset(string $key): bool
    {
        return isset($this->data[$key]);
    }

    public function __set(string $key, mixed $value): void
    {
        $this->data[$key] = $value;
    }

    public function __unset(string $key): void
    {
        unset($this->data[$key]);
    }

    public function destroy(): void
    {
        $this->data = [];
    }

    public function exists(): bool
    {
        return false;
    }

    public function get(string $key, mixed $defaultValue = null, bool $remove = false): mixed
    {
        if (!array_key_exists($key, $this->data)) {
            return $defaultValue;
        }

        $value = $this->data[$key];

        if ($remove) {
            unset($this->data[$key]);
        }

        return $value;
    }

    public function getAdapter(): SessionHandlerInterface
    {
        throw new \LogicException('not implemented in test fake');
    }

    public function getDI(): ?object
    {
        return null;
    }

    public function getId(): string
    {
        return '';
    }

    public function getName(): string
    {
        return '';
    }

    public function getOptions(): array
    {
        return [];
    }

    public function has(string $key): bool
    {
        return array_key_exists($key, $this->data);
    }

    public function regenerateId(bool $deleteOldSession = true): ManagerInterface
    {
        return $this;
    }

    public function remove(string $key): void
    {
        unset($this->data[$key]);
    }

    public function set(string $key, mixed $value): void
    {
        $this->data[$key] = $value;
    }

    public function setAdapter(SessionHandlerInterface $adapter): ManagerInterface
    {
        throw new \LogicException('not implemented in test fake');
    }

    public function setDI(object $container): void
    {
    }

    public function setId(string $sessionId): ManagerInterface
    {
        throw new \LogicException('not implemented in test fake');
    }

    public function setName(string $name): ManagerInterface
    {
        throw new \LogicException('not implemented in test fake');
    }

    public function setOptions(array $options): void
    {
    }

    public function start(): bool
    {
        return true;
    }

    public function status(): int
    {
        return ManagerInterface::SESSION_NONE;
    }
}
