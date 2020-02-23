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
use Phalcon\Mvc\Model\Row;

class ReadWriteAttributeCest
{
    /**
     * Tests Phalcon\Mvc\Model\Row :: readAttribute() / writeAttribute()
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-06-01
     *
     * @group common
     */
    public function mvcModelRowReadWriteAttribute(DatabaseTester $I)
    {
        $I->wantToTest('Mvc\Model\Row - readAttribute() / writeAttribute()');

        $row = new Row();

        $row->writeAttribute('inv_title', 'Sample title');

        $I->assertEquals(
            'Sample title',
            $row->readAttribute('inv_title')
        );
    }
}
