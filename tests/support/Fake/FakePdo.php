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

use PDO;
use PDOException;

/**
 * PDO handle that counts the transaction calls the adapter makes and returns
 * or throws what the test asks for, so no server is necessary.
 */
final class FakePdo extends PDO
{
    public int $commitCalls = 0;
    public PDOException | null $commitError = null;
    public bool $commitResult = true;
    public bool $inTransaction = true;
    public int $rollbackCalls = 0;
    public PDOException | null $rollbackError = null;
    public bool $rollbackResult = true;

    public function __construct()
    {
        parent::__construct('sqlite::memory:');
    }

    public function commit(): bool
    {
        $this->commitCalls++;

        if (null !== $this->commitError) {
            throw $this->commitError;
        }

        return $this->commitResult;
    }

    public function inTransaction(): bool
    {
        return $this->inTransaction;
    }

    public function rollBack(): bool
    {
        $this->rollbackCalls++;

        if (null !== $this->rollbackError) {
            throw $this->rollbackError;
        }

        return $this->rollbackResult;
    }
}
