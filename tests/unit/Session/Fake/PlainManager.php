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

namespace Phalcon\Tests\Unit\Session\Fake;

use Phalcon\Session\ManagerInterface;
use SessionHandlerInterface;

/**
 * Implements ManagerInterface only - no AbstractInjectionAware, no getDI() -
 * to prove components consuming the interface do not rely on the concrete
 * Manager class.
 */
final class PlainManager implements ManagerInterface
{
    private ?SessionHandlerInterface $adapter = null;

    private array $data = [];

    private string $id = '';

    private string $name = 'PHPSESSID';

    private array $options = [];

    private bool $started = false;

    public function __get(string $key)
    {
        return $this->get($key);
    }

    public function __isset(string $key): bool
    {
        return $this->has($key);
    }

    public function __set(string $key, $value): void
    {
        $this->set($key, $value);
    }

    public function __unset(string $key): void
    {
        $this->remove($key);
    }

    public function destroy(): void
    {
        $this->data    = [];
        $this->started = false;
    }

    public function exists(): bool
    {
        return $this->started;
    }

    public function get(string $key, $defaultValue = null, bool $remove = false)
    {
        $value = $this->data[$key] ?? $defaultValue;

        if ($remove) {
            unset($this->data[$key]);
        }

        return $value;
    }

    public function getAdapter(): SessionHandlerInterface | null
    {
        return $this->adapter;
    }

    public function getId(): string
    {
        return $this->id;
    }

    public function getName(): string
    {
        return $this->name;
    }

    public function getOptions(): array
    {
        return $this->options;
    }

    public function has(string $key): bool
    {
        return isset($this->data[$key]);
    }

    public function regenerateId(bool $deleteOldSession = true): ManagerInterface
    {
        return $this;
    }

    public function remove(string $key): void
    {
        unset($this->data[$key]);
    }

    public function set(string $key, $value): void
    {
        $this->data[$key] = $value;
    }

    public function setAdapter(SessionHandlerInterface $adapter): ManagerInterface
    {
        $this->adapter = $adapter;

        return $this;
    }

    public function setId(string $sessionId): ManagerInterface
    {
        $this->id = $sessionId;

        return $this;
    }

    public function setName(string $name): ManagerInterface
    {
        $this->name = $name;

        return $this;
    }

    public function setOptions(array $options): void
    {
        $this->options = $options;
    }

    public function start(): bool
    {
        $this->started = true;

        return true;
    }

    public function status(): int
    {
        return $this->started ? self::SESSION_ACTIVE : self::SESSION_NONE;
    }
}
