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

namespace Phalcon\Tests\Database\Mvc\Model\MetaData\Strategy;

use Phalcon\Mvc\Model\Exception as ModelException;
use Phalcon\Mvc\Model\MetaData\Strategy\Introspection;
use Phalcon\Storage\Exception;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Models\Invoices;
use Phalcon\Tests\Support\Models\InvoicesMap;
use Phalcon\Tests\Support\Traits\DiTrait;

final class IntrospectionTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    /**
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2023-07-01
     *
     * @group mysql
     */
    public function testMvcModelMetadataIntrospection(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();

        $strategy = new Introspection();
        $invoice  = new Invoices();

        $expected = [
            0 => null,
            1 => null,
        ];
        $actual   = $strategy->getColumnMaps($invoice, $this->container);
        $this->assertSame($expected, $actual);

        $expected = [
            0 => [
                0 => 'inv_id',
                1 => 'inv_cst_id',
                2 => 'inv_status_flag',
                3 => 'inv_title',
                4 => 'inv_total',
                5 => 'inv_created_at',
            ],
            1 => [
                0 => 'inv_id',
            ],
            2 => [
                0 => 'inv_cst_id',
                1 => 'inv_status_flag',
                2 => 'inv_title',
                3 => 'inv_total',
                4 => 'inv_created_at',
            ],
            3 => [
                0 => 'inv_id',
            ],
            4 => [
                'inv_id'          => 0,
                'inv_cst_id'      => 0,
                'inv_status_flag' => 26,
                'inv_title'       => 2,
                'inv_total'       => 7,
                'inv_created_at'  => 4,
            ],
            5 => [
                'inv_id'          => true,
                'inv_cst_id'      => true,
                'inv_status_flag' => true,
                'inv_total'       => true,
            ],
            8 => 'inv_id',
            9 => [
                'inv_id'          => 1,
                'inv_cst_id'      => 1,
                'inv_status_flag' => 1,
                'inv_title'       => 2,
                'inv_total'       => 32,
                'inv_created_at'  => 2,
            ],
            10 => [],
            11 => [],
            12 => [
                'inv_cst_id'      => null,
                'inv_status_flag' => null,
                'inv_title'       => null,
                'inv_total'       => null,
                'inv_created_at'  => null,
            ],
            13 => [],
        ];
        $actual   = $strategy->getMetaData($invoice, $this->container);
        $this->assertSame($expected, $actual);
    }

    /**
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2023-07-01
     *
     * @group mysql
     * @group sqlite
     */
    public function testMvcModelMetadataIntrospectionException(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();

        $strategy = new Introspection();
        $invoice = $this
            ->getMockBuilder(InvoicesMap::class)
            ->getMock()
        ;
        $invoice
            ->method('columnMap')
            ->willReturn(false)
        ;

        $this->expectException(ModelException::class);
        $this->expectExceptionMessage('columnMap() not returned an array');
        $strategy->getColumnMaps($invoice, $this->container);
    }
}
