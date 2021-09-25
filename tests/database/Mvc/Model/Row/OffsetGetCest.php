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

use DatabaseTester;
use Phalcon\Mvc\Model\Row;

class OffsetGetCest
{
    /**
     * Tests Phalcon\Mvc\Model\Row :: offsetGet()
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-06-01
     *
     * @group  common
     */
    public function mvcModelRowOffsetGet(DatabaseTester $I)
    {
        $I->wantToTest('Mvc\Model\Row - offsetGet()');

        $row = new Row();

        $row->writeAttribute('inv_title', 'Sample title');

        $I->assertEquals(
            'Sample title',
            $row['inv_title']
        );
    }
}
