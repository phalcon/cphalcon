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

namespace Phalcon\Tests\Database\Mvc\Model\Row;

use Phalcon\Mvc\Model\Row;
use Phalcon\Tests\AbstractDatabaseTestCase;

final class JsonSerializeTest extends AbstractDatabaseTestCase
{
    /**
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-06-01
     *
     * @group mysql
     * @group pgsql
     * @group sqlite
     */
    public function testMvcModelRowJsonSerialize(): void
    {
        $row = new Row();

        $row->writeAttribute('inv_id', 1);
        $row->writeAttribute('inv_cst_id', 2);
        $row->writeAttribute('inv_status_flag', 3);
        $row->writeAttribute('inv_title', 'Sample title');
        $row->writeAttribute('inv_total', 100.12);
        $row->writeAttribute('inv_created_at', '2019-12-25 01:02:03');

        $this->assertEquals(
            [
                'inv_id'          => 1,
                'inv_cst_id'      => 2,
                'inv_status_flag' => 3,
                'inv_title'       => 'Sample title',
                'inv_total'       => 100.12,
                'inv_created_at'  => '2019-12-25 01:02:03',
            ],
            $row->jsonSerialize()
        );
    }
}
