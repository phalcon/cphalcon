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
use Phalcon\Mvc\Model\ResultsetInterface;
use Phalcon\Tests\Benchmarks\Apps\Rest\Fixture;
use Phalcon\Tests\Benchmarks\Apps\Rest\Models\Robots;
use PhpBench\Attributes\BeforeMethods;
use RuntimeException;

#[BeforeMethods('setUp')]
final class ModelBench
{
    /**
     * The sum of the years of the first 20 robots (1951 to 1970).
     */
    private const EXPECTED_YEARS = 39210;

    private FactoryDefault $container;

    private ResultsetInterface $resultset;

    public function setUp(): void
    {
        $fixture         = new Fixture();
        $this->container = $fixture->container($fixture->database(), $fixture->metadata());
        $this->resultset = Robots::find(
            [
                'order' => 'id',
                'limit' => 20,
            ]
        );
    }

    /**
     * find() with 20 rows, and the hydration of each model.
     */
    public function benchFind(): void
    {
        $years  = 0;
        $robots = Robots::find(
            [
                'order' => 'id',
                'limit' => 20,
            ]
        );
        foreach ($robots as $robot) {
            $years += $robot->year;
        }

        if (self::EXPECTED_YEARS !== $years) {
            throw new RuntimeException(sprintf('Unexpected sum of years: %d', $years));
        }
    }

    public function benchFindFirst(): void
    {
        $robot = Robots::findFirst(
            [
                'conditions' => 'id = :id:',
                'bind'       => ['id' => 7],
            ]
        );

        if (!$robot instanceof Robots || 'Robot 7' !== $robot->name) {
            throw new RuntimeException('Robots::findFirst() returned an unexpected value');
        }
    }

    /**
     * assign(), validation and save() in a transaction that rolls back.
     */
    public function benchSave(): void
    {
        $connection = $this->container->getShared('db');
        $connection->begin();

        $robot = new Robots();
        $robot->assign(
            [
                'name' => 'Robot new',
                'type' => 'droid',
                'year' => 2026,
            ]
        );
        $saved = $robot->save();
        $id    = $robot->id;

        $connection->rollback();

        if (true !== $saved || 51 !== $id) {
            throw new RuntimeException(sprintf('Unexpected save: %s, id %s', var_export($saved, true), $id));
        }
    }

    public function benchToArray(): void
    {
        $rows = $this->resultset->toArray();

        if (20 !== count($rows) || 'Robot 1' !== $rows[0]['name']) {
            throw new RuntimeException('Resultset::toArray() returned an unexpected value');
        }
    }
}
