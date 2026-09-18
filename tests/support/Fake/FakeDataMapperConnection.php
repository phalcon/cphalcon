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

use Phalcon\DataMapper\Pdo\Connection;

/**
 * Connection that can report a different driver name or insert id. When the
 * test sets neither, the real connection answers.
 */
final class FakeDataMapperConnection extends Connection
{
    public string | null $driverName = null;
    public string | null $insertId = null;

    public function getDriverName(): string
    {
        return $this->driverName ?? parent::getDriverName();
    }

    public function lastInsertId(string | null $name = null): string
    {
        return $this->insertId ?? parent::lastInsertId($name);
    }
}
