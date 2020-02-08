<?php

/**
* This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Test\Fixtures\DataMapper\Pdo;

use Phalcon\DataMapper\Pdo\Connection;
use Phalcon\DataMapper\Pdo\Profiler\ProfilerInterface;

class ConnectionFixture extends Connection
{
    public function __construct(
        string $dsn,
        string $username = null,
        string $password = null,
        array $options = [],
        array $queries = [],
        ProfilerInterface $profiler = null
    ) {
        $this->pdo = new PdoFixture();
    }
}
