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

namespace Phalcon\Tests\Benchmarks\Mvc;

use Phalcon\Di\FactoryDefault;
use Phalcon\Mvc\Model\Query;
use Phalcon\Tests\Benchmarks\Apps\Rest\Fixture;
use Phalcon\Tests\Benchmarks\Apps\Rest\Models\Robots;
use PhpBench\Attributes\BeforeMethods;
use RuntimeException;

#[BeforeMethods('setUp')]
final class QueryBench
{
    private const PHQL = 'SELECT r.id, r.name FROM ' . Robots::class . ' r'
        . ' WHERE r.year > :year: ORDER BY r.name LIMIT 10';

    private FactoryDefault $container;

    private int $counter = 0;

    public function setUp(): void
    {
        $fixture         = new Fixture();
        $this->container = $fixture->container($fixture->database(), $fixture->metadata());
    }

    /**
     * A new PHQL string for each call: a miss in the parser cache and in the intermediate cache.
     */
    public function benchParseCold(): void
    {
        $this->counter++;

        $this->check((new Query(self::PHQL . ' OFFSET ' . $this->counter, $this->container))->parse());
    }

    /**
     * The same PHQL string for each call: a hit in both caches.
     */
    public function benchParseWarm(): void
    {
        $this->check((new Query(self::PHQL, $this->container))->parse());
    }

    private function check(array $intermediate): void
    {
        if ([Robots::class] !== array_values($intermediate['models'] ?? [])) {
            throw new RuntimeException('Unexpected intermediate code: ' . json_encode($intermediate));
        }
    }
}
