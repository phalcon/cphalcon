<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Mvc\Model;

use Codeception\Example;
use IntegrationTester;
use Phalcon\Mvc\Model\Criteria;
use Phalcon\Mvc\Model\Query\Builder;
use Phalcon\Mvc\Model\Resultset\Simple;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Models\People;
use Phalcon\Test\Models\Personas;
use Phalcon\Test\Models\Personers;
use Phalcon\Test\Models\Robots;
use Phalcon\Test\Models\Users;

use function cacheModelsDir;

class CriteriaCest
{
    use DiTrait;

    public function _before(IntegrationTester $I)
    {
        $this->setNewFactoryDefault();
        $this->setDiMysql();
    }

    public function _after(IntegrationTester $I)
    {
        $this->container['db']->close();
    }

    /**
     * Tests Criteria::inWhere with empty array.
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/10676
     * @author Phalcon Team <team@phalcon.io>
     * @since  2016-08-11
     */
    public function shouldExecuteInWhereQueryWithEmptyArray(IntegrationTester $I)
    {
        $criteria = Users::query()->inWhere(Users::class . '.id', []);

        $I->assertEquals(
            Users::class . '.id != ' . Users::class . '.id',
            $criteria->getWhere()
        );

        $I->assertInstanceOf(
            Simple::class,
            $criteria->execute()
        );
    }

    /**
     * Tests work with limit / offset
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/12419
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2016-12-18
     *
     * @dataProvider getLimitOffset
     */
    public function shouldCorrectHandleLimitAndOffset(IntegrationTester $I, Example $example)
    {
        $limit    = $example[0];
        $offset   = $example[1];
        $expected = $example[2];

        /** @var Criteria $query */
        $query = Users::query();

        $query->limit($limit, $offset);

        $I->assertEquals(
            $expected,
            $query->getLimit()
        );
    }

    private function getLimitOffset(): array
    {
        return [
            [
                -7,
                0,
                [
                    'number' => 7,
                    'offset' => 0,
                ],
            ],
            [
                '-7234',
                0,
                [
                    'number' => 7234,
                    'offset' => 0,
                ],
            ],
            [
                '18',
                0,
                [
                    'number' => 18,
                    'offset' => 0,
                ],
            ],
            [
                '18',
                2,
                [
                    'number' => 18,
                    'offset' => 2,
                ],
            ],
            [
                '-1000',
                -200,
                [
                    'number' => 1000,
                    'offset' => 200,
                ],
            ],
            [
                '1000',
                '-200',
                [
                    'number' => 1000,
                    'offset' => 200,
                ],
            ],
            [
                '0',
                '-200',
                null,
            ],
        ];
    }

    /**
     * Tests creating builder from criteria
     *
     * @since  2017-05-21
     *
     * @author Phalcon Team <team@phalcon.io>
     */
    public function createBuilderFromCriteria(IntegrationTester $I)
    {
        $criteria = Robots::query()->where("type='mechanical'");

        $I->assertInstanceOf(
            Builder::class,
            $criteria->createBuilder()
        );
    }

    public function havingNotOverwritingGroupBy(IntegrationTester $I)
    {
        $query = Personas::query()->groupBy('estado')->having('SUM(cupo) > 1000000');

        $I->assertEquals(
            'estado',
            $query->getGroupBy()
        );

        $I->assertEquals(
            'SUM(cupo) > 1000000',
            $query->getHaving()
        );
    }

    /**
     * @dataprovider adapterProvider
     */
    public function where(IntegrationTester $I, Example $example)
    {
        $this->container->setShared('db', $example['adapter']);

        $personas = Personas::query()->where("estado='I'")->execute();
        $people   = People::find("estado='I'");

        $I->assertEquals(
            count($personas->toArray()),
            count($people->toArray())
        );

        $I->assertInstanceOf(
            Simple::class,
            $personas
        );
    }

    /**
     * @dataprovider adapterProvider
     */
    public function whereRenamed(IntegrationTester $I, Example $example)
    {
        $this->container->setShared('db', $example['adapter']);

        $I->assertInstanceOf(
            Simple::class,
            Personers::query()->where("status='I'")->execute()
        );
    }

    /**
     * @dataprovider adapterProvider
     */
    public function conditions(IntegrationTester $I, Example $example)
    {
        $this->container->setShared('db', $example['adapter']);

        $personas = Personas::query()->conditions("estado='I'")->execute();
        $people   = People::find("estado='I'");

        $I->assertEquals(
            count($personas->toArray()),
            count($people->toArray())
        );
    }

    /**
     * @dataprovider adapterProvider
     */
    public function conditionsRenamed(IntegrationTester $I, Example $example)
    {
        $this->container->setShared('db', $example['adapter']);

        $I->assertInstanceOf(
            Simple::class,
            Personers::query()->conditions("status='I'")->execute()
        );
    }

    /**
     * @dataprovider adapterProvider
     */
    public function whereOrderBy(IntegrationTester $I, Example $example)
    {
        $this->container->setShared('db', $example['adapter']);

        $personas = Personas::query()
                            ->where("estado='A'")
                            ->orderBy('nombres')
                            ->execute()
        ;

        $people = People::find(
            [
                "estado='A'",
                'order' => 'nombres',
            ]
        );

        $I->assertEquals(
            count($personas->toArray()),
            count($people->toArray())
        );

        $I->assertEquals(
            $personas->getFirst()->cedula,
            $people->getFirst()->cedula
        );
    }

    /**
     * @dataprovider adapterProvider
     */
    public function whereOrderByRenamed(IntegrationTester $I, Example $example)
    {
        $this->container->setShared('db', $example['adapter']);

        $personers = Personers::query()
                              ->where("status='A'")
                              ->orderBy('navnes')
                              ->execute()
        ;

        $I->assertInstanceOf(
            Simple::class,
            $personers
        );

        $I->assertInstanceOf(
            Personers::class,
            $personers->getFirst()
        );
    }

    /**
     * @dataprovider adapterProvider
     */
    public function whereOrderByLimit(IntegrationTester $I, Example $example)
    {
        $this->container->setShared('db', $example['adapter']);

        $personas = Personas::query()
                            ->where("estado='A'")
                            ->orderBy('nombres')
                            ->limit(100)
                            ->execute()
        ;

        $people = People::find(
            [
                "estado='A'",
                'order' => 'nombres',
                'limit' => 100,
            ]
        );

        $I->assertEquals(
            count($personas->toArray()),
            count($people->toArray())
        );

        $I->assertEquals(
            $personas->getFirst()->cedula,
            $people->getFirst()->cedula
        );
    }

    /**
     * @dataprovider adapterProvider
     */
    public function whereOrderByLimitRenamed(IntegrationTester $I, Example $example)
    {
        $this->container->setShared('db', $example['adapter']);

        $personers = Personers::query()
                              ->where("status='A'")
                              ->orderBy('navnes')
                              ->limit(100)
                              ->execute()
        ;

        $I->assertInstanceOf(
            Simple::class,
            $personers
        );

        $I->assertInstanceOf(
            Personers::class,
            $personers->getFirst()
        );
    }

    /**
     * @dataprovider adapterProvider
     */
    public function bindParamsWithLimit(IntegrationTester $I, Example $example)
    {
        $this->container->setShared('db', $example['adapter']);

        $personas = Personas::query()
                            ->where('estado=?1')
                            ->bind([1 => 'A'])
                            ->orderBy('nombres')
                            ->limit(100)
                            ->execute()
        ;

        $people = People::find(
            [
                'estado=?1',
                'bind'  => [1 => 'A'],
                'order' => 'nombres',
                'limit' => 100,
            ]
        );

        $I->assertEquals(
            count($personas->toArray()),
            count($people->toArray())
        );

        $I->assertEquals(
            $personas->getFirst()->cedula,
            $people->getFirst()->cedula
        );
    }

    /**
     * @dataprovider adapterProvider
     */
    public function bindParamsWithOrderAndLimitRenamed(IntegrationTester $I, Example $example)
    {
        $this->container->setShared('db', $example['adapter']);

        $personers = Personers::query()
                              ->where('status=?1')
                              ->bind([1 => 'A'])
                              ->orderBy('navnes')
                              ->limit(100)
                              ->execute()
        ;

        $I->assertInstanceOf(
            Simple::class,
            $personers
        );

        $I->assertInstanceOf(
            Personers::class,
            $personers->getFirst()
        );
    }

    /**
     * @dataprovider adapterProvider
     */
    public function bindParamsAsPlaceholdersWithOrderAndLimitRenamed(IntegrationTester $I, Example $example)
    {
        $this->container->setShared('db', $example['adapter']);

        $personers = Personers::query()
                              ->where('status=:status:')
                              ->bind(['status' => 'A'])
                              ->orderBy('navnes')
                              ->limit(100)
                              ->execute()
        ;

        $I->assertInstanceOf(
            Simple::class,
            $personers
        );

        $I->assertInstanceOf(
            Personers::class,
            $personers->getFirst()
        );
    }

    /**
     * @dataprovider adapterProvider
     */
    public function limitWithOffset(IntegrationTester $I, Example $example)
    {
        $this->container->setShared('db', $example['adapter']);

        $personas = Personas::query()
                            ->where('estado=?1')
                            ->bind([1 => 'A'])
                            ->orderBy('nombres')
                            ->limit(100, 10)
                            ->execute()
        ;

        $people = People::find(
            [
                'estado=?1',
                'bind'  => [1 => 'A'],
                'order' => 'nombres',
                'limit' => [
                    'number' => 100,
                    'offset' => 10,
                ],
            ]
        );

        $I->assertEquals(
            count($personas->toArray()),
            count($people->toArray())
        );

        $I->assertEquals(
            $personas->getFirst()->cedula,
            $people->getFirst()->cedula
        );
    }

    /**
     * @dataprovider adapterProvider
     */
    public function bindOrderLimit(IntegrationTester $I, Example $example)
    {
        $this->container->setShared('db', $example['adapter']);

        $personas = Personas::query()
                            ->where('estado=:estado:')
                            ->bind(['estado' => 'A'])
                            ->orderBy('nombres')
                            ->limit(100)
                            ->execute()
        ;

        $people = People::find(
            [
                'estado=:estado:',
                'bind'  => ['estado' => 'A'],
                'order' => 'nombres',
                'limit' => 100,
            ]
        );

        $I->assertEquals(
            count($personas->toArray()),
            count($people->toArray())
        );

        $I->assertEquals(
            $personas->getFirst()->cedula,
            $people->getFirst()->cedula
        );
    }

    /**
     * @dataprovider adapterProvider
     */
    public function orderBy(IntegrationTester $I, Example $example)
    {
        $this->container->setShared('db', $example['adapter']);

        $personas = Personas::query()->orderBy('nombres');

        $I->assertEquals(
            'nombres',
            $personas->getOrderBy()
        );
    }

    /**
     * @issue        https://github.com/phalcon/cphalcon/issues/2131
     *
     * @dataprovider adapterProvider
     */
    public function freshCache(IntegrationTester $I, Example $example)
    {
        $this->container->setShared('db', $example['adapter']);

        $cache = $this->getAndSetModelsCacheStream();

        $cache->clear();

        $personas = Personas::query()
                            ->where("estado='I'")
                            ->cache(['key' => 'cache-for-issue-2131'])
                            ->execute()
        ;

        $I->assertTrue(
            $personas->isFresh()
        );

        $personas = Personas::query()
                            ->where("estado='I'")
                            ->cache(['key' => 'cache-for-issue-2131'])
                            ->execute()
        ;

        $I->assertFalse(
            $personas->isFresh()
        );

        $I->amInPath(
            cacheModelsDir()
        );

        $I->safeDeleteFile('cache-for-issue-2131');
        $I->dontSeeFileFound('cache-for-issue-2131');
    }

    /**
     * The data providers
     */
    protected function adapterProvider(): array
    {
        return [
            [
                'adapter' => $this->newDiMysql(),
            ],
            [
                'adapter' => $this->newDiSqlite(),
            ],
            [
                'adapter' => $this->newDiPostgresql(),
            ],
        ];
    }
}
