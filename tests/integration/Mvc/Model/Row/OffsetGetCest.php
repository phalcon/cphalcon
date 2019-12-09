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

class OffsetGetCest
{
    /**
     * Tests Phalcon\Mvc\Model\Row :: offsetGet()
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-06-01
     */
    public function mvcModelRowOffsetGet(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model\Row - offsetGet()');

        $row = new Row();

        $row->writeAttribute('estado', 'A');

        $I->assertEquals(
            'A',
            $row['estado']
        );
    }
}
