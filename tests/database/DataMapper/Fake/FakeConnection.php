<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Database\DataMapper\Fake;

use Phalcon\DataMapper\Pdo\Connection;
use Phalcon\DataMapper\Pdo\Profiler\ProfilerInterface;

class FakeConnection extends Connection
{
    public function __construct(
        string $dsn,
        ?string $username = null,
        ?string $password = null,
        array $options = [],
        array $queries = [],
        ?ProfilerInterface $profiler = null
    ) {
        $this->pdo = new PdoFixture();
    }
}
