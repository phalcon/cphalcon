<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Mvc\Model;

use Codeception\Example;
use IntegrationTester;
use Phalcon\Mvc\Model\Query\Builder;
use Phalcon\Mvc\Model\Resultset\Simple;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Models\People;
use Phalcon\Test\Models\Personas;
use Phalcon\Test\Models\Personers;
use Phalcon\Test\Models\Robots;
use Phalcon\Test\Models\Users;

class CriteriaCest
{
    use DiTrait;

    public function _before(IntegrationTester $I)
    {
        $this->setNewFactoryDefault();
        $this->setDiMysql();
    }

    /**
     * Tests Criteria::inWhere with empty array.
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/10676
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2016-08-11
     */
    public function shouldExecuteInWhereQueryWithEmptyArray(IntegrationTester $I)
    {
        $criteria = Users::query()->inWhere(Users::class . '.id', []);

        $I->assertEquals(Users::class . '.id != ' . Users::class . '.id', $criteria->getWhere());
        $I->assertInstanceOf(Simple::class, $criteria->execute());
    }

    /**
     * Tests work with limit / offset
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/12419
     * @author Serghei Iakovelv <serghei@phalconphp.com>
     * @since  2016-12-18
     */
    public function shouldCorrectHandleLimitAndOffset(IntegrationTester $I)
    {
        $I->skipTest('TODO - Check the test data');
        $examples = $this->getLimitOffset();
        foreach ($examples as $item) {
            $limit    = $item[0];
            $offset   = $item[1];
            $expected = $item[2];
            /** @var \Phalcon\Mvc\Model\Criteria $query */
            $query = Users::query();
            $query->limit($limit, $offset);

            $actual = $query->getLimit();
            $I->assertEquals($expected, $actual);
        }
    }

    private function getLimitOffset(): array
    {
        return [
            [-7, null, 7],
            ["-7234", null, 7234],
            ["18", null, 18],
            ["18", 2, ['number' => 18, 'offset' => 2]],
            ["-1000", -200, ['number' => 1000, 'offset' => 200]],
            ["1000", "-200", ['number' => 1000, 'offset' => 200]],
            ["0", "-200", null],
            ["%3CMETA%20HTTP-EQUIV%3D%22refresh%22%20CONT ENT%3D%220%3Burl%3Djavascript%3Aqss%3D7%22%3E", 50, null],
        ];
    }

    /**
     * Tests creating builder from criteria
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2017-05-21
     *
     * @param IntegrationTester $I
     */
    public function createBuilderFromCriteria(IntegrationTester $I)
    {
        $criteria = Robots::query()->where("type='mechanical'");
        $I->assertInstanceOf(Builder::class, $criteria->createBuilder());
    }

    public function havingNotOverwritingGroupBy(IntegrationTester $I)
    {
        $query = Personas::query()->groupBy('estado')->having('SUM(cupo) > 1000000');

        $I->assertEquals('estado', $query->getGroupBy());
        $I->assertEquals('SUM(cupo) > 1000000', $query->getHaving());
    }

    /**
     * @param IntegrationTester $I
     * @param Example           $example
     *
     * @dataprovider adapterProvider
     */
    public function where(IntegrationTester $I, Example $example)
    {
        $this->container->setShared('db', $example['adapter']);

        $personas = Personas::query()->where("estado='I'")->execute();
        $people   = People::find("estado='I'");

        $I->assertEquals(count($personas->toArray()), count($people->toArray()));
        $I->assertInstanceOf(Simple::class, $personas);
    }

    /**
     * @param IntegrationTester $I
     * @param Example           $example
     *
     * @dataprovider adapterProvider
     */
    public function whereRenamed(IntegrationTester $I, Example $example)
    {
        $this->container->setShared('db', $example['adapter']);

        $I->assertInstanceOf(Simple::class, Personers::query()->where("status='I'")->execute());
    }

    /**
     * @param IntegrationTester $I
     * @param Example           $example
     *
     * @dataprovider adapterProvider
     */
    public function conditions(IntegrationTester $I, Example $example)
    {
        $this->container->setShared('db', $example['adapter']);

        $personas = Personas::query()->conditions("estado='I'")->execute();
        $people   = People::find("estado='I'");

        $I->assertEquals(count($personas->toArray()), count($people->toArray()));
    }

    /**
     * @param IntegrationTester $I
     * @param Example           $example
     *
     * @dataprovider adapterProvider
     */
    public function conditionsRenamed(IntegrationTester $I, Example $example)
    {
        $this->container->setShared('db', $example['adapter']);

        $I->assertInstanceOf(Simple::class, Personers::query()->conditions("status='I'")->execute());
    }

    /**
     * @param IntegrationTester $I
     * @param Example           $example
     *
     * @dataprovider adapterProvider
     */
    public function whereOrderBy(IntegrationTester $I, Example $example)
    {
        $this->container->setShared('db', $example['adapter']);

        $personas = Personas::query()
                            ->where("estado='A'")
                            ->orderBy("nombres")
                            ->execute()
        ;

        $people = People::find(["estado='A'", "order" => "nombres"]);

        $I->assertEquals(count($personas->toArray()), count($people->toArray()));
        $I->assertEquals($personas->getFirst()->cedula, $people->getFirst()->cedula);
    }

    /**
     * @param IntegrationTester $I
     * @param Example           $example
     *
     * @dataprovider adapterProvider
     */
    public function whereOrderByRenamed(IntegrationTester $I, Example $example)
    {
        $this->container->setShared('db', $example['adapter']);

        $personers = Personers::query()
                              ->where("status='A'")
                              ->orderBy("navnes")
                              ->execute()
        ;

        $I->assertInstanceOf(Simple::class, $personers);
        $I->assertInstanceOf(Personers::class, $personers->getFirst());
    }

    /**
     * @param IntegrationTester $I
     * @param Example           $example
     *
     * @dataprovider adapterProvider
     */
    public function whereOrderByLimit(IntegrationTester $I, Example $example)
    {
        $this->container->setShared('db', $example['adapter']);

        $personas = Personas::query()
                            ->where("estado='A'")
                            ->orderBy("nombres")
                            ->limit(100)
                            ->execute()
        ;

        $people = People::find([
            "estado='A'",
            "order" => "nombres",
            "limit" => 100,
        ]);

        $I->assertEquals(count($personas->toArray()), count($people->toArray()));
        $I->assertEquals($personas->getFirst()->cedula, $people->getFirst()->cedula);
    }

    /**
     * @param IntegrationTester $I
     * @param Example           $example
     *
     * @dataprovider adapterProvider
     */
    public function whereOrderByLimitRenamed(IntegrationTester $I, Example $example)
    {
        $this->container->setShared('db', $example['adapter']);

        $personers = Personers::query()
                              ->where("status='A'")
                              ->orderBy("navnes")
                              ->limit(100)
                              ->execute()
        ;

        $I->assertInstanceOf(Simple::class, $personers);
        $I->assertInstanceOf(Personers::class, $personers->getFirst());
    }

    /**
     * @param IntegrationTester $I
     * @param Example           $example
     *
     * @dataprovider adapterProvider
     */
    public function bindParamsWithLimit(IntegrationTester $I, Example $example)
    {
        $this->container->setShared('db', $example['adapter']);

        $personas = Personas::query()
                            ->where("estado=?1")
                            ->bind([1 => "A"])
                            ->orderBy("nombres")
                            ->limit(100)
                            ->execute()
        ;

        $people = People::find([
            "estado=?1",
            "bind"  => [1 => "A"],
            "order" => "nombres",
            "limit" => 100,
        ]);

        $I->assertEquals(count($personas->toArray()), count($people->toArray()));
        $I->assertEquals($personas->getFirst()->cedula, $people->getFirst()->cedula);
    }

    /**
     * @param IntegrationTester $I
     * @param Example           $example
     *
     * @dataprovider adapterProvider
     */
    public function bindParamsWithOrderAndLimitRenamed(IntegrationTester $I, Example $example)
    {
        $this->container->setShared('db', $example['adapter']);

        $personers = Personers::query()
                              ->where("status=?1")
                              ->bind([1 => "A"])
                              ->orderBy("navnes")
                              ->limit(100)
                              ->execute()
        ;

        $I->assertInstanceOf(Simple::class, $personers);
        $I->assertInstanceOf(Personers::class, $personers->getFirst());
    }

    /**
     * @param IntegrationTester $I
     * @param Example           $example
     *
     * @dataprovider adapterProvider
     */
    public function bindParamsAsPlaceholdersWithOrderAndLimitRenamed(IntegrationTester $I, Example $example)
    {
        $this->container->setShared('db', $example['adapter']);

        $personers = Personers::query()
                              ->where("status=:status:")
                              ->bind(["status" => "A"])
                              ->orderBy("navnes")
                              ->limit(100)
                              ->execute()
        ;

        $I->assertInstanceOf(Simple::class, $personers);
        $I->assertInstanceOf(Personers::class, $personers->getFirst());
    }

    /**
     * @param IntegrationTester $I
     * @param Example           $example
     *
     * @dataprovider adapterProvider
     */
    public function limitWithOffset(IntegrationTester $I, Example $example)
    {
        $this->container->setShared('db', $example['adapter']);

        $personas = Personas::query()
                            ->where("estado=?1")
                            ->bind([1 => "A"])
                            ->orderBy("nombres")
                            ->limit(100, 10)
                            ->execute()
        ;

        $people = People::find([
            "estado=?1",
            "bind"  => [1 => "A"],
            "order" => "nombres",
            "limit" => ['number' => 100, 'offset' => 10],
        ]);

        $I->assertEquals(count($personas->toArray()), count($people->toArray()));
        $I->assertEquals($personas->getFirst()->cedula, $people->getFirst()->cedula);
    }

    /**
     * @param IntegrationTester $I
     * @param Example           $example
     *
     * @dataprovider adapterProvider
     */
    public function bindOrderLimit(IntegrationTester $I, Example $example)
    {
        $this->container->setShared('db', $example['adapter']);

        $personas = Personas::query()
                            ->where("estado=:estado:")
                            ->bind(["estado" => "A"])
                            ->orderBy("nombres")
                            ->limit(100)
                            ->execute()
        ;

        $people = People::find([
            "estado=:estado:",
            "bind"  => ["estado" => "A"],
            "order" => "nombres",
            "limit" => 100,
        ]);

        $I->assertEquals(count($personas->toArray()), count($people->toArray()));
        $I->assertEquals($personas->getFirst()->cedula, $people->getFirst()->cedula);
    }

    /**
     * @param IntegrationTester $I
     * @param Example           $example
     *
     * @dataprovider adapterProvider
     */
    public function orderBy(IntegrationTester $I, Example $example)
    {
        $this->container->setShared('db', $example['adapter']);

        $personas = Personas::query()->orderBy("nombres");

        $I->assertEquals($personas->getOrderBy(), "nombres");
    }

    /**
     * @param IntegrationTester $I
     * @param Example           $example
     *
     * @issue        https://github.com/phalcon/cphalcon/issues/2131
     * @dataprovider adapterProvider
     */
    public function freshCache(IntegrationTester $I, Example $example)
    {
        $this->container->setShared('db', $example['adapter']);
        $this->getAndSetModelsCacheFile();

        $personas = Personas::query()
                            ->where("estado='I'")
                            ->cache(['key' => 'cache-for-issue-2131'])
                            ->execute()
        ;

        $I->assertTrue($personas->isFresh());

        $personas = Personas::query()
                            ->where("estado='I'")
                            ->cache(['key' => 'cache-for-issue-2131'])
                            ->execute()
        ;

        $I->assertFalse($personas->isFresh());

        $I->amInPath(cacheFolder());
        $I->safeDeleteFile('cache-for-issue-2131');
        $I->dontSeeFileFound('cache-for-issue-2131');
    }

    /**
     * The data providers
     *
     * @return array
     */
    protected function adapterProvider()
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
