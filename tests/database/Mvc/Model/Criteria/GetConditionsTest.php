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

namespace Phalcon\Tests\Database\Mvc\Model\Criteria;

use Phalcon\Mvc\Model\Criteria;
use Phalcon\Mvc\Model\Query\Builder;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Models\Invoices;
use Phalcon\Tests\Support\Traits\DiTrait;

final class GetConditionsTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-02-01
     *
     * @group mysql
     * @group sqlite
     */
    public function testMvcModelCriteriaGetConditions(): void
    {
        $criteria = new Criteria();
        $criteria->setDI($this->container);

        $criteria
            ->setModelName(Invoices::class)
            ->conditions('inv_cst_id = 1')
        ;

        $builder = $criteria->createBuilder();

        $this->assertInstanceOf(Builder::class, $builder);

        $expected = 'SELECT [Phalcon\Tests\Support\Models\Invoices].* '
            . 'FROM [Phalcon\Tests\Support\Models\Invoices] '
            . 'WHERE inv_cst_id = 1';
        $actual   = $builder->getPhql();
        $this->assertEquals($expected, $actual);

        $expected = 'inv_cst_id = 1';
        $actual   = $criteria->getConditions();
        $this->assertEquals($expected, $actual);
    }
}
