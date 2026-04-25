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

use Phalcon\Mvc\Model\Query\Builder;
use Phalcon\Storage\Exception;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Models\Invoices;
use Phalcon\Tests\Support\Traits\DiTrait;

final class GetPhqlTest extends AbstractDatabaseTestCase
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
     * @since  2018-11-13
     *
     * @group mysql
     * @group pgsql
     * @group sqlite
     */
    public function testMvcModelQueryBuilderGetPhql(): void
    {
        $params = [
            'models'     => Invoices::class,
            'columns'    => ['inv_id', 'inv_title', 'inv_status_flag'],
            'conditions' => 'a > 5',
            'group'      => ['type', 'source'],
            'having'     => 'b < 5',
            'order'      => ['name', 'created'],
            'limit'      => 10,
            'offset'     => 15,
        ];

        $builder = new Builder($params, $this->container);

        $expected = 'SELECT inv_id, inv_title, inv_status_flag FROM [' . Invoices::class . '] '
            . 'WHERE a > 5 GROUP BY [type], [source] '
            . 'HAVING b < 5 ORDER BY [name], [created] '
            . 'LIMIT :APL0: OFFSET :APL1:';
        $actual   = $builder->getPhql();
        $this->assertEquals($expected, $actual);
    }
}
