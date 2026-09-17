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

use Phalcon\Db\Adapter\AdapterInterface;
use Phalcon\Di\DiInterface;
use Phalcon\Messages\MessageInterface;
use Phalcon\Mvc\Model\CriteriaInterface;
use Phalcon\Mvc\Model\MetaDataInterface;
use Phalcon\Mvc\Model\ResultsetInterface;
use Phalcon\Mvc\Model\TransactionInterface;
use Phalcon\Mvc\ModelInterface;
use RuntimeException;

/**
 * Model that only carries messages, so the tests need neither a database nor a
 * dependency injection container. Everything the model does with a connection
 * is out of scope and raises an exception.
 */
final class FakeModel implements ModelInterface
{
    /**
     * @var array<array-key, mixed>
     */
    private array $messages;

    /**
     * @param array<array-key, mixed> $messages
     */
    public function __construct(array $messages = [])
    {
        $this->messages = $messages;
    }

    public function appendMessage(MessageInterface $message): ModelInterface
    {
        $this->messages[] = $message;

        return $this;
    }

    public function assign(array $data, $whiteList = null, $dataColumnMap = null): ModelInterface
    {
        return $this;
    }

    public static function average(array $parameters = []): ResultsetInterface | float
    {
        return 0.0;
    }

    public static function cloneResult(
        ModelInterface $base,
        array $data,
        int $dirtyState = 0
    ): ModelInterface {
        return $base;
    }

    public static function cloneResultMap(
        $base,
        array $data,
        $columnMap,
        int $dirtyState = 0,
        bool $keepSnapshots = false
    ): ModelInterface {
        return new self();
    }

    public static function cloneResultMapHydrate(array $data, $columnMap, int $hydrationMode)
    {
        return null;
    }

    public static function count($parameters = null): ResultsetInterface | int
    {
        return 0;
    }

    public function create(): bool
    {
        return false;
    }

    public function delete(): bool
    {
        return false;
    }

    public static function find($parameters = null)
    {
        return null;
    }

    public static function findFirst($parameters = null)
    {
        return null;
    }

    public function fireEvent(string $eventName): bool
    {
        return true;
    }

    public function fireEventCancel(string $eventName): bool
    {
        return true;
    }

    public function getDirtyState(): int
    {
        return 0;
    }

    public function getMessages(): array
    {
        return $this->messages;
    }

    public function getModelsMetaData(): MetaDataInterface
    {
        throw new RuntimeException('The fake model has no meta data');
    }

    public function getOperationMade(): int
    {
        return 0;
    }

    public function getReadConnection(): AdapterInterface
    {
        throw new RuntimeException('The fake model has no connection');
    }

    public function getReadConnectionService(): string
    {
        return '';
    }

    public function getRelated(string $alias, $arguments = null)
    {
        return null;
    }

    public function getSchema(): string | null
    {
        return null;
    }

    public function getSource(): string
    {
        return '';
    }

    public function getWriteConnection(): AdapterInterface
    {
        throw new RuntimeException('The fake model has no connection');
    }

    public function getWriteConnectionService(): string
    {
        return '';
    }

    public static function maximum($parameters = null)
    {
        return null;
    }

    public static function minimum($parameters = null)
    {
        return null;
    }

    public static function query(DiInterface | null $container = null): CriteriaInterface
    {
        throw new RuntimeException('The fake model has no criteria');
    }

    public function refresh(): ModelInterface
    {
        return $this;
    }

    public function save(): bool
    {
        return false;
    }

    public function setConnectionService(string $connectionService): void
    {
    }

    public function setDirtyState(int $dirtyState): ModelInterface | bool
    {
        return $this;
    }

    public function setReadConnectionService(string $connectionService): void
    {
    }

    public function setSnapshotData(array $data, $columnMap = null): void
    {
    }

    public function setSync($elements = null, bool $enabled = true): ModelInterface
    {
        return $this;
    }

    public function setTransaction(TransactionInterface $transaction): ModelInterface
    {
        return $this;
    }

    public function setWriteConnectionService(string $connectionService): void
    {
    }

    public function skipOperation(bool $skip): void
    {
    }

    public static function sum($parameters = null): ResultsetInterface | float
    {
        return 0.0;
    }

    public function update(): bool
    {
        return false;
    }

    public function validationHasFailed(): bool
    {
        return false;
    }
}
