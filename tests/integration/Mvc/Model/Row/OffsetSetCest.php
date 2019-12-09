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
use Phalcon\Mvc\Model\Exception;
use Phalcon\Mvc\Model\Row;

class OffsetSetCest
{
    /**
     * Tests Phalcon\Mvc\Model\Row :: offsetSet()
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-06-01
     */
    public function mvcModelRowOffsetSet(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model\Row - offsetSet()');

        $row = new Row();

        $I->expectThrowable(
            new Exception('Row is an immutable ArrayAccess object'),
            function () use ($row) {
                $row['estado'] = 'A';
            }
        );
    }
}
