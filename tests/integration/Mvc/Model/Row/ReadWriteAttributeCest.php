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

namespace Phalcon\Test\Integration\Mvc\Model\Row;

use IntegrationTester;
use Phalcon\Mvc\Model\Row;

class ReadWriteAttributeCest
{
    /**
     * Tests Phalcon\Mvc\Model\Row :: readAttribute() / writeAttribute()
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-06-01
     */
    public function mvcModelRowReadWriteAttribute(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model\Row - readAttribute() / writeAttribute()');

        $row = new Row();

        $row->writeAttribute('estado', 'A');

        $I->assertEquals(
            'A',
            $row->readAttribute('estado')
        );
    }
}
