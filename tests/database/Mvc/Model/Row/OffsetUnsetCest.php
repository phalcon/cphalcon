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

namespace Phalcon\Test\Database\Mvc\Model\Row;

use DatabaseTester;
use Phalcon\Mvc\Model\Exception;
use Phalcon\Mvc\Model\Row;

class OffsetUnsetCest
{
    /**
     * Tests Phalcon\Mvc\Model\Row :: offsetUnset()
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-06-01
     */
    public function mvcModelRowOffsetUnset(DatabaseTester $I)
    {
        $I->wantToTest('Mvc\Model\Row - offsetUnset()');

        $row = new Row();

        $row->writeAttribute('inv_id', 1);

        $I->expectThrowable(
            new Exception('Row is an immutable ArrayAccess object'),
            function () use ($row) {
                unset($row['inv_id']);
            }
        );
    }
}
