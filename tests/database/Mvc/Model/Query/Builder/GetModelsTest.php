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

namespace Phalcon\Tests\Database\Mvc\Model\Query\Builder;

use Phalcon\Storage\Exception;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Models\Customers;
use Phalcon\Tests\Support\Models\Invoices;
use Phalcon\Tests\Support\Traits\DiTrait;

final class GetModelsTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    /**
     * @return void
     */
    public function setUp(): void
    {
        try {
            $this->setNewFactoryDefault();
        } catch (Exception $e) {
            $this->fail($e->getMessage());
        }

        $this->setDatabase();
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-04-08
     *
     * @group mysql
     */
    public function testMvcModelQueryBuilderGetModelsNull(): void
    {
        $manager = $this->getService('modelsManager');
        $builder = $manager->createBuilder();

        $this->assertNull($builder->getModels());
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-04-08
     *
     * @group mysql
     */
    public function testMvcModelQueryBuilderGetModelsString(): void
    {
        $manager = $this->getService('modelsManager');
        $builder = $manager
            ->createBuilder()
            ->from(['Invoices' => Invoices::class])
        ;

        $expected = Invoices::class;
        $actual   = $builder->getModels();
        $this->assertEquals($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-04-08
     *
     * @group mysql
     */
    public function testMvcModelQueryBuilderGetModelsArray(): void
    {
        $manager = $this->getService('modelsManager');
        $builder = $manager
            ->createBuilder()
            ->from(['Invoices' => Invoices::class])
            ->addFrom(Customers::class, 'Customers')
        ;

        $expected = [
            'Invoices'  => Invoices::class,
            'Customers' => Customers::class,
        ];
        $actual   = $builder->getModels();
        $this->assertEquals($expected, $actual);
    }
}
