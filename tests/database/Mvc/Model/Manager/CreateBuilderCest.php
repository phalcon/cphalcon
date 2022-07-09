<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the
 * LICENSE.txt file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Database\Mvc\Model\Manager;

use DatabaseTester;
use Phalcon\Mvc\Model\ManagerInterface;
use Phalcon\Mvc\Model\Query\StatusInterface;
use Phalcon\Mvc\Model\Resultset\Complex;
use Phalcon\Mvc\Model\Resultset\Simple;
use Phalcon\Storage\Exception;
use Phalcon\Tests\Fixtures\Traits\DiTrait;
use Phalcon\Tests\Models\Invoices;

use function spl_object_hash;

class CreateBuilderCest
{
    use DiTrait;

    /**
     * Tests Phalcon\Mvc\Model\Manager :: createBuilder()
     *
     * @param  DatabaseTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2022-07-04
     *
     * @group  mysql
     * @group  pgsql
     */
    public function mvcModelManagerCreateBuilder(DatabaseTester $I)
    {
        $I->wantToTest('Mvc\Model\Manager :: executeQuery() - #15024');

        $this->setNewFactoryDefault();
        $this->setDatabase($I);

        /** @var ManagerInterface $manager */
        $manager = $this->getService('modelsManager');

        $actual = $manager->getBuilder();
        $I->assertNull($actual);

        $builder    = $manager->createBuilder();
        $getBuilder = $manager->getBuilder();
        $expected   = spl_object_hash($builder);
        $actual     = spl_object_hash($getBuilder);
        $I->assertSame($expected, $actual);

        $builder    = $manager->createBuilder();
        $expected   = spl_object_hash($builder);
        $I->assertNotSame($expected, $actual);
    }
}
