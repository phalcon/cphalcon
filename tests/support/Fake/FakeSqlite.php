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

use PDOException;
use Phalcon\Db\Adapter\Pdo\Sqlite;

/**
 * Sqlite adapter whose savepoint creation always fails, so the tests can check
 * how the adapter restores the transaction level.
 */
final class FakeSqlite extends Sqlite
{
    public function createSavepoint(string $name): bool
    {
        throw new PDOException('savepoint failed');
    }
}
