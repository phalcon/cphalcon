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
use Phalcon\Tests\AbstractDatabaseTestCase;

final class ForUpdateTest extends AbstractDatabaseTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-02-01
     *
     * @group mysql
     * @group pgsql
     * @group sqlite
     */
    public function testMvcModelCriteriaForUpdate(): void
    {
        $criteria = new Criteria();

        $expected = [];
        $actual   = $criteria->getParams();
        $this->assertEquals($expected, $actual);

        $criteria->forUpdate(true);

        $expected = [
            'for_update' => true,
        ];
        $actual   = $criteria->getParams();
        $this->assertEquals($expected, $actual);
    }
}
